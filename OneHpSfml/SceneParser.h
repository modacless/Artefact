#pragma once
#include <fstream>
#include <SFML/Graphics.hpp>
#include "nlohmann/json.hpp"
#include "TileMap.h"

using json = nlohmann::json;

struct SceneDatas 
{
public:

	SceneDatas(std::string name)
	{
		sceneName = name;
	};

	std::string GetSceneName() { return sceneName; };
	void SetSceneName(std::string sceneName) { this->sceneName = sceneName; };

	//Paramater
	sf::Vector2<float> scenePosition;
	sf::Vector2<int> sceneSize;
	sf::Vector2<int> tileSize;

	std::vector<TileMap> tilesOfScene;
	
	int* sceneTileNumber;

private:
	std::string sceneName;

protected:
};

#pragma once
class SceneParser
{
public:
	SceneParser(std::string filePath);
	~SceneParser();

	std::list<SceneDatas> allScenesDatas;

protected:

	int* tileMap; //To Change


private:

};

	