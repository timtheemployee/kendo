#include "VertexBufferLayout.h"

VertexBufferLayout::VertexBufferLayout() : _elements{}, _stride{0} {}
VertexBufferLayout::~VertexBufferLayout() {}

auto VertexBufferLayout::push(unsigned int type, unsigned int count) const -> void {
    _elements.push_back({type, count, GL_FALSE});
}

auto VertexBufferLayout::floats(unsigned int count) const -> void {
    push(GL_FLOAT, count);
    _stride += count * getSizeOfType(GL_FLOAT);
}

auto VertexBufferLayout::ints(unsigned int count) const -> void {
    push(GL_UNSIGNED_INT, count);
    _stride += count * getSizeOfType(GL_UNSIGNED_INT);
}

auto VertexBufferLayout::bytes(unsigned int count) const -> void {
    push(GL_UNSIGNED_BYTE, count);
    _stride += count * getSizeOfType(GL_UNSIGNED_BYTE);
}

auto VertexBufferLayout::getStride() const -> unsigned int {
    return _stride;
}

auto VertexBufferLayout::getElements() const -> const std::vector<VertexBufferElement>& {
    return _elements;
}
