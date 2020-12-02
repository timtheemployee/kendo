#include "Mesh.h"

Mesh::Mesh(const VertexData &vertex_data) {
    _verticesSize = vertex_data.indecies.size();
    glGenVertexArrays(1, &_vertexAttributeObject);
    glBindVertexArray(_vertexAttributeObject);

    GLuint elementBuffer;
    glGenBuffers(1, &elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertex_data.indecies.size() * sizeof(int), vertex_data.indecies.data(), GL_STATIC_DRAW);

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_data.vertices.size() * sizeof(float), vertex_data.vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    GLuint textureBuffer;
    glGenBuffers(1, &textureBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_data.uv.size() * sizeof(float), vertex_data.uv.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindVertexArray(0);
    glDeleteBuffers(1, &elementBuffer);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &textureBuffer);
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

