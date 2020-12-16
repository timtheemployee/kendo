#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include <GL/glew.h>
#include "GlExtensions.h"

class VertexArray {
private:
    GLuint _arrayId;
public:
    VertexArray();
    ~VertexArray();

    auto addBuffer(const VertexBuffer &buffer, const VertexBufferLayout &layout) const -> void;
    auto bind() const -> void;
    auto unbind() const -> void;
};
