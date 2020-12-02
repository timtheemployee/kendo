//TODO Include something crossplatform instead glfw?
#include "data/VertexData.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class Mesh
{
private:
    GLuint _vertexAttributeObject = 0;
    int _verticesSize;

public:
   Mesh(const VertexData &vertex_data);
      //TODO snake case
   auto getAttributeObject() const -> GLuint;

   auto getVerticesSize() const -> int;
   //TODO snake case
   auto clenUp() -> void;
};

