#version 150

in vec3 position;
in vec2 textureIn;

out vec2 textureOut;

void main()
{
    gl_Position = vec4(position, 1.f);
    textureOut = textureIn;
}
