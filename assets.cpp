#include "Assets.h"


Assets::Assets()
{
	#pragma region Colored 2D Shader Program
	Shader* _vertexShader_Colored2D = new Shader("Shader.Colored.2D.Vertex", "Shaders/Colored.2D.VertexShader.glsl", Shader::Type::Vertex);
	m_Assets.insert({_vertexShader_Colored2D->ID(), _vertexShader_Colored2D});

	Shader* _fragmentShader_Colored2D = new Shader("Shader.Colored.2D.Fragment", "Shaders/Colored.2D.FragmentShader.glsl", Shader::Type::Fragment);
	m_Assets.insert({_fragmentShader_Colored2D->ID(), _fragmentShader_Colored2D});

	ShaderProgram_Colored2D* _program_Colored2D = new ShaderProgram_Colored2D(_vertexShader_Colored2D, _fragmentShader_Colored2D);
	m_Assets.insert({_program_Colored2D->ID(), _program_Colored2D});
	
	#pragma endregion

	#pragma region Colored 3D Shader Program
	Shader* _vertexShader_Colored3D = new Shader("Shader.Colored.3D.Vertex", "Shaders/Colored.3D.VertexShader.glsl", Shader::Type::Vertex);
	m_Assets.insert({ _vertexShader_Colored3D->ID(), _vertexShader_Colored3D });

	Shader* _fragmentShader_Colored3D = new Shader("Shader.Colored.3D.Fragment", "Shaders/Colored.3D.FragmentShader.glsl", Shader::Type::Fragment);
	m_Assets.insert({ _fragmentShader_Colored3D->ID(), _fragmentShader_Colored3D });

	ShaderProgram_Colored3D* _program_Colored3D = new ShaderProgram_Colored3D(_vertexShader_Colored3D, _fragmentShader_Colored3D);
	m_Assets.insert({ _program_Colored3D->ID(), _program_Colored3D });

	#pragma endregion

	#pragma region Textured 2D Shader Program
	Shader* _vertexShader_Textured2D = new Shader("Shader.Textured.2D.Vertex", "Shaders/Textured.2D.VertexShader.glsl", Shader::Type::Vertex);
	m_Assets.insert({ _vertexShader_Textured2D->ID(), _vertexShader_Textured2D });

	Shader* _fragmentShader_Textured2D = new Shader("Shader.Textured.2D.Fragment", "Shaders/Textured.2D.FragmentShader.glsl", Shader::Type::Fragment);
	m_Assets.insert({ _fragmentShader_Textured2D->ID(), _fragmentShader_Textured2D });

	ShaderProgram_Textured2D* _program_Textured2D = new ShaderProgram_Textured2D(_vertexShader_Textured2D, _fragmentShader_Textured2D);
	m_Assets.insert({ _program_Textured2D->ID(), _program_Textured2D });

	#pragma endregion

	#pragma region Textured 3D Shader Program
	Shader* _vertexShader_Textured3D = new Shader("Shader.Textured.3D.Vertex", "Shaders/Textured.3D.VertexShader.glsl", Shader::Type::Vertex);
	m_Assets.insert({ _vertexShader_Textured3D->ID(), _vertexShader_Textured3D });

	Shader* _fragmentShader_Textured3D = new Shader("Shader.Textured.3D.Fragment", "Shaders/Textured.3D.FragmentShader.glsl", Shader::Type::Fragment);
	m_Assets.insert({ _fragmentShader_Textured3D->ID(), _fragmentShader_Textured3D });

	ShaderProgram_Textured3D* _program_Textured3D = new ShaderProgram_Textured3D(_vertexShader_Textured3D, _fragmentShader_Textured3D);
	m_Assets.insert({ _program_Textured3D->ID(), _program_Textured3D });

	#pragma endregion

	#pragma region Meshes
	Mesh_2D_RightTriangle* _mesh_2D_RightTriangle = new Mesh_2D_RightTriangle();
	m_Assets.insert({ _mesh_2D_RightTriangle->ID(), _mesh_2D_RightTriangle });
	
	Mesh_2D_Triangle* _mesh_2D_Triangle = new Mesh_2D_Triangle();
	m_Assets.insert({ _mesh_2D_Triangle->ID(), _mesh_2D_Triangle });

	Mesh_2D_Square* _mesh_2D_Square = new Mesh_2D_Square();
	m_Assets.insert({ _mesh_2D_Square->ID(), _mesh_2D_Square });

	Mesh_2D_Pentagon* _mesh_2D_Pentagon = new Mesh_2D_Pentagon();
	m_Assets.insert({ _mesh_2D_Pentagon->ID(), _mesh_2D_Pentagon });

	Mesh_2D_Octagon* _mesh_2D_Octagon = new Mesh_2D_Octagon();
	m_Assets.insert({ _mesh_2D_Octagon->ID(), _mesh_2D_Octagon });

	Mesh_2D_SemiOctagon* _mesh_2D_SemiOctagon = new Mesh_2D_SemiOctagon();
	m_Assets.insert({ _mesh_2D_SemiOctagon->ID(), _mesh_2D_SemiOctagon });

	Mesh_3D_Cube* _mesh_3D_Cube = new Mesh_3D_Cube();
	m_Assets.insert({ _mesh_3D_Cube->ID(), _mesh_3D_Cube });

	Mesh_3D_Tetrahedron* _mesh_3D_Tetrahedron = new Mesh_3D_Tetrahedron();
	m_Assets.insert({ _mesh_3D_Tetrahedron->ID(), _mesh_3D_Tetrahedron });
	
	Mesh_3D_Sphere* _mesh_3D_Sphere = new Mesh_3D_Sphere();
	m_Assets.insert({ _mesh_3D_Sphere->ID(), _mesh_3D_Sphere });

	Mesh_3D_Icosphere* _mesh_3D_Icosphere = new Mesh_3D_Icosphere();
	m_Assets.insert({ _mesh_3D_Icosphere->ID(), _mesh_3D_Icosphere });

	Mesh_File_OBJ* _mesh_robot = new Mesh_File_OBJ("Mesh.Robot", "Assets/Robot.obj");
	m_Assets.insert({_mesh_robot->ID(), _mesh_robot});
	#pragma endregion

	#pragma region Textures
	Texture* _square = new Texture("Texture.Square", "Assets/Square.png");
	m_Assets.insert({ _square->ID(), _square });

	Texture* _rTriangle = new Texture("Texture.RightTriangle", "Assets/RightTriangle.png");
	m_Assets.insert({ _rTriangle->ID(), _rTriangle });

	Texture* _pentagon = new Texture("Texture.Pentagon", "Assets/Pentagon.png");
	m_Assets.insert({ _pentagon->ID(), _pentagon });

	Texture* _secureServ = new Texture("Texture.SecureServ", "Assets/SecureServ.png");
	m_Assets.insert({ _secureServ->ID(), _secureServ });

	Texture* _secureServ2 = new Texture("Texture.SecureServ2", "Assets/SecureServ2.png");
	m_Assets.insert({ _secureServ2->ID(), _secureServ2 });

	Texture* _allSeeingEye = new Texture("Texture.AllSeeingEye", "Assets/AllSeeingEye.png");
	m_Assets.insert({ _allSeeingEye->ID(), _allSeeingEye });

	Texture* _crate = new Texture("Texture.Crate", "Assets/Texture.Crate.jpg");
	m_Assets.insert({ _crate->ID(), _crate });
	
	Texture* _markedCrate = new Texture("Texture.MarkedCrate", "Assets/Texture.Crate_With_Sides_Marked.jpg");
	m_Assets.insert({ _markedCrate->ID(), _markedCrate });

	Texture* _mcGrass = new Texture("Texture.MCGrass", "Assets/MC.Grass.png");
	m_Assets.insert({ _mcGrass->ID(), _mcGrass });
	
	Texture* _wall = new Texture("Texture.Wall", "Assets/Texture.Wall.jpg");
	m_Assets.insert({ _wall->ID(), _wall });

	Texture* _texture_robot = new Texture("Texture.Robot", "Assets/Robot.Diffuse.jpg", true);
	m_Assets.insert({ _texture_robot->ID(), _texture_robot });
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