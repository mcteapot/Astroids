/*
 *  Ship.h
 *  Astroids
 *
 *  Created by arjun prakash on 6/7/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef SHIP_H
#define SHIP_H

#define PI 3.14159265

//Headers
#include <string>
#include <iostream>
#include <math.h>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"


#include "Sprite.h"
//#include "Utilities.h"

class Ship : public Sprite {
public:
	Ship(SDL_Surface *shipSurface, SDL_Surface *shipBoosterSurface, SDL_Surface *shipDeathSurface, SDL_Surface *aScreen, int aIndex, float x = 1, float y = 1, float r = 90, int lives = 3);
	~Ship();
	void keyPress(char c, int numR);
	bool move(float r, SDL_Rect *aClip); 
	void draw(); 
protected:
	SDL_Surface *tempSurface;
	SDL_Surface *tempSheetSurface;
	SDL_Surface *spriteBoosterSurface;
	SDL_Surface *spriteDeathSurface;
		
	SDL_Rect *rSurface[361];
	
	int rJump;
	int rTempJump;
	int roat;
	char upKey; 
	char downKey;
	char rightKey;
	char leftKey;
	char spaceKey;
	
	
	float decay;
	float xSpeed;
	float ySpeed;
	float maxSpeed;
	float minSpeed;
	
};


#endif //SHIP_H