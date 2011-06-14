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

#define PI 3.14159265358979323846264

//Headers
#include <string>
#include <iostream>
#include <math.h>
#include <vector>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"


#include "Sprite.h"
#include "Bullet.h"
//#include "Utilities.h"
class Ship : public Sprite {
public:
	//Ship(SDL_Surface *shipSurface, SDL_Surface *shipBoosterSurface, SDL_Surface *shipDeathSurface, SDL_Surface *aScreen, int aIndex, float x = 1, float y = 1, float r = 90, int lives = 3, int wWin = 500, int hWin = 375);
	Ship(SDL_Surface *shipSurface, SDL_Surface *shipBoosterSurface, SDL_Surface *shipDeathSurface, SDL_Surface *bSurface, SDL_Surface *aScreen, int aIndex, std::vector< Bullet> *bullets, float x = 1, float y = 1, float r = 90, int lives = 3, int wWin = 500, int hWin = 375);
	~Ship();

	void keyPress(char c, int numR);
	bool move(float r, SDL_Rect *aClip); 
	void draw();
	void destroy();
	void reSet(); 
protected:
	//Bullet Stuff
	void createBullet();
	SDL_Surface *bulletSurface;
	std::vector< Bullet> *bulletVector;
	int maxBulletCount;
	
	SDL_Surface *tempSurface;
	SDL_Surface *tempSheetSurface;
	SDL_Surface *spriteBoosterSurface;
	SDL_Surface *spriteDeathSurface;
	
		
	SDL_Rect *rSurface[361];
	
	
	
	bool alive;
	
	int rJump;
	int rTempJump;
	int roat;
	
	float xInit;
	float yInit;
	
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
	bool shoot;
	
	int wWindow;
	int hWindow;
	
};


#endif //SHIP_H