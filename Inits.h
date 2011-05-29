/*
 *  inits.h
 *  Astroids
 *
 *  Created by arjun prakash on 5/28/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "SDL/SDL.h"

//Data
SDL_Surface *screen;
int    done;
SDL_Event event;



//void initSDLWindow(int screenWidth, int screenHeight) : Init SDL Windows
void initSDLWindow(int screenWidth, int screenHeight) {
	/* Initialize the SDL library */
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n",
				SDL_GetError());
		exit(1);
	}
	
	//Set 640x480 video mode 
	screen=SDL_SetVideoMode(screenWidth , screenHeight, 0, SDL_SWSURFACE);
	if (screen == NULL) {
		fprintf(stderr, "Couldn't set %ix%ix%d video mode: %s\n",
				screenWidth , screenHeight, 0, SDL_GetError());
		SDL_Quit();
		exit(2);
	}
	
	SDL_WM_SetCaption( "Astroids", NULL );
	done = 0;
}

//void initSDLEvents() : Init SDL Events
void initSDLEvents() {
	/* Check for events */
	while ( SDL_PollEvent(&event) ) {
		switch (event.type) {
				
			case SDL_MOUSEMOTION:
				break;
			case SDL_MOUSEBUTTONDOWN:
				break;
			case SDL_KEYDOWN:
				/* Any keypress quits the app... */
			case SDL_QUIT:
				done = 1;
				break;
			default:
				break;
		}
	}
	
}

//void initSDLCleanUp() : Init SDL Quit
void initSDLCleanUp() {
	SDL_Quit();
}

#endif //INIT_H