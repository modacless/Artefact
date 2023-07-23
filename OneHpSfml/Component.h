#pragma once
#include <SFML/Graphics.hpp>

class GameObject;

class IComponent
{
public :

	virtual void Start(){} //First Frame of the Object
	virtual ~IComponent() = default;
	//Render Update 
	virtual void Render(sf::RenderWindow& window){} //All render behavior
	//Logic Update
	virtual void Update(float deltaTime) { if (parentObject == nullptr ) return; } //Update based on delta time
	virtual void UpdateEvent(sf::Event event){} //Update event base
	virtual void Debug(float deltaTime) {} //Debug draw && update

	std::string type;
	//Type definition
	GameObject* parentObject;

	//Launch at the end of creating object


};

