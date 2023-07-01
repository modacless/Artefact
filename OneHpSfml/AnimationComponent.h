#pragma once
#include "Component.h"

class AnimationComponent : IComponent
{

public:
	AnimationComponent(std::string filepath, int rowOfAnimation , int columnOfAnimation, int pixelSizeXText, int pixelSizeYText, float speed);
	void Render(sf::RenderWindow& window) override;
	void Update(float deltaTime) override;

protected:

	sf::Sprite sprite;
	sf::Texture texture;

private:
	int row;
	int column;
	int pixelSizeX;
	int pixelSizeY;
	float speedAnimation;

	float timer;
};

