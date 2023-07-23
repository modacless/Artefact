#include "TileObjectCollision.h"
#include <iostream>

TileObjectCollision::TileObjectCollision(std::string name, sf::Vector2f position) : GameObject(name, position)
{
	shape = new Shape();
	sf::Vector2f axis = sf::Vector2f(32, 32);
	shape->rectangle = new Shape::rect(position, axis);
	collisonComponent = new CollisionComponent(shape); //maybe memory leak
	this->AddComponent(*collisonComponent);
	SpriteComponent sprite1 = SpriteComponent("../Assets/Sprites/Test/Collisiontest.png");
	this->AddComponent(sprite1);
}

TileObjectCollision::~TileObjectCollision() 
{
	//delete shape;
	//shape = nullptr;

	components.clear();


}
