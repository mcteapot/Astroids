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

//SDL event
SDL_Event event;

//SDL Surface
SDL_Surface *screen;

//Data
int run;
int frame;

//void initSDLWindow(int screenWidth, int screenHeight) : Init SDL Windows
void initSDLWindow( int SCREENWIDTH, int SCREENHIGHT, int SCREENBPP ) {
	/* Initialize the SDL library */
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n",
				SDL_GetError());
		exit(1);
	}
	
	//Set 640x480 video mode 
	screen=SDL_SetVideoMode( SCREENWIDTH , SCREENHIGHT, SCREENBPP, SDL_SWSURFACE );
	if (screen == NULL) {
		fprintf( stderr, "Couldn't set %ix%ix%d video mode: %s\n", SCREENWIDTH , SCREENHIGHT, SCREENBPP, SDL_GetError() );
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
	//Data Inits
	run = 1;
	frame = 0;
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

//SDL_Surface *loadImage( char *filename ) : Load image
SDL_Surface *loadImage( char *filename,  int alpha ) {
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
	
    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;
	
    //Load the image
    loadedImage = IMG_Load( filename );
	
    //If the image loaded
    if( loadedImage != NULL ) {
		
        //Create an optimized surface
		if (alpha = 0) {
			optimizedImage = SDL_DisplayFormat( loadedImage );
		}
		if (alpha = 1) {
			optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		}
        //Free the old surface
        SDL_FreeSurface( loadedImage );
		
        //If the surface was optimized
        if( optimizedImage != NULL ) {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }
	
    //Return the optimized surface
    return optimizedImage;
}

//void applySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip ) : apply surface
void applySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip ) {
    //Holds offsets
    SDL_Rect offset;
	
    //Get offsets
    offset.x = x;
    offset.y = y;
	
    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}


#endif //INIT_H