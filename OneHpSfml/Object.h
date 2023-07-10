#pragma once
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/String.hpp>
#include <memory>

#include <vector>
#include "Component.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "CollisionComponent.h"


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
	template<>
	void AddComponent(CollisionComponent& componentToAdd);

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
	template<typename C>
	C* GetComponent()
	{
		for (std::vector<IComponent*>::iterator it = components.begin(); it != components.end(); ++it)
		{
			if(typeid(C) == typeid(CollisionComponent))
			{
				return static_cast<C*>((*it));
			}
		}

		return nullptr;
	};

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

template<>
inline void GameObject::AddComponent(CollisionComponent& componentToAdd)
{
	components.push_back(new CollisionComponent(componentToAdd));
}

