/*
 *  floorManager.cpp
 *  ztower-ng
 *
 *  Created by gm on 7/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "floorManager.h"
#include "utils.h"

FloorManager::FloorManager(textureManager *tm2) {
	tm = tm2;
	emptybg = tm->texture("empty");
	firestairs = tm->texture("firestairs");
}

int FloorManager::buildFloor(int floor, Uint32 xleft, Uint32 xright) {
	leftBound[floor] = xleft;
	rightBound[floor] = xright;
	return 1;
}

int FloorManager::extendFloor(int pos){
	return 0;
}

void FloorManager::drawFloor() {
	Uint32 llen = leftBound.size();
	Uint32 rlen = rightBound.size();
	if (llen != rlen) {
		printf("warning: left != right\n");
	}
	for(int i=0;i<llen;i++) {
		printf("lbound = %u, rbound = %u\n",leftBound[i],rightBound[i]);
		Uint32 leftPixels = pos2pixels(leftBound[i]);
		Uint32 rightPixels = pos2pixels(rightBound[i]);
		emptybg->drawWidth(leftPixels, floor2pixels(i), rightPixels-leftPixels);
		firestairs->draw(rightPixels, floor2pixels(i));
		firestairs->draw(leftPixels-(firestairs->sizex),floor2pixels(i));
	}
}