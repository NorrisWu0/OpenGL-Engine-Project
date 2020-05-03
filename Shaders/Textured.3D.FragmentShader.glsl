#version 330 core

in vec2 interpolatedTextureCoordinate;
uniform sampler2D image;

out vec4 fragmentColor;

void main()
{
    fragmentColor = interpolatedTextureCoordinate;
}