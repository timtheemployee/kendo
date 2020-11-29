#include <Renderer.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

auto process_input(GLFWwindow* window) -> void {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

auto on_frame_size_changed(GLFWwindow* window, int width, int height) -> void {
    glViewport(0, 0, width, height);
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

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glfwSetFramebufferSizeCallback(window, on_frame_size_changed);

    auto renderer = Renderer{};
    auto program = Program{"", "base"};
    program.bind_attribute(0, "position");

    std::vector<float> square = {
        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f
    };

    std::vector<int> indecies = {
        0, 1, 3, 3, 1, 2
    };

    const auto square_mesh = Mesh{square, indecies};

    while(!glfwWindowShouldClose(window)) {
        process_input(window);
        renderer.prepare();
        renderer.use(program);
        renderer.render(square_mesh);
        renderer.dismiss(program);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    program.dispose();

    glfwTerminate();
    return 0;
}
