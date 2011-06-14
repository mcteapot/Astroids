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
Ship::Ship(SDL_Surface *shipSurface, SDL_Surface *shipBoosterSurface, SDL_Surface *shipDeathSurface, SDL_Surface *bSurface, SDL_Surface *aScreen, int aIndex, std::vector< Bullet> *bullets, float x, float y, float r, int lives, int wWin, int hWin)
	: Sprite( shipSurface, aScreen, aIndex, x, y, lives ) {
		
		//tempSheetSurface = shipSheetSurface;
		tempSurface = shipSurface;
		spriteBoosterSurface = shipBoosterSurface;
		spriteDeathSurface = shipDeathSurface;
		
		bulletSurface = bSurface;
		bulletVector = bullets;
		
		upKey = 'u';
		downKey = 'd';
		rightKey = 'r';
		leftKey = 'l';
		spaceKey = 's';
		
		alive = true;
		
		roat = positon.rotation = r;
		
		rJump = 5;
		rTempJump = 0;
		
		xInit = x;
		yInit = y;
		
		decay = .99;
		xSpeed = 0;
		ySpeed = 0;
		maxSpeed = 17;
		minSpeed = -17;
		shoot = true;
		
		wWindow = wWin;
		hWindow = hWin;
		
		maxBulletCount = 15;

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
	//erase the dying spire
}




//void keyPress(char c, int numR) 
void Ship::keyPress(char c, int numR) {
	
	float rads = PI / 180;
	float vx = sin((positon.rotation+90) * rads);
	float vy = cos((positon.rotation+90) * rads);
	if (alive) {
		if (keystates[ SDLK_UP ]) {
			if ((xSpeed != minSpeed) || (xSpeed != maxSpeed)) {
				xSpeed += vx/6;
			}
			if ((ySpeed != minSpeed) || (ySpeed != maxSpeed)) {
				ySpeed += vy/6;
			}
			
			move( 0, rSurface[(int)(positon.rotation)]);
			spriteSurface = spriteBoosterSurface;
		}
		if (keystates[ SDLK_DOWN ]) {
			move( 0, rSurface[(int)(positon.rotation)]);
			//debug
			//destroy();
		}
		if (keystates[ SDLK_RIGHT ]) {
			//std::cout << ",r: " << positon.rotation << std::endl;
			rTempJump += rJump;
			if (rTempJump == 15) {
				move( rTempJump, rSurface[(int)(positon.rotation)]);
				rTempJump = 0;
				
			}
			move( 0, rSurface[(int)(positon.rotation)]);
			if (keystates[ SDLK_UP ]) {
				spriteSurface = spriteBoosterSurface;
			} else {
				spriteSurface = tempSurface;
			}
			
		}
		if (keystates[ SDLK_LEFT ]) {
			//std::cout << ",r: " << positon.rotation << std::endl;
			rTempJump += rJump;
			if (rTempJump == 15) {
				move( -rTempJump, rSurface[(int)(positon.rotation)]);
				rTempJump = 0;
				
			}
			move( 0, rSurface[(int)(positon.rotation)]);
			if (keystates[ SDLK_UP ]) {
				spriteSurface = spriteBoosterSurface;
			} else {
				spriteSurface = tempSurface;
			}
		}
		if (keystates[ SDLK_SPACE ]) {
			if (shoot) {
				//std::cout << "pew " << std::endl;
				createBullet(); 
				shoot = false;
			}
			if (keystates[ SDLK_UP ]) {
				spriteSurface = spriteBoosterSurface;
			} else {
				spriteSurface = tempSurface;
			}
		}
		if (!( (keystates[ SDLK_UP ]) || (keystates[ SDLK_DOWN ]) || (keystates[ SDLK_RIGHT ]) || (keystates[ SDLK_LEFT ]) )) {
			move( 0,rSurface[(int)(positon.rotation)]);
			spriteSurface = tempSurface;
			
		}
		if (!(keystates[ SDLK_UP ])) {
			xSpeed *= decay;
			ySpeed *= decay;
		}
		if (!(keystates[ SDLK_SPACE ])) {
			shoot = true;
			
		}
	} else {
		if (keystates[ SDLK_UP ]) {
			//debug
			//reSet();
		}
	}



}

//bool move(float r, SDL_Rect *aClip);
bool Ship::move(float r, SDL_Rect *aClip) {
	
	//std::cout << xSpeed << ", " << ySpeed << std::endl;
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

//void draw();
void Ship::draw() {
	
	//draw sprite
	if (positon.x < 0-rSurface[(int)(positon.rotation)]->w) {
		positon.x = wWindow;
	}
	if (positon.x > wWindow) {
		positon.x = 0-rSurface[(int)(positon.rotation)]->w;
	}
	if (positon.y > hWindow) {
		positon.y = 0-rSurface[(int)(positon.rotation)]->h;
	}
	if (positon.y < 0-rSurface[(int)(positon.rotation)]->h) {
		positon.y = hWindow;
	}
	if (alive) {
		//applySurface(positon.x, positon.y, spriteSurface, screen, clip);
		//std::cout << "working" << std::endl;
		applySurface(positon.x, positon.y, spriteSurface, screen, clip);
	}else {
		//applySurface(positon.x, positon.y, spriteSurface, screen, clip);
		applySurface(positon.x, positon.y, spriteDeathSurface, screen, NULL);
	}

}
//void destroy();
void Ship::destroy() {
	addLives(-1);
	alive = false;
	xSpeed = 0;
	ySpeed = 0;
}
//void reSet();
void Ship::reSet() {
	positon.rotation = 90;
	positon.x = xInit;
	positon.y = yInit;
	alive = true;
}

//void createBullet();
void Ship::createBullet() {
	//debug
	//std::cout << bulletVector->size() << std::endl;
	if (bulletVector->size() < maxBulletCount ) {
		int newBulletCount = bulletVector->size()+1;
		bulletVector->push_back(Bullet(bulletSurface, screen, newBulletCount, true, (positon.x)+(rSurface[(int)(positon.rotation)]->w/2 )-1, (positon.y)+(rSurface[(int)(positon.rotation)]->h/2)-1, xSpeed, ySpeed, positon.rotation));
		//std::cout << "pew " << std::endl;
	}
	//bulletVector->push_back
	
}

