from download import WallpaperDownloader
from user32 import User32
from tempfile import gettempdir
from pathlib import Path

wallpaper_downloader = WallpaperDownloader()
wallpaper_save_dir = Path(gettempdir()) / "wallpapers"
wallpaper_save_dir.mkdir(parents=True, exist_ok=True)

user_32 = User32()

main_title = "Windows Wallpaper Switcher"
