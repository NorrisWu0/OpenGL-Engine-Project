#pragma once

#include "Mesh.h"

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#include <string>
#include <fstream>

class Mesh_File_OBJ : public Mesh
{
public:
	Mesh_File_OBJ(const char* m_ID, const char _filePath);
	~Mesh_File_OBJ();
};

