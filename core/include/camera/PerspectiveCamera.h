#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class PerspectiveCamera {

private:
    constexpr static auto _up = glm::vec3{0.f, 1.f, 0.f};
    constexpr static auto _front = glm::vec3{0.0f, 0.0f, -1.0f};
    mutable glm::vec3 _position;
    glm::mat4 _projection;

public:
    PerspectiveCamera(const float width, const float height);

    auto setPosition(const glm::vec3 &position) const -> void;
    auto position() const -> glm::vec3;
    auto view() const -> glm::mat4;
    auto projection() const -> glm::mat4;
};
