#include "assets.h"
#include "shader.h"
#include "texture.h"

// Shader Programs
#include "ShaderProgram.h"
#include "ShaderProgram_Colored2D.h"
#include "ShaderProgram_Colored3D.h"
#include "ShaderProgram_Textured3D.h"

// Meshes
#include "Mesh_2D_Triangle.h"
#include "Mesh_2D_Square.h"
#include "Mesh_2D_Octagon.h"
#include "Mesh_2D_SemiOctagon.h"
#include "Mesh_3D_Cube.h"

#define GLEW_STATIC
#include <glew.h>

#include <iostream>

Assets::Assets()
{
	#pragma region Colored 2D Shader Program
	Shader* _vertexShader_Colored2D = new Shader("Shader.Colored.2D.Vertex", "Shaders/Colored.2D.VertexShader.glsl", Shader::Type::Vertex);
	m_Assets.insert({_vertexShader_Colored2D->id(), _vertexShader_Colored2D});

	Shader* _fragmentShader_Colored2D = new Shader("Shader.Colored.2D.Fragment", "Shaders/Colored.2D.FragmentShader.glsl", Shader::Type::Fragment);
	m_Assets.insert({_fragmentShader_Colored2D->id(), _fragmentShader_Colored2D});

	ShaderProgram_Colored2D* _program_Colored2D = new ShaderProgram_Colored2D(_vertexShader_Colored2D, _fragmentShader_Colored2D);
	m_Assets.insert({_program_Colored2D->id(), _program_Colored2D});
	
	#pragma endregion

	#pragma region Colored 3D Shader Program
	Shader* _vertexShader_Colored3D = new Shader("Shader.Colored.3D.Vertex", "Shaders/Colored.3D.VertexShader.glsl", Shader::Type::Vertex);
	m_Assets.insert({ _vertexShader_Colored3D->id(), _vertexShader_Colored3D });

	Shader* _fragmentShader_Colored3D = new Shader("Shader.Colored.3D.Fragment", "Shaders/Colored.3D.FragmentShader.glsl", Shader::Type::Fragment);
	m_Assets.insert({ _fragmentShader_Colored3D->id(), _fragmentShader_Colored3D });

	ShaderProgram_Colored3D* _program_Colored3D = new ShaderProgram_Colored3D(_vertexShader_Colored3D, _fragmentShader_Colored3D);
	m_Assets.insert({ _program_Colored3D->id(), _program_Colored3D });

	#pragma endregion

	#pragma region Textured 3D Shader Program
	Shader* _vertexShader_Textured3D = new Shader("Shader.Textured.3D.Vertex", "Shaders/Textured.3D.VertexShader.glsl", Shader::Type::Vertex);
	m_Assets.insert({ _vertexShader_Textured3D->id(), _vertexShader_Textured3D });

	Shader* _fragmentShader_Textured3D = new Shader("Shader.Textured.3D.Fragment", "Shaders/Textured.3D.FragmentShader.glsl", Shader::Type::Fragment);
	m_Assets.insert({ _fragmentShader_Textured3D->id(), _fragmentShader_Textured3D });

	ShaderProgram_Textured3D* _program_Textured3D = new ShaderProgram_Textured3D(_vertexShader_Textured3D, _fragmentShader_Textured3D);
	m_Assets.insert({ _program_Textured3D->id(), _program_Textured3D });

	#pragma endregion

	#pragma region Meshes
	Mesh_2D_Triangle* _mesh_2D_Triangle = new Mesh_2D_Triangle();
	m_Assets.insert({ _mesh_2D_Triangle->id(), _mesh_2D_Triangle });

	Mesh_2D_Square* _mesh_2D_Square = new Mesh_2D_Square();
	m_Assets.insert({ _mesh_2D_Square->id(), _mesh_2D_Square });

	Mesh_2D_Octagon* _mesh_2D_Octagon = new Mesh_2D_Octagon();
	m_Assets.insert({ _mesh_2D_Octagon->id(), _mesh_2D_Octagon });

	Mesh_2D_SemiOctagon* _mesh_2D_SemiOctagon = new Mesh_2D_SemiOctagon();
	m_Assets.insert({ _mesh_2D_SemiOctagon->id(), _mesh_2D_SemiOctagon });

	Mesh_3D_Cube* _mesh_3D_Cube = new Mesh_3D_Cube();
	m_Assets.insert({ _mesh_3D_Cube->id(), _mesh_3D_Cube });

	#pragma endregion

	#pragma region Textures
	Texture* _crate = new Texture("Texture.Crate", "Assets/Texture.Crate.jpg");
	m_Assets.insert({ _crate->id(), _crate });

	Texture* _markedCrate = new Texture("Texture.MarkedCrate", "Assets/Texture.Crate_With_Sides_Marked.jpg");
	m_Assets.insert({ _markedCrate->id(), _markedCrate });

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