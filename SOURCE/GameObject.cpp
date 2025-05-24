#pragma once
#include "GameObject.h"
#include "CustomInput.h"
#include "CustomTime.h"
#include "Component.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
    //오브젝트 제거시 componet 삭제
    for (Component* comp : _components)
    {
        delete comp;
        comp = nullptr;
    }
}

void GameObject::Init()
{
    for (Component* comp : _components)
    {
        comp->Init();
    }
}

void GameObject::Update() 
{
    const int speed = 100.0f;

    for (Component* comp : _components)
    {
        comp->Update();
    }
}

void GameObject::LateUpdate()
{
    for (Component* comp : _components)
    {
        comp->LateUpdate();
    }
}

void GameObject::Render(HDC hdc)
{
    for (Component* comp : _components)
    {
        comp->Render(hdc);
    }
}


