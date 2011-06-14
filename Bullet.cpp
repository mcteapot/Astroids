/*
 *  Bullet.cpp
 *  Astroids
 *
 *  Created by arjun prakash on 6/13/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#include "Bullet.h"
Bullet::Bullet() : Sprite( NULL, NULL, 0, 0, 0, 1 ) {
}
Bullet::Bullet(SDL_Surface *astroidSurface, SDL_Surface *aScreen, int aIndex, bool create, float x, float y, float xS, float yS, float r, int lives, int wWin, int hWin)
: Sprite( astroidSurface, aScreen, aIndex, x, y, lives ) { 
	wWindow = wWin;
	hWindow = hWin;
	alive =  create;
	positon.rotation = r;
	positon.x = x;
	positon.y = y;
	
	float rads = PI / 180;
	float Speed = 6;
	float vx = (sin((positon.rotation+90) * rads))*Speed;
	float vy = (cos((positon.rotation+90) * rads))*Speed;
	positon.x = x;
	positon.y = y;
	xSpeed = vx;
	ySpeed = vy;
	//xSpeed = xS * Speed;
	//ySpeed = yS * Speed;

	startFrame = 0;
	
	classID = BULLET_CLASSID;
}

Bullet::~Bullet() {

}

void Bullet::draw() {
	positon.x += xSpeed;
	positon.y += ySpeed;
	//draw sprite
	if (positon.x < 0-spriteSurface->w) {
		//destory();
	}
	if (positon.x > wWindow) {
		//destory();
	}
	if (positon.y > hWindow) {
		//destory();
	}
	if (positon.y < 0-spriteSurface->h) {
		//destory();
	}
	if (alive) {
		//applySurface(positon.x, positon.y, spriteSurface, screen, clip);
		applySurface(positon.x, positon.y, spriteSurface, screen, NULL);
	}else {
		//applySurface(positon.x, positon.y, spriteSurface, screen, clip);
		applySurface(positon.x, positon.y, NULL, screen, NULL);
	}
}

void Bullet::fire(float x, float y, float xS, float yS, int frame) {
	alive= true;
	startFrame = frame;
	positon.x = x;
	positon.y = y;
	xSpeed = 0;
	ySpeed = 0;
}
bool Bullet::isFired() {
	return alive;
}
void Bullet::destory() {
	alive= false;
	startFrame = 0;
	positon.x = 1;
	positon.y = 1;
	xSpeed = 0;
	ySpeed = 0;
	positon.rotation = 0;

}
