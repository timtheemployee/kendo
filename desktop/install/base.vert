#version 330 core

in vec3 positionIn;
in vec2 texCoordinatesIn;

out vec3 positionOut;
out vec2 texCoordinatesOut;

uniform mat4 transformationMatrix;

void main()
{
    gl_Position = transformationMatrix * vec4(positionIn, 1.f);
    positionOut = positionIn;
    texCoordinatesOut = texCoordinatesIn;
}
