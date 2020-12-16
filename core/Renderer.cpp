#include "Renderer.h"

Renderer::Renderer(){}

auto Renderer::draw(const VertexArray &vertexArray,
                    const IndexBuffer &buffer,
                    const Shader &shader) const -> void {
    shader.bind();
    vertexArray.bind();
    buffer.bind();
    GL_CALL(glDrawElements(GL_TRIANGLES, buffer.getCount(), GL_UNSIGNED_INT, nullptr));
}

auto Renderer::clear() const -> void {
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
}
