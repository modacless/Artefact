#include "CollisionManager.h"


void CollisionManager::addCollision(Collision collision){
	allCollision.push_back(collision);
}


void CollisionManager::removeCollision(Collision collision) {
	//allCollision.erase(std::remove(allCollision.begin(), allCollision.end(), collision), allCollision.end());
}