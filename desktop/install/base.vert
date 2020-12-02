#version 150

in vec3 position;
in vec2 textureIn;

out vec3 colour;
out vec2 textureOut;

void main()
{
    gl_Position = vec4(position, 1.f);
    colour = vec3(position.x + .5f, 1.f, position.y + .5f);
    textureOut = textureIn;
}
