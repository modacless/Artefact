#pragma once
#include "Component.h"

class CameraComponent : public IComponent
{
public:
	CameraComponent(sf::Vector2<float> center, sf::Vector2<float> size);
	~CameraComponent();

	void Update(float deltaTime) override;
	sf::View* GetCamera();

protected:

	sf::View* camera;

};

