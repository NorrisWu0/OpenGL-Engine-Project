#include "ShaderProgram_Colored2D.h"
#include "mesh.h"
#include "expectations.h"
#include "configuration.h"

ShaderProgram_Colored2D::ShaderProgram_Colored2D(const Shader* vertex_shader, const Shader* fragment_shader)
	: ShaderProgram("ShaderProgram.2D.Colored", vertex_shader, fragment_shader)
{
}
ShaderProgram_Colored2D::~ShaderProgram_Colored2D()
{
}

void ShaderProgram_Colored2D::Render(const Configuration* config, const Mesh* mesh, const std::vector<GLfloat>* colors, const glm::mat4* Transformation) const
{
	glUseProgram(program());
	glBindVertexArray(vao());

	GLuint vbo_index;
	glGenBuffers(1, &vbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh->verticies().size(), mesh->verticies().data(), GL_STATIC_DRAW);

	GLint vertex_location = glGetAttribLocation(program(), "vertex_position");
	expect(vertex_location != -1, "Failed to get vertex_location");
	glEnableVertexAttribArray(vertex_location);
	glVertexAttribPointer(vertex_location, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	
	GLuint cbo_index;
	glGenBuffers(1, &cbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, cbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * colors->size(), colors->data(), GL_STATIC_DRAW);

	GLint color_location = glGetAttribLocation(program(), "vertex_color");
	expect(color_location != -1, "Failed to get color_location");
	glEnableVertexAttribArray(color_location);
	glVertexAttribPointer(color_location, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	
	GLuint transformation_location = glGetUniformLocation(program(), "transformation");
	expect(transformation_location != -1, "Failed to get transformation_location");
	glUniformMatrix4fv(transformation_location, 1, GL_FALSE, &(*Transformation)[0][0]);

	if(config->renderWireframe)
	{
		glDrawArrays(GL_LINE_LOOP, 0, GLsizei(mesh->verticies().size() / 2));
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, GLsizei(mesh->verticies().size() / 2));
	}


	glDeleteBuffers(1, &vbo_index);
	glDeleteBuffers(1, &cbo_index);
}