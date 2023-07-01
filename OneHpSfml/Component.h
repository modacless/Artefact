#pragma once
#include <SFML/Graphics.hpp>

class IComponent
{
public :

	//Launch at the end of creating object
	virtual void Start(){} //First Frame of the Object
	virtual ~IComponent() = default;
	//Render Update 
	virtual void Render(sf::RenderWindow& window){} //All render behavior
	//Logic Update
	virtual void Update(float deltaTime){} //Update based on delta time
	virtual void UpdateEvent(sf::Event event){} //Update event base
	virtual void Debug(float deltaTime) {} //Debug draw && update

};

