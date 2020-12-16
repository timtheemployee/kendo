#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const std::vector<float> &data) {
    GL_CALL(glGenBuffers(1, &_bufferId));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, _bufferId));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() {
    GL_CALL(glDeleteBuffers(1, &_bufferId));
}

auto VertexBuffer::bind() const -> void {
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, _bufferId));
}

auto VertexBuffer::unbind() const -> void {
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
