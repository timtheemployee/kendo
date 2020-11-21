#include <string>
#include <filesystem>

namespace desktop {

class ShaderLoader
{

private:
    const std::filesystem::path _root_path;

    auto load_shader(const std::filesystem::path &name) const -> std::string;

public:
    ShaderLoader(const std::filesystem::path &root_path);
    auto load_fragment_shader(const std::string &name) const -> std::string;
    auto load_vertex_shader(const std::string &name) const -> std::string;
};

}
