#pragma once
#include <glew.h>
#include <string>
#include <map>
#include <iostream>

#include "Shader.h"
#include "Texture.h"

// Shader Programs
#include "ShaderProgram.h"
#include "ShaderProgram_Colored2D.h"
#include "ShaderProgram_Colored3D.h"
#include "ShaderProgram_Textured2D.h"
#include "ShaderProgram_Textured3D.h"

// Meshes
#include "Mesh_2D_RightTriangle.h"
#include "Mesh_2D_Triangle.h"
#include "Mesh_2D_Square.h"
#include "Mesh_2D_Pentagon.h"
#include "Mesh_2D_Octagon.h"
#include "Mesh_2D_SemiOctagon.h"
#include "Mesh_3D_Cube.h"
#include "Mesh_3D_Tetrahedron.h"
#include "Mesh_3D_Sphere.h"
#include "Mesh_3D_Icosphere.h"

class Asset;


class Assets
{
public:
	Assets();
	~Assets();

	const Asset* GetAsset(const char* _id) const;

private:
	std::map<const char*, const Asset*> m_Assets;
};