cmake_minimum_required(VERSION 3.5)
project(spotify-qt-quick LANGUAGES CXX VERSION 2.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt
include(core/cmake/FindQt.cmake)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Quick QuickControls2 REQUIRED)

# Glob source files
file(GLOB MAIN_SRC "${PROJECT_SOURCE_DIR}/src/*.[hc]pp")
file(GLOB SUB_SRC "${PROJECT_SOURCE_DIR}/src/*/*.[hc]pp")
set(SOURCES ${MAIN_SRC} ${SUB_SRC})

# Add all source files to main executable
if (QT_VERSION_MAJOR EQUAL 6)
	qt_add_executable(${PROJECT_NAME} ${SOURCES} res.qrc)
else ()
	if (ANDROID)
		add_library(${PROJECT_NAME} SHARED ${SOURCES} res.qrc)
	else ()
		add_executable(${PROJECT_NAME} ${SOURCES} res.qrc)
	endif ()
endif ()

# Headers are in src/
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Get version from Git
find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
	execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
		OUTPUT_VARIABLE GIT_COMMIT
		OUTPUT_STRIP_TRAILING_WHITESPACE)
	target_compile_definitions(${PROJECT_NAME} PRIVATE GIT_COMMIT="${GIT_COMMIT}")
endif ()

# Version macros
target_compile_definitions(${PROJECT_NAME} PRIVATE APP_VERSION="v${PROJECT_VERSION}")

# Don't show console window under windows
if (WIN32)
	target_link_options(${PROJECT_NAME} PRIVATE -mwindows)
endif ()

# Link Qt
target_link_libraries(${PROJECT_NAME} PRIVATE
	Qt${QT_VERSION_MAJOR}::Core
	Qt${QT_VERSION_MAJOR}::Gui
	Qt${QT_VERSION_MAJOR}::Quick
	Qt${QT_VERSION_MAJOR}::QuickControls2)

# spotify-qt-lib
set(LIB_QT_IMPL ON)
add_subdirectory(core/lib)
target_link_libraries(${PROJECT_NAME} PRIVATE spotify-qt-lib)
