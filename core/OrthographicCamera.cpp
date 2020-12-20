#include "camera/OrthographicCamera.h"

OrthographicCamera::OrthographicCamera(const float width, const float height) :
    _projection{glm::ortho(0.0f, width, 0.0f, height, _nearPlane, _farPlane)},
    _view{glm::translate(glm::mat4{1}, {0.f, 0.f, -3.f})}
{}

OrthographicCamera::~OrthographicCamera() {}

auto OrthographicCamera::setPosition(const glm::vec3 &position) -> void {
    _view = glm::translate(_view, position);
}

auto OrthographicCamera::translate(float dx, float dy, float dz) -> void {
    _view = glm::translate(_view, {dx, dy, dz});
}

auto OrthographicCamera::projection() const -> glm::mat4 {
    return _projection;
}

auto OrthographicCamera::view() const -> glm::mat4 {
    return _view;
}
