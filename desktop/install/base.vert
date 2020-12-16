#version 330 core

in vec3 positionIn;
out vec3 positionOut;

void main()
{
    gl_Position = vec4(positionIn, 1.f);
    positionOut = positionIn;
}
