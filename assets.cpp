#include "assets.h"
#include "shader.h"
#include "texture.h"

// Shader Programs
#include "ShaderProgram.h"
#include "ShaderProgram_Colored2D.h"
#include "ShaderProgram_Colored3D.h"

// Meshes
#include "Mesh_Triangle.h"
#include "Mesh_Square.h"
#include "Mesh_Octagon.h"
#include "Mesh_SemiOctagon.h"
#include "Mesh_Cube.h"

#define GLEW_STATIC
#include <glew.h>

#include <iostream>

Assets::Assets()
{
	#pragma region Colored 2D Shader Program
	Shader* _vertexShader_Colored2D = new Shader("Shader.Colored.2D.Vertex", "Shaders/colored.2D.vertex_shader.glsl", Shader::Type::Vertex);
	m_Assets.insert({_vertexShader_Colored2D->id(), _vertexShader_Colored2D});

	Shader* _fragmentShader_Colored2D = new Shader("Shader.Colored.2D.Fragment", "Shaders/colored.2D.fragment_shader.glsl", Shader::Type::Fragment);
	m_Assets.insert({_fragmentShader_Colored2D->id(), _fragmentShader_Colored2D});

	ShaderProgram_Colored2D* _program_Colored2D = new ShaderProgram_Colored2D(_vertexShader_Colored2D, _fragmentShader_Colored2D);
	m_Assets.insert({_program_Colored2D->id(), _program_Colored2D});
	
	#pragma endregion

	#pragma region Colored 3D Shader Program
	Shader* _vertexShader_Colored3D = new Shader("Shader.Colored.3D.Vertex", "Shaders/colored.3D.vertex_shader.glsl", Shader::Type::Vertex);
	m_Assets.insert({ _vertexShader_Colored3D->id(), _vertexShader_Colored3D });

	Shader* _fragmentShader_Colored3D = new Shader("Shader.Colored.3D.Fragment", "Shaders/colored.3D.fragment_shader.glsl", Shader::Type::Fragment);
	m_Assets.insert({ _fragmentShader_Colored3D->id(), _fragmentShader_Colored3D });

	ShaderProgram_Colored3D* _program_Colored3D = new ShaderProgram_Colored3D(_vertexShader_Colored3D, _fragmentShader_Colored3D);
	m_Assets.insert({ _program_Colored3D->id(), _program_Colored3D });

	#pragma endregion

	#pragma region Meshes
	Mesh_Triangle* _mesh_Triangle = new Mesh_Triangle();
	m_Assets.insert({_mesh_Triangle->id(), _mesh_Triangle});

	Mesh_Square* _mesh_Square = new Mesh_Square();
	m_Assets.insert({_mesh_Square->id(), _mesh_Square});

	Mesh_Octagon* _mesh_Octagon = new Mesh_Octagon();
	m_Assets.insert({ _mesh_Octagon->id(), _mesh_Octagon });

	Mesh_SemiOctagon* _mesh_SemiOctagon = new Mesh_SemiOctagon();
	m_Assets.insert({ _mesh_SemiOctagon->id(), _mesh_SemiOctagon });

	Mesh_Cube* _mesh_Cube = new Mesh_Cube();
	m_Assets.insert({ _mesh_Cube->id(), _mesh_Cube });

	#pragma endregion
}
Assets::~Assets()
{
}

const Asset* Assets::GetAsset(const char* id) const
{
	if(m_Assets.find(id) == m_Assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID: " << id << std::endl;
		exit(1);
	}

	return m_Assets.find(id)->second;
}