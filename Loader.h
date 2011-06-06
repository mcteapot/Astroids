/*
 *  Loader.h
 *  Astroids
 *
 *  Created by arjun prakash on 5/30/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"


//SDL Image Surface
SDL_Surface *background;
SDL_Surface *astroidL01;
//SDL Text Surface
SDL_Surface *message;

//SDL Font
TTF_Font *font;

void loadFiles() {
    //Load surfaces
    background = loadImage( "Astroids.app/Contents/Resources/background.png", 0 );
	astroidL01 = loadImage( "Astroids.app/Contents/Resources/astroidL01.png", 0 );
	
    //Load fonts
    font = TTF_OpenFont( "Astroids.app/Contents/Resources/Arial.ttf", 50 );
	
	//Set Color
	
	
    //If there was a problem in loading the background
    if( background == NULL ) { exit(2); }
	
    //If there was an error in loading the font
    if( font == NULL ) { exit(2); }
	
}

void createText() {
	//SDL Colors for text
	SDL_Color textColor = { 0, 0, 0 };

    //Generate the message surface
    message = TTF_RenderText_Solid( font, "FUCKING ASTROIDS", textColor );
}

void quitSDL() {
    //Free surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( message );
	
    //Close font
    TTF_CloseFont( font );
	
    //Quit SDL_ttf
    TTF_Quit();
	
    //Quit SDL
    SDL_Quit();
}
