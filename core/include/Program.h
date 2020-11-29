#include "ShaderLoader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

class Program {
private:
    ShaderLoader _loader;
    GLuint _program;
    GLuint _vertex_shader_id;
    GLuint _fragment_shader_id;

    auto create(const std::string &shader) -> GLuint;
    auto shader(const std::string &source, GLuint type) const -> GLuint;
    auto get_shader_type(const GLuint type) const -> std::string;

public:
    Program(const std::filesystem::path &shaders_root, const std::string &name);
    auto bind_attribute(const GLuint &position, const std::string &attribute_name) -> void;
    auto use() const -> void;
    auto dispose() const -> void;
    auto clean_up() -> void;
};
