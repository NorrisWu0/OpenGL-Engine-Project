#include "Mesh_Octagon.h"

Mesh_Octagon::Mesh_Octagon() : Mesh("Mesh.Octagon")
{
	m_Verticies.insert(m_Verticies.end(), { -0.73f, 0.3f });
	m_Verticies.insert(m_Verticies.end(), { -0.3f, 0.73f });
	m_Verticies.insert(m_Verticies.end(), { 0.3f, 0.73f });

	m_Verticies.insert(m_Verticies.end(), { 0.3f, 0.73f });
	m_Verticies.insert(m_Verticies.end(), { 0.73f, 0.3f });
	m_Verticies.insert(m_Verticies.end(), { -0.73f, 0.3f });
	
	m_Verticies.insert(m_Verticies.end(), { -0.73f, 0.3f });
	m_Verticies.insert(m_Verticies.end(), { 0.73f, 0.3f });
	m_Verticies.insert(m_Verticies.end(), { 0.73f, -0.3f });

	m_Verticies.insert(m_Verticies.end(), { 0.73f, -0.3f });
	m_Verticies.insert(m_Verticies.end(), { -0.73f, 0.3f });
	m_Verticies.insert(m_Verticies.end(), { -0.73f, -0.3f });
	
	m_Verticies.insert(m_Verticies.end(), { -0.73f, -0.3f });
	m_Verticies.insert(m_Verticies.end(), { 0.73f, -0.3f });
	m_Verticies.insert(m_Verticies.end(), { 0.3f, -0.73f });
	
	m_Verticies.insert(m_Verticies.end(), { 0.3f, -0.73f });
	m_Verticies.insert(m_Verticies.end(), { -0.3f, -0.73f });
	m_Verticies.insert(m_Verticies.end(), { -0.73f, -0.3f });

	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { -0.73f, 0.3f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { -0.3f, 0.73f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.3f, 0.73f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.3f, 0.73f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.73f, 0.3f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { -0.73f, 0.3f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { -0.73f, 0.3f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.73f, 0.3f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.73f, -0.3f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.73f, -0.3f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { -0.73f, 0.3f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { -0.73f, -0.3f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { -0.73f, -0.3f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.73f, -0.3f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.3f, -0.73f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.3f, -0.73f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { -0.3f, -0.73f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { -0.73f, -0.3f });
}

Mesh_Octagon::~Mesh_Octagon()
{
}
