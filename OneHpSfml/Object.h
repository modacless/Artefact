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
	void AddComponent(const T &componentToAdd);

	template<>
	void AddComponent(const SpriteComponent& componentToAdd);
	void AddComponent(const std::vector<IComponent> &componentToAdd);

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
	std::vector<std::shared_ptr<IComponent>> components;

private:
};

template<typename T>
inline void GameObject::AddComponent(const T& componentToAdd)
{
	components.push_back(std::make_unique<T>(componentToAdd));
}

template<>
inline void GameObject::AddComponent(const SpriteComponent& componentToAdd)
{
	components.push_back(std::make_unique<SpriteComponent>(componentToAdd));
}


