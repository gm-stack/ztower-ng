#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "SDL.h"

#include "defs.h"
#include "gametime.h"

static SDL_Surface *gScreen;
static GameTime gt;


static void initAttributes ()
{
    SDL_GL_SetAttribute (SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, 1);
}

static void createSurface (int fullscreen)
{
    Uint32 flags = 0;
    
    flags = SDL_OPENGL;
    if (fullscreen)
        flags |= SDL_FULLSCREEN;
    
    gScreen = SDL_SetVideoMode (1024, 768, 0, flags);
    if (gScreen == NULL) {
        fprintf (stderr, "Couldn't set 640x480 OpenGL video mode: %s\n",
                 SDL_GetError());
		SDL_Quit();
		exit(2);
	}
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

    initAttributes ();    
    createSurface (0);
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
