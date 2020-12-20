#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class OrthographicCamera {
private:
    constexpr static float _farPlane = 1000.f;
    constexpr static float _nearPlane = 0.1f;
    glm::mat4 _projection;
    glm::mat4 _view;

public:
    OrthographicCamera(const float width, const float height);
    ~OrthographicCamera();

    auto setPosition(const glm::vec3 &position) -> void;
    auto translate(float dx, float dy, float dz) -> void;
    auto projection() const -> glm::mat4;
    auto view() const -> glm::mat4;
};
