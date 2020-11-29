#version 150

in vec3 colour;

out vec4 FragColor;

void main()
{
    FragColor = vec4(colour, .0f);
}
