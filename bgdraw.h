/*
 *  bgdraw.h
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#import "gametime.h"
#import "zImage.h"

class bgDraw {
	public:
	bgDraw(GameTime *gt2, zImage *bg);
	void drawBG();
	void glRectangle(int x1, int y1, int x2, int y2);
private:
	GameTime *gt;
	zImage *bgimage;
};

