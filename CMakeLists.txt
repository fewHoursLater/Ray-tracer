cmake_minimum_required(VERSION 2.8)

project(Ray tracer)

#aux_source_directory(. SRC_LIST)

set(Ray tracer_SRC main.cpp Vector_3_float.cpp Figure.cpp Box.cpp Sphere.cpp Tetrahedron.cpp Spectator.cpp Light.cpp Screen.cpp Functions.cpp)
set(Ray tracer_HDR Header.h Vector_3_float.h Figure.h Box.h Sphere.h Tetrahedron.h Spectator.h Light.h Screen.h Functions.h)

add_executable(${PROJECT_NAME} ${Ray tracer_SRC} ${Ray tracer_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")