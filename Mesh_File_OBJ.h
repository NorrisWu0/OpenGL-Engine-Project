#pragma once
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <string>
#include <fstream>
#include <sstream>

#include "Mesh.h"


class Mesh_File_OBJ : public Mesh
{
public:
	Mesh_File_OBJ(const char* _id, const char* _filePath);
	~Mesh_File_OBJ();
};