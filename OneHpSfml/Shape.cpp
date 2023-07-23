#include "Shape.h"

bool Shape::pointIsInRect(sf::Vector2f point_test, rect* rect_b) {
	bool isInside;
	float dim_sum = 0;
	float half = 0.5f;
	float B, C;
//TODO: fix 
	for (unsigned int i = 0; i < 3; i++) {
		
		B = distancePoints(rect_b->points[i], rect_b->points[i + 1]);
		C = distancePoints(point_test, (rect_b->points[i + 1] + rect_b->points[i]) * half);
		
		dim_sum += B * C;

	}
	B = distancePoints(rect_b->points[3], rect_b->points[0]);
	C = distancePoints(point_test, (rect_b->points[3] + rect_b->points[0]) * half);
	dim_sum += B * C;

	dim_sum *= half;
	isInside = (dim_sum <= rect_b->axisSize.x * rect_b->axisSize.y);

	return isInside;
}

float Shape::distancePoints(sf::Vector2f point_a, sf::Vector2f point_b)
{
	sf::Vector2f diff = point_a - point_b;
	return sqrt(powf(diff.x, 2) + powf(diff.y, 2));
}

bool Shape::collideCirclevsCirle(Shape::circle circle_a, Shape::circle circle_b)
{
	return distanceSquarred(circle_a, circle_b) < std::powf((circle_a.radius + circle_b.radius), 2);
}

bool Shape::collideCirclevsrect(circle circle, rect rect)
{

	return false;
}

bool Shape::collideCirclevsCapsule(circle circle, capsule capsule)
{
	return false;
}


bool Shape::collideRectvsRect(rect* rect_a, rect* rect_b)
{
	bool isInside = false;
	for (unsigned int i = 0; i < 4; i++) {
			if (pointIsInRect(rect_a->points[i], rect_b)) {
				return true;
		}
	}
	return false;
}

bool Shape::collideRectvsCapsule(rect rect, capsule capsule)
{
	return false;
}
