#include "CollisionComponent.h"
#include "Object.h"

CollisionComponent::CollisionComponent(Shape* shape)
{
	this->shape = shape;
	
	if(shape->rectangle != nullptr)
	{
		shapePossibility = ShapePossibility::rect;
		
	}

}

CollisionComponent::CollisionComponent(Shape::circle& circle)
{
	//this->circle = new Shape::circle(circle);
	shapePossibility = ShapePossibility::circle;
}

CollisionComponent::CollisionComponent(Shape::rect* rect)
{
	shape->rectangle = rect;
	shapePossibility = ShapePossibility::rect;
}

CollisionComponent::CollisionComponent(Shape::capsule& capsule)
{
	//this->capsule = new Shape::capsule(capsule);
	shapePossibility = ShapePossibility::capsule;
}

CollisionComponent::~CollisionComponent()
{
	delete shape;
}

void CollisionComponent::Start()
{
}

void CollisionComponent::Render(sf::RenderWindow& window)
{

}

void CollisionComponent::Update(float deltaTime)
{
	IComponent::Update(deltaTime);


	switch (shapePossibility) {
	case ShapePossibility::circle:
		break;
	case ShapePossibility::rect:
		shape->rectangle->updateRectangle(parentObject->getPosition());
		break;
	case ShapePossibility::capsule:
		break;
	}
		
}