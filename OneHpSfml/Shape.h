#pragma once
#include <cmath>
#include <SFML/System/Vector2.hpp>
#include "math.h"
#include <vector>

class Shape
{
public:
	struct rect
	{
		sf::Vector2f center;
		// axis is in X, Y size 
		sf::Vector2f axisSize;  

		std::vector<sf::Vector2f> points;
		
		/*		
			"0"----"1"
			|		|
			"3" ---	"2"
		
		*/
	
		rect(sf::Vector2f center, sf::Vector2f axisSize) {
			points[0] = sf::Vector2f(-axisSize.x*0.5f, axisSize.y * 0.5f);
			points[1] = sf::Vector2f(axisSize.x * 0.5f, axisSize.y * 0.5f);
			points[2] = sf::Vector2f(axisSize.x * 0.5f, -axisSize.y * 0.5f);
			points[3] = sf::Vector2f(-axisSize.x * 0.5f, -axisSize.y * 0.5f);
		
		}

	};

	struct circle
	{
		sf::Vector2f center;
		float radius;

	};

	struct capsule
	{
		sf::Vector2f center;
		sf::Vector2f direction;
		float height;
		float width;
	};
	
	template<typename T, typename U>
	float distanceSquarred(const T struct_a, const U struc_b);
	


protected:

	bool collideCirclevsCirle(circle circle_a, circle circle_b);
	bool collideCirclevsrect(circle circle, rect rect);
	bool collideCirclevsCapsule(circle circle, capsule capsule);

	bool collideRectvsRect(rect rect_a, rect rect_b);
	bool collideRectvsCapsule(rect rect, capsule capsule);

	bool collideCapsulevsCapsule(capsule capsule_a, capsule capsule_b);

	
};


template<typename T, typename U >
inline float Shape::distanceSquarred(const T struct_a, const U struct_b)
{
	return std::powf((struct_a.center.x - struct_b.center.x), 2) + std::powf((struct_a.center.y - struct_b.center.y), 2);
}

template<>
inline float Shape::distanceSquarred(const circle struct_a, const  circle struct_b)
{
	return std::powf((struct_a.center.x - struct_b.center.x), 2) + std::powf((struct_a.center.y - struct_b.center.y), 2);
}

template<>
inline float Shape::distanceSquarred(const rect struct_a, const rect struct_b)
{
	return std::powf((struct_a.center.x - struct_b.center.x), 2) + std::powf((struct_a.center.y - struct_b.center.y), 2);
}

template<>
inline float Shape::distanceSquarred(const capsule struct_a, const capsule struct_b)
{
	return std::powf((struct_a.center.x - struct_b.center.x), 2) + std::powf((struct_a.center.y - struct_b.center.y), 2);
}
