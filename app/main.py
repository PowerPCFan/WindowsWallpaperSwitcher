from ui import ui
import sys

if __name__ == "__main__":
    try:
        ui.show_ui()
    except KeyboardInterrupt:
        sys.exit(0)
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
