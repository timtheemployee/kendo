#include "GlExtensions.h"
#include <GL/glew.h>
#include <vector>

class IndexBuffer {
private:
    GLuint _bufferId;
    int _count;

public:
    IndexBuffer(const std::vector<int> &data);
    ~IndexBuffer();

    auto bind() const -> void;
    auto unbind() const -> void;

    auto getCount() const -> GLuint;
};
