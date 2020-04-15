#include "OctagonMesh.h"

OctagonMesh::OctagonMesh() : Mesh("Mesh.Octagon")
{
	_verticies.insert(_verticies.end(), { -0.73f, 0.3f });
	_verticies.insert(_verticies.end(), { -0.3f, 0.73f });
	_verticies.insert(_verticies.end(), { 0.3f, 0.73f });

	_verticies.insert(_verticies.end(), { 0.3f, 0.73f });
	_verticies.insert(_verticies.end(), { 0.73f, 0.3f });
	_verticies.insert(_verticies.end(), { -0.73f, 0.3f });
	
	_verticies.insert(_verticies.end(), { -0.73f, 0.3f });
	_verticies.insert(_verticies.end(), { 0.73f, 0.3f });
	_verticies.insert(_verticies.end(), { 0.73f, -0.3f });

	_verticies.insert(_verticies.end(), { 0.73f, -0.3f });
	_verticies.insert(_verticies.end(), { -0.73f, 0.3f });
	_verticies.insert(_verticies.end(), { -0.73f, -0.3f });
	
	_verticies.insert(_verticies.end(), { -0.73f, -0.3f });
	_verticies.insert(_verticies.end(), { 0.73f, -0.3f });
	_verticies.insert(_verticies.end(), { 0.3f, -0.73f });
	
	_verticies.insert(_verticies.end(), { 0.3f, -0.73f });
	_verticies.insert(_verticies.end(), { -0.3f, -0.73f });
	_verticies.insert(_verticies.end(), { -0.73f, -0.3f });

	_texture_coordinates.insert(_texture_coordinates.end(), { -0.73f, 0.3f });
	_texture_coordinates.insert(_texture_coordinates.end(), { -0.3f, 0.73f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.3f, 0.73f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.3f, 0.73f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.73f, 0.3f });
	_texture_coordinates.insert(_texture_coordinates.end(), { -0.73f, 0.3f });
	_texture_coordinates.insert(_texture_coordinates.end(), { -0.73f, 0.3f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.73f, 0.3f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.73f, -0.3f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.73f, -0.3f });
	_texture_coordinates.insert(_texture_coordinates.end(), { -0.73f, 0.3f });
	_texture_coordinates.insert(_texture_coordinates.end(), { -0.73f, -0.3f });
	_texture_coordinates.insert(_texture_coordinates.end(), { -0.73f, -0.3f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.73f, -0.3f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.3f, -0.73f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.3f, -0.73f });
	_texture_coordinates.insert(_texture_coordinates.end(), { -0.3f, -0.73f });
	_texture_coordinates.insert(_texture_coordinates.end(), { -0.73f, -0.3f });
}

OctagonMesh::~OctagonMesh()
{
}
