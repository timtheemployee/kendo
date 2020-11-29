#include "Program.h"

Program::Program(const std::filesystem::path &shaders_root) : _loader{shaders_root}, _program{0} {
}

auto Program::create(const std::string &shader) -> void {
    const auto vertex = _loader.load_vertex_shader(shader);
    const auto fragment = _loader.load_fragment_shader(shader);

    const auto vertex_shader_id = this->shader(vertex, GL_VERTEX_SHADER);
    const auto fragment_shader_id = this->shader(fragment, GL_FRAGMENT_SHADER);

    _program = glCreateProgram();
    glAttachShader(_program, vertex_shader_id);
    glAttachShader(_program, fragment_shader_id);
    glLinkProgram(_program);

    int linkingStatus;
    glGetProgramiv(_program, GL_LINK_STATUS, &linkingStatus);

    if (linkingStatus == GL_FALSE) {
        glDeleteShader(vertex_shader_id);
        glDeleteShader(fragment_shader_id);
        glDeleteProgram(_program);
        const auto message = "Error while linking program";
        throw std::invalid_argument(message);
    }

    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);
}

auto Program::shader(const std::string &source, GLuint type) const -> GLuint {
    const auto shader = glCreateShader(type);
    const auto *raw = source.c_str();
    glShaderSource(shader, 1, &raw, nullptr);
    glCompileShader(shader);

    int compileResult;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

    if (compileResult == GL_FALSE) {
        const auto message = "Error while compiling " + get_shader_type(type) + " ";

        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        throw std::invalid_argument(message + infoLog);
    }

    return shader;
}

auto Program::get_shader_type(const GLuint type) const -> std::string {
    if (type == GL_FRAGMENT_SHADER) return "fragment shader";
    if (type == GL_VERTEX_SHADER) return "vertex shader";

    throw std::invalid_argument("Illegal shader type");
}

auto Program::use() -> void {
    glUseProgram(_program);
}

auto Program::clean_up() -> void {
    glDeleteProgram(_program);
}
