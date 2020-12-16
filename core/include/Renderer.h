#include "Mesh.h"
#include "Program.h"
#include "GlExtensions.h"

class Renderer
{
public:
    Renderer();
    auto prepare() -> void;
    auto use(const Program &program) -> void;
    auto render(const Mesh &mesh) -> void;
    auto dismiss(const Program &program) -> void;
};
