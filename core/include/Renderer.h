#include "GlExtensions.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Entity.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Renderer
{
private:
    constexpr static auto xAxis = glm::vec3{1, 0, 0};
    constexpr static auto yAxis = glm::vec3{0, 1, 0};
    constexpr static auto zAxis = glm::vec3{0, 0, 1};

    auto getTransformationMatrix(const Entity &entity) const -> glm::mat4;

public:
    Renderer();
    auto clear() const -> void;
    auto draw(const VertexArray &vertexArray,
              const IndexBuffer &buffer,
              const Shader &shader) const -> void;

    auto draw(const Entity &entity,
              const Shader &shader) const -> void;
};
