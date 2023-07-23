#include "TileObjectCollision.h"

TileObjectCollision::TileObjectCollision(std::string name) : GameObject(name)
{
	
	Shape::rect rect1 = Shape::rect(sf::Vector2f(10, 10), sf::Vector2f(1.f, 1.f));
	CollisionComponent collision1 = CollisionComponent(rect1);
	this->AddComponent(collision1);
	SpriteComponent sprite1 = SpriteComponent("../Assets/Sprites/Test/Collisiontest.png");
	this->AddComponent(sprite1);
}
