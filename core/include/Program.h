#include "ShaderLoader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

class Program {
private:
    ShaderLoader _loader;
    GLuint _program;

    auto shader(const std::string &source, GLuint type) const -> GLuint;
    auto get_shader_type(const GLuint type) const -> std::string;

public:
    Program(const std::filesystem::path &shaders_root);
    auto create(const std::string &shader) -> void;
    auto use() -> void;
    auto clean_up() -> void;
};
