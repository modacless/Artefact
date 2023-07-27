#include "Shape.h"

bool Shape::pointIsInRect(sf::Vector2f point_test, rect* rect_b) {
	bool isInside;
	
	float p0, p1, p2, p3;
	sf::Vector2f edge;
	sf::Vector2f OT;

	edge = (rect_b->points[1] - rect_b->points[0]);
	OT = (point_test - rect_b->points[0]);
	p0 = customMaths::dotVector(edge, OT);

	edge = (rect_b->points[1] - rect_b->points[2]);
	OT = (point_test - rect_b->points[0]);
	p1= customMaths::dotVector(edge, OT);

	edge = (rect_b->points[2] - rect_b->points[3]);
	OT = (point_test - rect_b->points[0]);
	p2 = customMaths::dotVector(edge, OT);

	edge = (rect_b->points[0] - rect_b->points[3]);
	OT = (point_test - rect_b->points[0]);
	p3 = customMaths::dotVector(edge, OT);
	
	isInside = p0 * p1 > 0 && p1 * p2 > 0 && p2 * p3 > 0;

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
