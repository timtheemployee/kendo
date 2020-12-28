#include <GLFW/glfw3.h>
#include <functional>


typedef

class WindowHandler {
private:
    GLFWwindow *_window;
    std::function<void(GLFWwindow*)> _windowListener = nullptr;

public:
    WindowHandler(GLFWwindow *window);
    ~WindowHandler() = default;

    auto setWindowListener(const std::function<void(GLFWwindow*)> &windowListener) -> void;
    auto update() const -> void;
};
