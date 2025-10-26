#include <iostream>
#include <stdexcept>

#include <ui/ui.h>

int main() {
    try {
        return show_ui();
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }
}
