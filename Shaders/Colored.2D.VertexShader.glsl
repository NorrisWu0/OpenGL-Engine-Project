#version 330 core

in vec2 vertexPosition;
in vec4 vertexColor;

uniform mat4 transformation;

out vec4 interpolatedColor;

void main()
{
    vec4 _transformedPosition = transformation * vec4(vertexPosition.xy, 1.0, 1.0);

    gl_Position        = _transformedPosition;
    interpolatedColor = vertexColor;
}