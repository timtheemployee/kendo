#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const std::vector<int> &data) {
    _count = data.size();
    GL_CALL(glGenBuffers(1, &_bufferId));
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferId));
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(int), data.data(), GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
    GL_CALL(glDeleteBuffers(1, &_bufferId));
}

auto IndexBuffer::bind() const -> void {
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferId));
}

auto IndexBuffer::unbind() const -> void {
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

auto IndexBuffer::getCount() const -> GLuint {
    return _count;
}
