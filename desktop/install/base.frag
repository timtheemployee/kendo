#version 150

in vec3 positionOut;
in vec2 texCoordinatesOut;

out vec4 FragColor;

uniform float time;
uniform sampler2D image;
uniform sampler2D sampleImage;

void main()
{
    FragColor = mix(texture(image, texCoordinatesOut),
                    texture(sampleImage, texCoordinatesOut),
                    sin(time)) * vec4(positionOut + vec3(sin(time)), 1.f);
//    FragColor = texture(image, texCoordinatesOut);
}
