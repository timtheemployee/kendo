#version 150

in vec2 textureOut;

out vec4 FragColor;

uniform sampler2D wallTexture;

void main()
{
    FragColor = texture(wallTexture, textureOut);
}
