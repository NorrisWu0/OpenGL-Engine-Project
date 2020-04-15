#pragma once

#include "SemiOctagonMesh.h"

SemiOctagonMesh::SemiOctagonMesh() : Mesh("Mesh.Bunker")
{
	_verticies.insert(_verticies.end(), { -0.73f, 0.0f });
	_verticies.insert(_verticies.end(), { -0.73f, 0.3f });
	_verticies.insert(_verticies.end(), { 0.0f, 0.0f });  

	_verticies.insert(_verticies.end(), { -0.73f, 0.3f });
	_verticies.insert(_verticies.end(), { -0.3f, 0.73f });
	_verticies.insert(_verticies.end(), { 0.0f, 0.0f });  

	_verticies.insert(_verticies.end(), { -0.3f, 0.73f });
	_verticies.insert(_verticies.end(), { 0.3f, 0.73f });
	_verticies.insert(_verticies.end(), { 0.0f, 0.0f });  

	_verticies.insert(_verticies.end(), { 0.3f, 0.73f });
	_verticies.insert(_verticies.end(), { 0.73f, 0.3f });
	_verticies.insert(_verticies.end(), { 0.0f, 0.0f });  

	_verticies.insert(_verticies.end(), { 0.73f, 0.3f });
	_verticies.insert(_verticies.end(), { 0.73f, 0.0f });
	_verticies.insert(_verticies.end(), { 0.0f, 0.0f });  


	_texture_coordinates.insert(_texture_coordinates.end(), { 0.0f, 0.0f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.0f, 0.2054f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.5f, 0.0f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.0f, 0.2054f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.5f, 0.0f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.2945f, 0.5f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.2945f, 0.5f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.5f, 0.0f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.2945f, 0.5f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.2945f, 0.5f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.5f, 0.0f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 1.0f, 0.2054f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 1.0f, 0.2054f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 0.5f, 0.0f });
	_texture_coordinates.insert(_texture_coordinates.end(), { 1.0f, 0.0f });

}

SemiOctagonMesh::~SemiOctagonMesh()
{
}
