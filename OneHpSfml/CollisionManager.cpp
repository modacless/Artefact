#include "CollisionManager.h"


void CollisionManager::addCollision(CollisionComponent* collision){
	allCollision.push_back(collision);
}


void CollisionManager::removeCollision(CollisionComponent* collision) {
	//allCollision.erase(std::remove(allCollision.begin(), allCollision.end(), collision), allCollision.end());
}