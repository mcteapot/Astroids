/*
 *  Ship.cpp
 *  Astroids
 *
 *  Created by arjun prakash on 6/7/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#include "Ship.h"

//Ship(SDL_Surface *aSurface, SDL_Surface *aScreen, int aIndex, float x, float y, int lives);
Ship::Ship(SDL_Surface *shipSurface, SDL_Surface *shipBoosterSurface, SDL_Surface *shipDeathSurface, SDL_Surface *aScreen, int aIndex, float x, float y, float r, int lives)
	: Sprite( shipSurface, aScreen, aIndex, x, y, lives ) {
		tempSurface = shipSurface;
		spriteBoosterSurface = shipBoosterSurface;
		spriteDeathSurface = shipDeathSurface;
		
		upKey = 'u';
		downKey = 'd';
		rightKey = 'r';
		leftKey = 'l';
		spaceKey = 's';
		
		roat = positon.rotation = r;
		
		rJump = 10;
		
		classID = SHIP_CLASSID;
		//rotateSpriteBoostSurface = rotozoomSurface(tempSurface, 255.0, 1.0, 1.0);
		
		//rotateSpriteBoostSurface = rotozoomSurface(tempSurface, 225., 1, 1);
		for (int i = 0; i < 360; i+=1) {
			//rotateSpriteSurface[i] = 
			//rotateSpriteBoostSurface[i] = rotozoomSurface(shipBoosterSurface, i, 1, 1);
			
			rotateSpriteSurface[i] = rotozoomSurface(shipSurface, i, 1, 1);
			rotateSpriteBoostSurface[i] = rotozoomSurface(shipBoosterSurface, i, 1, 1);
		}
}

//~Ship();
Ship::~Ship() {

}




//keyPress(char c); 
void Ship::keyPress(char c, int numR) {

	if (keystates[ SDLK_UP ]) {
		move(0, -1, 0);
		spriteSurface = rotateSpriteBoostSurface[(int)(positon.rotation)];
	}
	if (keystates[ SDLK_DOWN ]) {
		move(0, 1, 0);
		spriteSurface = rotateSpriteBoostSurface[(int)(positon.rotation)];
	}
	if (keystates[ SDLK_RIGHT ]) {
		std::cout << ",r: " << positon.rotation << std::endl;
		move(0, 0, rJump);
		spriteSurface = rotateSpriteBoostSurface[(int)(positon.rotation)];
	}
	if (keystates[ SDLK_LEFT ]) {
		std::cout << ",r: " << positon.rotation << std::endl;
		move(0, 0, -rJump);
		spriteSurface = rotateSpriteBoostSurface[(int)(positon.rotation)];
	}
	if (keystates[ SDLK_SPACE ]) {
		std::cout << "pew " << std::endl;
	}
	if (!( (keystates[ SDLK_UP ]) || (keystates[ SDLK_DOWN ]) || (keystates[ SDLK_RIGHT ]) || (keystates[ SDLK_LEFT ]) )) {
		spriteSurface = rotateSpriteSurface[(int)(positon.rotation)];

	}

}