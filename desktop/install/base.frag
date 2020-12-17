#version 150

in vec3 positionOut;
in vec2 texCoordinatesOut;

out vec4 FragColor;

uniform float time;
uniform sampler2D image;

void main()
{
    FragColor = texture(image, texCoordinatesOut) * vec4(positionOut.x, positionOut.y, 0.5f, 1.f) * sin(time);
}
