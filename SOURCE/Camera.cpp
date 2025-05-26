#include "Camera.h"
#include "Transform.h"
#include "OGApplication.h"

extern OGApplication temp_Class;

Camera::Camera() : Component(OG_Utils::eComponentType::Camera), _distance(Vector2::Zero), _resolution(Vector2::Zero), _lookPosition(Vector2::Zero),_target(nullptr)
{
}

Camera::~Camera()
{
}

void Camera::Init()
{
	_resolution.x = temp_Class.GetWidth();
	_resolution.y = temp_Class.GetHeight();
}

void Camera::Update()
{
	if (_target)
	{
		Transform* tr = _target->GetComponent<Transform>();
		_lookPosition = tr->GetPosition();
	}

	Transform* cameraTr = GetOwner()->GetComponent<Transform>();
	_lookPosition = cameraTr->GetPosition();

	_distance = _lookPosition - (_resolution / 2.0f);
}

void Camera::LateUpdate()
{
}

void Camera::Render(HDC hdc)
{
}
