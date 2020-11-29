#include "Mesh.h"

Mesh::Mesh(const std::vector<float> &vertices, const std::vector<int> &indecies) {
    _verticesSize = indecies.size();

    glGenVertexArrays(1, &_vertexAttributeObject);
    glBindVertexArray(_vertexAttributeObject);

    GLuint elementBuffer;
    glGenBuffers(1, &elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indecies.size() * sizeof(int), indecies.data(), GL_STATIC_DRAW);

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glBindVertexArray(0);

    glDeleteBuffers(1, &elementBuffer);
    glDeleteBuffers(1, &vertexBuffer);
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

