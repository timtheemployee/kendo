#version 330 core

in vec3 positionIn;
in vec2 texCoordinatesIn;

out vec3 positionOut;
out vec2 texCoordinatesOut;

void main()
{
    gl_Position = vec4(positionIn, 1.f);
    positionOut = positionIn;
    texCoordinatesOut = texCoordinatesIn;
}
