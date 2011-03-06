/*
 *  buildingObject.h
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#import "texturemanager.h"
#import "zImage.h"
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


class buildingObject {
public:
	buildingObject(Uint32 position2, Uint32 floor2, textureManager* tm);
	void draw();
	virtual void fivemin_process();
protected:
	lua_State* L;
	textureManager *tm;
	zImage* texture;
private:
	Uint32 position;
	Uint32 floor;
};