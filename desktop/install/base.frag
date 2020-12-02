#version 150

in vec3 colour;
in vec2 textureOut;

out vec4 FragColor;

uniform sampler2D wallTexture;

void main()
{
    FragColor = texture(wallTexture, textureOut);
}
