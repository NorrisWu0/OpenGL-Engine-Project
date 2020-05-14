#include "asset.h"


Asset::Asset(const char* _id)
	: m_ID(_id)
{
}
Asset::~Asset()
{
}

const char* Asset::ID() const
{
	return m_ID;
}