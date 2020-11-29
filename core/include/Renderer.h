#include "Mesh.h"
#include "Program.h"

class Renderer
{
private:
    Program _program;

public:
    Renderer(const std::string &shaders_root);
    auto attach_shader(const std::string &name) -> void;
    auto prepare() -> void;
    auto render(const Mesh &mesh) -> void;
    auto clean_up() -> void;
};
