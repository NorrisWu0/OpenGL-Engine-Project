#include "Mesh_2D_RightTriangle.h"

Mesh_2D_RightTriangle::Mesh_2D_RightTriangle() : Mesh("Mesh.RightTriangle")
{
	auto _v1 = {-0.25f, 0.5f};
	auto _v2 = {-0.25f, -0.5f};
	auto _v3 = {0.25f, -0.5f};

	auto _tc1 = { 0.0f, 0.0f };
	auto _tc2 = { 0.0f, 1.0f };
	auto _tc3 = { 0.5f, 1.0f };

	m_Verticies.insert(m_Verticies.end(), _v1);
	m_Verticies.insert(m_Verticies.end(), _v2);
	m_Verticies.insert(m_Verticies.end(), _v3);

	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc1);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc2);
	m_TextureCoordinates.insert(m_TextureCoordinates.end(), _tc3);

}
