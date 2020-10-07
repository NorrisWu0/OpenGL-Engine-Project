#include "Assets.h"

#include <glew.h>
#include <string>
#include <iostream>

#include "Rendering/Shader.h"
#include "Mesh/Texture.h"

// Shader Programs
#include "Rendering/ShaderProgram.h"
#include "Rendering/ShaderPrograms/ShaderProgram_Colored2D.h"
#include "Rendering/ShaderPrograms/ShaderProgram_Colored3D.h"
#include "Rendering/ShaderPrograms/ShaderProgram_Textured2D.h"
#include "Rendering/ShaderPrograms/ShaderProgram_Textured3D.h"

// Meshes
#include "Mesh/Meshes/Mesh_2D_RightTriangle.h"
#include "Mesh/Meshes/Mesh_2D_Triangle.h"
#include "Mesh/Meshes/Mesh_2D_Square.h"
#include "Mesh/Meshes/Mesh_2D_Pentagon.h"
#include "Mesh/Meshes/Mesh_2D_Octagon.h"
#include "Mesh/Meshes/Mesh_2D_SemiOctagon.h"
#include "Mesh/Meshes/Mesh_3D_Cube.h"
#include "Mesh/Meshes/Mesh_3D_InvertedCube.h"
#include "Mesh/Meshes/Mesh_3D_Quad.h"
#include "Mesh/Meshes/Mesh_3D_Tetrahedron.h"
#include "Mesh/Meshes/Mesh_File_OBJ.h"

