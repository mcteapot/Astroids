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
Astroid::Astroid(SDL_Surface *astroidSurface, SDL_Surface *astroidDeathSurface, SDL_Surface *aScreen, int aIndex,  int aSize, bool create, float x, float y, float r, int lives, int wWin, int hWin) 
: Sprite( astroidSurface, aScreen, aIndex, x, y, lives ) {
	
	spriteDeathSurface = astroidDeathSurface;
	
	wWindow = wWin;
	hWindow = hWin;
	
	float rads = PI / 180;
	//float Speed = .75;
	float a = .6;
	float b = .9;
	float Speed = ((b-a)*((float)rand()/RAND_MAX))+a;
	//initialize random seed
	//srand ( time(0) );
	std::cout << Speed << std::endl;
	type = rand() % 3;
	if (create) {
		positon.rotation = r;
	} else {
		positon.rotation = roat = (((rand() % 360) / 15) * 15);
	}
	
	xSpeed = (sin((positon.rotation+90) * rads)) * Speed;
	ySpeed = (cos((positon.rotation+90) * rads)) * Speed;
	
	size = aSize;
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
	clip = rSurface[type];
	int location = rand() % 5;
	//std::cout << "Locating: " << location << std::endl;
	int randX = rand() % wWindow;
	int randY = rand() % hWindow;
	int clamp = (clip->w)+30;
	if (!create) {
		if (location == 0) {
			//start left
			positon.x = 0-clip->w+10;
			positon.y = (rand() % (hWindow-clamp) + clamp);
		} else if (location == 1) {
			//start top
			positon.x = (rand() % (wWindow-clamp) + clamp);
			positon.y = 0-clip->h+10;
		} else if (location == 2) {
			//start right
			positon.x = wWindow+10;
			positon.y = (rand() % (hWindow-clamp) + clamp);
		} else if (location == 3) {
			//start bottom
			positon.x = (rand() % (wWindow-clamp) + clamp);
			positon.y = hWindow+10;
		} else if (location == 4) {
			positon.x = randX;
			positon.y = randY;
		}
		//std::cout <<"Type: " << type << " X: " << positon.x << " Y: " << positon.y << std::endl;
	}
	
}
//~Astroid();
Astroid::~Astroid() {
	//erase the dying spire
}

//void draw();
void Astroid::draw() {
	
	if (isAlive()) {
		//std::cout << xSpeed << ", " << ySpeed << std::endl;
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
		
		applySurface(positon.x, positon.y, spriteSurface, screen, clip);
	} else {
		applySurface(positon.x, positon.y, spriteDeathSurface, screen, clip);
	}
	
	
}
//void destroy();
void Astroid::destroy() {
	addLives(-1);
	xSpeed = 0;
	ySpeed = 0;
}