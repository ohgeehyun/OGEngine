#pragma once
#include "GameObject.h"
#include "CustomInput.h"
#include "CustomTime.h"
#include "Component.h"
#include "Transform.h"

GameObject::GameObject()
{
    _components.resize((UINT)OG_Utils::eComponentType::End);
    InitTransform();
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

void GameObject::InitTransform()
{
    AddComponent<Transform>();
}


void GameObject::Init()
{
    for (Component* comp : _components)
    {
        if (comp == nullptr)
            continue;

        comp->Init();
    }
}

void GameObject::Update() 
{
    const int speed = 100.0f;

    for (Component* comp : _components)
    {
        if (comp == nullptr)
            continue;

        comp->Update();
    }
}

void GameObject::LateUpdate()
{
    for (Component* comp : _components)
    {
        if (comp == nullptr)
            continue;

        comp->LateUpdate();
    }
}

void GameObject::Render(HDC hdc)
{
    for (Component* comp : _components)
    {
        if (comp == nullptr)
            continue;

        comp->Render(hdc);
    }
}


