#include <filesystem>
#include <stdexcept>
#include "Texture.h"

class TextureLoader {

public:
    TextureLoader();
    auto get_texture(const std::filesystem::path &path) const -> Texture;
};
