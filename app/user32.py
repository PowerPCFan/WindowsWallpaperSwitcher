import ctypes
from enum import Enum
from pathlib import Path


class Action(Enum):
    SPI_SETDESKWALLPAPER = 20


class ApplyMode(Enum):
    TEMPORARY = 0
    UPDATE_WIN_INI = 1
    UPDATE_IMMEDIATELY = 2
    SAVE_AND_APPLY_IMMEDIATELY = 3


class User32:
    def SystemParametersInfo(
        self,
        data_pointer: str | Path,
        action: Action,
        # default to 0 / unused
        action_param: int = 0,
        # default to save and apply immediately
        apply_mode: ApplyMode = ApplyMode.SAVE_AND_APPLY_IMMEDIATELY
    ) -> bool:
        return ctypes.windll.user32.SystemParametersInfoW(
            action.value,
            action_param,
            str(data_pointer),
            apply_mode.value
        )
