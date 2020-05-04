#pragma once

#include "Mesh_2D_SemiOctagon.h"

Mesh_2D_SemiOctagon::Mesh_2D_SemiOctagon() : Mesh("Mesh.Bunker")
{
	m_Verticies.insert(m_Verticies.end(), { -0.73f, 0.0f });
	m_Verticies.insert(m_Verticies.end(), { -0.73f, 0.3f });
	m_Verticies.insert(m_Verticies.end(), { 0.0f, 0.0f });  

	m_Verticies.insert(m_Verticies.end(), { -0.73f, 0.3f });
	m_Verticies.insert(m_Verticies.end(), { -0.3f, 0.73f });
	m_Verticies.insert(m_Verticies.end(), { 0.0f, 0.0f });  

	m_Verticies.insert(m_Verticies.end(), { -0.3f, 0.73f });
	m_Verticies.insert(m_Verticies.end(), { 0.3f, 0.73f });
	m_Verticies.insert(m_Verticies.end(), { 0.0f, 0.0f });  

	m_Verticies.insert(m_Verticies.end(), { 0.3f, 0.73f });
	m_Verticies.insert(m_Verticies.end(), { 0.73f, 0.3f });
	m_Verticies.insert(m_Verticies.end(), { 0.0f, 0.0f });  

	m_Verticies.insert(m_Verticies.end(), { 0.73f, 0.3f });
	m_Verticies.insert(m_Verticies.end(), { 0.73f, 0.0f });
	m_Verticies.insert(m_Verticies.end(), { 0.0f, 0.0f });  


	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.0f, 0.0f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.0f, 0.2054f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.5f, 0.0f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.0f, 0.2054f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.5f, 0.0f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.2945f, 0.5f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.2945f, 0.5f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.5f, 0.0f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.2945f, 0.5f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.2945f, 0.5f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.5f, 0.0f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 1.0f, 0.2054f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 1.0f, 0.2054f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 0.5f, 0.0f });
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), { 1.0f, 0.0f });

}

Mesh_2D_SemiOctagon::~Mesh_2D_SemiOctagon()
{
}
