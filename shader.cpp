#include "Shader.h"

Shader::Shader(const char* _id, const char* _filePath, const Type type)
	: Asset(_id)
{
	std::ifstream _file(_filePath);
	expect(_file.is_open(), (std::string("Failed to open file. File: ") + _filePath).c_str());
	std::string _source = std::string((std::istreambuf_iterator<char>(_file)), std::istreambuf_iterator<char>());
	const char* _sourceCStr = _source.c_str();

	switch (type)
	{
		case Type::Vertex:
		{
			_data = glCreateShader(GL_VERTEX_SHADER);
			break;
		}
		case Type::Fragment:
		{
			_data = glCreateShader(GL_FRAGMENT_SHADER);
			break;
		}
		default:
			throw std::runtime_error("Unknown shader type provided.");
	}

	glShaderSource(_data, 1, &_sourceCStr, NULL);
	glCompileShader(_data);

	GLint _shaderCompileResult;
	glGetShaderiv(_data, GL_COMPILE_STATUS, &_shaderCompileResult);
	if (_shaderCompileResult == GL_FALSE)
	{
		GLchar _log[1024];
		glGetShaderInfoLog(_data, sizeof(_log), NULL, _log);
		throw std::runtime_error(_log);
	}
}

Shader::~Shader() {}
const GLuint Shader::data() const { return _data; }