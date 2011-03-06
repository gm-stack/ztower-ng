/*
 *  ConstructionManager.h
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

using namespace std;
#import <string>
#import <list>
#import "texturemanager.h"
#import "buildingObject.h"
#import "buildingOffice.h"


class ConstructionManager {
public:
	ConstructionManager(textureManager *tm2);
	void drawObjects();
	void buildOffice(Uint32 position, Uint32 floor);
private:
	list<buildingObject*> objects;
	textureManager *tm;
};