#pragma once
#include "../Source/Resources.h"
#include "../Source/Texture.h"

void LoadResources()
{
	Resources::Load<graphcis::Texture>(L"BackGround", L"G:\\unity\\OGEngine\\Resourses\\CloudOcean.png");
}