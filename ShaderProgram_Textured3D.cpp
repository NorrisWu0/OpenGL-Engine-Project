#include "ShaderProgram_Textured3D.h"
#include "mesh.h"
#include "expectations.h"
#include "configuration.h"

ShaderProgram_Textured3D::ShaderProgram_Textured3D(const Shader* _vertexShader, const Shader* _fragmentShader)
	: ShaderProgram("ShaderProgram.3D.Textured", _vertexShader, _fragmentShader)
{
}
ShaderProgram_Textured3D::~ShaderProgram_Textured3D()
{
}

void ShaderProgram_Textured3D::Render(const Configuration* _config, const Mesh* _mesh, const Texture* _texture, const glm::mat4* _transformation) const
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

	GLint transformation_location = glGetUniformLocation(GetProgram(), "transformation");
	expect(transformation_location != -1, "Failed to find mask uniform location.");
	glUniformMatrix4fv(transformation_location, 1, GL_FALSE, &(*_transformation)[0][0]);

	GLuint tbo_index;
	glGenBuffers(1, &tbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, tbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _mesh->texture_coordinates().size(), _mesh->texture_coordinates().data(), GL_STATIC_DRAW);

	GLint vertex_texture_coordinate_location = glGetAttribLocation(GetProgram(), "vertexTextureCoordinate");
	expect(vertex_texture_coordinate_location != -1, "Failed to get vertexTextureCoordinate");
	glEnableVertexAttribArray(vertex_texture_coordinate_location);
	glVertexAttribPointer(vertex_texture_coordinate_location, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	GLuint texture_location;
	glGenTextures(1, &texture_location);

	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, texture_location);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _texture->width(), _texture->height(),
		0, GL_RGB, GL_UNSIGNED_BYTE, _texture->data());
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	GLint image_location = glGetUniformLocation(GetProgram(), "image");
	expect(image_location != -1, "Failed to find image uniform location.");
	glUniform1i(image_location, 0);

	if (_config->renderWireframe)
	{
		glDrawArrays(GL_LINE_LOOP, 0, GLsizei(_mesh->verticies().size() / 2));
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, GLsizei(_mesh->verticies().size() / 2));
	}


	glDeleteBuffers(1, &vbo_index);
	glDeleteTextures(1, &texture_location);
}
