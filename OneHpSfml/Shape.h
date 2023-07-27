#pragma once
#include <cmath>
#include <SFML/System/Vector2.hpp>
#include <math.h>
#include <vector>
#include "customMaths.h"

class Shape
{
public:

	Shape() {};
	~Shape()
	{
		//if(rectangle != nullptr)
			//delete rectangle;
	}


	struct rect
	{
		sf::Vector2f center;
		// axis is in X, Y size 
		sf::Vector2f axisSize;  

		//std::vector<sf::Vector2f> points;

		sf::Vector2f points[4];
		
		/*		
			"0"----"1"
			|		|
			"3" ---	"2"
		
		*/

		rect() {};
		rect(sf::Vector2f& _center, sf::Vector2f& axisSize) {
			this->center = _center;

			points[0] = sf::Vector2f(center.x-axisSize.x * 0.5f, center.y+ axisSize.y * 0.5f);
			points[1] = sf::Vector2f(center.x+axisSize.x * 0.5f, center.x+axisSize.y * 0.5f);
			points[2] = sf::Vector2f(center.x+axisSize.x * 0.5f, center.x -axisSize.y * 0.5f);
			points[3] = sf::Vector2f(center.x-axisSize.x * 0.5f, center.x -axisSize.y * 0.5f);
 			this->axisSize = axisSize;
		}

		~rect()
		{
			//delete[4] points;
		}


		void updateRectangle(sf::Vector2f _center)
		{
			this->center = _center;
			points[0] = sf::Vector2f(center.x-axisSize.x * 0.5f, center.y+ axisSize.y * 0.5f);
			points[1] = sf::Vector2f(center.x+axisSize.x * 0.5f, center.x+axisSize.y * 0.5f);
			points[2] = sf::Vector2f(center.x+axisSize.x * 0.5f, center.x -axisSize.y * 0.5f);
			points[3] = sf::Vector2f(center.x-axisSize.x * 0.5f, center.x -axisSize.y * 0.5f);
		}

	} *rectangle;

	struct circle
	{
		sf::Vector2f center;
		float radius;
		circle() 
		{
			center = sf::Vector2f(0, 0);
			radius = 0;
		}
		circle(sf::Vector2f center, float radius) {
			this->center = center;
			this->radius = radius;
		}
	};

	struct capsule
	{
		capsule(){}
		sf::Vector2f center;
		sf::Vector2f direction;
		float height;
		float width;
	};
	
	template<typename T, typename U>
	float distanceSquarred(const T struct_a, const U struc_b);


	bool collideCirclevsCirle(circle circle_a, circle circle_b);
	bool collideCirclevsrect(circle circle, rect rect);
	bool collideCirclevsCapsule(circle circle, capsule capsule);

	bool collideRectvsRect(rect* rect_a, rect* rect_b);
	bool collideRectvsCapsule(rect rect, capsule capsule);

	bool collideCapsulevsCapsule(capsule capsule_a, capsule capsule_b);
	


protected:

	bool pointIsInRect(sf::Vector2f point_test, rect *rect_b);
	float distancePoints(sf::Vector2f point_a, sf::Vector2f point_b);
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
