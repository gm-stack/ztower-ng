/*
 *  zImage.h
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#import "SDL.h"
#import "SDL_opengl.h"
#import <SDL_image/SDL_image.h>

class zImage {
	public:
	zImage(char* filename);
	void draw(int x, int y);
	SDL_Surface *surface;
	GLuint glu;
	float tcx;
	float tcy;
	int sizex;
	int sizey;
};