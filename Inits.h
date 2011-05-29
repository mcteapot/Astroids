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
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"

//Data
SDL_Surface *screen;
int    run;
SDL_Event event;
//Data Fonts
TTF_Font *font;
//Data Images
SDL_Surface *background;
SDL_Surface *message;


void loadFiles() {
    //Load images
    //background = load_image( "Astroids.app/Contents/Resources/background.png" );
    //Load font
    font = TTF_OpenFont( "Astroids.app/Contents/Resources/Arial.ttf", 50 );
}

//void initSDLWindow(int screenWidth, int screenHeight) : Init SDL Windows
void initSDLWindow(int SCREENWIDTH, int SCREENHIGHT, int SCREENBPP) {
	/* Initialize the SDL library */
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n",
				SDL_GetError());
		exit(1);
	}
	
	//Set 640x480 video mode 
	screen=SDL_SetVideoMode(SCREENWIDTH , SCREENHIGHT, SCREENBPP, SDL_SWSURFACE);
	if (screen == NULL) {
		fprintf(stderr, "Couldn't set %ix%ix%d video mode: %s\n",
				SCREENWIDTH , SCREENHIGHT, SCREENBPP, SDL_GetError());
		SDL_Quit();
		exit(2);
	}
	
	//Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        exit(3);
    }
	//Set Appliction Name
	SDL_WM_SetCaption( "Astroids", NULL );
	run = 1;
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
				run = 0;
				break;
			default:
				break;
		}
	}
	
}

//void initSDLCleanUp() : Init SDL Quit
void initSDLCleanUp() {
	
	//Close the font
    TTF_CloseFont( font );
	
    //Quit SDL_ttf
    TTF_Quit();
	
    //Quit SDL
    SDL_Quit();
}

#endif //INIT_H