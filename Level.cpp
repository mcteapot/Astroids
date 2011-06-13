/*
 *  Level.cpp
 *  Astroids
 *
 *  Created by arjun prakash on 6/12/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#include "Level.h"

Level::Level(SDL_Surface *aScreen, int w, int h) {
	//set Data
	screen = aScreen;
	wWindow = w;
	hWindow = h;
	intScore = 0000;
	theLevel = 1;
	scoreToText(intScore);
	gameOver = false;
	//set color
	SDL_Color whiteColor = { 255, 255, 255 };
	textColor = whiteColor;
	//set Methods
	initAssets();
	loadLevel();
	createText();
}

Level::~Level() {
	unloadLevel();
}
//bool play()
bool Level::play() {
	//Apply the surface
	displyUI(aShip->getLives());
	aShip->keyPress(initSDLEvents(), 1);
	aShip->draw();
	return false;

}
//void displyUI(int lives);
void Level::displyUI(int lives) {
	for (int i = 0; i < lives; i++) {
		aShipLives[i]->draw();
	}

}
//void scoreToText(int i);
void Level::scoreToText(int i) {
	std::stringstream out;
	out << intScore;
	stringScore = out.str();

}
//void createText();
void Level::createText() {
	
    //Generate the message surface
    textScore = TTF_RenderText_Solid( fontS, stringScore.c_str(), textColor );
	textGameOver = TTF_RenderText_Solid( fontL, "GAME OVER", textColor );
	
}
//void loadLevel();
void Level::loadLevel() {
	
	aShip = new Ship(shipSheet01, shipSheetBooster01, shipDeath01, screen, 1, (( wWindow - 32 ) / 2), (( hWindow-32) / 2), 90, 3);
	for (int i = 0; i < aShip->getLives(); i++) {
		aShipLives[i] = new Sprite(shipLife01, screen, 1, 10+(32*i), 10);
	}
}

//void initAssets();
void Level::initAssets() {
	shipLife01 = loadImage( (char *)"Astroids.app/Contents/Resources/shipLife.png", 1 );
	shipDeath01 = loadImage( (char *)"Astroids.app/Contents/Resources/shipDeadth.png", 1 );
	shipSheet01 = loadImage( (char *)"Astroids.app/Contents/Resources/shipSheetA.png", 1 );
	shipSheetBooster01 = loadImage( (char *)"Astroids.app/Contents/Resources/shipSheetBoosterA.png", 1 );
	
	bullet01 = loadImage( (char *)"Astroids.app/Contents/Resources/bullet.png", 0 );
	
	astroidSheetL01 = loadImage( (char *)"Astroids.app/Contents/Resources/astroidsSheetLA.png", 1 );
	astroidSheetM01 = loadImage( (char *)"Astroids.app/Contents/Resources/astroidsSheetMA.png", 1 );
	astroidSheetS01 = loadImage( (char *)"Astroids.app/Contents/Resources/astroidsSheetSA.png", 1 );
	
	astroidDeathL01 = loadImage( (char *)"Astroids.app/Contents/Resources/astroidDeathLA.png", 1 );
	astroidDeathM01 = loadImage( (char *)"Astroids.app/Contents/Resources/astroidDeathMA.png", 1 );
	astroidDeathS01 = loadImage( (char *)"Astroids.app/Contents/Resources/astroidDeathSA.png", 1 );
	
	//Load fonts
    fontL = TTF_OpenFont( "Astroids.app/Contents/Resources/Arial.ttf", 50 );
	fontS = TTF_OpenFont( "Astroids.app/Contents/Resources/Arial.ttf", 30 );	

}
//void unloadLevel();
void Level::unloadLevel() {
	SDL_FreeSurface( shipDeath01 );
	
	SDL_FreeSurface( shipSheet01 );
	SDL_FreeSurface( shipSheetBooster01 );
	
	SDL_FreeSurface( astroidSheetL01 );
	SDL_FreeSurface( astroidSheetM01 );
	SDL_FreeSurface( astroidSheetS01 );
	
	SDL_FreeSurface( astroidDeathL01 );
	SDL_FreeSurface( astroidDeathM01 );
	SDL_FreeSurface( astroidDeathS01 );
	
	SDL_FreeSurface( textScore );
	SDL_FreeSurface( textGameOver );
}

//SDL_Surface *loadImage( char *filename ) : Load image
SDL_Surface *Level::loadImage( char *filename,  int alpha ) {
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