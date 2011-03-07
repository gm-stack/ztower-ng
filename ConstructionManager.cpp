/*
 *  ConstructionManager.cpp
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ConstructionManager.h"

ConstructionManager::ConstructionManager(textureManager *tm2) {
	tm = tm2;
}

void ConstructionManager::drawObjects() {
	for (list<buildingObject*>::iterator it = objects.begin(); it != objects.end(); it++) {
		(*it)->draw();
	}
}

void ConstructionManager::fivemin_process() {
	for (list<buildingObject*>::iterator it = objects.begin(); it != objects.end(); it++) {
		(*it)->fivemin_process();
	}
}

void ConstructionManager::buildOffice(Uint32 position, int floor) {
	Office *built = new Office(position,floor,tm);
	objects.push_back(built);
}