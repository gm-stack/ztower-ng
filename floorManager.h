/*
 *  floorManager.h
 *  ztower-ng
 *
 *  Created by gm on 7/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

using namespace std;
#import <map>
#import "texturemanager.h"

class FloorManager {
public:
	FloorManager(textureManager *tm2);
	int buildFloor(int floor, Uint32 xleft, Uint32 xright);
	int extendFloor(int pos);
	void drawFloor();
private:
	map<int,int> leftBound;
	map<int,int> rightBound;
	textureManager *tm;
	zImage *emptybg;
	zImage *firestairs;
};
