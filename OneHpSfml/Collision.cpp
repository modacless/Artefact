#include "Collision.h"


Collision::Collision(Shape::circle circle)
{
	this->circle = circle;
	shape = new Shape();
	shapePossibility = ShapePossibility::circle;
}

Collision::Collision(Shape::rect rect)
{
	this->rect = rect;
	shape = new Shape();
	shapePossibility = ShapePossibility::rect;
}

Collision::Collision(Shape::capsule capsule)
{
	this->capsule = capsule;
	shape = new Shape();
	shapePossibility = ShapePossibility::capsule;
}

Collision::~Collision()
{
	delete shape;
	shape = nullptr;
}

void Collision::Start()
{
}

void Collision::Render(sf::RenderWindow& window)
{

}

void Collision::Update(float deltaTime)
{
	switch (shapePossibility) {
	case ShapePossibility::circle:
		break;
	case ShapePossibility::rect:
		break;
	case ShapePossibility::capsule:
		break;
	}
		
}