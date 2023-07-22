#include "Scene.h"

Scene::Scene(std::string pathOfMap)
{
	sceneParser = new SceneParser(pathOfMap);
	objsManager = new ObjectManager();
	
}

Scene::~Scene()
{
	delete sceneParser;
	delete objsManager;
}

void Scene::SceneDraw(sf::RenderWindow& window)
{
	for(auto it = sceneParser->allScenesDatas.begin(); it != sceneParser->allScenesDatas.end();++it)
	{
		for(int i = 0; i< it->tilesOfScene.size();i++)
		{
			window.draw(it->tilesOfScene[i]);
		}
	}
}


