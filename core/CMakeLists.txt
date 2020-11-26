cmake_minimum_required(VERSION 3.17.0)

project(core)

add_library(${PROJECT_NAME}
    Mesh.cpp
    Renderer.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE glfw
    PRIVATE libglew_static
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
