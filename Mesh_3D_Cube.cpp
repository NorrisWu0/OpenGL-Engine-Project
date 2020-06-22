#include "Mesh_3D_Cube.h"

Mesh_3D_Cube::Mesh_3D_Cube() : Mesh("Mesh.Cube")
{
	auto _v1 = { -0.5f, 0.5f, 0.5f };
	auto _v2 = { -0.5f, -0.5f, 0.5f };
	auto _v3 = { 0.5f, -0.5f, 0.5f };
	auto _v4 = { 0.5f, 0.5f, 0.5f };

	auto _v5 = { -0.5f, 0.5f, -0.5f };
	auto _v6 = { -0.5f, -0.5f, -0.5f };
	auto _v7 = { 0.5f, -0.5f, -0.5f };
	auto _v8 = { 0.5f, 0.5f, -0.5f };

	auto _front = { 0.0f, 0.0f, 1.0f };
	auto _back = { 0.0f, 0.0f, -1.0f };
	auto _left = { -1.0f, 0.0f, 0.0f };
	auto _right = { 1.0f, 0.0f, 0.0f };
	auto _top = { 0.0f, 1.0f, 0.0f };
	auto _bottom = { 0.0f, -1.0f, 0.0f };

	auto _width = 1.0f / 1.0f;
	for (int _faceIndex = 0; _faceIndex < 6; ++_faceIndex)
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

	#pragma region Front
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v3);
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v3);
	m_Verticies.insert(m_Verticies.end(), _v4);

	m_Normals.insert(m_Normals.end(), _front);
	m_Normals.insert(m_Normals.end(), _front);
	m_Normals.insert(m_Normals.end(), _front);
	m_Normals.insert(m_Normals.end(), _front);
	m_Normals.insert(m_Normals.end(), _front);
	m_Normals.insert(m_Normals.end(), _front);
	#pragma endregion

	#pragma region Right
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v3);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v8);

	m_Normals.insert(m_Normals.end(), _right);
	m_Normals.insert(m_Normals.end(), _right);
	m_Normals.insert(m_Normals.end(), _right);
	m_Normals.insert(m_Normals.end(), _right);
	m_Normals.insert(m_Normals.end(), _right);
	m_Normals.insert(m_Normals.end(), _right);

	#pragma endregion

	#pragma region Back
	m_Verticies.insert(m_Verticies.end(), _v8);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v8);
	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v5);

	m_Normals.insert(m_Normals.end(), _back);
	m_Normals.insert(m_Normals.end(), _back);
	m_Normals.insert(m_Normals.end(), _back);
	m_Normals.insert(m_Normals.end(), _back);
	m_Normals.insert(m_Normals.end(), _back);
	m_Normals.insert(m_Normals.end(), _back);

	#pragma endregion

	#pragma region Left
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v1);

	m_Normals.insert(m_Normals.end(), _left);
	m_Normals.insert(m_Normals.end(), _left);
	m_Normals.insert(m_Normals.end(), _left);
	m_Normals.insert(m_Normals.end(), _left);
	m_Normals.insert(m_Normals.end(), _left);
	m_Normals.insert(m_Normals.end(), _left);

	#pragma endregion

	#pragma region Top
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v8);

	m_Normals.insert(m_Normals.end(), _top);
	m_Normals.insert(m_Normals.end(), _top);
	m_Normals.insert(m_Normals.end(), _top);
	m_Normals.insert(m_Normals.end(), _top);
	m_Normals.insert(m_Normals.end(), _top);
	m_Normals.insert(m_Normals.end(), _top);

	#pragma endregion

	#pragma region Bottom
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v3);

	m_Normals.insert(m_Normals.end(), _bottom);
	m_Normals.insert(m_Normals.end(), _bottom);
	m_Normals.insert(m_Normals.end(), _bottom);
	m_Normals.insert(m_Normals.end(), _bottom);
	m_Normals.insert(m_Normals.end(), _bottom);
	m_Normals.insert(m_Normals.end(), _bottom);

	#pragma endregion

}

Mesh_3D_Cube::~Mesh_3D_Cube() {}
