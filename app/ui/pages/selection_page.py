from PyQt6.QtWidgets import QWidget
from PyQt6.QtWidgets import QPushButton
from PyQt6.QtWidgets import QVBoxLayout
from PyQt6.QtWidgets import QHBoxLayout
from PyQt6.QtWidgets import QScrollArea
from PyQt6.QtWidgets import QRadioButton
from PyQt6.QtWidgets import QButtonGroup
from PyQt6.QtWidgets import QMessageBox

from ..misc import apply_wallpaper

from typing import TYPE_CHECKING
if TYPE_CHECKING:
    from .main_page import MainWindow


class WallpaperSelectionPage(QWidget):
    def __init__(self, font_stack: str, main_window: "MainWindow"):
        super().__init__()
        self.font_stack = font_stack
        self.main_window = main_window

        layout = QVBoxLayout()

        button_layout = QHBoxLayout()

        self.back_button = QPushButton("Back")
        self.back_button.clicked.connect(self.go_back)
        button_layout.addWidget(self.back_button)

        button_layout.addStretch()

        self.apply_button = QPushButton("Apply")
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
