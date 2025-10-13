from ui import show_ui

if __name__ == "__main__":
    try:
        show_ui()
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
