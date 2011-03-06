/*
 *  buildingOffice.cpp
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "buildingOffice.h"
#import "defs.h"

Office::Office(Uint32 position2, Uint32 floor2, textureManager* tm):
buildingObject(position2,floor2,tm) {
	luaL_dofile(L,SYSTEM_FILEPATH "Office.lua");
	texture = tm->texture("office_1_open");
}

void Office::fivemin_process() {
	printf("fivemin_process\n");
}