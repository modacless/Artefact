#include "CollisionManager.h"


void CollisionManager::addCollision(CollisionComponent* collision){
	allCollision.push_back(collision);
}


void CollisionManager::removeCollision(CollisionComponent* collision) {
	allCollision.erase(std::remove(allCollision.begin(), allCollision.end(), collision), allCollision.end());
}

std::vector<CollisionComponent*>  CollisionManager::checkCollision(CollisionComponent* collision)
{
	std::vector<CollisionComponent*> vecCollide;
	for (CollisionComponent* current : allCollision) {
		if (current->shape->collideRectvsRect(collision->shape->rectangle, current->shape->rectangle)) {
			vecCollide.push_back(current);
		}
		
	}
	return vecCollide;
}
