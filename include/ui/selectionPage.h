#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QMessageBox>
#include <QString>
#include <QStringList>

class MainWindow;

class WallpaperSelectionPage : public QWidget {
    Q_OBJECT

    public:
        explicit WallpaperSelectionPage(const QString& fontStack, MainWindow* mainWindow, QWidget *parent = nullptr);
        
        void setupWallpapers(const QString& version, const QStringList& urls, const QStringList& names);

    private slots:
        void onApply();
        void goBack();

    private:
        QString m_fontStack;
        MainWindow* m_mainWindow;

        QPushButton* m_backButton;
        QPushButton* m_applyButton;
        QScrollArea* m_scrollArea;
        QButtonGroup* m_buttonGroup;

        QStringList m_currentUrls;
        QStringList m_currentNames;
};
