#include "include/WindowHandler.h"

WindowHandler::WindowHandler(GLFWwindow *window): _window{window} {}

auto WindowHandler::setWindowListener(const std::function<void(GLFWwindow*)> &windowListener) -> void {
    _windowListener = windowListener;
}

auto WindowHandler::update() const -> void {
    if (_windowListener != nullptr) {
        _windowListener.operator()(_window);
    }
}
