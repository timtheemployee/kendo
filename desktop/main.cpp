#include <Renderer.h>
#include <TextureLoader.h>
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
    std::cout << "renderer created" << std::endl;
    auto texture_loader = TextureLoader{};
    std::cout << "texture loader initialized" << std::endl;
    auto wall_texture = texture_loader.get_texture("wall.jpg");
    std::cout << "wall texture loaded" << std::endl;

    auto program = Program{"", "base"};
    std::cout << "Shaders initialized" << std::endl;

    std::vector<float> square = {
        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f
    };

    std::vector<int> indecies = {
        0, 1, 3, 3, 1, 2
    };

    std::vector<float> uv = {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f
    };

    const auto vertex_data = VertexData{square, uv, indecies};
    std::cout << "vertex data created" << std::endl;
    const auto square_mesh = Mesh{vertex_data};
    std::cout << "mesh created" << std::endl;

    while(!glfwWindowShouldClose(window)) {
        process_input(window);
        wall_texture.bind();
        renderer.prepare();
        renderer.use(program);
        renderer.render(square_mesh);
        renderer.dismiss(program);
        wall_texture.unbind();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    program.dispose();

    glfwTerminate();
    return 0;
}
