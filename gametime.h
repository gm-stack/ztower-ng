/*
 *  gametime.h
 *  ztower-ng
 *
 *  Created by gm on 5/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

class GameTime {
	public:
	GameTime();
	void incrementMinutes();
	Uint32 getHour();
	Uint32 getMinute();
	
	private:
	Uint32 minutes;
};
