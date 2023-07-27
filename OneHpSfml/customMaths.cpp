#include "customMaths.h"


float customMaths::dotVector(sf::Vector2f vec1, sf::Vector2f vec2) {
	float res = vec1.x * vec2.y - vec1.y * vec2.x;
	return res;
}