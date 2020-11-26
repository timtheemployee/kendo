#include "Renderer.h"

Renderer::Renderer(){}

auto Renderer::prepare() -> void {
    glClearColor(1.f, 0.f, 0.f, 1.f);
}

auto Renderer::render(const Mesh &mesh) -> void {
    _meshes.push_back(mesh);

    glBindVertexArray(mesh.getAttributeObject());
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, mesh.getVerticesSize());
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

auto Renderer::clenUp() -> void {
    for (Mesh &mesh : _meshes) {
        mesh.clenUp();
    }
}
