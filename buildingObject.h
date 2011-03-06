/*
 *  buildingObject.h
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#import "zImage.h"
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


class buildingObject {
public:
	buildingObject(zImage* texture2,Uint32 position2, Uint32 floor2);
	void draw();
	virtual void fivemin_process();
private:
	zImage* texture;
	Uint32 position;
	Uint32 floor;
	lua_State* L;
};