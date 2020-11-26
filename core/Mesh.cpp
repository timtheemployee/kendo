#include "Mesh.h"

Mesh::Mesh(const std::vector<float> &vertices) {
    _verticesSize = vertices.size();

    glGenVertexArrays(1, &_vertexAttributeObject);
    glBindVertexArray(_vertexAttributeObject);

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glDeleteBuffers(1, &buffer);
}

auto Mesh::getVerticesSize() const -> int {
    return _verticesSize;
}

auto Mesh::getAttributeObject() const -> GLuint {
    return _vertexAttributeObject;
}

auto Mesh::clenUp() -> void {
    glDeleteVertexArrays(1, &_vertexAttributeObject);
}

