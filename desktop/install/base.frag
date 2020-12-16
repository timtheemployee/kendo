#version 150

in vec3 positionOut;

out vec4 FragColor;
uniform float time;

void main()
{
    FragColor = vec4(positionOut.x * sin(time), positionOut.y, positionOut.z, 1.f) * sin(time);
}
