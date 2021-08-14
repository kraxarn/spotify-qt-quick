cmake_minimum_required(VERSION 3.5)
project(spotify-qt-quick LANGUAGES CXX VERSION 2.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt
# TODO: Not properly updated for Qt 6 yet
find_package(Qt5 COMPONENTS Quick QuickControls2 Widgets WebEngine REQUIRED)

# Glob source files
file(GLOB MAIN_SRC "${PROJECT_SOURCE_DIR}/src/*.[hc]pp")
file(GLOB SUB_SRC "${PROJECT_SOURCE_DIR}/src/*/*.[hc]pp")
set(SOURCES ${MAIN_SRC} ${SUB_SRC})

# Add all source files to main executable
if (ANDROID)
	add_library(spotify-qt-quick SHARED ${SOURCES} res.qrc)
else ()
	add_executable(spotify-qt-quick ${SOURCES} res.qrc)
endif ()

# Headers are in src/
target_include_directories(spotify-qt-quick PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Get version from Git
find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
	execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
		OUTPUT_VARIABLE GIT_COMMIT
		OUTPUT_STRIP_TRAILING_WHITESPACE)
	target_compile_definitions(spotify-qt-quick PRIVATE GIT_COMMIT="${GIT_COMMIT}")
endif ()

# Version macros
target_compile_definitions(${PROJECT_NAME} PRIVATE APP_VERSION="v${PROJECT_VERSION}")

# Don't show console window under windows
if (WIN32)
	target_link_options(spotify-qt PRIVATE -mwindows)
endif ()

# Link Qt
target_link_libraries(spotify-qt-quick PRIVATE
	Qt5::Core
	Qt5::Quick
	Qt5::QuickControls2
	# TODO: Some stuff like dialogs still depend on Widgets
	Qt5::Widgets
	# TODO: WebEngine doesn't actually work on mobile
	Qt5::WebEngine)

# spotify-qt-lib
set(QT_VERSION_MAJOR 5)
set(LIB_QT_IMPL ON)
add_subdirectory(core/lib)
target_link_libraries(spotify-qt-quick PRIVATE spotify-qt-lib)
