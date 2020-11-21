cmake_minimum_required(VERSION 3.17.0)

project(desktop)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE core
    PRIVATE glfw
    PRIVATE libglew_static
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
