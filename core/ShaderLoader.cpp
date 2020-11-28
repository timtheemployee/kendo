#include "ShaderLoader.h"
#include <fstream>
#include <sstream>

ShaderLoader::ShaderLoader(const std::filesystem::path &root_path): _root_path{root_path}{}

auto ShaderLoader::load_vertex_shader(const std::string &name) const -> std::string
{
    return load_shader(_root_path / std::filesystem::path{name + ".vert"});
}

auto ShaderLoader::load_fragment_shader(const std::string &name) const -> std::string
{
    return load_shader(_root_path / std::filesystem::path{name + ".frag"});
}

auto ShaderLoader::load_shader(const std::filesystem::path &name) const -> std::string
{

    std::ifstream file{name};

    if (!file.is_open())
    {
        auto message = "File with name " + name.string() + " not exists";
        throw std::invalid_argument(message);
    }

    std::stringstream content;
    content << file.rdbuf();

    return content.str();
}
