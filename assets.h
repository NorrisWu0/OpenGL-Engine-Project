#pragma once

#include <string>
#include <map>

class Asset;

class Assets
{
public:
	Assets();
	~Assets();

	const Asset* GetAsset(const char* id) const;

private:
	std::map<const char*, const Asset*> m_Assets;
};