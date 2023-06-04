#include "Object.h"


GameObject::GameObject(std::string name)
{
	this->name = name;
}

GameObject::~GameObject() 
{
	for (int i = 0; i< components.size();i++)
	{
		delete components[i];
		components[i] = nullptr;
	}
}


void GameObject::RenderComponent(sf::RenderWindow& window)
{
	for (auto& component : components)
	{
		component->Render(window);
	}
}

void GameObject::UpdateComponent(float deltaTime)
{
	for (auto& component : components)
	{
		component->Update(deltaTime);
	}
}
