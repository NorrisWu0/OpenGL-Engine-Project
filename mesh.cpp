#pragma once

#include "mesh.h"

Mesh::Mesh(const char* id)
	: Asset(id)
{
}
Mesh::~Mesh()
{
}

const std::vector<GLfloat> Mesh::verticies() const
{
	return m_Verticies;
}

const std::vector<GLfloat> Mesh::texture_coordinates() const
{
	return m_TextureCoordinates;
}

const std::vector<GLfloat> Mesh::indicies() const
{
	return m_Indicies;
}

const std::vector<GLfloat> Mesh::normals() const
{
	return m_Normals;
}