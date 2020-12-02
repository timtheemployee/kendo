#include <GL/glew.h>
#include "data/TextureData.h"
#include <stdexcept>

class Texture {

private:
    GLuint _texture_id;

public:
    Texture(const TextureData &texture_data);

    auto bind() const -> void;
    auto unbind() const -> void;
};
