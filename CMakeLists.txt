cmake_minimum_required(VERSION 2.8)
if (POLICY CMP0017)
    cmake_policy(SET CMP0017 OLD)
endif()

set(QT_CLIPBOARD_PROVIDER_INCLUDE_DIR "include")
set(QT_CLIPBOARD_PROVIDER_SRC_DIR "src")

# FIXME: nasty
set(CEGUI_INCLUDE_PATH "/home/kulik/Devel/CEGUI/cegui_mk2/cegui/include" "/home/kulik/Devel/CEGUI/cegui_mk2/build/cegui/include")
# FIXME: even nastier
set(QT_INCLUDE_PATH "/usr/include/qt4")

project(QtClipboardProvider)

file (GLOB QT_CLIPBOARD_PROVIDER_SOURCE_FILES ${QT_CLIPBOARD_PROVIDER_SRC_DIR}/*.cpp)
include_directories(${QT_CLIPBOARD_PROVIDER_INCLUDE_DIR} ${CEGUI_INCLUDE_PATH} ${QT_INCLUDE_PATH})
add_library(QtClipboardProvider SHARED ${QT_CLIPBOARD_PROVIDER_SOURCE_FILES})
