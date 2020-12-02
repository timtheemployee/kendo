#include <stb_image.h>

struct TextureData {
    int width;
    int height;
    unsigned char *data;

    auto free() const -> void;
};
