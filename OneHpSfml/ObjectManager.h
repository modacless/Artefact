#pragma once
#include <list>
#include <memory>
#include "Object.h"
#include "CollisionManager.h";

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
	template<typename C>
	void AddGameObject(C gameObject)
	{
		const auto collisionComp = gameObject->GetComponent<CollisionComponent>();
		if (collisionComp != nullptr)
		{
			collisionManager->addCollision(collisionComp);

		}

		gameObject->Start();
		gameObjects.emplace_back(std::move(gameObject));
	};

	template<typename C>
	void DeleteGameObject(C gameObject)
	{
		for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it)
		{
			it->reset();
		}

		delete collisionManager;
		collisionManager = nullptr;
	}



protected:

	std::list<std::unique_ptr<GameObject>> gameObjects;
	CollisionManager* collisionManager;

private:
};





