cmake_minimum_required(VERSION 3.16)
project(WindowsWallpaperSwitcher)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set Qt installation path
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.3/mingw_64")

# Find required Qt components
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Automatically handle Qt's MOC, UIC, and RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Include directories
include_directories(include)

# Glob source files from src directory
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

# Glob header files from include directory
file(GLOB_RECURSE HEADERS "include/*.h" "include/*.hpp")

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)

# Link Windows libraries
if(WIN32)
    target_link_libraries(${PROJECT_NAME} urlmon)
endif()

# Set target properties for Windows
if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
    
    # Add custom command to deploy Qt dependencies
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS ${CMAKE_PREFIX_PATH}/bin)
    
    if(WINDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${WINDEPLOYQT_EXECUTABLE} $<TARGET_FILE:${PROJECT_NAME}>
            COMMENT "Deploying Qt libraries")
    endif()
endif()