#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class PerspectiveCamera {

private:
    glm::mat4 _projection;
    glm::mat4 _view;

public:
    PerspectiveCamera(const float width, const float height);

    auto view() const -> glm::mat4;
    auto projection() const -> glm::mat4;
};
