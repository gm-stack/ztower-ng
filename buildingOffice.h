/*
 *  buildingOffice.h
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#import "buildingObject.h"
#import "texturemanager.h"

class Office : public buildingObject {
public:
	Office(Uint32 position2, Uint32 floor2, textureManager* tm);
	void fivemin_process();
};