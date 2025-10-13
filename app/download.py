import requests
from pathlib import Path


def _download_large_file(
    url: str,
    destination: str | Path,
    chunk_size: int = 8192,
    headers: dict | None = None,
    timeout: int | None = None
) -> None:

    try:
        with requests.get(
            url,
            stream=True,
            headers=headers,
            timeout=timeout
        ) as r:
            r.raise_for_status()
            with open(destination, mode='wb') as f:
                for chunk in r.iter_content(chunk_size=chunk_size):
                    if chunk:
                        f.write(chunk)
    except requests.exceptions.RequestException as e:
        print(f"Error downloading file: {e}")


class WallpaperDownloader:
    def __init__(self) -> None:
        pass

    def download(
        self,
        url: str,
        save_path: str | Path,
        timeout: int = 10
    ) -> None:
        _download_large_file(
            url=url,
            destination=save_path,
            timeout=timeout
        )
