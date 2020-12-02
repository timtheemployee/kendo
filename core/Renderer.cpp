#include "Renderer.h"

Renderer::Renderer(){}

auto Renderer::prepare() -> void {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.f, 0.f, 0.f, 1.f);
}

auto Renderer::use(const Program &program) -> void {
    program.use();
}

auto Renderer::render(const Mesh &mesh) -> void {
    glBindVertexArray(mesh.getAttributeObject());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glDrawElements(GL_TRIANGLES, mesh.getVerticesSize(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

auto Renderer::dismiss(const Program &program) -> void {
    program.dispose();
}
