#include "TextureLoader.h"

TextureLoader::TextureLoader() {
    stbi_set_flip_vertically_on_load(true);
}

auto TextureLoader::getTexture(const std::filesystem::path &name, const std::string &uniformName) const -> std::shared_ptr<Texture> {
    if (!std::filesystem::exists(name)) {
        throw std::invalid_argument("File with name not exists");
    }

    int width, height, color_channels;
    auto *data = stbi_load(name.string().c_str(), &width, &height, &color_channels, 4);
    return std::make_shared<Texture>(Texture{width, height, data, uniformName});
}
