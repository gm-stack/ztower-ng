/*
 *  gametime.h
 *  ztower-ng
 *
 *  Created by gm on 5/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#import "ConstructionManager.h"

class GameTime {
	public:
	GameTime(ConstructionManager *cm2);
	void incrementMinutes();
	Uint32 getHour();
	Uint32 getMinute();
	float getFracHour();
	
	private:
	Uint32 minutes;
	ConstructionManager *cm;
};
