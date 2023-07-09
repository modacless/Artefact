#pragma once
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/String.hpp>
#include <memory>

#include <vector>
#include "Component.h"
#include "SpriteComponent.h"
#include "InputComponent.h"


class GameObject : public sf::Transformable
{
public:

	GameObject(std::string name);
	~GameObject();

	void Start();

	//Component Logique
	template<typename T>
	void AddComponent(T &componentToAdd);

	template<>
	void AddComponent(SpriteComponent& componentToAdd);
	template<>
	void AddComponent(InputComponent& componentToAdd);

	//Render all components
	void RenderComponent(sf::RenderWindow& window);
	//Update all components
	void UpdateComponent(float deltaTime);

	//Update all event components
	void UpdateEvent(sf::Event event);

	//GameObject Logic
	void SetPosition(sf::Vector2f position);

	//GameObject Parameter
	void SetDebugMode(bool debug);

	//Get component
	template<typename X>
	X GetComponent(X &component);

protected:

	//GameObject Parameter
	std::string name;
	std::vector<IComponent*> components;

	//Debug mode for object && component
	bool isDebugMode = false;

private:

};

//Add Component 
template<typename T>
inline void GameObject::AddComponent(T& componentToAdd)
{
	components.push_back(new T(componentToAdd));
}
	
template<>
inline void GameObject::AddComponent(SpriteComponent& componentToAdd)
{
	components.push_back(new SpriteComponent(componentToAdd));
}

template<>
inline void GameObject::AddComponent(InputComponent& componentToAdd)
{
	components.push_back(new InputComponent(componentToAdd));
}

//Get Component
template<typename X>
inline X GameObject::GetComponent(X& component) 
{

	/*for (auto it = components; it != components.end(), ++it)
	{
		if (std::string(typeid(component).name()) == typeid(it).name())
		{
			//return it;
		}
	}*/

	return nullptr;
}
