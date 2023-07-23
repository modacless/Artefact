#include "ObjectManager.h"

#include <iostream>
#include "TileObjectCollision.h"

ObjectManager::ObjectManager()
{
	collisionManager = new CollisionManager();
}

ObjectManager::~ObjectManager()
{
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		it->reset();
	}

	delete collisionManager;
	collisionManager = nullptr;
}


void ObjectManager::Update(float deltaTime)
{
	for(const auto& gameObject : gameObjects)
	{
		gameObject->UpdateComponent(deltaTime);
	}
}

void ObjectManager::UpdateEvent(sf::Event event)
{
	for(const auto& gameObject : gameObjects)
	{
		gameObject->UpdateEvent(event);
	}
}

void ObjectManager::Render(sf::RenderWindow& window)
{
	for (const auto& gameObject : gameObjects)
	{
		gameObject->RenderComponent(window);
	}
}



