/*
 *  utils.cpp
 *  ztower-ng
 *
 *  Created by gm on 7/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "utils.h"

int floor2pixels(int floor) {
	return (floor*36)+8;
}

int pos2pixels(int pos) {
	return (pos*8);
}