/*
 *  Sprite.cpp
 *  Astroids
 *
 *  Created by arjun prakash on 6/5/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#include "Sprite.h"

//Sprite(SDL_Surface *aSurface , int aIndex, float x = 1, float y = 1, int lives = 1);
Sprite::Sprite(SDL_Surface *aSurface, SDL_Surface *aScreen, int aIndex, float x, float y, int lives) {

	spriteSurface = aSurface;
	screen = aScreen;
	deadSurface =  NULL;
	clip = NULL;
	positon.x = x;
	positon.y = y;
	positon.rotation = 90;
	spriteIndex = aIndex;
	
	numLives = lives;
	
	classID = SPRITE_CLASSID;
	
	keystates = SDL_GetKeyState( NULL );

}
//~Sprite();
Sprite::~Sprite() {
	//erase the dying spire
}




//vect getPosition();
vect Sprite::getPosition() {

	return positon;
}
//float getX();
float Sprite::getX() {
	return positon.x;
}
//float getY();
float Sprite::getY() {
	return positon.y;
}
//float getRotation();
float Sprite::getRotation() {
	return positon.rotation;
}




//virtual void addLives(int num = 1);
void Sprite::addLives(int num) {
	numLives +=  num;
}
//int getLives();
int Sprite::getLives() {
	return numLives;
}
//bool isAlive();
bool Sprite::isAlive() {
	return (numLives > 0); 
}

//virtual bool move(float x, float y, float r = 0);
bool Sprite::move(float x, float y, float r, SDL_Rect *aClip) {
	positon.x += x;
	positon.y += y;
	positon.rotation += r;
	if (positon.rotation > 359) {
		positon.rotation = 0;
	}
	if (positon.rotation < 0) {
		positon.rotation = 359;
	}
	clip = aClip;
	return true;
}
//void draw(float x, float y, float r = 0);
void Sprite::draw(float x, float y, float r) {
	//move(x,y,r);
	//draw sprite
	if (numLives) {
		applySurface(positon.x, positon.y, spriteSurface, screen, clip);
	}else {
		applySurface(positon.x, positon.y, deadSurface, screen, clip);
	}

}

//ADD-ON
SDL_Surface* Sprite::getSpriteSurface()
{
    return spriteSurface;
}
//OPERATOR OVERLOADING
bool Sprite::operator<(const Sprite &rhs)
{
    return (this->positon.x < rhs.positon.x);
}

bool Sprite::operator>(const Sprite &rhs)
{
    return (this->positon.x > rhs.positon.x);
}



