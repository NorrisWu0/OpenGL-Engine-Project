#include "Mesh_2D_Octagon.h"

Mesh_2D_Octagon::Mesh_2D_Octagon() : Mesh("Mesh.Octagon")
{
	auto _v1 = { -0.73f, 0.3f };
	auto _v2 = { -0.73f, -0.3f };
	auto _v3 = { -0.3f, -0.73f };
	auto _v4 = { 0.3f, -0.73f };
	auto _v5 = { 0.73f, -0.3f };
	auto _v6 = { 0.73f, 0.3f };
	auto _v7 = { 0.3f, 0.73f };
	auto _v8 = { -0.3f, 0.73f };

	auto _tc1 = { 0.0f, 0.279f };
	auto _tc2 = { 0.0f, 0.699f };
	auto _tc3 = { 0.3f, 1.0f };
	auto _tc4 = { 0.72f, 1.0f };
	auto _tc5 = { 1.00f, 0.699f };
	auto _tc6 = { 1.00f, 0.279f };
	auto _tc7 = { 0.72f, 0.0f };
	auto _tc8 = { 0.3f, 0.0f };

	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v3);
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v3);
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v8);

	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc1);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc2);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc3);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc1);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc3);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc4);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc1);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc4);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc5);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc1);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc5);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc6);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc1);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc6);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc7);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc1);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc7);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc8);
}

Mesh_2D_Octagon::~Mesh_2D_Octagon()
{
}
