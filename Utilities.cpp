/*
 *  ApplySurface.c
 *  Astroids
 *
 *  Created by arjun prakash on 6/5/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#include "Utilities.h"

//SDL event
SDL_Event event;
//Get the keystates
Uint8 *keystates = SDL_GetKeyState( NULL );

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

//void initSDLEvents() : Init SDL Events
char initSDLEvents() {
	//Check for events 
	char keyPress = ' ';
	while ( SDL_PollEvent(&event) ) {
		switch (event.type) {
				
			case SDL_MOUSEMOTION:
				break;
			case SDL_MOUSEBUTTONDOWN:
				break;
			case SDL_QUIT:
				keyPress = 'q';
				break;
			case SDL_KEYDOWN:
				switch( event.key.keysym.sym ) {
					case SDLK_UP: keyPress = 'u'; break;
					case SDLK_DOWN: keyPress = 'd'; break;
					case SDLK_LEFT: keyPress = 'l'; break;
					case SDLK_RIGHT: keyPress = 'r'; break;
					case SDLK_SPACE: keyPress = 's'; break;
					case SDLK_ESCAPE: keyPress = 'q'; break;
					case SDLK_RETURN: keyPress = 'e'; break;
				}
				break;
			default:
				break;
		}
	}
	return keyPress;
	
}

void getSDLKeyStates() {
	


}