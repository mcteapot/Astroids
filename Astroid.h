/*
 *  Astroid.h
 *  Astroids
 *
 *  Created by arjun prakash on 6/12/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef ASTROID_H
#define ASTROID_H

#define PI 3.14159265358979323846264

//Headers
#include <string>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"

#include "Sprite.h"

class Astroid : public Sprite {
public:	
	Astroid(SDL_Surface *astroidSurface, SDL_Surface *astroidDeathSurface, SDL_Surface *aScreen, int aIndex,  int siz = 3, float x = 1, float y = 1, float r = 90, int lives = 1, int wWin = 500, int hWin = 375);
	~Astroid();
	
	void draw(); 
protected:
	//SDL_Surface *spriteSheetSurface;
	SDL_Surface *spriteDeathSurface;
	
	SDL_Rect *rSurface[2];
	
	int size;
	int roat;
	int type;
	
	int wWindow;
	int hWindow;
	float xSpeed;
	float ySpeed;
};

#endif //ASTROID_H