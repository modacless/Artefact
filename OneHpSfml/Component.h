#pragma once
#include <SFML/Graphics.hpp>

class IComponent
{
public :

	virtual ~IComponent();

	//Launch at the end of creating object
	virtual void Start();

	//Render Update 
	virtual void Render(sf::RenderWindow& window);

	//Logic Update
	virtual void Update(float deltaTime);
};

