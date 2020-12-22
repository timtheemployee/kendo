#include "Texture.h"

Texture::Texture(const int width,
                 const int height,
                 unsigned char *data,
                 const std::string &uniformName): _width{width}, _height{height}, _data{data}, _uniformName{uniformName} {

    GL_CALL(glGenTextures(1, &_textureId));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, _textureId));

    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    GL_CALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _data));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, 0));

    if (_data != nullptr) {
        stbi_image_free(_data);
    }
}

Texture::~Texture() {
    GL_CALL(glDeleteTextures(1, &_textureId));
}

auto Texture::bind(const int slot) const -> void {
    GL_CALL(glActiveTexture(GL_TEXTURE0 + slot));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, _textureId));
}

auto Texture::unbind() const -> void {
    GL_CALL(glBindTexture(GL_TEXTURE_2D, 0));
}

auto Texture::getWidth() const -> int {
    return _width;
}

auto Texture::getHeight() const -> int {
    return _height;
}

auto Texture::getUniformName() const -> const std::string& {
    return _uniformName;
}
