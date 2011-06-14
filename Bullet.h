/*
 *  Bullet.h
 *  Astroids
 *
 *  Created by arjun prakash on 6/13/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef BULLET_H
#define BULLET_H

#define PI 3.14159265358979323846264

//Headers
#include <string>
#include <iostream>
#include <math.h>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"


#include "Sprite.h"
//#include "Utilities.h"


class Bullet : public Sprite {
public:
	Bullet();
	Bullet(SDL_Surface *astroidSurface, SDL_Surface *aScreen, int aIndex, bool create = false, float x = 1, float y = 1, float xS = 1, float yS = 1, float r = 90, int lives = 1, int wWin = 500, int hWin = 375);
	~Bullet();
	
	void draw();
	void fire(float x, float y,float xS,float yS, int frame);
	bool isFired();
	void destory();
	
protected:
	int roat;
	bool alive;
	
	float Speed;
	int startFrame;
	
	int wWindow;
	int hWindow;
	float xSpeed;
	float ySpeed;
};

#endif //BULLET_H
