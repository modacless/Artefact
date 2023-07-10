#pragma once

#include "Object.h"
#include "CollisionComponent.h"

class CollisionManager
{
public:
	CollisionManager() {}
	std::vector<CollisionComponent*> allCollision;

	void addCollision(CollisionComponent* collision);
	void removeCollision(CollisionComponent* collision);
};

