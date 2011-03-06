/*
 *  gametime.cpp
 *  ztower-ng
 *
 *  Created by gm on 5/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "gametime.h"

GameTime::GameTime() {
	minutes = 0;
	hours = 0;
	return;
}

void GameTime::incrementMinutes() {
	minutes++;
	if (minutes == 60) {
		minutes = 0;
		hours++;
	}
}

Uint32 GameTime::getMinute() {
	return minutes % 60;
}

Uint32 GameTime::getHour() {
	return hours;
}

float GameTime::getFracHour() {
	return ((float)(hours % 24) + ((float)minutes/60.0f));
}