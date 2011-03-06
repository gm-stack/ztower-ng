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
	textures["office_1_open"] = new zImage(SYSTEM_FILEPATH "images/office_1_open.png");
	textures["office_1_closed"] = new zImage(SYSTEM_FILEPATH "images/office_1_closed.png");
}

zImage* textureManager::texture(char* texture) {
	if(textures[texture] != NULL) {
		return textures[texture];
	} else {
		printf("Call to unknown texture %s\n",texture);
		return NULL;
	}
}