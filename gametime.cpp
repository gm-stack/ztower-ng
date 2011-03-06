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
	return;
}

void GameTime::incrementMinutes() {
	minutes++;
}

Uint32 GameTime::getMinute() {
	return minutes % 60;
}

Uint32 GameTime::getHour() {
	return (minutes / 60) % 24;
}