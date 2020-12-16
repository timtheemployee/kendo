#pragma once

#include <GL/glew.h>
#include <iostream>

#define GL_ASSERT(x) if (!(x)) \
    std::cout << "FILE: " << __FILE__ << " LINE:" << __LINE__ << std::endl;

#define GL_CALL(x) glClearError();\
    x;\
    GL_ASSERT(glLogCall())

static auto glClearError() -> void {
    while(glGetError() != GL_NO_ERROR);
}

static auto glLogCall() -> bool {
    while(GLenum error = glGetError()) {
        std::cout << "[OpenGL Error]: " << error << std::endl;
        return false;
    }

    return true;
}
