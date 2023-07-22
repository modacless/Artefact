#pragma once
#include "TileMap.h"
#include "ObjectManager.h"
#include "SceneParser.h"

class Scene
{
public:
	Scene(std::string pathOfMap);
	~Scene();

	void SceneStart();

	void SceneUpdate();

	void SceneDraw(sf::RenderWindow& window);

protected:

	TileMap* tileMap;
	SceneParser* sceneParser;
	ObjectManager* objsManager;


private:


};

