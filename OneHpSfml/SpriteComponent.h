#pragma once

#include "Component.h"
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class SpriteComponent : public IComponent
{

public:

	SpriteComponent(std::string filepath);

	//Rendering
	void Render(sf::RenderWindow& window) override;



private:

	sf::Texture texture;
	sf::Sprite sprite;
};

