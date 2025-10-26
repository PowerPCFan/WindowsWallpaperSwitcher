#include "ui/selectionPage.h"
#include "ui/mainPage.h"
#include "Download.h"
#include <QStandardPaths>
#include <QDir>
#include <QMessageBox>
#include <QUrl>
// #include <windows.h>
#include <winuser.h>

std::string getTempPath() {
    const char* temp = std::getenv("TEMP");
    if (!temp) {
        temp = std::getenv("TMP");
    }
    return temp ? std::string(temp) : std::string("C:\\Temp");
}

void applyWallpaper(const QString& url, const QString& name) {
    std::string tempDir = getTempPath();
    QString wallpaperDir = QString::fromStdString(tempDir) + "/windowswallpaperswitcher-wallpapers";

    QDir dir;
    if (!dir.exists(wallpaperDir)) {
        dir.mkpath(wallpaperDir);
    }

    QUrl qurl(url);
    QString fileName = qurl.fileName();
    if (fileName.isEmpty()) {
        fileName = name + ".jpg";
    }
    QString savePath = wallpaperDir + "/" + fileName;

    std::wstring wUrl = url.toStdWString();
    std::wstring wSavePath = savePath.toStdWString();

    if (Downloader::downloadFile(wUrl, wSavePath)) {
        std::wstring wallpaperPath = savePath.toStdWString();

        bool wallpaperChangeSucceeded = SystemParametersInfoW(
            SPI_SETDESKWALLPAPER,                  // uiAction - set desktop wallpaper (equal to 20)
            0,                                     // uiParam - not used, set to 0 and ignore
            (PVOID)wallpaperPath.c_str(),          // pvParam - path to wallpaper file, as a C string
            SPIF_UPDATEINIFILE | SPIF_SENDCHANGE   // fWinIni - this is equal to 3 (save and apply immediately)
        );

        if (!(wallpaperChangeSucceeded)) {
            QMessageBox::warning(nullptr, "Error", QString("Failed to set wallpaper: %1").arg(name));
        }
    } else {
        QMessageBox::warning(nullptr, "Error", QString("Failed to download wallpaper: %1").arg(name));
    }
}

WallpaperSelectionPage::WallpaperSelectionPage(const QString& fontStack, MainWindow* mainWindow, QWidget *parent) : QWidget(parent), m_fontStack(fontStack), m_mainWindow(mainWindow), m_buttonGroup(nullptr) {
    auto layout = new QVBoxLayout(this);

    auto buttonLayout = new QHBoxLayout();

    m_backButton = new QPushButton("Back");
    connect(m_backButton, &QPushButton::clicked, this, &WallpaperSelectionPage::goBack);
    buttonLayout -> addWidget(m_backButton);

    buttonLayout -> addStretch();

    m_applyButton = new QPushButton("Apply");
    buttonLayout -> addWidget(m_applyButton);

    layout -> addLayout(buttonLayout);

    m_scrollArea = new QScrollArea();
    m_scrollArea -> setWidgetResizable(true);
    layout -> addWidget(m_scrollArea);

    setLayout(layout);
}

void WallpaperSelectionPage::setupWallpapers(const QString& version, const QStringList& urls, const QStringList& names) {
    m_mainWindow -> setWindowTitle(QString("%1 Wallpapers").arg(version));
    m_currentUrls = urls;
    m_currentNames = names;

    auto scrollWidget = new QWidget();
    auto scrollLayout = new QVBoxLayout(scrollWidget);
    scrollLayout -> setSpacing(8);

    if (m_buttonGroup) {
        delete m_buttonGroup;
    }

    m_buttonGroup = new QButtonGroup(this);

    for (const QString& name : names) {
        auto radio = new QRadioButton(name);
        radio -> setStyleSheet("padding: 4px;");
        scrollLayout -> addWidget(radio);
        m_buttonGroup -> addButton(radio);
    }

    scrollLayout -> addStretch();
    scrollWidget -> setLayout(scrollLayout);
    m_scrollArea -> setWidget(scrollWidget);

    disconnect(m_applyButton, &QPushButton::clicked, this, &WallpaperSelectionPage::onApply);
    connect(m_applyButton, &QPushButton::clicked, this, &WallpaperSelectionPage::onApply);
}

void WallpaperSelectionPage::onApply() {
    auto checked = m_buttonGroup -> checkedButton();
    if (checked) {
        int index = m_currentNames.indexOf(checked -> text());
        if (index != -1) {
            m_applyButton -> setEnabled(false);
            m_applyButton -> setText("Applying...");

            applyWallpaper(m_currentUrls[index], checked -> text());

            m_applyButton -> setEnabled(true);
            m_applyButton -> setText("Apply");

            QMessageBox::information(this, "Success", QString("Wallpaper '%1' has been applied!").arg(checked -> text()));

            goBack();
        }
    } else {
        QMessageBox::warning(this, "Error", "Please select a wallpaper.");
    }
}

void WallpaperSelectionPage::goBack() {
    m_mainWindow -> showMainPage();
}
