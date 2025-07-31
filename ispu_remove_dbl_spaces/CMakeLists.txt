cmake_minimum_required(VERSION 3.5)

project(ispu_remove_dbl_spaces VERSION 0.1)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

add_executable(ispu_remove_dbl_spaces
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

target_link_libraries(ispu_remove_dbl_spaces PRIVATE
    Qt6::Core 
    Qt6::Widgets
    )

set_target_properties(ispu_remove_dbl_spaces PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
