#include "camera/PerspectiveCamera.h"

#include <iostream>
#include <glm/gtx/string_cast.hpp>

PerspectiveCamera::PerspectiveCamera(const float width, const float height) :
    _position{glm::vec3{0.0f, 0.0f, 3.f}},
    _projection{glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.f)},
    _movementSpeed{0.05f}
{}

auto PerspectiveCamera::setPosition(const glm::vec3 &position) const -> void {
    _position = position;
}

auto PerspectiveCamera::view() const -> glm::mat4 {
    return glm::lookAt(_position, _position + _front, _up);
}

auto PerspectiveCamera::projection() const -> glm::mat4 {
    return _projection;
}

auto PerspectiveCamera::position() const -> glm::vec3 {
    return _position;
}

auto PerspectiveCamera::forward() -> void {
    _position += _movementSpeed * _front;
}

auto PerspectiveCamera::backward() -> void {
    _position -= _movementSpeed * _front;
}

auto PerspectiveCamera::left() -> void {
    _position -= glm::normalize(glm::cross(_front, _up)) * _movementSpeed;
}

auto PerspectiveCamera::right() -> void {
    _position += glm::normalize(glm::cross(_front, _up)) * _movementSpeed;
}
