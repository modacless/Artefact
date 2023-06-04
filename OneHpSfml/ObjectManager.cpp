#include "ObjectManager.h"

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{
	gameObjects.clear();
}

void ObjectManager::Update(float deltaTime)
{
	for(const auto& gameObject : gameObjects)
	{
		gameObject->UpdateComponent(deltaTime);
	}
}

void ObjectManager::Render(sf::RenderWindow& window)
{
	for (const auto& gameObject : gameObjects)
	{
		gameObject->RenderComponent(window);
	}
}

void ObjectManager::AddGameObject(std::unique_ptr<GameObject> gameObject)
{
	gameObjects.emplace_back(std::move(gameObject));
}
