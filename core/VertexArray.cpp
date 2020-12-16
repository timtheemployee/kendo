#include "VertexArray.h"

VertexArray::VertexArray() {
    GL_CALL(glGenVertexArrays(1, &_arrayId));
    GL_CALL(glBindVertexArray(_arrayId));
}

VertexArray::~VertexArray() {
    GL_CALL(glDeleteVertexArrays(1, &_arrayId));
}

auto VertexArray::addBuffer(const VertexBuffer &buffer, const VertexBufferLayout &layout) const -> void {
    bind();
    buffer.bind();
    auto elements = layout.getElements();
    int offset = 0;
    for (int i = 0; i < elements.size(); i++) {
        auto element = elements[i];
        GL_CALL(glEnableVertexAttribArray(i));
        GL_CALL(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*) offset));
        offset += element.count * getSizeOfType(element.type);
    }
}

auto VertexArray::bind() const -> void {
    GL_CALL(glBindVertexArray(_arrayId));
}

auto VertexArray::unbind() const -> void {
    GL_CALL(glBindVertexArray(0));
}
