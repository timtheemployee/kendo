#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Entity {
private:
    const VertexArray &_vertexArray;
    const IndexBuffer &_indexBuffer;

    mutable glm::mat4 _model;

public:
    Entity(const VertexArray &vertexArray, const IndexBuffer &indexBuffer);
    ~Entity();

    auto translate(float dx, float dy, float dz) const -> void;
    auto rotate(float dx, float dy, float dz) const -> void;
    auto scale(float scale) const -> void;

    auto getVertexArray() const -> const VertexArray&;
    auto getIndexBuffer() const -> const IndexBuffer&;

    auto getModel() const -> const glm::mat4&;
    auto setModel(const glm::mat4 &model) const -> void;
};
