#version 330 core

in vec3 positionIn;
in vec2 texCoordinatesIn;

out vec3 positionOut;
out vec2 texCoordinatesOut;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;

void main()
{
    gl_Position = projectionMatrix * transformationMatrix * vec4(positionIn, 1.f);
    positionOut = positionIn;
    texCoordinatesOut = texCoordinatesIn;
}
