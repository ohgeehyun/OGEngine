#pragma once
#include "Entity.h"


//순수 가상 함수 사용, 추상 클래스 
class Resource : public Entity
{
public:
	Resource(OG_Utils::eResourceType type);
	virtual ~Resource();

	virtual HRESULT Load(const std::wstring& path) = 0;
	
	const std::wstring& GetPath() { return _path; }
	void SetPath(const std::wstring& path) { _path = path; }

public:
	Resource() = delete;

private:
	OG_Utils::eResourceType _type;
	std::wstring _path;
};
