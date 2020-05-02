#pragma once

#include "Mesh_Square.h"

Mesh_Square::Mesh_Square()
	: Mesh("Mesh.Square")
{
	m_Verticies.insert(m_Verticies.end(), {-0.5f, 0.5f});  // v1
	m_Verticies.insert(m_Verticies.end(), {-0.5f, -0.5f}); // v2
	m_Verticies.insert(m_Verticies.end(), {0.5f, -0.5f});  // v3
	m_Verticies.insert(m_Verticies.end(), {-0.5f, 0.5f});  // v1
	m_Verticies.insert(m_Verticies.end(), {0.5f, -0.5f});  // v3
	m_Verticies.insert(m_Verticies.end(), {0.5f, 0.5f});   // v4

	m_TextureCoordinates.insert(m_TextureCoordinates.end(), {0.0f, 1.0f});
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), {0.0f, 0.0f});
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), {1.0f, 0.0f});
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), {0.0f, 1.0f});
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), {1.0f, 0.0f});
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), {1.0f, 1.0f});
}
Mesh_Square::~Mesh_Square()
{
}