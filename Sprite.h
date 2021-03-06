/*
 *  Sprite.h
 *  Astroids
 *
 *  Created by arjun prakash on 6/5/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef SPRITE_H
#define SPRITE_H

//Headers
#include <string>
#include <iostream>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"

#include "Utilities.h"

enum  {
	SPRITE_CLASSID,
	SHIP_CLASSID,
	ASTROIDL_CLASSID,
	ASTROIDM_CLASSID,
	ASTROIDS_CLASSID,
	BULLET_CLASSID,
};

struct vect {
	float x;
	float y;
	float rotation;
};

class Sprite {
	

public:
	Sprite( SDL_Surface *aSurface, SDL_Surface *aScreen, int aIndex, float x = 1, float y = 1, int lives = 1 );
	~Sprite();
	
	vect getPosition();
	float getX();
	float getY();
	float getRotation();
	
	virtual void addLives( int num = 1 );
	int getLives();
	bool isAlive();
	
	virtual bool move( float x, float y, float r = 0, SDL_Rect *aClip = NULL  );
	void draw( float x = 0, float y = 0, float r = 0 );
	
	//ADD-ONS
	SDL_Surface* getSpriteSurface();
	SDL_Rect* getSpriteClip();
	bool operator<(const Sprite &rhs);
	bool operator>(const Sprite &rhs);

protected:
	SDL_Surface *spriteSurface;
	SDL_Surface *screen;
	SDL_Surface *deadSurface;
	
	SDL_Rect *clip;
	
	Uint8 *keystates;
	
	vect positon;
	int spriteIndex;
	int numLives;
	int classID;
	
	
	
	
};

#endif //SPRITE_H