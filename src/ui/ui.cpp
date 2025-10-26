#include <ui/ui.h>
#include <ui/mainPage.h>

#include <QApplication>
#include <QStyleFactory>
#include <QFontDatabase>
#include <QFont>

int show_ui() {
    int argc = 0;
    char** argv = nullptr;
    QApplication app(argc, argv);
    app.setStyle(QStyleFactory::create("WindowsVista"));

    int fontId = QFontDatabase::addApplicationFont("./src/fonts/inter.ttf");
    if (fontId != -1) {
        QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
        if (!fontFamilies.isEmpty()) {
            QString fontFamily = fontFamilies.at(0);
            QFont interFont(fontFamily);
            app.setFont(interFont);
        }
    }

    MainWindow main_win;
    main_win.show();

    return app.exec();
}
