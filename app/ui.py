# ---------- Imports ---------- #

import sys

from PyQt6.QtWidgets import QApplication
from PyQt6.QtWidgets import QWidget
from PyQt6.QtWidgets import QLabel
from PyQt6.QtWidgets import QPushButton
from PyQt6.QtWidgets import QVBoxLayout
from PyQt6.QtWidgets import QHBoxLayout
from PyQt6.QtWidgets import QScrollArea
from PyQt6.QtWidgets import QRadioButton
from PyQt6.QtWidgets import QButtonGroup
from PyQt6.QtWidgets import QMessageBox
from PyQt6.QtWidgets import QStackedWidget

from PyQt6.QtCore import Qt

from PyQt6.QtGui import QFontDatabase

from wallpaper_dicts import XP
from wallpaper_dicts import VISTA
from wallpaper_dicts import SEVEN
from wallpaper_dicts import EIGHT_POINT_ONE
from wallpaper_dicts import TEN
from wallpaper_dicts import ELEVEN

from download import WallpaperDownloader

from user32 import User32
from user32 import Action
from user32 import ApplyMode

from pathlib import Path

from tempfile import gettempdir

# ---------- End Imports ---------- #


# ---------- Constants / Globals ---------- #

wallpaper_downloader = WallpaperDownloader()
wallpaper_save_dir = Path(gettempdir()) / "wallpapers"
wallpaper_save_dir.mkdir(parents=True, exist_ok=True)

user_32 = User32()

main_title = "Windows Wallpaper Switcher"

# ---------- End Constants / Globals ---------- #


# ---------- UI Classes / Functions ---------- #

def apply_wallpaper(url: str, name: str):
    safe_name = ""
    for char in name:
        if char.isalnum() or char in ('-', '_'):
            safe_name += char
        else:
            safe_name += "-"

    wallpaper_path = wallpaper_save_dir / f"{safe_name}.jpg"

    wallpaper_downloader.download(
        url=url,
        save_path=wallpaper_path
    )

    user_32.SystemParametersInfo(
        data_pointer=str(wallpaper_path.resolve()),
        action=Action.SPI_SETDESKWALLPAPER,
        apply_mode=ApplyMode.SAVE_AND_APPLY_IMMEDIATELY
    )

    QMessageBox.information(
        None,
        "Wallpaper Applied",
        f"Wallpaper '{name}' applied!"
    )


class MainWindow(QWidget):
    def __init__(self, font_stack: str):
        super().__init__()
        self.font_stack = font_stack
        self.setWindowTitle(main_title)
        self.resize(400, 400)
        self.setStyleSheet(f"font-family: {font_stack};")

        self.stacked_widget = QStackedWidget()

        self.main_page = self.create_main_page()
        self.stacked_widget.addWidget(self.main_page)

        self.wallpaper_page = WallpaperSelectionPage(font_stack, self)
        self.stacked_widget.addWidget(self.wallpaper_page)

        layout = QVBoxLayout()
        layout.addWidget(self.stacked_widget)
        self.setLayout(layout)

        self.show_main_page()

    def create_main_page(self):
        page = QWidget()
        layout = QVBoxLayout()
        layout.setSpacing(10)

        label = QLabel("Select a Windows version to view wallpapers")
        label.setStyleSheet("font-size: 16px; font-weight: bold;")
        label.setWordWrap(True)
        label.setAlignment(Qt.AlignmentFlag.AlignHCenter)
        layout.addWidget(label)

        layout.addSpacing(10)

        self.versions_dict: dict[str, dict[str, str]] = {
            "Windows XP": XP,
            "Windows Vista": VISTA,
            "Windows 7": SEVEN,
            "Windows 8.1": EIGHT_POINT_ONE,
            "Windows 10": TEN,
            "Windows 11": ELEVEN
        }

        for version, mapping in self.versions_dict.items():
            btn = QPushButton(version)
            btn.setStyleSheet("padding: 8px;")
            btn.clicked.connect(lambda checked, v=version, m=mapping: self.show_wallpapers(v, list(m.values()), list(m.keys())))  # noqa: E501
            layout.addWidget(btn)

        layout.addStretch()
        page.setLayout(layout)
        return page

    def show_main_page(self):
        self.setWindowTitle(main_title)
        self.stacked_widget.setCurrentWidget(self.main_page)

    def show_wallpapers(self, version: str, urls: list[str], names: list[str]):
        self.wallpaper_page.setup_wallpapers(version, urls, names)
        self.stacked_widget.setCurrentWidget(self.wallpaper_page)


class WallpaperSelectionPage(QWidget):
    def __init__(self, font_stack: str, main_window: MainWindow):
        super().__init__()
        self.font_stack = font_stack
        self.main_window = main_window

        layout = QVBoxLayout()

        button_layout = QHBoxLayout()

        self.back_button = QPushButton("Back")
        self.back_button.setStyleSheet("padding: 6px 12px;")
        self.back_button.clicked.connect(self.go_back)
        button_layout.addWidget(self.back_button)

        button_layout.addStretch()

        self.apply_button = QPushButton("Apply")
        self.apply_button.setStyleSheet("padding: 6px 12px;")
        button_layout.addWidget(self.apply_button)

        layout.addLayout(button_layout)

        self.scroll_area = QScrollArea()
        self.scroll_area.setWidgetResizable(True)
        layout.addWidget(self.scroll_area)

        self.setLayout(layout)

    def setup_wallpapers(
        self,
        version: str,
        urls: list[str],
        names: list[str]
    ):
        self.main_window.setWindowTitle(f"{version} Wallpapers")
        self.current_urls = urls
        self.current_names = names

        scroll_widget = QWidget()
        scroll_layout = QVBoxLayout()
        scroll_layout.setSpacing(8)

        self.button_group = QButtonGroup()
        for name in names:
            radio = QRadioButton(name)
            radio.setStyleSheet("padding: 4px;")
            scroll_layout.addWidget(radio)
            self.button_group.addButton(radio)

        scroll_layout.addStretch()
        scroll_widget.setLayout(scroll_layout)
        self.scroll_area.setWidget(scroll_widget)

        try:
            self.apply_button.clicked.disconnect()
        except TypeError:
            pass
        self.apply_button.clicked.connect(self.on_apply)

    def on_apply(self):
        checked = self.button_group.checkedButton()
        if checked:
            index = self.current_names.index(checked.text())
            apply_wallpaper(self.current_urls[index], checked.text())
            self.go_back()
        else:
            QMessageBox.warning(self, "Error", "Please select a wallpaper.")

    def go_back(self):
        self.main_window.show_main_page()


# ---------- End UI Classes / Functions ---------- #


# ---------- UI Entry Point ---------- #

def show_ui() -> None:
    app = QApplication(sys.argv)

    inter_id = QFontDatabase.addApplicationFont(
        (Path(__file__).parent / "fonts" / "inter.ttf").resolve().__str__()
    )
    if inter_id != -1:
        inter_family = QFontDatabase.applicationFontFamilies(inter_id)[0]
        font_stack = f"'{inter_family}', system-ui"
    else:
        font_stack = "system-ui"

    main_win = MainWindow(font_stack)
    main_win.show()
    sys.exit(app.exec())

# ---------- End UI Entry Point ---------- #
