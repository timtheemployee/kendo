#include "GlExtensions.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include <GL/glew.h>

class Renderer
{
public:
    Renderer();
    auto clear() const -> void;
    auto draw(const VertexArray &vertexArray,
              const IndexBuffer &buffer,
              const Shader &shader) const -> void;
};
