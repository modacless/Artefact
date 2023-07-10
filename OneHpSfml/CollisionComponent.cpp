#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(Shape::circle circle)
{
	this->circle = circle;
	shape = new Shape();
	shapePossibility = ShapePossibility::circle;
}

CollisionComponent::CollisionComponent(Shape::rect rect)
{
	this->rect = rect;
	shape = new Shape();
	shapePossibility = ShapePossibility::rect;
}

CollisionComponent::CollisionComponent(Shape::capsule capsule)
{
	this->capsule = capsule;
	shape = new Shape();
	shapePossibility = ShapePossibility::capsule;
}

CollisionComponent::~CollisionComponent()
{
	delete shape;
	shape = nullptr;
}

void CollisionComponent::Start()
{
}

void CollisionComponent::Render(sf::RenderWindow& window)
{

}

void CollisionComponent::Update(float deltaTime)
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