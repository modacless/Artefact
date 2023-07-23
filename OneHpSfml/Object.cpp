#include "Object.h"

GameObject::GameObject(std::string name, sf::Vector2f position)
{
	this->name = name;
	this->setPosition(position);
}

GameObject::~GameObject() 
{
	components.clear(); //Memory leak ?
}

void GameObject::Start()
{
	for (auto& component : components)
	{
		component->Start();
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
		if(isDebugMode)
		{
			component->Debug(deltaTime);
		}
	}
}

void GameObject::UpdateEvent(sf::Event event)
{
	for (auto& component : components)
	{
		component->UpdateEvent(event);
	}
}

void GameObject::SetDebugMode(bool debug)
{
	isDebugMode = debug;
}

