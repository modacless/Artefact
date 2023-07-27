#include "CameraComponent.h"

CameraComponent::CameraComponent(sf::Vector2<float> center, sf::Vector2<float> size)
{
	camera = new sf::View(center, size);
}

CameraComponent::~CameraComponent()
{
	delete camera;
}

void CameraComponent::Update(float deltaTime)
{
	IComponent::Update(deltaTime);

}

sf::View* CameraComponent::GetCamera()
{
	return camera;
}
