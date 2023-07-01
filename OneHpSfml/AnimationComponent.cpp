#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(std::string filepath, int rowOfAnimation, int columnOfAnimation, int pixelSizeXText, int pixelSizeYText, float speed)
{
	texture.loadFromFile(filepath);
	sprite.setTexture(texture);

	row = rowOfAnimation;
	column = columnOfAnimation;
	pixelSizeX = pixelSizeXText;
	pixelSizeY = pixelSizeYText;

	speedAnimation = speed;
}

void AnimationComponent::Render(sf::RenderWindow& window)
{
	
}
