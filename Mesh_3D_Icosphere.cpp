#include "Mesh_3D_Icosphere.h"

Mesh_3D_Icosphere::Mesh_3D_Icosphere() : Mesh("Mesh.Icosphere")
{
	/*auto _v0 = { 0.0f, -0.525731f, 0.850651f };
	auto _v1 = { 0.850651f, 0.0f, 0.525731f };
	auto _v2 = { 0.850651f, 0.0f, -0.525731f };
	auto _v3 = { -0.850651f, 0.0f, -0.525731f };
	auto _v4 = { -0.850651f, 0.0f, 0.525731f };
	auto _v5 = { -0.525731f, 0.850651f, 0.0f };
	auto _v6 = { 0.525731f, 0.850651f, 0.0f };
	auto _v7 = { 0.525731f, -0.850651f, 0.0f };
	auto _v8 = { -0.525731f, -0.850651f, 0.0f };
	auto _v9 = { 0.0f, -0.525731f, -0.850651f };
	auto _v10 = { 0.0f, 0.525731f, -0.850651f };
	auto _v11 = { 0.0f, 0.525731f, 0.850651f };

	auto _width = 1.0f / 20.0f;
	for (int _faceIndex = 0; _faceIndex < 20; ++_faceIndex)
	{
		auto tl = { _faceIndex * _width, 0.0f };
		auto tr = { (_faceIndex * _width) + _width, 0.0f };
		auto br = { (_faceIndex * _width) + _width, 1.0f };
		auto bl = { _faceIndex * _width, 1.0f };

		m_TextureCoordinates.insert(m_TextureCoordinates.end(), tl);
		m_TextureCoordinates.insert(m_TextureCoordinates.end(), bl);
		m_TextureCoordinates.insert(m_TextureCoordinates.end(), br);
		m_TextureCoordinates.insert(m_TextureCoordinates.end(), tl);
		m_TextureCoordinates.insert(m_TextureCoordinates.end(), br);
		m_TextureCoordinates.insert(m_TextureCoordinates.end(), tr);
	}

	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v6);

	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v2);

	m_Verticies.insert(m_Verticies.end(), _v3);
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v5);

	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v3);
	m_Verticies.insert(m_Verticies.end(), _v8);

	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v11);

	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v10);

	m_Verticies.insert(m_Verticies.end(), _v9);
	m_Verticies.insert(m_Verticies.end(), _v10);
	m_Verticies.insert(m_Verticies.end(), _v2);

	m_Verticies.insert(m_Verticies.end(), _v10);
	m_Verticies.insert(m_Verticies.end(), _v9);
	m_Verticies.insert(m_Verticies.end(), _v3);

	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v8);
	m_Verticies.insert(m_Verticies.end(), _v9);

	m_Verticies.insert(m_Verticies.end(), _v8);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v0);

	m_Verticies.insert(m_Verticies.end(), _v11);
	m_Verticies.insert(m_Verticies.end(), _v0);
	m_Verticies.insert(m_Verticies.end(), _v1);

	m_Verticies.insert(m_Verticies.end(), _v0);
	m_Verticies.insert(m_Verticies.end(), _v11);
	m_Verticies.insert(m_Verticies.end(), _v4);

	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v10);

	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v11);

	m_Verticies.insert(m_Verticies.end(), _v3);
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v10);

	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v11);

	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v9);

	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v0);

	m_Verticies.insert(m_Verticies.end(), _v3);
	m_Verticies.insert(m_Verticies.end(), _v9);
	m_Verticies.insert(m_Verticies.end(), _v8);

	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v8);
	m_Verticies.insert(m_Verticies.end(), _v0);*/
}

Mesh_3D_Icosphere::~Mesh_3D_Icosphere()
{
}