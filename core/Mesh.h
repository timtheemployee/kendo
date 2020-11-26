//TODO Include something crossplatform instead glfw?
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class Mesh
{
private:
    GLuint _vertexAttributeObject;
    int _verticesSize;

public:

   Mesh(const std::vector<float> &vertices);
   auto getAttributeObject() const -> GLuint;
   auto getVerticesSize() const -> int;
   auto clenUp() -> void;
};

