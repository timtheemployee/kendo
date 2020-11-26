#include "Mesh.h"

class Renderer
{
private:
    std::vector<Mesh> _meshes;

public:
    Renderer();
    auto prepare() -> void;
    auto render(const Mesh &mesh) -> void;
    auto clenUp() -> void;
};
