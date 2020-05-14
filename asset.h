#pragma once

// NEXT: forward declarations.

class Asset
{
public:
	Asset(const char* _id);
	~Asset();

	const char* ID() const;

private:
	const char* m_ID;
};