#version 330 core

in vec3 positionIn;
in vec2 texCoordinatesIn;

out vec3 positionOut;
out vec2 texCoordinatesOut;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(positionIn, 1.f);
    positionOut = positionIn;
    texCoordinatesOut = texCoordinatesIn;
}
