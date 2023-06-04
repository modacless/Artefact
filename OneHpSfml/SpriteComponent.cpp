#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(std::string filepath)
{
	texture.loadFromFile(filepath);
	sprite.setTexture(texture, false);

}

void SpriteComponent::Render(sf::RenderWindow& window)
{
	window.draw(sprite);
}
