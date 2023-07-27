#pragma once
#include <SFML/Graphics.hpp>

#include "Component.h"
#include "Shape.h"

enum class ShapePossibility {
	rect = 0,
	circle = 1,
	capsule = 2,

};


class CollisionComponent : public IComponent
{

public:
	CollisionComponent() {};
	CollisionComponent(Shape* shape);
	CollisionComponent(Shape::circle* circle);
	CollisionComponent(Shape::rect* rect);
	CollisionComponent(Shape::capsule* capsule); 

	virtual ~CollisionComponent() override;

	//Launch at the end of creating object
	virtual void Start() override;

	//Render Update 
	virtual void Render(sf::RenderWindow& window) override;

	//Logic Update
	virtual void Update(float deltaTime) override;

	Shape *shape;
	Shape::circle* circle;
	Shape::rect* rect;
	Shape::capsule* capsule;

	

	
protected:

	ShapePossibility shapePossibility;
	         

};

