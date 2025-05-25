#pragma once
#include "pch.h"
#include "Resource.h"

class Resources
{
public:
	template<typename T>
	static T* Find(const std::wstring& key)
	{
		auto iter = _resources.find(key);

		if (iter == _resources.end())
		{
			return nullptr;
		}

		return dynamic_cast<T*>(iter->second);
	}

	template<typename T>
	static T* Load(const std::wstring& key , const std::wstring& path)
	{
		T* resource = Resources::Find<T> (key);
		if (resource != nullptr)
		{
			return resource;
		}
		
		resource = new T();

		ASSERT_CRASH(!resource->Load(path));

		resource->SetName(key);
		resource->SetPath(path);
		_resources.insert(std::make_pair(key,resource));

		return resource;
	}

private:
	static std::map<std::wstring, Resource*> _resources;
};

