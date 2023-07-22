#include "SceneParser.h"
#include <iostream>
#include "PoorTools.h"


SceneParser::SceneParser(std::string filePath)
{
	std::ifstream levelFile(filePath);
	const json levelData = json::parse(levelFile);

	allScenesDatas = std::list< SceneDatas*>();

	if (levelData != nullptr) 
	{
		SceneDatas* sceneDatas = new SceneDatas(levelData.at("identifier"));
		sceneDatas->scenePosition = sf::Vector2<float>(levelData.at("worldX"), levelData.at("worldY"));
		sceneDatas->sceneSize = sf::Vector2<int>(levelData.at("pxWid"), levelData.at("pxHei"));

		//std::cout << sceneDatas.GetSceneName();
		//std::cout << sceneDatas.sceneSize.x << " " << sceneDatas.sceneSize.y << "\n";
		//std::cout << sceneDatas.scenePosition.x << " " << sceneDatas.scenePosition.y << "\n";

		//sceneTileNumber = levelData.at("layerInstances").get_to("")

		//auto tiles = levelData.at("layerInstances");
		const int sizeMapData = levelData.at("layerInstances").size();
		//int* _tileMap = new int[sizeTile];

		for(auto elem : levelData.at("layerInstances"))
		{

			if(elem.at("__identifier") == "Static_Collision")
			{
				int cWid = elem.at("__cWid");
				int cHei = elem.at("__cHei");

				int gridSize = elem.at("__gridSize");

				int intGridCsvSize = cWid * cHei;
				int* intGridCsv = new int[intGridCsvSize];
				
				for(int i = 0; i< intGridCsvSize; i++)
				{
					intGridCsv[i] = elem.at("intGridCsv").at(i);
				}

				sceneDatas->collisionTile = new SceneDatas::CollisionTile(intGridCsv, gridSize, cWid, cHei);
			}


			if(elem.at("__type") == "Tiles")
			{

				const int sizeOfMapTile = elem.at("gridTiles").size();

				std::string pathOfTile = elem.at("__tilesetRelPath");
				PoorTools::removeOccurrences(pathOfTile, "../");

				std::cout << pathOfTile;

				int cWid = elem.at("__cWid");
				int cHei = elem.at("__cHei");

				const int gridSize = elem.at("__gridSize");
				const int sizeOfMap = cWid*cHei;

				int* tileMap = new int[sizeOfMap];

				//Create Empty tiles;
				for(int zer = 0; zer < sizeOfMap; zer++)
				{
					tileMap[zer] = 0;
				}

				sceneDatas->tileSize = sf::Vector2<int>(cWid, cHei);

				//Fill with tile number
				for(auto tile : elem.at("gridTiles"))
				{
					//Get x/y from json
					int xTile = tile.at("px").at(0) / gridSize;
					int yTile = tile.at("px").at(1) / gridSize;

					//Get index : (row * length(row))+ column
					int indexOfMap = (yTile * (cWid)) + xTile;
					tileMap[indexOfMap] = tile.at("t");
				}
				TileMap tilemap =TileMap();
				tilemap.Load(pathOfTile, sf::Vector2<int>(gridSize, gridSize), sf::Vector2<int>(cWid, cHei), tileMap);
				sceneDatas->tilesOfScene.push_back(tilemap);
			}

		}

		allScenesDatas.push_back(sceneDatas);
		
	}else
	{
		assert("level incorrect : " + levelData == nullptr);
	}
}

SceneParser::~SceneParser()
{
	while (!allScenesDatas.empty()) delete allScenesDatas.front(), allScenesDatas.pop_front();
	
}

