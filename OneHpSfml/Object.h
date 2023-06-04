#pragma once
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/String.hpp>
#include <memory>

#include <vector>
#include "Component.h"
#include "SpriteComponent.h"

class GameObject : public sf::Transformable
{
public:

	GameObject(std::string name);
	~GameObject();

	//Component Logique
	template<typename T>
	void AddComponent(T *componentToAdd);

	template<>
	void AddComponent(SpriteComponent* componentToAdd);

	//Render all components
	void RenderComponent(sf::RenderWindow& window);
	//Update all components
	void UpdateComponent(float deltaTime);

	//GameObject Logique
	void SetPosition(sf::Vector2f position);

	//GameObject Parameter

protected:

	//GameObject Parameter
	std::string name;
	std::vector<IComponent*> components;

private:
};

template<typename T>
inline void GameObject::AddComponent(T* componentToAdd)
{
	components.push_back(componentToAdd);
}
	
template<>
inline void GameObject::AddComponent(SpriteComponent* componentToAdd)
{
	components.push_back(componentToAdd);
}


