#include "Mesh_3D_Quad.h"


Mesh_3D_Quad::Mesh_3D_Quad() : Mesh("Mesh.Quad")
{
	auto _v1 = { -0.5f, 0.0f, 0.5f };
	auto _v4 = { 0.5f, 0.0f, 0.5f };
	auto _v5 = { -0.5f, 0.0f, -0.5f };
	auto _v8 = { 0.5f, 0.0f, -0.5f };

	auto _top = { 0.0f, 1.0f, 0.0f };

		auto tl = { 0.0f, 0.0f };
		auto tr = { 1.0f, 0.0f };
		auto br = { 1.0f, 1.0f };
		auto bl = { 0.0f, 1.0f };

	#pragma region Top
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v8);

	m_TextureCoordinates.insert(m_TextureCoordinates.end(), tl);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), bl);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), br);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), tl);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), br);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), tr);

	m_Normals.insert(m_Normals.end(), _top);
	m_Normals.insert(m_Normals.end(), _top);
	m_Normals.insert(m_Normals.end(), _top);
	m_Normals.insert(m_Normals.end(), _top);
	m_Normals.insert(m_Normals.end(), _top);
	m_Normals.insert(m_Normals.end(), _top);
	#pragma endregion
}

Mesh_3D_Quad::~Mesh_3D_Quad() {}