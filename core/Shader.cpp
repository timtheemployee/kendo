#include "Shader.h"

Shader::Shader(const std::filesystem::path &path, const std::string &filename) : _loader{path}, _shaderId{0} {
    const auto vertexShaderSource = _loader.load_vertex_shader(filename);
    const auto fragmentShaderSource = _loader.load_fragment_shader(filename);

    auto vertexShader = compileShader(vertexShaderSource, GL_VERTEX_SHADER);
    auto fragmentShader = compileShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

    GL_CALL(_shaderId = glCreateProgram());
    GL_CALL(glAttachShader(_shaderId, vertexShader));
    GL_CALL(glAttachShader(_shaderId, fragmentShader));
    GL_CALL(glLinkProgram(_shaderId));
    GL_CALL(glValidateProgram(_shaderId));

    GL_CALL(glDeleteShader(vertexShader));
    GL_CALL(glDeleteShader(fragmentShader));
}

auto Shader::compileShader(const std::string &source, GLuint type) const -> GLuint {
    GL_CALL(auto shader = glCreateShader(type));
    auto *rawSource = source.c_str();
    GL_CALL(glShaderSource(shader, 1, &rawSource, nullptr));
    GL_CALL(glCompileShader(shader));

    int compileResult;
    GL_CALL(glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult));

    //TODO Make error messages more informative
    if (compileResult == GL_FALSE) {
        char infoLog[512];
        GL_CALL(glGetShaderInfoLog(shader, 512, nullptr, infoLog));
        throw std::invalid_argument(infoLog);
    }

    return shader;
}

Shader::~Shader() {
    GL_CALL(glDeleteProgram(_shaderId));
}

auto Shader::bind() const -> void {
    GL_CALL(glUseProgram(_shaderId));
}

auto Shader::unbind() const -> void {
    GL_CALL(glUseProgram(0));
}

auto Shader::setUniform4f(const std::string &name, float v0, float v1, float v2, float v3) const -> void {
    auto location = getUniformLocation(name);
    GL_CALL(glUniform4f(location, v0, v1, v2, v3));
}

auto Shader::setUniform1f(const std::string &name, float v0) const -> void {
    auto location = getUniformLocation(name);
    GL_CALL(glUniform1f(location, v0));
}

auto Shader::setUniform1i(const std::string &name, int v0) const -> void {
    auto location = getUniformLocation(name);
    GL_CALL(glUniform1i(location, v0));
}

auto Shader::setUniformMat4f(const std::string &name, const glm::mat4 &matrix) const -> void {
    auto location = getUniformLocation(name);
    GL_CALL(glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix)));
}

auto Shader::getUniformLocation(const std::string &name) const -> GLuint {
    if (_uniformCache.find(name) != _uniformCache.end()) return _uniformCache[name];

    GL_CALL(GLint location = glGetUniformLocation(_shaderId, name.c_str()));
    if (location == -1) {
        std::cout << "Warning: uniform with name " << name << " not found" << std::endl;
    }

    _uniformCache[name] = location;
    return location;
}
