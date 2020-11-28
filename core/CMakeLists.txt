cmake_minimum_required(VERSION 3.17.0)

project(core)

add_library(${PROJECT_NAME}
    Mesh.cpp
    Renderer.cpp
    ShaderLoader.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE glfw
    PRIVATE libglew_static
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
