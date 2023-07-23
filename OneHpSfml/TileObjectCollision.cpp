#include "TileObjectCollision.h"

TileObjectCollision::TileObjectCollision(std::string name, sf::Vector2f position) : GameObject(name, position)
{
	Shape::rect rect = Shape::rect(position, sf::Vector2f(32, 32));
	CollisionComponent collision1 = CollisionComponent(rect);
	this->AddComponent(collision1);
	SpriteComponent sprite1 = SpriteComponent("../Assets/Sprites/Test/Collisiontest.png");
	this->AddComponent(sprite1);
}

TileObjectCollision::~TileObjectCollision() 
{
	//components.clear();
}
