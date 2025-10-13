from ui import ui

if __name__ == "__main__":
    try:
        ui.show_ui()
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
