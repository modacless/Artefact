#include "SpriteComponent.h"
#include "Object.h"

SpriteComponent::SpriteComponent(std::string filepath)
{
	texture.loadFromFile(filepath);
	sprite.setTexture(texture, false);
	
}

void SpriteComponent::Update(float deltaTime)
{
	IComponent::Update(deltaTime);
	sprite.setPosition(parentObject->getPosition());
}

void SpriteComponent::Render(sf::RenderWindow& window)
{
	window.draw(sprite);
}
