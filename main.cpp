#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "SDL.h"
#include <SDL_image/SDL_image.h>

#include "defs.h"
#include "gametime.h"
#include "textureManager.h"

static SDL_Surface *gScreen;

static GameTime gt;
static textureManager textM;
static bgDraw bg(&gt);

static void createSurface (int fullscreen)
{
    Uint32 flags = 0;
    
    flags = SDL_OPENGL | SDL_RESIZABLE;
    if (fullscreen)
        flags |= SDL_FULLSCREEN;
    
	SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, 1);
    gScreen = SDL_SetVideoMode (1024, 768, 32, flags);
    if (gScreen == NULL) {
        fprintf (stderr, "Couldn't set 640x480 OpenGL video mode: %s\n",
                 SDL_GetError());
		SDL_Quit();
		exit(2);
	}
	
	SDL_GL_SwapBuffers();
	
	glViewport(0,0,1024,768);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(0.0f, 1024.0, 0.0f, 768.0, 1.0f, -1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
	
}


static Uint32 redraw_event_push(Uint32 interval, void* param);

static void mainLoop ()
{
    SDL_Event event;
	SDL_TimerID timer1;
    int done = 0;
    
	timer1 = SDL_AddTimer(timebase, redraw_event_push, 0);
	
    while ( !done ) {

		/* Check for events */
		while ( SDL_PollEvent (&event) ) {
			switch (event.type) {

				case SDL_MOUSEMOTION:
					break;
				case SDL_MOUSEBUTTONDOWN:
					break;
				case SDL_KEYDOWN:
					/* Any keypress quits the app... */
				case REDRAW_EVENT:
					SDL_AddTimer(timebase, redraw_event_push, 0);
					glClear(GL_COLOR_BUFFER_BIT);
					gt.incrementMinutes();
					bg.drawBG();
					SDL_GL_SwapBuffers();
					break;
				case SDL_QUIT:
					done = 1;
					break;
				default:
					break;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	if ( SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0 ) {
		
        fprintf(stderr, "Couldn't initialize SDL: %s\n",
			SDL_GetError());
		exit(1);
	}
	
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) == 0) {
		printf("IMG_Init failed: %s\n", IMG_GetError());
	}

    createSurface (0);
	textM.loadAll();
    mainLoop ();
 	SDL_Quit();
	
    return 0;
}

static Uint32 redraw_event_push(Uint32 interval, void* param) {
	SDL_Event event;
	event.type = REDRAW_EVENT;
	SDL_PushEvent(&event);
	return 0;
}
