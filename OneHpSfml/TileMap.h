#pragma once
#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

	void Load(const std::string& pathToTileMap, sf::Vector2<int> sizeOfTile, sf::Vector2<int> sizeOfMapPerTile, const int* tiles);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Texture texture;
	sf::VertexArray vertices;
};

