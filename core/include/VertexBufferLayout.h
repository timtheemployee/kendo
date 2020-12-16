#pragma once

#include <vector>
#include <GL/glew.h>
#include "GlExtensions.h"

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned int normalized;
};

class VertexBufferLayout {
private:
    mutable std::vector<VertexBufferElement> _elements;
    mutable unsigned int _stride;
    auto push(unsigned int type, unsigned int count) const -> void;

public:
    VertexBufferLayout();
    ~VertexBufferLayout();

    auto floats(unsigned int count) const -> void;
    auto ints(unsigned int count) const -> void;
    auto bytes(unsigned int count) const -> void;
    auto getStride() const -> unsigned int;
    auto getElements() const -> const std::vector<VertexBufferElement>&;
};
