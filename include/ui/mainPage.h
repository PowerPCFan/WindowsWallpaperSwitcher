#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QStackedWidget>
#include <QString>
#include <QMap>
#include <QStringList>
#include <memory>

#include "Wallpapers.h"

class WallpaperSelectionPage;

class MainWindow : public QWidget {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow() = default;

        void showMainPage();
        void showWallpapers(const QString& version, const QStringList& urls, const QStringList& names);

    private:
        QWidget* createMainPage();
        void setupVersionsDict();

        QString m_fontStack;
        QStackedWidget* m_stackedWidget;
        QWidget* m_mainPage;
        WallpaperSelectionPage* m_wallpaperPage;
        QMap<QString, WallpaperStore> m_versionsDict;

        static const QString MAIN_TITLE;
};
