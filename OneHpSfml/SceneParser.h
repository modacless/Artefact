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

	~SceneDatas() 
	{
		delete collisionTile;
	}

	std::string GetSceneName() { return sceneName; };
	void SetSceneName(std::string sceneName) { this->sceneName = sceneName; };

	//Paramater
	sf::Vector2<float> scenePosition;
	sf::Vector2<int> sceneSize;
	sf::Vector2<int> tileSize;

	std::vector<TileMap> tilesOfScene;

	struct DataTileCollisions
	{
		int gridSize; //Size of collision
		int SceneWidthPerTile; //Size of map per grid size tile : gridSize * SceneWidth = size of 1 grid * number of width grid
		int ScenHeightPerTile;
		int* collisionMap;//Where collision belongs

		DataTileCollisions() 
		{ 
			gridSize = 0; SceneWidthPerTile = 0; ScenHeightPerTile = 0; 
		};

		DataTileCollisions(int* _collisionMap, int& _gridSize, int& _SceneWidthPerTile, int& _ScenHeightPerTile)
		{
			collisionMap = _collisionMap;
			gridSize = _gridSize;
			SceneWidthPerTile = _SceneWidthPerTile;
			ScenHeightPerTile = _ScenHeightPerTile;
		}

	} *collisionTile;

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

	std::list<SceneDatas*> allScenesDatas;

protected:



private:

};

	