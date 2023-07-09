#include "ObjectManager.h"

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{
	for(auto it = gameObjects.begin();it != gameObjects.end();++it)
	{
		it->reset();
	}
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

void ObjectManager::AddGameObject(std::unique_ptr<GameObject> gameObject)
{
	gameObject->Start();
	gameObjects.emplace_back(std::move(gameObject));

	//if(gameObject->GetComponent(Collision::))
}
