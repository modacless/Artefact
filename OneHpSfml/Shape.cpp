#include "Shape.h"

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


bool Shape::collideRectvsRect(rect rect_a, rect rect_b)
{
	
	return false;
}

bool Shape::collideRectvsCapsule(rect rect, capsule capsule)
{
	return false;
}
