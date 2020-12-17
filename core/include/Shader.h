#pragma once

#include <string>
#include <filesystem>
#include <GL/glew.h>
#include <stdexcept>
#include <iostream>
#include <unordered_map>
#include "ShaderLoader.h"
#include "GlExtensions.h"

class Shader {
private:
    ShaderLoader _loader;
    GLuint _shaderId;
    mutable std::unordered_map<std::string, GLint> _uniformCache;

    auto getUniformLocation(const std::string &name) const -> GLuint;
    auto compileShader(const std::string &source, GLuint type) const -> GLuint;

public:
    Shader(const std::filesystem::path &path, const std::string &fileName);
    ~Shader();

    auto bind() const -> void;
    auto unbind() const -> void;

    auto setUniform4f(const std::string &name, float v0, float v1, float v2, float v3) const -> void;
    auto setUniform1f(const std::string &name, float v0) const -> void;
    auto setUniform1i(const std::string &name, int v0) const -> void;
};
