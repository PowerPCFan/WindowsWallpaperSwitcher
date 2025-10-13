from .ui_global_vars import wallpaper_downloader, wallpaper_save_dir, user_32
from user32 import Action, ApplyMode
from PyQt6.QtWidgets import QMessageBox


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
