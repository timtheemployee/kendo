#include "Renderer.h"

Renderer::Renderer(const PerspectiveCamera &camera) : _camera{camera} {}

auto Renderer::clear() const -> void {
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
}

auto Renderer::draw(const Entity &entity, const Shader &shader) const -> void {
    shader.bind();
    entity.getVertexArray().bind();
    entity.getIndexBuffer().bind();

    shader.setUniformMat4f("projection", _camera.projection());
    shader.setUniformMat4f("view", _camera.view());
    shader.setUniformMat4f("model", entity.getModel());

    GL_CALL(glDrawElements(GL_TRIANGLES, entity.getIndexBuffer().getCount(), GL_UNSIGNED_INT, nullptr));
}
