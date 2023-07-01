#include "Object.h"


GameObject::GameObject(std::string name)
{
	this->name = name;
}

GameObject::~GameObject() 
{
	components.clear();
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
