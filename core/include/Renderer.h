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
public:
    Renderer();
    auto clear() const -> void;
    auto draw(const Entity &entity,
              const Shader &shader) const -> void;
};
