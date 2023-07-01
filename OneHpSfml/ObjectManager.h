#pragma once
#include <list>
#include <memory>
#include "Object.h"

class ObjectManager
{
public:

	//Base
	ObjectManager();
	~ObjectManager();
	void Update(float deltaTime);
	void UpdateEvent(sf::Event event);
	void Render(sf::RenderWindow& window);

	//List Management
	void AddGameObject(std::unique_ptr<GameObject> gameObject);
	void DeleteGameObject(std::unique_ptr<GameObject> gameObject);



protected:

	std::list<std::unique_ptr<GameObject>> gameObjects;

private:
};


