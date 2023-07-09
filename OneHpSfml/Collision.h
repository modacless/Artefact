#pragma once
#include <SFML/Graphics.hpp>

class Collision
{
public:
	virtual ~Collision();

	//Launch at the end of creating object
	virtual void Start();

	//Render Update 
	virtual void Render(sf::RenderWindow& window);

	//Logic Update
	virtual void Update(float deltaTime);
	
protected:


	         

};

