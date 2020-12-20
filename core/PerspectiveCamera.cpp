#include "camera/PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(const float width, const float height) :
    _projection{glm::mat4{1.f}},
    _view{glm::mat4{1.f}} {

    _view = glm::translate(_view, {0.f, 0.f, -3.0f});
    _projection = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);
}

auto PerspectiveCamera::view() const -> glm::mat4 {
    return _view;
}

auto PerspectiveCamera::projection() const -> glm::mat4 {
    return _projection;
}
