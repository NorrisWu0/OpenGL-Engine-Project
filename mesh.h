#pragma once
#include <glew.h>
#include <vector>

#include "Asset.h"


class Mesh : public Asset
{
public:
	Mesh(const char* _id);
	~Mesh();

	const std::vector<GLfloat> verticies()           const;
	const std::vector<GLfloat> texture_coordinates() const;
	const std::vector<GLfloat> indicies()            const;
	const std::vector<GLfloat> normals()             const;
	
protected:
	std::vector<GLfloat> m_Verticies;
	std::vector<GLfloat> m_TextureCoordinates;
	std::vector<GLfloat> m_Indicies;
	std::vector<GLfloat> m_Normals;
};