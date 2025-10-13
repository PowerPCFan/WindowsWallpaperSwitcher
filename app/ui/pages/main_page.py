from ..ui_global_vars import main_title

from wallpaper_dicts import XP
from wallpaper_dicts import VISTA
from wallpaper_dicts import SEVEN
from wallpaper_dicts import EIGHT_POINT_ONE
from wallpaper_dicts import TEN
from wallpaper_dicts import ELEVEN

from PyQt6.QtWidgets import QWidget
from PyQt6.QtWidgets import QLabel
from PyQt6.QtWidgets import QPushButton
from PyQt6.QtWidgets import QVBoxLayout
from PyQt6.QtWidgets import QStackedWidget

from PyQt6.QtCore import Qt

from .selection_page import WallpaperSelectionPage


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
