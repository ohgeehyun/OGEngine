#pragma once
#include "../Source/Resources.h"
#include "../Source/Texture.h"

void LoadResources()
{
	Resources::Load<graphcis::Texture>(L"BackGround", L"..\\\Resourses\\img\\map\\map_pure.png");
	Resources::Load<graphcis::Texture>(L"PackMan", L"..\\Resourses\\img\\pacman\\0.png");
	Resources::Load<graphcis::Texture>(L"Chichken", L"..\\Resourses\\chicken.bmp");
	Resources::Load<graphcis::Texture>(L"Cat", L"..\\Resourses\\ChickenAlpha.bmp");
	Resources::Load<graphcis::Texture>(L"Bubble", L"..\\Resourses\\Bubble.png");
	Resources::Load<graphcis::Texture>(L"MapleEffect", L"..\\Resourses\\ezgif.com-gif-maker.png");
}