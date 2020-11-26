#include "core/Renderer.h"
#include <stdio.h>
#include <iostream>
#include "ShaderLoader.h"

auto process_input(GLFWwindow* window) -> void {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

auto on_frame_size_changed(GLFWwindow* window, int width, int height) -> void {
    glViewport(0, 0, width, height);
}

auto initalize() -> GLuint {
    float vertices[] = {
        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.0f, -0.5f, 0.0f,

        0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f
    };

    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glBindVertexArray(0);

    glDeleteBuffers(1, &vbo);

    return vao;
}


auto getShaderType(const GLuint type) -> std::string {
    if (type == GL_FRAGMENT_SHADER) return "fragment shader";
    if (type == GL_VERTEX_SHADER) return "vertex shader";

    throw std::invalid_argument("Illegal shader type");
}

auto shader(const std::string source, GLuint type) -> GLuint {
    const auto shader = glCreateShader(type);
    const auto *raw = source.c_str();
    glShaderSource(shader, 1, &raw, nullptr);
    glCompileShader(shader);

    int compileResult;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

    if (compileResult == GL_FALSE) {
        const auto message = "Error while compiling " + getShaderType(type) + " ";

        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        throw std::invalid_argument(message + infoLog);
    }

    return shader;
}


auto program() -> GLuint {
    const auto loader = desktop::ShaderLoader{""};

    const auto vertexShader = loader.load_vertex_shader("base");
    const auto fragmentShader = loader.load_fragment_shader("base");

    const auto vertexShaderId = shader(vertexShader, GL_VERTEX_SHADER);
    const auto fragmentShaderId = shader(fragmentShader, GL_FRAGMENT_SHADER);

    const auto program = glCreateProgram();
    glAttachShader(program, vertexShaderId);
    glAttachShader(program, fragmentShaderId);
    glLinkProgram(program);

    int linkingResult;
    glGetProgramiv(program, GL_LINK_STATUS, &linkingResult);

    if (linkingResult == GL_FALSE) {
        const auto message = "Error while linking program";
        throw std::invalid_argument(message);
    }

    glDeleteShader(fragmentShaderId);
    glDeleteShader(vertexShaderId);

    return program;
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    auto window = glfwCreateWindow(800, 600, "Desktop", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

#ifdef __APPLE__
    glewExperimental = GL_TRUE;
#endif

    glewInit();

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, on_frame_size_changed);

    const auto triangleProgram = program();
    const auto vao = initalize();

    while(!glfwWindowShouldClose(window)) {
        process_input(window);

        glClearColor(.2f, .3f, .3f, .0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(triangleProgram);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
