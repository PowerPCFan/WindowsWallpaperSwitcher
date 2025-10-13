import sys

from PyQt6.QtWidgets import QApplication, QStyleFactory
from PyQt6.QtGui import QFontDatabase

from pathlib import Path

from .pages.main_page import MainWindow


def show_ui() -> None:
    app = QApplication(sys.argv)
    app.setStyle(QStyleFactory.create("WindowsVista"))

    inter_id = QFontDatabase.addApplicationFont(((
        Path(__file__)
        .parent
        .parent
        / "fonts"
        / "inter.ttf"
    ).resolve().__str__()))

    if inter_id != -1:
        inter_family = QFontDatabase.applicationFontFamilies(inter_id)[0]
        font_stack = f"'{inter_family}', system-ui"
    else:
        font_stack = "system-ui"

    main_win = MainWindow(font_stack)
    main_win.show()

    exit_code = app.exec()
    sys.exit(exit_code)
