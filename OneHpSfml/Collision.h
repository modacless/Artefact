#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"

enum class ShapePossibility {
	rect = 0,
	circle = 1,
	capsule = 2,

};


class Collision
{
public:
	Collision(Shape::circle circle);
	Collision(Shape::rect rect);
	Collision(Shape::capsule capsule); 

	virtual ~Collision();

	//Launch at the end of creating object
	virtual void Start();

	//Render Update 
	virtual void Render(sf::RenderWindow& window);

	//Logic Update
	virtual void Update(float deltaTime);

	Shape *shape;
	Shape::circle circle;
	Shape::rect rect;
	Shape::capsule capsule;

	
protected:

	ShapePossibility shapePossibility;
	         

};

