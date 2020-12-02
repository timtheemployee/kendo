#include "Texture.h"
#include <iostream>

Texture::Texture(const TextureData &texture_data) {
    std::cout << "Initializing texture" << std::endl;
    glGenTextures(1, &_texture_id);
    glBindTexture(GL_TEXTURE_2D, _texture_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    std::cout << "Texture parameters initialized" << std::endl;

    if (texture_data.data) {
        std::cout << "Binding texture data" << std::endl;
        glTexImage2D(GL_TEXTURE_2D,
                     0,
                     GL_RGB,
                     texture_data.width,
                     texture_data.height,
                     0,
                     GL_RGB,
                     GL_UNSIGNED_BYTE,
                     texture_data.data);
        glGenerateMipmap(GL_TEXTURE_2D);
        std::cout << "Texture data generated, mipmap created" << std::endl;
    } else {
        std::invalid_argument("Error while getting data check TextureLoader");
    }

    texture_data.free();
    std::cout << "Free texture data" << std::endl;
    glBindTexture(GL_TEXTURE_2D, 0);
    std::cout << "Texture initialization complete" << std::endl;
}

auto Texture::bind() const -> void {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture_id);
}

auto Texture::unbind() const -> void {
    glBindTexture(GL_TEXTURE_2D, 0);
}