Assets::Assets()
{
	#pragma region Colored 2D Shader Program
	Shader* _vertexShader_Colored2D = new Shader("Shader.Colored.2D.Vertex", "Shaders/Colored.2D.VertexShader.glsl", Shader::Type::Vertex);
	m_Assets.insert({_vertexShader_Colored2D->GetID(), _vertexShader_Colored2D});

	Shader* _fragmentShader_Colored2D = new Shader("Shader.Colored.2D.Fragment", "Shaders/Colored.2D.FragmentShader.glsl", Shader::Type::Fragment);
	m_Assets.insert({_fragmentShader_Colored2D->GetID(), _fragmentShader_Colored2D});

	ShaderProgram_Colored2D* _program_Colored2D = new ShaderProgram_Colored2D(_vertexShader_Colored2D, _fragmentShader_Colored2D);
	m_Assets.insert({_program_Colored2D->GetID(), _program_Colored2D});
	
	#pragma endregion

	#pragma region Colored 3D Shader Program
	Shader* _vertexShader_Colored3D = new Shader("Shader.Colored.3D.Vertex", "Shaders/Colored.3D.VertexShader.glsl", Shader::Type::Vertex);
	m_Assets.insert({ _vertexShader_Colored3D->GetID(), _vertexShader_Colored3D });

	Shader* _fragmentShader_Colored3D = new Shader("Shader.Colored.3D.Fragment", "Shaders/Colored.3D.FragmentShader.glsl", Shader::Type::Fragment);
	m_Assets.insert({ _fragmentShader_Colored3D->GetID(), _fragmentShader_Colored3D });

	ShaderProgram_Colored3D* _program_Colored3D = new ShaderProgram_Colored3D(_vertexShader_Colored3D, _fragmentShader_Colored3D);
	m_Assets.insert({ _program_Colored3D->GetID(), _program_Colored3D });

	#pragma endregion

	#pragma region Textured 2D Shader Program
	Shader* _vertexShader_Textured2D = new Shader("Shader.Textured.2D.Vertex", "Shaders/Textured.2D.VertexShader.glsl", Shader::Type::Vertex);
	m_Assets.insert({ _vertexShader_Textured2D->GetID(), _vertexShader_Textured2D });

	Shader* _fragmentShader_Textured2D = new Shader("Shader.Textured.2D.Fragment", "Shaders/Textured.2D.FragmentShader.glsl", Shader::Type::Fragment);
	m_Assets.insert({ _fragmentShader_Textured2D->GetID(), _fragmentShader_Textured2D });

	ShaderProgram_Textured2D* _program_Textured2D = new ShaderProgram_Textured2D(_vertexShader_Textured2D, _fragmentShader_Textured2D);
	m_Assets.insert({ _program_Textured2D->GetID(), _program_Textured2D });

	#pragma endregion

	#pragma region Textured 3D Shader Program
	Shader* _vertexShader_Textured3D = new Shader("Shader.Textured.3D.Vertex", "Shaders/Textured.3D.VertexShader.glsl", Shader::Type::Vertex);
	m_Assets.insert({ _vertexShader_Textured3D->GetID(), _vertexShader_Textured3D });

	Shader* _fragmentShader_Textured3D = new Shader("Shader.Textured.3D.Fragment", "Shaders/Textured.3D.FragmentShader.glsl", Shader::Type::Fragment);
	m_Assets.insert({ _fragmentShader_Textured3D->GetID(), _fragmentShader_Textured3D });

	ShaderProgram_Textured3D* _program_Textured3D = new ShaderProgram_Textured3D(_vertexShader_Textured3D, _fragmentShader_Textured3D);
	m_Assets.insert({ _program_Textured3D->GetID(), _program_Textured3D });

	#pragma endregion

	#pragma region Meshes
	Mesh_2D_RightTriangle* _mesh_2D_RightTriangle = new Mesh_2D_RightTriangle();
	m_Assets.insert({ _mesh_2D_RightTriangle->GetID(), _mesh_2D_RightTriangle });
	
	Mesh_2D_Triangle* _mesh_2D_Triangle = new Mesh_2D_Triangle();
	m_Assets.insert({ _mesh_2D_Triangle->GetID(), _mesh_2D_Triangle });

	Mesh_2D_Square* _mesh_2D_Square = new Mesh_2D_Square();
	m_Assets.insert({ _mesh_2D_Square->GetID(), _mesh_2D_Square });

	Mesh_2D_Pentagon* _mesh_2D_Pentagon = new Mesh_2D_Pentagon();
	m_Assets.insert({ _mesh_2D_Pentagon->GetID(), _mesh_2D_Pentagon });

	Mesh_2D_Octagon* _mesh_2D_Octagon = new Mesh_2D_Octagon();
	m_Assets.insert({ _mesh_2D_Octagon->GetID(), _mesh_2D_Octagon });

	Mesh_2D_SemiOctagon* _mesh_2D_SemiOctagon = new Mesh_2D_SemiOctagon();
	m_Assets.insert({ _mesh_2D_SemiOctagon->GetID(), _mesh_2D_SemiOctagon });

	Mesh_3D_Cube* _mesh_3D_SignPost = new Mesh_3D_Cube();
	m_Assets.insert({ _mesh_3D_SignPost->GetID(), _mesh_3D_SignPost });

	Mesh_3D_InvertedCube* _mesh_3D_InvertedCube = new Mesh_3D_InvertedCube();
	m_Assets.insert({ _mesh_3D_InvertedCube->GetID(), _mesh_3D_InvertedCube });
	
	Mesh_3D_Quad* _mesh_3D_Quad = new Mesh_3D_Quad();
	m_Assets.insert({ _mesh_3D_Quad->GetID(), _mesh_3D_Quad });

	Mesh_3D_Tetrahedron* _mesh_3D_Tetrahedron = new Mesh_3D_Tetrahedron();
	m_Assets.insert({ _mesh_3D_Tetrahedron->GetID(), _mesh_3D_Tetrahedron });
	#pragma endregion

	#pragma region Textures
	Texture* _gridBox = new Texture("Texture.GridBox", "OpenGL Engine Project/Assets/Sprites/GridBox.png");
	m_Assets.insert({ _gridBox->GetID(), _gridBox });

	Texture* _infoSign = new Texture("Texture.InfoSign", "OpenGL Engine Project/Assets/Sprites/InfoSign.png");
	m_Assets.insert({ _infoSign->GetID(), _infoSign });

	Texture* _warningSign = new Texture("Texture.WarningSign", "OpenGL Engine Project/Assets/Sprites/WarningSign.png");
	m_Assets.insert({ _warningSign->GetID(), _warningSign });

	Texture* _allSeeingEye = new Texture("Texture.AllSeeingEye", "OpenGL Engine Project/Assets/Sprites/AllSeeingEye.png");
	m_Assets.insert({ _allSeeingEye->GetID(), _allSeeingEye });

	Texture* _dropTrap = new Texture("Texture.DropTrap", "OpenGL Engine Project/Assets/Sprites/DropTrap.png");
	m_Assets.insert({ _dropTrap->GetID(), _dropTrap });

	Texture* _lava = new Texture("Texture.Lava", "OpenGL Engine Project/Assets/Sprites/Lava.jpg");
	m_Assets.insert({ _lava->GetID(), _lava });

	Texture* _afterlife = new Texture("Texture.Afterlife", "OpenGL Engine Project/Assets/Sprites/Afterlife.png");
	m_Assets.insert({ _afterlife->GetID(), _afterlife });
	#pragma endregion

}

Assets::~Assets() {}

const Asset* Assets::GetAsset(const char* _id) const
{
	if(m_Assets.find(_id) == m_Assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID: " << _id << std::endl;
		exit(1);
	}

	return m_Assets.find(_id)->second;
}