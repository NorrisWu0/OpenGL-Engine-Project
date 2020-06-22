#version 330 core

in vec2 interpolatedTextureCoordinate;
in vec3 normal;
in vec3 fragmentPosition;

uniform sampler2D image;
uniform vec3 ambientLight;
uniform vec3 lightPosition;
uniform vec3 lightColor;

out vec4 fragmentColor;


void main()
{
    vec4 _imageTextel = texture(image, interpolatedTextureCoordinate);
    
//    vec3 _normalizedNormal = normalize(normal);
//    vec3 _normalizedLightDirection = normalize(lightPosition - fragmentPosition);
//    float _lightMultiplier = max(dot(_normalizedNormal, _normalizedLightDirection), 0.0);
//
//    vec4 _ambientSource = vec4(_imageTextel.rbg * ambientLight, _imageTextel.a);
//    vec4 _directionalSource = (_imageTextel * vec4(lightColor.xyz * _lightMultiplier, 1.0));

    fragmentColor = _imageTextel;
}