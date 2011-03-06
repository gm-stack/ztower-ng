/*
 *  buildingObject.cpp
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "buildingObject.h"

buildingObject::buildingObject(zImage* texture2,Uint32 position2, Uint32 floor2) {
	texture = texture2;
	position = position2;
	floor = floor2;
	
	L = lua_open();
	luaopen_base(L);
	luaopen_table(L);
	luaopen_string(L);
	luaopen_math(L);
}

void buildingObject::draw() {
	texture->draw(position,floor);
}

void buildingObject::fivemin_process() {
}