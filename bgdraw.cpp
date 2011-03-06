/*
 *  bgdraw.cpp
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "bgdraw.h"

bgDraw::bgDraw(GameTime *gt2) {
	gt = gt2;
}

void bgDraw::drawBG() {
	short int redshift,greenshift,blueshift;
	short int redscale,greenscale,bluescale;
	float hours = gt->getFracHour();
	
	// this code is so full of magic numbers it needs mana to run
	
	if (hours < 4) {
		redscale = 18; greenscale = 18; bluescale = 18;
		redshift = 0; greenshift = 0; blueshift = 0;
	} else if (hours >= 4 && hours < 9) {
		redscale = 17; greenscale = 18; bluescale = 18;
		redshift = (((hours - 4.0f) / 5.0f) * 136.0f);
		greenshift = (((hours - 4.0f) / 5.0f) * 207.0f);
		blueshift = (((hours - 4.0f) / 5.0f) * 222.0f);
	} else if (hours >=9 && hours < 14) {
		bluescale = greenscale = redscale = (((hours - 9) / 5) * 50) + 18;
		redshift = 136; greenshift = 207; blueshift = 222;
	} else if (hours >= 14 && hours <21) {
		bluescale = greenscale = redscale = (((7 - (hours - 14)) / 7) * 50) + 18;
		redshift = 136; greenshift = 207; blueshift = 222;
	} else {
		redscale = greenscale = bluescale = 18;
		redshift = ((3.0f - (hours - 21.0f)) / 3.0f) * 136.0f;
		greenshift = ((3.0f - (hours - 21.0f)) / 3.0f) * 207.0f;
		blueshift = ((3.0f - (hours - 21.0f)) / 3.0f) * 222.0f;
	}
	
	short int red,green,blue;
	red = redshift + (200/redscale);
	green = greenshift + (200/greenscale);
	blue = blueshift + (200/bluescale);
	
	glDisable(GL_TEXTURE_2D);
	glColor4f( red/255.0f, green/255.0f, blue/255.0f, 1.0f);
	glRectangle(0,0,1024,768);
	
	glColor4f(0.5f, 0.4f, 0.2985f, 1.0f);
	glRectangle(0,0,1024, 8);
	glEnable(GL_TEXTURE_2D);
		
}

void bgDraw::glRectangle(int x1, int y1, int x2, int y2) {
	glBegin(GL_QUADS);
	glVertex3i(x1,y1,0);
	glVertex3i(x1,y2,0);
	glVertex3i(x2,y2,0);
	glVertex3i(x2,y1,0);
	glEnd();
}