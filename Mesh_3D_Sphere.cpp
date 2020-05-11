#define PI 3.1415926535897932384626433832795 

#include "Mesh_3D_Sphere.h"
#include <math.h>

Mesh_3D_Sphere::Mesh_3D_Sphere() : Mesh("Mesh.Sphere")
{
    int radius = 1;
    int sectorCount = 10;
    int stackCount = 5;

    float x, y, z, xy;                              // vertex position
    float s, t;                                     // vertex texCoord

    float sectorStep = 2 * (float)PI / sectorCount;
    float stackStep = (float)PI / stackCount;
    float sectorAngle, stackAngle;

    for (int i = 0; i <= stackCount; ++i)
    {
        stackAngle = (float)PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
        xy = radius * cosf(stackAngle);             // r * cos(u)
        z = radius * sinf(stackAngle);              // r * sin(u)

        // add (sectorCount+1) vertices per stack
        // the first and last vertices have same position and normal, but different tex coords
        for (int j = 0; j <= sectorCount; ++j)
        {
            sectorAngle = j * sectorStep;           // starting from 0 to 2pi

            // vertex position (x, y, z)
            x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
            y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
            m_Verticies.insert(m_Verticies.end(), {x, y, z});

            // normalized vertex normal (nx, ny, nz)
            /*nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            normals.push_back(nx);
            normals.push_back(ny);
            normals.push_back(nz);*/

            // vertex tex coord (s, t) range between [0, 1]
            s = (float)j / sectorCount;
            t = (float)i / stackCount;
            m_TextureCoordinates.push_back(s);
            m_TextureCoordinates.push_back(t);
        }
    }

    // generate CCW index list of sphere triangles
    std::vector<int> indices;
    int k1, k2;
    for (int i = 0; i < stackCount; ++i)
    {
        k1 = i * (sectorCount + 1);     // beginning of current stack
        k2 = k1 + sectorCount + 1;      // beginning of next stack

        for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
        {
            // 2 triangles per sector excluding first and last stacks
            // k1 => k2 => k1+1
            if (i != 0)
            {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }

            // k1+1 => k2 => k2+1
            if (i != (stackCount - 1))
            {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }

}

Mesh_3D_Sphere::~Mesh_3D_Sphere()
{
}