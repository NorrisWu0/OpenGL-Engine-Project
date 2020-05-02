#include "Mesh_Cube.h"

Mesh_Cube::Mesh_Cube() : Mesh("Mesh.Cube")
{
	auto _v1 = { -0.5f, 0.5f, 0.5f };
	auto _v2 = { -0.5f, -0.5f, 0.5f };
	auto _v3 = { 0.5f, -0.5f, 0.5f };
	auto _v4 = { 0.5f, 0.5f, 0.5f };

	auto _v5 = { -0.5f, 0.5f, -0.5f };
	auto _v6 = { -0.5f, -0.5f, -0.5f };
	auto _v7 = { 0.5f, -0.5f, -0.5f };
	auto _v8 = { 0.5f, 0.5f, -0.5f };

	auto _tl = {0.0f, 0.0f};
	auto _tr = {1.0f, 0.0f};
	auto _bl = {1.0f, 1.0f};
	auto _br = {0.0f, 1.0f};

	#pragma region Front
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v3);
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v3);
	m_Verticies.insert(m_Verticies.end(), _v4);
	#pragma endregion

	#pragma region Left
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v1);
	#pragma endregion

	#pragma region Back
	m_Verticies.insert(m_Verticies.end(), _v8);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v8);
	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v5);
	#pragma endregion

	#pragma region Right
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v3);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v8);
	#pragma endregion

	#pragma region Top
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v5);
	m_Verticies.insert(m_Verticies.end(), _v4);
	m_Verticies.insert(m_Verticies.end(), _v8);
	#pragma endregion

	#pragma region Bottom
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v6);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v7);
	m_Verticies.insert(m_Verticies.end(), _v3);

	//m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tl);
	//m_TextureCoordinates.insert(m_TextureCoordinates.end(), _bl);
	//m_TextureCoordinates.insert(m_TextureCoordinates.end(), _br);
	//m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tl);
	//m_TextureCoordinates.insert(m_TextureCoordinates.end(), _br);
	//m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tr);
	#pragma endregion

	

}

Mesh_Cube::~Mesh_Cube()
{
}
