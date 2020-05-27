#include "ShaderProgram_Textured3D.h"


ShaderProgram_Textured3D::ShaderProgram_Textured3D(const Shader* _vertex, const Shader* _fragment)
	: ShaderProgram("ShaderProgram.3D.Textured", _vertex, _fragment)
{}

ShaderProgram_Textured3D::~ShaderProgram_Textured3D() {}

void ShaderProgram_Textured3D::Render(const Configuration* _config, const Mesh* _mesh, const Texture* _texture, const glm::mat4* _transformation) const
{
	glUseProgram(GetProgram());
	glBindVertexArray(GetVAO());

	#pragma region Vertex Buffer Object
	GLuint _vboIndex;
	glGenBuffers(1, &_vboIndex);
	glBindBuffer(GL_ARRAY_BUFFER, _vboIndex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _mesh->verticies().size(), _mesh->verticies().data(), GL_STATIC_DRAW);
	#pragma endregion

	#pragma region Vertex Position
	GLint _vertexPosition = glGetAttribLocation(GetProgram(), "vertexPosition");
	expect(_vertexPosition != -1, "Failed to get vertex position");
	glEnableVertexAttribArray(_vertexPosition);
	glVertexAttribPointer(_vertexPosition, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	#pragma endregion

	#pragma region Texture Buffer Object
	GLuint _tboIndex;
	glGenBuffers(1, &_tboIndex);
	glBindBuffer(GL_ARRAY_BUFFER, _tboIndex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _mesh->texture_coordinates().size(), _mesh->texture_coordinates().data(), GL_STATIC_DRAW);
	#pragma endregion

	#pragma region Texture Coordinate
	GLint _textureCoordPosition = glGetAttribLocation(GetProgram(), "vertexTextureCoordinate");
	expect(_textureCoordPosition != -1, "Failed to get texture coordinate position");
	glEnableVertexAttribArray(_textureCoordPosition);
	glVertexAttribPointer(_textureCoordPosition, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	#pragma endregion

	#pragma region Transformation
	GLint _transformLocation = glGetUniformLocation(GetProgram(), "transformation");
	expect(_transformLocation != -1, "Failed to find mask uniform location.");
	glUniformMatrix4fv(_transformLocation, 1, GL_FALSE, &(*_transformation)[0][0]);
	#pragma endregion

	#pragma region Texture Position
	GLuint _texturePosition;
	glGenTextures(1, &_texturePosition);

	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, _texturePosition);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _texture->width(), _texture->height(), 0, GL_RGB, GL_UNSIGNED_BYTE, _texture->data());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	#pragma endregion

	#pragma region Image Position
	GLint _imagePosition = glGetUniformLocation(GetProgram(), "image");
	expect(_imagePosition != -1, "Failed to find image uniform location.");
	glUniform1i(_imagePosition, 0);
	#pragma endregion

	if (_config->renderWireframe)
		glDrawArrays(GL_LINE_LOOP, 0, GLsizei(_mesh->verticies().size() / 2));
	else
		glDrawArrays(GL_TRIANGLES, 0, GLsizei(_mesh->verticies().size() / 2));


	glDeleteBuffers(1, &_vboIndex);
	glDeleteTextures(1, &_texturePosition);
}
