#pragma once
#include "../Source/Resources.h"
#include "../Source/Texture.h"

void LoadResources()
{
	Resources::Load<graphcis::Texture>(L"BackGround", L"G:\\unity\\OGEngine\\Resourses\\img\\map\\map_pure.png");
	Resources::Load<graphcis::Texture>(L"PackMan", L"G:\\unity\\OGEngine\\Resourses\\img\\pacman\\dead\\0.png");
}