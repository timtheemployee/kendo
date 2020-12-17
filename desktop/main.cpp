#include <Renderer.h>
#include <VertexArray.h>
#include <VertexBufferLayout.h>
#include <TextureLoader.h>
#include <Shader.h>
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
    auto texture_loader = TextureLoader{};
    auto shader = Shader{"", "base"};

    std::vector<float> square = {
        -0.5f, 0.5f, 0.0f,   0.0f,  1.0f,
        -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,
        0.5f, -0.5f, 0.0f,   1.0f,  0.0f,
        0.5f, 0.5f, 0.0f,    1.0f,  1.0f
    };


    std::vector<int> indecies = {
        0, 1, 3, 3, 1, 2
    };

    auto indexBuffer = IndexBuffer{indecies};

    auto vertexArray = VertexArray{};

    auto vertexBuffer = VertexBuffer{square};

    auto layout = VertexBufferLayout{};
    layout.floats(3);
    layout.floats(2);

    vertexArray.addBuffer(vertexBuffer, layout);

    auto textureLoader = TextureLoader{};
    auto texture = textureLoader.get_texture("wall.jpg");

    texture.bind();
    shader.setUniform1i("image", 0);

    while(!glfwWindowShouldClose(window)) {
        process_input(window);
        renderer.clear();

        shader.bind();
        shader.setUniform1f("time", glfwGetTime());
        shader.unbind();

        renderer.draw(vertexArray, indexBuffer, shader);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
