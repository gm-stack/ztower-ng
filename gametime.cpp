/*
 *  gametime.cpp
 *  ztower-ng
 *
 *  Created by gm on 5/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "gametime.h"

GameTime::GameTime(ConstructionManager *cm2) {
	minutes = 0;
	cm = cm2;
	return;
}

void GameTime::incrementMinutes() {
	minutes++;
	if (!(minutes % 5)) {
		cm->fivemin_process();
	}
}

Uint32 GameTime::getMinute() {
	return minutes % 60;
}

Uint32 GameTime::getHour() {
	return (unsigned int)(minutes / 60);
}

float GameTime::getFracHour() {
	return (float)minutes/60.0f;
}