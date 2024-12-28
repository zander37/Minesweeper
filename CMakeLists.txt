cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Minesweeper)

## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "c:/SFML/lib/cmake/SFML")
include_directories(c:/SFML/include/SFML)
find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)
add_executable(untitled main.cpp
        window.h
        window.cpp
        button.h
        button.cpp
)
target_link_libraries(untitled sfml-system sfml-window sfml-graphics sfml-audio)
