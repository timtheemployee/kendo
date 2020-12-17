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

public:
    Texture(const int width, const int height, unsigned char *data);
    ~Texture();

    auto bind(const int slot = 0) const -> void;
    auto unbind() const -> void;

    auto getWidth() const -> int;
    auto getHeight() const -> int;
};
