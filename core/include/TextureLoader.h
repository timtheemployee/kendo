#include <filesystem>
#include <stdexcept>
#include "Texture.h"

class TextureLoader {
private:
public:
    TextureLoader();
    auto getTexture(const std::filesystem::path &path, const std::string &uniformName) const -> Texture;
};
