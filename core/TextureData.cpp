#include "data/TextureData.h"

auto TextureData::free() const -> void {
    stbi_image_free(data);
}
