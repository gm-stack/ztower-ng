/*
 *  buildingOffice.h
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#import "buildingObject.h"

class Office : public buildingObject {
	Office(zImage* texture2, Uint32 position2, Uint32 floor2);
	void fivemin_process();
};