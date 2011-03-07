/*
 *  buildingObject.cpp
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "buildingObject.h"
#include "utils.h"

buildingObject::buildingObject(Uint32 position2, Uint32 floor2, textureManager* tm2) {
	position = position2;
	floor = floor2;
	tm = tm2;
	
	L = lua_open();
	luaopen_base(L);
	luaopen_table(L);
	luaopen_string(L);
	luaopen_math(L);
	printf("lua inited\n");
}

void buildingObject::draw() {
	int floor_pixels = floor2pixels(floor);
	Uint32 pos_pixels = pos2pixels(position);
	texture->draw(pos_pixels,floor_pixels);
}

void buildingObject::fivemin_process() {
}