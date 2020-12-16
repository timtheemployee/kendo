#pragma once

#include "GlExtensions.h"
#include <GL/glew.h>
#include <vector>

class VertexBuffer {
private:
    GLuint _bufferId;

public:
    VertexBuffer(const std::vector<float> &data);
    ~VertexBuffer();

    auto bind() const -> void;
    auto unbind() const -> void;
};
