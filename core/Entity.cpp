#include "Entity.h"

Entity::Entity(const VertexArray &vertexArray, const IndexBuffer &indexBuffer, const std::vector<Texture> &textures) :
    _vertexArray{vertexArray},
    _indexBuffer{indexBuffer},
    _textures{textures},
    _model{1}
{}

Entity::~Entity() {}

auto Entity::translate(float dx, float dy, float dz) const -> void {
    _model = glm::translate(_model, glm::vec3{dx, dy, dz});
}

auto Entity::rotate(float dx, float dy, float dz) const -> void {
    _model = glm::rotate(_model, glm::radians(dx), {1, 0, 0});
    _model = glm::rotate(_model, glm::radians(dy), {0, 1, 0});
    _model = glm::rotate(_model, glm::radians(dz), {0, 0, 1});
}

auto Entity::scale(float scale) const -> void {
    _model = glm::scale(_model, glm::vec3{scale});
}

auto Entity::getVertexArray() const -> const VertexArray& {
    return _vertexArray;
}

auto Entity::getIndexBuffer() const -> const IndexBuffer& {
    return _indexBuffer;
}

auto Entity::getModel() const -> const glm::mat4& {
    return _model;
}

auto Entity::getTextures() const -> const std::vector<Texture>& {
    return _textures;
}
