#include "TestChamber.h"

TestChamber::TestChamber(const char* _id) : GameObject(_id) {}
TestChamber::~TestChamber() {}

void TestChamber::SimulateAI(const double, const Assets*, const Scene*, const Configuration*, const Input*) {}

void TestChamber::Render(const double , const Assets* _assets, const Scene* _scene, const Configuration* _config)
{
	const ShaderProgram_Textured3D* _program = (ShaderProgram_Textured3D*)_assets->GetAsset("ShaderProgram.3D.Textured");
	const Texture* _texture = (Texture*)_assets->GetAsset("Texture.GridBox");

	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.InvertedCube");

	_program->Render(_config, _mesh, _texture, Translation(), Rotation(), Scale(), Camera(_scene, _config), Projection(_scene, _config));

}
