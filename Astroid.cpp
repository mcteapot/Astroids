/*
 *  Astroid.cpp
 *  Astroids
 *
 *  Created by arjun prakash on 6/12/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#include "Astroid.h"

//Astroid(SDL_Surface *astroidSurface, SDL_Surface *astroidDeathSurface, SDL_Surface *aScreen, int aIndex,  int siz = 3, float x = 1, float y = 1, float r = 90, int lives = 1, int wWin = 500, int hWin = 375);
Astroid::Astroid(SDL_Surface *astroidSurface, SDL_Surface *astroidDeathSurface, SDL_Surface *aScreen, int aIndex,  int siz, float x, float y, float r, int lives, int wWin, int hWin) 
	: Sprite( astroidSurface, aScreen, aIndex, x, y, lives ) {
		
		spriteDeathSurface = astroidDeathSurface;
		
		wWindow = wWin;
		hWindow = hWin;
		
		float rads = PI / 180;
		int Speed = 0;
		
		//initialize random seed
		srand ( time(NULL) );
		
		type = rand() % 3;
		positon.rotation = roat = (((rand() % 360) / 15) * 15);
		
		xSpeed = (sin((positon.rotation+90) * rads)) + Speed;
		ySpeed = (cos((positon.rotation+90) * rads)) + Speed;
		
		size = siz;
		if (size == 3) {
			classID = ASTROIDL_CLASSID;
			for (int i = 0; i < 3; i++) {
				rSurface[i] = new SDL_Rect;
				rSurface[i]->x = (68*i);
				rSurface[i]->y = 0;
				rSurface[i]->w = 68;
				rSurface[i]->h = 68;
			}
		} else if (size == 2) {
			classID = ASTROIDM_CLASSID;
			for (int i = 0; i < 3; i++) {
				rSurface[i] = new SDL_Rect;
				rSurface[i]->x = (34*i);
				rSurface[i]->y = 0;
				rSurface[i]->w = 34;
				rSurface[i]->h = 34;
			}
		} else if (size == 1) {
			classID = ASTROIDS_CLASSID;
			for (int i = 0; i < 3; i++) {
				rSurface[i] = new SDL_Rect;
				rSurface[i]->x = (16*i);
				rSurface[i]->y = 0;
				rSurface[i]->w = 16;
				rSurface[i]->h = 16;
			}
		}
		clip = rSurface[1];
		
}
//~Astroid();
Astroid::~Astroid() {
	//erase the dying spire
}

//void draw();
void Astroid::draw() {
	std::cout << xSpeed << ", " << ySpeed << std::endl;
	positon.x += xSpeed;
	positon.y += ySpeed;
	//draw sprite
	if (positon.x < 0-clip->w) {
		positon.x = wWindow;
	}
	if (positon.x > wWindow) {
		positon.x = 0-clip->w;
	}
	if (positon.y > hWindow) {
		positon.y = 0-clip->h;
	}
	if (positon.y < 0-clip->h) {
		positon.y = hWindow;
	}
	//applySurface(positon.x, positon.y, spriteSurface, screen, clip);
	applySurface(positon.x, positon.y, spriteSurface, screen, clip);
}