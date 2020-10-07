#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


Texture::Texture(const char* _id, const char* _filePath, bool _flipVertical)
	: Asset(_id)
{
	stbi_set_flip_vertically_on_load(_flipVertical);
	_data = stbi_load(_filePath, &_width, &_height, &_components, STBI_rgb);
}

Texture::~Texture()
{
	delete _data;
}

const unsigned char* Texture::data() const
{
	return _data;
}

const int Texture::width() const
{
	return _width;
}
const int Texture::height() const
{
	return _height;
}
const int Texture::components() const
{
	return _components;
}