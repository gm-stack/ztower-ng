/*
 *  buildingOffice.cpp
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "buildingOffice.h"

Office::Office(zImage* texture2, Uint32 position2, Uint32 floor2):
buildingObject(texture2,position2,floor2) {
}

void Office::fivemin_process() {
	printf("fivemin_process\n");
}