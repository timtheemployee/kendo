#include "Mesh.h"

Mesh::Mesh(const VertexData &vertex_data) {
    _verticesSize = vertex_data.indecies.size();
    GL_CALL(glGenVertexArrays(1, &_vertexAttributeObject));
    GL_CALL(glBindVertexArray(_vertexAttributeObject));

    GLuint elementBuffer;
    GL_CALL(glGenBuffers(1, &elementBuffer));
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer));
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertex_data.indecies.size() * sizeof(int), vertex_data.indecies.data(), GL_STATIC_DRAW));

    GLuint vertexBuffer;
    GL_CALL(glGenBuffers(1, &vertexBuffer));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, vertex_data.vertices.size() * sizeof(float), vertex_data.vertices.data(), GL_STATIC_DRAW));

    GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr));
    GL_CALL(glEnableVertexAttribArray(0));

    GL_CALL(glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float))));
    GL_CALL(glEnableVertexAttribArray(1));

    GL_CALL(glBindVertexArray(0));
    GL_CALL(glDeleteBuffers(1, &elementBuffer));
    GL_CALL(glDeleteBuffers(1, &vertexBuffer));
}

auto Mesh::getVerticesSize() const -> int {
    return _verticesSize;
}

auto Mesh::getAttributeObject() const -> GLuint {
    return _vertexAttributeObject;
}

auto Mesh::clenUp() -> void {
    GL_CALL(glDeleteVertexArrays(1, &_vertexAttributeObject));
}

