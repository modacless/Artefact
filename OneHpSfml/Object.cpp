#include "Object.h"


GameObject::GameObject(std::string name)
{
	this->name = name;
}

GameObject::~GameObject() 
{

}

void GameObject::AddComponent(const std::vector<IComponent> &componentsToAdd)
{
	for (auto component : componentsToAdd)
	{
		components.push_back(std::make_shared<IComponent>(component));
	}
}

void GameObject::RenderComponent(sf::RenderWindow& window)
{
	for( auto ptr = components.begin(); ptr < components.end(); ++ptr)
	{
		ptr->get()->Render(window);
	}
}

void GameObject::UpdateComponent(float deltaTime)
{
	for (auto ptr = components.begin(); ptr < components.end(); ++ptr)
	{
		ptr->get()->Update(deltaTime);
	}
}
