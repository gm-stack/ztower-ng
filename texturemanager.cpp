/*
 *  texturemanager.cpp
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "texturemanager.h"
#include "defs.h"

textureManager::textureManager() {
}

void textureManager::loadAll() {
	textures["buildingsbg"] = new zImage(SYSTEM_FILEPATH "images/buildingsbg.png");
}
