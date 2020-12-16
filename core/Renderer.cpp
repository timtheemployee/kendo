#include "Renderer.h"

Renderer::Renderer(){}

auto Renderer::prepare() -> void {
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
    GL_CALL(glClearColor(1.f, 0.f, 0.f, 1.f));
}

auto Renderer::use(const Program &program) -> void {
    program.use();
}

auto Renderer::render(const Mesh &mesh) -> void {
    GL_CALL(glBindVertexArray(mesh.getAttributeObject()));
    GL_CALL(glEnableVertexAttribArray(0));
    GL_CALL(glEnableVertexAttribArray(1));
    GL_CALL(glDrawElements(GL_TRIANGLES, mesh.getVerticesSize(), GL_UNSIGNED_INT, 0));
    GL_CALL(glDisableVertexAttribArray(0));
    GL_CALL(glBindVertexArray(0));
}

auto Renderer::dismiss(const Program &program) -> void {
    program.dispose();
}
