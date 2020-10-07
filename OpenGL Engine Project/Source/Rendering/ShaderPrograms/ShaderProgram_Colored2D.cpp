#include "ShaderProgram_Colored2D.h"


ShaderProgram_Colored2D::ShaderProgram_Colored2D(const Shader* _vertex, const Shader* _fragment)
	: ShaderProgram("ShaderProgram.2D.Colored", _vertex, _fragment) {}

ShaderProgram_Colored2D::~ShaderProgram_Colored2D() {}

void ShaderProgram_Colored2D::Render(const Configuration* _config, const Mesh* _mesh, const std::vector<GLfloat>* _colors, const glm::mat4* _transformation) const
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
	GLint _verterPosition = glGetAttribLocation(GetProgram(), "vertexPosition");
	expect(_verterPosition != -1, "Failed to get vertex position");
	glEnableVertexAttribArray(_verterPosition);
	glVertexAttribPointer(_verterPosition, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	#pragma endregion

	#pragma region Color Buffer Object
	GLuint _cboIndex;
	glGenBuffers(1, &_cboIndex);
	glBindBuffer(GL_ARRAY_BUFFER, _cboIndex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _colors->size(), _colors->data(), GL_STATIC_DRAW);
	#pragma endregion

	#pragma region Color Position
	GLint _colorPosition = glGetAttribLocation(GetProgram(), "vertexColor");
	expect(_colorPosition != -1, "Failed to get color position");
	glEnableVertexAttribArray(_colorPosition);
	glVertexAttribPointer(_colorPosition, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	#pragma endregion
	
	#pragma region Transformation
	GLuint _transformLocation = glGetUniformLocation(GetProgram(), "transformation");
	expect(_transformLocation != -1, "Failed to get transform location");
	glUniformMatrix4fv(_transformLocation, 1, GL_FALSE, &(*_transformation)[0][0]);
	#pragma endregion

	if(_config->RenderWireframe)
		glDrawArrays(GL_LINE_LOOP, 0, GLsizei(_mesh->verticies().size() / 2));
	else
		glDrawArrays(GL_TRIANGLES, 0, GLsizei(_mesh->verticies().size() / 2));

	glDeleteBuffers(1, &_vboIndex);
	glDeleteBuffers(1, &_cboIndex);
}