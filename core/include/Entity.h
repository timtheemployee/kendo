#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include <glm/glm.hpp>

class Entity {
private:
    VertexArray _vertexArray;
    IndexBuffer _indexBuffer;

    mutable glm::vec3 _position;
    mutable float _rotationX, _rotationY, _rotationZ;
    mutable float _scale;

public:
    Entity(const VertexArray &vertexArray, const IndexBuffer &indexBuffer);
    ~Entity();

    auto translate(float dx, float dy, float dz) const -> void;
    auto rotate(float dx, float dy, float dz) const -> void;
    auto scale(float scale) const -> void;

    auto getVertexArray() const -> const VertexArray&;
    auto getIndexBuffer() const -> const IndexBuffer&;

    auto getPosition() const -> const glm::vec3&;
    auto getRotationX() const -> float;
    auto getRotationY() const -> float;
    auto getRotationZ() const -> float;
    auto getScale() const -> float;
};
