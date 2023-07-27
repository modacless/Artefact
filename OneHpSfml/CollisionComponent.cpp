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

CollisionComponent::CollisionComponent(Shape::circle* circle)
{
	this->circle = new Shape::circle(circle);
	shape = new Shape();
	shapePossibility = ShapePossibility::circle;
}

CollisionComponent::CollisionComponent(Shape::rect& rect)
{
	this->rect = new Shape::rect(rect);
	shape = new Shape();
	shapePossibility = ShapePossibility::rect;
}

CollisionComponent::CollisionComponent(Shape::capsule* capsule)
{
	this->capsule = new Shape::capsule(capsule);
	shape = new Shape();
	shapePossibility = ShapePossibility::capsule;
}

CollisionComponent::~CollisionComponent()
{
	/*delete shape;
	shape = nullptr;

	if (circle != nullptr)
		delete circle;


	if (rect != nullptr)
		delete rect;


	if (capsule != nullptr)
		delete capsule;*/
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
		rect->updateRectangle(parentObject->getPosition());
		break;
	case ShapePossibility::capsule:
		break;
	}
		
}