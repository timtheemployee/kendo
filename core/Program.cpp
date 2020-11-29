#include "Program.h"

Program::Program(const std::filesystem::path &shaders_root, const std::string &name) : _loader{shaders_root} {
    _program = create(name);
}

auto Program::create(const std::string &shader) -> GLuint {
    const auto vertex = _loader.load_vertex_shader(shader);
    const auto fragment = _loader.load_fragment_shader(shader);

    _vertex_shader_id = this->shader(vertex, GL_VERTEX_SHADER);
    _fragment_shader_id = this->shader(fragment, GL_FRAGMENT_SHADER);

    GLuint _program = glCreateProgram();
    glAttachShader(_program, _vertex_shader_id);
    glAttachShader(_program, _fragment_shader_id);
    glLinkProgram(_program);

    int linkingStatus;
    glGetProgramiv(_program, GL_LINK_STATUS, &linkingStatus);

    if (linkingStatus == GL_FALSE) {
        clean_up();
        const auto message = "Error while linking program";
        throw std::invalid_argument(message);
    }

    return _program;
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

auto Program::bind_attribute(const GLuint &position, const std::string &attribute_name) -> void {
    glBindAttribLocation(_program, position, attribute_name.c_str());
}

auto Program::use() const -> void {
    glUseProgram(_program);
}

auto Program::dispose() const -> void {
    glUseProgram(0);
}

auto Program::clean_up() -> void {
    glDetachShader(_program, _vertex_shader_id);
    glDetachShader(_program, _fragment_shader_id);
    glDeleteShader(_vertex_shader_id);
    glDeleteShader(_fragment_shader_id);
    glDeleteProgram(_program);
}
