#include "Mesh.h"
#include "ShaderLoader.h"

class Renderer
{
private:
    ShaderLoader loader;

public:
    Renderer();
    auto attach_shader(const std::string name) -> void;
    auto prepare() -> void;
    auto render(const Mesh &mesh) -> void;
    auto clean_up() -> void;
};
