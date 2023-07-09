#pragma once

#include "Object.h"
#include "Collision.h"

class CollisionManager
{
public:
	CollisionManager() {}
	std::vector<Collision> allCollision;

	void addCollision(Collision collision);
	void removeCollision(Collision collision);
};

