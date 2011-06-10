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
		//tempSheetSurface = shipSheetSurface;
		tempSurface = shipSurface;
		spriteBoosterSurface = shipBoosterSurface;
		spriteDeathSurface = shipDeathSurface;
		
		upKey = 'u';
		downKey = 'd';
		rightKey = 'r';
		leftKey = 'l';
		spaceKey = 's';
		
		roat = positon.rotation = r;
		
		rJump = 5;
		rTempJump = 0;
		
		decay = .99;
		xSpeed = 0;
		ySpeed = 0;
		maxSpeed = 17;
		minSpeed = -17;
		

		classID = SHIP_CLASSID;

		for (int i = 0; i < 361; i+=1) {
			rSurface[i] = new SDL_Rect;
			rSurface[i]->x = ((i/15)*32);
			rSurface[i]->y = 0;
			rSurface[i]->w = 32;
			rSurface[i]->h = 32;
			if (i ==360) {
				rSurface[i] = new SDL_Rect;
				rSurface[i]->x = ((0/15)*32);
				rSurface[i]->y = 0;
				rSurface[i]->w = 32;
				rSurface[i]->h = 32;
			}
		}
}

//~Ship();
Ship::~Ship() {

}




//keyPress(char c); 
void Ship::keyPress(char c, int numR) {
	
	float rads = PI / 180;
	float vx = sin((positon.rotation+90) * rads);
	float vy = cos((positon.rotation+90) * rads);
	
	if (keystates[ SDLK_UP ]) {
		if (xSpeed != minSpeed) {
			xSpeed += vx/3;
		}
		if (ySpeed != minSpeed) {
			ySpeed += vy/3;
		}
		
		move( 0, rSurface[(int)(positon.rotation)]);
		spriteSurface = spriteBoosterSurface;
	}
	if (keystates[ SDLK_DOWN ]) {

	}
	if (keystates[ SDLK_RIGHT ]) {
		std::cout << ",r: " << positon.rotation << std::endl;
		rTempJump += rJump;
		if (rTempJump == 15) {
			move( rTempJump, rSurface[(int)(positon.rotation)]);
			rTempJump = 0;

		}
		spriteSurface = tempSurface;
	}
	if (keystates[ SDLK_LEFT ]) {
		std::cout << ",r: " << positon.rotation << std::endl;
		rTempJump += rJump;
		if (rTempJump == 15) {
			move( -rTempJump, rSurface[(int)(positon.rotation)]);
			rTempJump = 0;

		}
		spriteSurface = tempSurface;
	}
	if (keystates[ SDLK_SPACE ]) {
		std::cout << "pew " << std::endl;
	}
	if (!( (keystates[ SDLK_UP ]) || (keystates[ SDLK_DOWN ]) || (keystates[ SDLK_RIGHT ]) || (keystates[ SDLK_LEFT ]) )) {
		move( 0,rSurface[(int)(positon.rotation)]);
		spriteSurface = tempSurface;
		
	}
	if (!(keystates[ SDLK_UP ])) {
		xSpeed *= decay;
		ySpeed *= decay;
	}

}

//bool move(float r, SDL_Rect *aClip);
bool Ship::move(float r, SDL_Rect *aClip) {
	positon.x += xSpeed;
	positon.y += ySpeed;
	positon.rotation += r;
	if (positon.rotation > 360) {
		positon.rotation = 0;
	}
	if (positon.rotation < 0) {
		positon.rotation = 360;
	}
	clip = aClip;
	return true;
}

//void draw(float x, float y, float r = 0);
void Ship::draw() {
	//draw sprite
	applySurface(positon.x, positon.y, spriteSurface, screen, clip);
}

