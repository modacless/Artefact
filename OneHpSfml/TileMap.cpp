#include "TileMap.h"
#include <cassert>
#include <iostream>

void TileMap::Load(const std::string& pathToTileMap, sf::Vector2<int> sizeOfTile, sf::Vector2<int> sizeOfMapPerTile, const int* tiles)
{
	if (texture.loadFromFile(pathToTileMap))
	{
		vertices.setPrimitiveType(sf::Triangles);
		vertices.resize(sizeOfMapPerTile.x * sizeOfMapPerTile.y * 6);

		for (unsigned int j = 0; j< sizeOfMapPerTile.y; ++j) {
			//std::cout << "\n";
			for (unsigned int i = 0; i < sizeOfMapPerTile.x; ++i)
			{
				int tileNumber = tiles[i + j * sizeOfMapPerTile.x];

				//std::cout << tileNumber << " ";

				// on en déduit sa position dans la texture du tileset
				int tu = tileNumber % (texture.getSize().x / sizeOfTile.x);
				int tv = tileNumber / (texture.getSize().x / sizeOfTile.x);

				// on récupère un pointeur vers les vertex des triangles à définir dans le tableau de vertex
				sf::Vertex* triangles = &vertices[(i + j * sizeOfMapPerTile.x) * 6];

				triangles[0].position = sf::Vector2f(i * sizeOfTile.x, j * sizeOfTile.y);
				triangles[1].position = sf::Vector2f((i + 1) * sizeOfTile.x, j * sizeOfTile.y);
				triangles[2].position = sf::Vector2f(i * sizeOfTile.x, (j + 1) * sizeOfTile.y);
				triangles[3].position = sf::Vector2f(i * sizeOfTile.x, (j + 1) * sizeOfTile.y);
				triangles[4].position = sf::Vector2f((i + 1) * sizeOfTile.x, j * sizeOfTile.y);
				triangles[5].position = sf::Vector2f((i + 1) * sizeOfTile.x, (j + 1) * sizeOfTile.y);

				// on définit ses 6 coordonnées de texture correspondantes
				triangles[0].texCoords = sf::Vector2f(tu * sizeOfTile.x, tv * sizeOfTile.y);
				triangles[1].texCoords = sf::Vector2f((tu + 1) * sizeOfTile.x, tv * sizeOfTile.y);
				triangles[2].texCoords = sf::Vector2f(tu * sizeOfTile.x, (tv + 1) * sizeOfTile.y);
				triangles[3].texCoords = sf::Vector2f(tu * sizeOfTile.x, (tv + 1) * sizeOfTile.y);
				triangles[4].texCoords = sf::Vector2f((tu + 1) * sizeOfTile.x, tv * sizeOfTile.y);
				triangles[5].texCoords = sf::Vector2f((tu + 1) * sizeOfTile.x, (tv + 1) * sizeOfTile.y);

			}

		}
	}else
	{
		assert("Can't load tile png");
	}
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// on applique la transformation 
	states.transform *= getTransform();

	// on applique la texture du tileset
	states.texture = &texture;

	// et on dessine enfin le tableau de vertex
	target.draw(vertices, states);
}
