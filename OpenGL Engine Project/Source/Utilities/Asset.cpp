#include "Asset.h"


Asset::Asset(const char* _id)
	: m_ID(_id) {}

Asset::~Asset() {}

const char* Asset::GetID() const { return m_ID; }