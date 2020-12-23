#pragma once

#include <GL/glew.h>
#include "GlExtensions.h"
#include <stdexcept>
#include <stb_image.h>

class Texture {

private:
    GLuint _textureId;
    int _width;
    int _height;
    unsigned char *_data;
    const std::string &_uniformName;

public:
    Texture(const int width, const int height, unsigned char *data, const std::string &uniformName);

    ~Texture();

    //resources should not be copied
    Texture(const Texture &other) = delete;
    auto operator=(const Texture &other) -> Texture = delete;

    //but resources can be moved
    Texture(Texture &&other) noexcept;
    auto operator=(Texture &&other) noexcept -> Texture&;

    auto bind(const int slot = 0) const -> void;
    auto unbind() const -> void;

    auto getWidth() const -> int;
    auto getHeight() const -> int;

    auto getUniformName() const -> const std::string&;
};
