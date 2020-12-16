#include "Texture.h"

Texture::Texture(const TextureData &texture_data) {
    GL_CALL(glGenTextures(1, &_texture_id));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, _texture_id));

    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

    if (texture_data.data) {
        GL_CALL(glTexImage2D(GL_TEXTURE_2D,
                     0,
                     GL_RGB,
                     texture_data.width,
                     texture_data.height,
                     0,
                     GL_RGB,
                     GL_UNSIGNED_BYTE,
                     texture_data.data));
        GL_CALL(glGenerateMipmap(GL_TEXTURE_2D));
    } else {
        std::invalid_argument("Error while getting data check TextureLoader");
    }

    texture_data.free();
    GL_CALL(glBindTexture(GL_TEXTURE_2D, 0));
}

auto Texture::bind() const -> void {
    GL_CALL(glActiveTexture(GL_TEXTURE0));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, _texture_id));
}

auto Texture::unbind() const -> void {
    GL_CALL(glBindTexture(GL_TEXTURE_2D, 0));
}
