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
/*
SDL_Surface *ship01;
SDL_Surface *shipBooster01;
SDL_Surface *shipDeath01;

SDL_Surface *shipSheet01;
SDL_Surface *shipSheetBooster01;

SDL_Surface *astroidL01;
SDL_Surface *astroidL02;
SDL_Surface *astroidL03;
SDL_Surface *astroidM01;
SDL_Surface *astroidM02;
SDL_Surface *astroidM03;
SDL_Surface *astroidS01;
SDL_Surface *astroidS02;
SDL_Surface *astroidS03;

SDL_Surface *astroidSheetL01;
SDL_Surface *astroidSheetM01;
SDL_Surface *astroidSheetS01;

SDL_Surface *astroidDeathL01;
SDL_Surface *astroidDeathM01;
SDL_Surface *astroidDeathS01;
//SDL Text Surface
SDL_Surface *message;
 */
//SDL Text Surface
SDL_Surface *menuScreen;
SDL_Surface *menuTitle;

//SDL Font
TTF_Font *fontL;
TTF_Font *fontS;

void loadFiles() {
    //Load surfaces
	background = loadImage( "Astroids.app/Contents/Resources/backgroundBlack.png", 0 );
	
	/*
	ship01 = loadImage( "Astroids.app/Contents/Resources/ship.png", 0 );
	shipBooster01 = loadImage( "Astroids.app/Contents/Resources/shipBooster.png", 0 );
	shipDeath01 = loadImage( "Astroids.app/Contents/Resources/shipDeadth.png", 1 );
	
	shipSheet01 = loadImage( "Astroids.app/Contents/Resources/shipSheetA.png", 1 );
	shipSheetBooster01 = loadImage( "Astroids.app/Contents/Resources/shipSheetBoosterA.png", 1 );
	
	astroidL01 = loadImage( "Astroids.app/Contents/Resources/astroidLA01.png", 1 );
	astroidL02 = loadImage( "Astroids.app/Contents/Resources/astroidLA02.png", 1 );
	astroidL03 = loadImage( "Astroids.app/Contents/Resources/astroidLA03.png", 1 );
	astroidM01 = loadImage( "Astroids.app/Contents/Resources/astroidMA01.png", 1 );
	astroidM02 = loadImage( "Astroids.app/Contents/Resources/astroidMA02.png", 1 );
	astroidM03 = loadImage( "Astroids.app/Contents/Resources/astroidMA03.png", 1 );
	astroidS01 = loadImage( "Astroids.app/Contents/Resources/astroidSA01.png", 1 );
	astroidS02 = loadImage( "Astroids.app/Contents/Resources/astroidSA02.png", 1 );
	astroidS03 = loadImage( "Astroids.app/Contents/Resources/astroidSA03.png", 1 );
	
	astroidSheetL01 = loadImage( "Astroids.app/Contents/Resources/astroidsSheetLA.png", 1 );
	astroidSheetM01 = loadImage( "Astroids.app/Contents/Resources/astroidsSheetMA.png", 1 );
	astroidSheetS01 = loadImage( "Astroids.app/Contents/Resources/astroidsSheetSA.png", 1 );
	
	astroidDeathL01 = loadImage( "Astroids.app/Contents/Resources/astroidDeathLA.png", 1 );
	astroidDeathM01 = loadImage( "Astroids.app/Contents/Resources/astroidDeathMA.png", 1 );
	astroidDeathS01 = loadImage( "Astroids.app/Contents/Resources/astroidDeathSA.png", 1 );
	*/
	
    //Load fonts
    fontL = TTF_OpenFont( "Astroids.app/Contents/Resources/Arial.ttf", 50 );
	fontS = TTF_OpenFont( "Astroids.app/Contents/Resources/Arial.ttf", 30 );	
	
    //If there was a problem in loading the background
    if( background == NULL ) { exit(2); }
	
    //If there was an error in loading the font
    if( fontL == NULL ) { exit(2); }
	if( fontS == NULL ) { exit(2); }
	
}

void createText() {
	//SDL Colors for text
	SDL_Color textColor = { 255, 255, 255 };
	
    //Generate the message surface
    //message = TTF_RenderText_Solid( fontL, "FUCKING ASTEROIDS", textColor );
	menuTitle = TTF_RenderText_Solid( fontL, "ASTEROIDS", textColor );
	menuScreen = TTF_RenderText_Solid( fontS, "Hit Enter Key to Start.", textColor );
}

void quitSDL() {
    //Free surfaces
    SDL_FreeSurface( background );
	/*
    SDL_FreeSurface( ship01 );
	SDL_FreeSurface( shipBooster01 );
	SDL_FreeSurface( shipDeath01 );
	
	SDL_FreeSurface( shipSheet01 );
	SDL_FreeSurface( shipBooster01 );
	
    SDL_FreeSurface( astroidL01 );
    SDL_FreeSurface( astroidL02 );
    SDL_FreeSurface( astroidL03 );
    SDL_FreeSurface( astroidM01 );
    SDL_FreeSurface( astroidM02 );
    SDL_FreeSurface( astroidM03 );
    SDL_FreeSurface( astroidS01 );
    SDL_FreeSurface( astroidS02 );
    SDL_FreeSurface( astroidS03 );
	
	SDL_FreeSurface( astroidSheetL01 );
	SDL_FreeSurface( astroidSheetM01 );
	SDL_FreeSurface( astroidSheetS01 );
	
	SDL_FreeSurface( astroidDeathL01 );
	SDL_FreeSurface( astroidDeathM01 );
	SDL_FreeSurface( astroidDeathS01 );
	
	SDL_FreeSurface( message );
	 */
    SDL_FreeSurface( menuScreen );
    SDL_FreeSurface( menuTitle );
	
    //Close font
    TTF_CloseFont( fontL );
	TTF_CloseFont( fontS );
	
    //Quit SDL_ttf
    TTF_Quit();
	
    //Quit SDL
    SDL_Quit();
}
