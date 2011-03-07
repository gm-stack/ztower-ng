/*
 *  zImage.cpp
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "zImage.h"

zImage::zImage(char* filename) {
	SDL_Surface *image;
	image = IMG_Load(filename);
	if (!image) {
		printf("Failed to load %s: %s\n",filename, IMG_GetError());
		return;
	}
	
	int w=1; while (w<image->w) {w = w*2;}
	int h=1; while (h<image->h) {h = h*2;}
		
	surface = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
	SDL_SetAlpha(image, 0, 255);
	
	tcx = ((float)image->w/(float)surface->w);
	tcy = ((float)image->h/(float)surface->h);
	sizex = image->w;
	sizey = image->h;
		
	SDL_BlitSurface(image, NULL, surface, NULL);
	
	
	glGenTextures(1, &glu);
	glBindTexture(GL_TEXTURE_2D, glu);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, surface->pixels);
	SDL_FreeSurface(image);
}

void zImage::draw(int x, int y) {
	glBindTexture(GL_TEXTURE_2D, glu);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glBegin(GL_QUADS);
	glColor4f(1.0f,1.0f,1.0f,1.0f);
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(x, y+sizey,0);
	
	glTexCoord2f(tcx,0);
	glVertex3f(x+sizex, y+sizey, 0);
	
	glTexCoord2f(tcx,tcy);
	glVertex3f(x+sizex, y, 0);
	
	glTexCoord2f(0,tcy);
	glVertex3f(x,y,0);
	
	glEnd();
}

void zImage::drawWidth(int x, int y, int width) {
	glBindTexture(GL_TEXTURE_2D, glu);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glBegin(GL_QUADS);
	glColor4f(1.0f,1.0f,1.0f,1.0f);
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(x, y+sizey,0);
	
	glTexCoord2f(tcx,0);
	glVertex3f(x+width, y+sizey, 0);
	
	glTexCoord2f(tcx,tcy);
	glVertex3f(x+width, y, 0);
	
	glTexCoord2f(0,tcy);
	glVertex3f(x,y,0);
	
	glEnd();
}