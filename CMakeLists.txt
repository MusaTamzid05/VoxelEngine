cmake_minimum_required(VERSION 3.0)

project(game)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


SET(SOURCE_FILES
    src/main.cpp
    src/window.cpp
    src/utils.cpp
    src/shader.cpp
    src/triangle.cpp
    src/camera.cpp
    src/renderer.cpp
    src/block.cpp
    src/texture_manager.cpp
    src/chunk.cpp
    src/light.cpp
    src/material.cpp
    )



add_executable(game ${SOURCE_FILES})

include_directories(include)
target_link_libraries(game sfml-graphics sfml-window sfml-system GL glut GLEW dl)
