#include "Entity.h"

Entity::Entity(const VertexArray &vertexArray, const IndexBuffer &indexBuffer) :
    _vertexArray{vertexArray},
    _indexBuffer{indexBuffer},
    _position{0, 0, 0},
    _rotationX{0}, _rotationY{0}, _rotationZ{0},
    _scale{1}
{}

Entity::~Entity() {}

auto Entity::translate(float dx, float dy, float dz) const -> void {
    _position.x += dx;
    _position.y += dy;
    _position.z += dz;
}

auto Entity::rotate(float dx, float dy, float dz) const -> void {
    _rotationX += dx;
    _rotationY += dy;
    _rotationZ += dz;
}

auto Entity::scale(float scale) const -> void {
    _scale = scale;
}

auto Entity::getVertexArray() const -> const VertexArray& {
    return _vertexArray;
}

auto Entity::getIndexBuffer() const -> const IndexBuffer& {
    return _indexBuffer;
}

auto Entity::getPosition() const -> const glm::vec3& {
    return _position;
}

auto Entity::getRotationX() const -> float {
    return _rotationX;
}

auto Entity::getRotationY() const -> float {
    return _rotationY;
}

auto Entity::getRotationZ() const -> float {
    return _rotationZ;
}

auto Entity::getScale() const -> float {
    return _scale;
}
