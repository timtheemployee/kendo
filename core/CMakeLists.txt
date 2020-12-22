cmake_minimum_required(VERSION 3.17.0)

project(core)

add_library(${PROJECT_NAME}
    Renderer.cpp
    ShaderLoader.cpp
    TextureLoader.cpp
    Texture.cpp
    VertexBuffer.cpp
    IndexBuffer.cpp
    VertexBufferLayout.cpp
    VertexArray.cpp
    Shader.cpp
    Entity.cpp
    PerspectiveCamera.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE glm
    PRIVATE glfw
    PRIVATE libglew_static
    PRIVATE stb
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
