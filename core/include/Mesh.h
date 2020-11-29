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
   Mesh(const std::vector<float> &vertices, const std::vector<int> &indecies);
   //TODO snake case
   auto getAttributeObject() const -> GLuint;
   //TODO snake case
   auto getVerticesSize() const -> int;
   //TODO snake case
   auto clenUp() -> void;
   auto indecies_supported() const -> bool;
};

