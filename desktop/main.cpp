#include <Renderer.h>
#include <VertexArray.h>
#include <VertexBufferLayout.h>
#include <loading/TextureLoader.h>
#include <Shader.h>
#include <Entity.h>
#include <camera/PerspectiveCamera.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <memory>

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

    GL_CALL(glEnable(GL_BLEND));
    GL_CALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));


    auto camera = PerspectiveCamera{(float) width, (float) height};
    auto renderer = Renderer{camera};
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
    auto texture = textureLoader.getTexture("wall.jpg", "image");

    auto sample = textureLoader.getTexture("sample.png", "sampleImage");
    auto textures = std::vector<std::shared_ptr<Texture>>{texture, sample};

    auto entity = Entity{vertexArray, indexBuffer, textures};
    auto secondEntity = Entity{vertexArray, indexBuffer, textures};

    secondEntity.scale(.5f);
    secondEntity.translate(0.5f, 0.5f, 2.f);
    const auto radius = 10.f;
    while(!glfwWindowShouldClose(window)) {
        float cameraX = sin(glfwGetTime()) * radius;
        float cameraZ = cos(glfwGetTime()) * radius;

        camera.setPosition(glm::vec3{cameraX, 0.f, cameraZ});
        process_input(window);
        renderer.clear();
        shader.bind();
        shader.setUniform1f("time", glfwGetTime());
        shader.unbind();

        renderer.draw(entity, shader);
        renderer.draw(secondEntity, shader);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    texture->unbind();
    sample->unbind();

    glfwTerminate();
    return 0;
}
