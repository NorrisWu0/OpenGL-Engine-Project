#include "Mesh_File_OBJ.h"


Mesh_File_OBJ::Mesh_File_OBJ(const char* _id, const char* _filePath) : Mesh(_id)
{
	std::ifstream _file(_filePath);

	std::vector<glm::vec3> _verticies;
	std::vector<glm::vec2> _textureCoords;
	std::vector<glm::vec2> _normal;

	std::vector<unsigned int> _vertexIndicies;
	std::vector<unsigned int> _textureCoordsIndicies;
	std::vector<unsigned int> _normalIndicies;

	std::string _line;
	while (std::getline(_file, _line))
	{
		if (_line.substr(0, 2) == "vt") //vertex texture coordinates
		{
			const size_t _size = _textureCoords.size();
			_textureCoords.resize(_size + 1);

			std::istringstream _ss(_line.substr(3));
			_ss >> _textureCoords.data()[_size].x >> _textureCoords.data()[_size].y;
		}
		else if (_line.substr(0, 2) == "vn") //vertex normal
		{
			const size_t _size = _normal.size();
			_normal.resize(_size + 1);

			std::istringstream _ss(_line.substr(3));
			_ss >> _normal.data()[_size].x >> _normal.data()[_size].y;
		}
		else if (_line[0] == 'v') // vertex
		{
			const size_t _size = _verticies.size();
			_verticies.resize(_size + 1);

			std::istringstream _ss(_line.substr(3));
			_ss >> _verticies.data()[_size].x >> _verticies.data()[_size].y >> _verticies.data()[_size].z;
		}
		
		else if (_line[0] == 'f')
		{
			std::istringstream _ss(_line.substr(2));
			while (_ss.good())
			{
				const size_t _size = _vertexIndicies.size();
				_vertexIndicies.resize(_size + 1);
				_textureCoordsIndicies.resize(_size + 1);
				_normalIndicies.resize(_size + 1);

				char _seperator;

				_ss >> _vertexIndicies.data()[_size] >> _seperator >> _textureCoordsIndicies.data()[_size] >> _seperator >> _normalIndicies.data()[_size];
			}
		}
	}

	for (size_t i = 0; i < _vertexIndicies.size(); ++i)
	{
		int _vertexIndex = _vertexIndicies[i] - 1;

		glm::vec3 _vertex = _verticies[_vertexIndex];

		m_Verticies.push_back(_vertex.x);
		m_Verticies.push_back(_vertex.y);
		m_Verticies.push_back(_vertex.z);
	}

	for (size_t i = 0; i < _textureCoordsIndicies.size(); ++i)
	{
		int _textureCoordsIndex = _textureCoordsIndicies[i] - 1;

		glm::vec2 _textureCoord = _textureCoords[_textureCoordsIndex];

		m_TextureCoordinates.push_back(_textureCoord.x);
		m_TextureCoordinates.push_back(_textureCoord.y);
	}
}

Mesh_File_OBJ::~Mesh_File_OBJ() {}
