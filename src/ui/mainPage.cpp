#include "ui/mainPage.h"
#include "ui/selectionPage.h"
#include <QtWidgets/QApplication>
#include <QtCore/Qt>

#include <QtWidgets/QScrollArea>

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
    auto scrollArea = new QScrollArea();
    scrollArea -> setWidgetResizable(true);

    auto page = new QWidget(scrollArea);
    auto layout = new QVBoxLayout(page);

    scrollArea -> setWidget(page);

    layout -> setAlignment(Qt::AlignTop);
    layout -> setSpacing(10);

    auto label = new QLabel("Select an operating system to view its wallpapers");
    label -> setStyleSheet("font-weight: bold;");
    label -> setWordWrap(true);
    label -> setAlignment(Qt::AlignHCenter);
    layout -> addWidget(label);

    layout -> addSpacing(10);

    auto windowsVersionsLabel = new QLabel("Windows Versions:");
    layout -> addWidget(windowsVersionsLabel);

    const QStringList windowsVersions = {
        "Windows XP",
        "Windows Vista",
        "Windows 7",
        "Windows 8.1",
        "Windows 10",
        "Windows 11"
    };

    for (const QString& windowsVersion : windowsVersions) {
        auto btn = new QPushButton(windowsVersion);
        btn -> setStyleSheet("padding: 8px;");

        connect(btn, &QPushButton::clicked, [this, windowsVersion]() {
            const WallpaperStore& wallpapers = m_versionsDict[windowsVersion];
            QStringList urls, names;

            for (const auto& wallpaper : wallpapers) {
                names.append(QString::fromStdString(wallpaper.name));
                urls.append(QString::fromStdString(wallpaper.url));
            }

            showWallpapers(windowsVersion, urls, names);
        });

        layout -> addWidget(btn);
    }

    auto macosVersionsLabel = new QLabel("macOS Versions:");
    layout -> addWidget(macosVersionsLabel);

    const QStringList macOSVersions = {
        "Mac OS X 10.0 (Cheetah)",
        "Mac OS X 10.1 (Puma)",
        "Mac OS X 10.2 (Jaguar)",
        "Mac OS X 10.3 (Panther)",
        "Mac OS X 10.4 (Tiger)",
        "Mac OS X 10.5 (Leopard)",
        "Mac OS X 10.6 (Snow Leopard)",
        "OS X 10.7 (Lion)",
        "OS X 10.8 (Mountain Lion)",
        "OS X 10.9 (Mavericks)",
        "OS X 10.10 (Yosemite)",
        "OS X 10.11 (El Capitan)",
        "macOS 10.12 (Sierra)",
        "macOS 10.13 (High Sierra)",
        "macOS 10.14 (Mojave)",
        "macOS 10.15 (Catalina)",
        "macOS 11 (Big Sur)",
        "macOS 12 (Monterey)",
        "macOS 13 (Ventura)",
        "macOS 14 (Sonoma)",
        "macOS 15 (Sequoia)",
    };

    for (const QString& macOSVersion : macOSVersions) {
        auto btn = new QPushButton(macOSVersion);
        btn -> setStyleSheet("padding: 8px;");

        connect(btn, &QPushButton::clicked, [this, macOSVersion]() {
            const WallpaperStore& wallpapers = m_versionsDict[macOSVersion];
            QStringList urls, names;

            for (const auto& wallpaper : wallpapers) {
                names.append(QString::fromStdString(wallpaper.name));
                urls.append(QString::fromStdString(wallpaper.url));
            }

            showWallpapers(macOSVersion, urls, names);
        });

        layout -> addWidget(btn);
    }

    layout->addStretch();

    return scrollArea;
}

void MainWindow::setupVersionsDict() {
    m_versionsDict["Windows XP"] = xp;
    m_versionsDict["Windows Vista"] = vista;
    m_versionsDict["Windows 7"] = seven;
    m_versionsDict["Windows 8.1"] = eightPointOne;
    m_versionsDict["Windows 10"] = ten;
    m_versionsDict["Windows 11"] = eleven;

    m_versionsDict["Mac OS X 10.0 (Cheetah)"] = macOS_10_0;
    m_versionsDict["Mac OS X 10.1 (Puma)"] = macOS_10_1;
    m_versionsDict["Mac OS X 10.2 (Jaguar)"] = macOS_10_2;
    m_versionsDict["Mac OS X 10.3 (Panther)"] = macOS_10_3;
    m_versionsDict["Mac OS X 10.4 (Tiger)"] = macOS_10_4;
    m_versionsDict["Mac OS X 10.5 (Leopard)"] = macOS_10_5;
    m_versionsDict["Mac OS X 10.6 (Snow Leopard)"] = macOS_10_6;
    m_versionsDict["OS X 10.7 (Lion)"] = macOS_10_7;
    m_versionsDict["OS X 10.8 (Mountain Lion)"] = macOS_10_8;
    m_versionsDict["OS X 10.9 (Mavericks)"] = macOS_10_9;
    m_versionsDict["OS X 10.10 (Yosemite)"] = macOS_10_10;
    m_versionsDict["OS X 10.11 (El Capitan)"] = macOS_10_11;
    m_versionsDict["macOS 10.12 (Sierra)"] = macOS_10_12;
    m_versionsDict["macOS 10.13 (High Sierra)"] = macOS_10_13;
    m_versionsDict["macOS 10.14 (Mojave)"] = macOS_10_14;
    m_versionsDict["macOS 10.15 (Catalina)"] = macOS_10_15;
    m_versionsDict["macOS 11 (Big Sur)"] = macOS_11;
    m_versionsDict["macOS 12 (Monterey)"] = macOS_12;
    m_versionsDict["macOS 13 (Ventura)"] = macOS_13;
    m_versionsDict["macOS 14 (Sonoma)"] = macOS_14;
    m_versionsDict["macOS 15 (Sequoia)"] = macOS_15;
}

void MainWindow::showMainPage() {
    setWindowTitle(MAIN_TITLE);
    m_stackedWidget -> setCurrentWidget(m_mainPage);
}

void MainWindow::showWallpapers(const QString& version, const QStringList& urls, const QStringList& names) {
    m_wallpaperPage -> setupWallpapers(version, urls, names);
    m_stackedWidget -> setCurrentWidget(m_wallpaperPage);
}
