cmake_minimum_required(VERSION 3.16)
project(rythmopen_poc VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Multimedia)

add_executable(rythmopen_poc
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.hpp
)

target_link_libraries(rythmopen_poc
    Qt6::Core
    Qt6::Widgets
    Qt6::Multimedia
)

install(TARGETS rythmopen_poc
    RUNTIME DESTINATION bin
)
