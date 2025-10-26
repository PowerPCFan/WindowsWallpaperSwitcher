#include "ui/mainPage.h"
#include "ui/selectionPage.h"
#include <QtWidgets/QApplication>
#include <QtCore/Qt>

const QString MainWindow::MAIN_TITLE = "Windows Wallpaper Switcher";

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), m_fontStack("Inter, system-ui") {
    setWindowTitle(MAIN_TITLE);
    resize(400, 400);
    setStyleSheet(QString("font-family: %1;").arg(m_fontStack));

    m_stackedWidget = new QStackedWidget(this);

    m_mainPage = createMainPage();
    m_stackedWidget -> addWidget(m_mainPage);

    m_wallpaperPage = new WallpaperSelectionPage(m_fontStack, this);
    m_stackedWidget -> addWidget(m_wallpaperPage);

    auto layout = new QVBoxLayout(this);
    layout -> addWidget(m_stackedWidget);
    setLayout(layout);

    setupVersionsDict();
    showMainPage();
}

QWidget* MainWindow::createMainPage() {
    auto page = new QWidget();
    auto layout = new QVBoxLayout(page);
    layout -> setSpacing(10);

    auto label = new QLabel("Select a Windows version to view wallpapers");
    label -> setStyleSheet("font-size: 16px; font-weight: bold;");
    label -> setWordWrap(true);
    label -> setAlignment(Qt::AlignHCenter);
    layout -> addWidget(label);

    layout -> addSpacing(10);

    const QStringList versions = {
        "Windows XP",
        "Windows Vista",
        "Windows 7",
        "Windows 8.1",
        "Windows 10",
        "Windows 11"
    };

    for (const QString& version : versions) {
        auto btn = new QPushButton(version);
        btn -> setStyleSheet("padding: 8px;");

        connect(btn, &QPushButton::clicked, [this, version]() {
            const WallpaperStore& wallpapers = m_versionsDict[version];
            QStringList urls, names;

            for (const auto& wallpaper : wallpapers) {
                names.append(QString::fromStdString(wallpaper.name));
                urls.append(QString::fromStdString(wallpaper.url));
            }

            showWallpapers(version, urls, names);
        });

        layout -> addWidget(btn);
    }

    layout -> addStretch();
    page -> setLayout(layout);
    return page;
}

void MainWindow::setupVersionsDict() {
    m_versionsDict["Windows XP"] = xp;
    m_versionsDict["Windows Vista"] = vista;
    m_versionsDict["Windows 7"] = seven;
    m_versionsDict["Windows 8.1"] = eightPointOne;
    m_versionsDict["Windows 10"] = ten;
    m_versionsDict["Windows 11"] = eleven;
}

void MainWindow::showMainPage() {
    setWindowTitle(MAIN_TITLE);
    m_stackedWidget -> setCurrentWidget(m_mainPage);
}

void MainWindow::showWallpapers(const QString& version, const QStringList& urls, const QStringList& names) {
    m_wallpaperPage -> setupWallpapers(version, urls, names);
    m_stackedWidget -> setCurrentWidget(m_wallpaperPage);
}
