#include "ShaderProgram_Colored3D.h"
#include "mesh.h"
#include "expectations.h"
#include "configuration.h"

ShaderProgram_Colored3D::ShaderProgram_Colored3D(const Shader* _vertexShader, const Shader* _fragmentShader)
	: ShaderProgram("ShaderProgram.3D.Colored", _vertexShader, _fragmentShader)
{
}
ShaderProgram_Colored3D::~ShaderProgram_Colored3D()
{
}

void ShaderProgram_Colored3D::Render(const Configuration* _config, const Mesh* _mesh, const std::vector<GLfloat>* _colors, const glm::mat4* _transformation) const
{
	glUseProgram(GetProgram());
	glBindVertexArray(GetVAO());

	GLuint vbo_index;
	glGenBuffers(1, &vbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _mesh->verticies().size(), _mesh->verticies().data(), GL_STATIC_DRAW);

	GLint vertex_location = glGetAttribLocation(GetProgram(), "vertexPosition");
	expect(vertex_location != -1, "Failed to get vertexPosition");
	glEnableVertexAttribArray(vertex_location);
	glVertexAttribPointer(vertex_location, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	GLuint cbo_index;
	glGenBuffers(1, &cbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, cbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _colors->size(), _colors->data(), GL_STATIC_DRAW);

	GLint color_location = glGetAttribLocation(GetProgram(), "vertexColor");
	expect(color_location != -1, "Failed to get colorPosition");
	glEnableVertexAttribArray(color_location);
	glVertexAttribPointer(color_location, 4, GL_FLOAT, GL_FALSE, 0, NULL);

	GLuint transformation_location = glGetUniformLocation(GetProgram(), "transformation");
	expect(transformation_location != -1, "Failed to get transformation_location");
	glUniformMatrix4fv(transformation_location, 1, GL_FALSE, &(*_transformation)[0][0]);

	if (_config->renderWireframe)
	{
		glDrawArrays(GL_LINE_LOOP, 0, GLsizei(_mesh->verticies().size() / 2));
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, GLsizei(_mesh->verticies().size() / 2));
	}


	glDeleteBuffers(1, &vbo_index);
	glDeleteBuffers(1, &cbo_index);
}