#include "Renderer.h"

Renderer::Renderer(const std::string &shaders_root): _program(shaders_root){}

auto Renderer::prepare() -> void {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.f, 0.f, 0.f, 1.f);
}

auto Renderer::render(const Mesh &mesh) -> void {
    glBindVertexArray(mesh.getAttributeObject());
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, mesh.getVerticesSize(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

auto Renderer::attach_shader(const std::string &name) -> void {
    _program.create(name);
    _program.use();
}

auto Renderer::clean_up() -> void {
    _program.clean_up();
}
