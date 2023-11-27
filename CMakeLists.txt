cmake_minimum_required(VERSION 3.0)

project(voxel)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


SET(SOURCE_FILES
    src/main.cpp
    src/window.cpp
    src/utils.cpp
    src/shader.cpp
    src/triangle.cpp
    src/camera.cpp
    )



add_executable(voxel ${SOURCE_FILES})

include_directories(include)
target_link_libraries(voxel sfml-graphics sfml-window sfml-system GL glut GLEW dl)
