#include "TextureLoader.h"

TextureLoader::TextureLoader() {
    stbi_set_flip_vertically_on_load(true);
}

auto TextureLoader::get_texture(const std::filesystem::path &name) const -> Texture {
    if (!std::filesystem::exists(name)) {
        throw std::invalid_argument("File with name not exists");
    }

    int width, height, color_channels;
    auto *data = stbi_load(name.string().c_str(), &width, &height, &color_channels, 4);
    auto texture_data = TextureData{width, height, data};

    return Texture{texture_data};
}
