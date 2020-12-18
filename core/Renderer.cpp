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

auto Renderer::draw(const Entity &entity, const Shader &shader) const -> void {
    shader.bind();
    entity.getVertexArray().bind();
    entity.getIndexBuffer().bind();

    auto transformation = getTransformationMatrix(entity);
    shader.setUniformMat4f("transformationMatrix", transformation);

    GL_CALL(glDrawElements(GL_TRIANGLES, entity.getIndexBuffer().getCount(), GL_UNSIGNED_INT, nullptr));
}

auto Renderer::getTransformationMatrix(const Entity &entity) const -> glm::mat4 {
    auto identity = glm::mat4{1};
    auto translated = glm::translate(identity, entity.getPosition());
    auto rotatedByX = glm::rotate(translated, glm::radians(entity.getRotationX()), xAxis);
    auto rotatedByY = glm::rotate(rotatedByX, glm::radians(entity.getRotationY()), yAxis);
    auto rotatedByZ = glm::rotate(rotatedByY, glm::radians(entity.getRotationZ()), zAxis);
    auto scaled = glm::scale(rotatedByZ, glm::vec3{entity.getScale()});

    return scaled;
}
