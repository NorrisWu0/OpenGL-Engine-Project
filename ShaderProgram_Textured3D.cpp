#include "ShaderProgram_Textured3D.h"


ShaderProgram_Textured3D::ShaderProgram_Textured3D(const Shader* _vertex, const Shader* _fragment)
	: ShaderProgram("ShaderProgram.3D.Textured", _vertex, _fragment)
{}

ShaderProgram_Textured3D::~ShaderProgram_Textured3D() {}

void ShaderProgram_Textured3D::Render(const Configuration* _config, const Mesh* _mesh, const Texture* _texture, const glm::mat4 _translation, const glm::mat4 _rotation, const glm::mat4 _scale, const glm::mat4 _camera, const glm::mat4 projection) const
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
	expect(_vertexPosition != -1, "Failed to get vertex position variable in shader");
	glEnableVertexAttribArray(_vertexPosition);
	glVertexAttribPointer(_vertexPosition, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	#pragma endregion

	#pragma region Normal Buffer Object
	GLuint _nboIndex;
	glGenBuffers(1, &_nboIndex);
	glBindBuffer(GL_ARRAY_BUFFER, _nboIndex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _mesh->normals().size(), _mesh->normals().data(), GL_STATIC_DRAW);
	#pragma endregion

	#pragma region Vertex Normal
	GLint _vertexNormalValue = glGetAttribLocation(GetProgram(), "vertexNormal");
	expect(_vertexNormalValue != -1, "Failed to get vertex normal value.");
	glEnableVertexAttribArray(_vertexNormalValue);
	glVertexAttribPointer(_vertexNormalValue, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	#pragma endregion

	#pragma region Translation
	GLint _translatedValue = glGetUniformLocation(GetProgram(), "translation");
	expect(_translatedValue != -1, "Failed to find translation variable in shader");
	glUniformMatrix4fv(_translatedValue, 1, GL_FALSE, &(_translation)[0][0]);
	#pragma endregion

	#pragma region Rotation
	GLint _rotationValue = glGetUniformLocation(GetProgram(), "rotation");
	expect(_rotationValue != -1, "Failed to find rotation variable in shader");
	glUniformMatrix4fv(_rotationValue, 1, GL_FALSE, &(_rotation)[0][0]);
	#pragma endregion

	#pragma region Scale
	GLint _scaleValue = glGetUniformLocation(GetProgram(), "scale");
	expect(_scaleValue != -1, "Failed to find scale variable in shader");
	glUniformMatrix4fv(_scaleValue, 1, GL_FALSE, &(_scale)[0][0]);
	#pragma endregion

	#pragma region Camera
	GLint _cameraValue = glGetUniformLocation(GetProgram(), "camera");
	expect(_cameraValue != -1, "Failed to find camera variable in shader");
	glUniformMatrix4fv(_cameraValue, 1, GL_FALSE, &(_camera)[0][0]);
	#pragma endregion

	#pragma region Projection
	GLint _projectionValue = glGetUniformLocation(GetProgram(), "projection");
	expect(_projectionValue != -1, "Failed to find projection variable in shader");
	glUniformMatrix4fv(_projectionValue, 1, GL_FALSE, &(projection)[0][0]);
	#pragma endregion

	#pragma region Ambient Light
	GLint _ambientLightValue = glGetUniformLocation(GetProgram(), "ambientLight");
	expect(_ambientLightValue != -1, "Failed to find ambientLight variable in shader");
	const glm::vec3 _ambientLightColor(.1f, 0.1f, 0.1f);
	glUniform3fv(_ambientLightValue, 1, (float*)(&_ambientLightColor));
	#pragma endregion

	#pragma region Light Position
	const glm::vec3 _lightPosition(0.0, 23.0, 0.0);
	GLint _lightPositionValue = glGetUniformLocation(GetProgram(), "lightPosition");
	expect(_lightPositionValue != -1, "Failed to find light position variable in shader.");
	glUniform3fv(_lightPositionValue, 1, (float*)(&_lightPosition));
	#pragma endregion

	#pragma region Light Color
	const glm::vec3 _lightColor(0.8, 0.8, 0.8);
	GLint _lightColorValue = glGetUniformLocation(GetProgram(), "lightColor");
	expect(_lightColorValue != -1, "Failed to find light position value.");
	glUniform3fv(_lightColorValue, 1, (float*)(&_lightColor));
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

	#pragma region Texture
	GLuint _textureValue;
	glGenTextures(1, &_textureValue);

	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, _textureValue);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _texture->width(), _texture->height(), 0, GL_RGB, GL_UNSIGNED_BYTE, _texture->data());
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	#pragma endregion

	#pragma region Image
	GLint _imageValue = glGetUniformLocation(GetProgram(), "image");
	expect(_imageValue != -1, "Failed to find image value.");
	glUniform1i(_imageValue, 0);
	#pragma endregion

	if (_config->RenderWireframe)
		glDrawArrays(GL_LINE_LOOP, 0, GLsizei(_mesh->verticies().size() / 2));
	else
		glDrawArrays(GL_TRIANGLES, 0, GLsizei(_mesh->verticies().size() / 2));


	glDeleteBuffers(1, &_vboIndex);
	glDeleteTextures(1, &_textureValue);
}
