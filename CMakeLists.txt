cmake_minimum_required(VERSION 2.8)

project(Ray_tracer)

#aux_source_directory(. SRC_LIST)

set(Ray_tracer_SRC main.cpp Box.cpp Functions.cpp Light.cpp Screen.cpp Spectator.cpp Sphere.cpp Tetrahedron.cpp Vector3d.cpp)
set(Ray_tracer_HDR Box.h CImg.h Figure.h Functions.h Header.h Light.h Screen.h Spectator.h Sphere.h Tetrahedron.h Vector3d.h)

add_executable(${PROJECT_NAME} ${Ray_tracer_SRC} ${Ray_tracer_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")