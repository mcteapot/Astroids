/*
 *  Level.h
 *  Astroids
 *
 *  Created by arjun prakash on 6/12/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef LEVEL_H
#define LEVEL_H

//Headers
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"

#include "Utilities.h"
#include "Sprite.h"
#include "Ship.h"
#include "Astroid.h"
#include "Bullet.h"
#include "Collision.h"


class Level {
public:
	Level(SDL_Surface *aScreen, int w, int h);
	~Level();
	
	bool play(int frame);
	
protected:
	//methods game
	void displyUI(int lives);
	void scoreToText(int i);
	void drawBullets();
	void boundBullets();
	void drawAstroids();
	void checkCollision();
	void endGame();
	
	//methods loaders
	void createText();
	void createAstroids();
	void loadLevel();
	void initAssets();
	void unloadLevel();
	SDL_Surface *loadImage( char *filename,  int alpha );
	
	
	//onject store
	std::vector<Bullet> bulletVector;
	std::vector<Astroid> astroidVector;
	
	//data
	int intScore;
	std::string stringScore;
	
	bool gameOver;
	int wWindow;
	int hWindow;
	int theLevel;
	int astroidNumber;
	
	int currentFrame;
	int tempFrame;
	
	//Gameonjects
	Ship *aShip;
	Sprite *aShipLives[3];
	
	//Astroid *aAstroidL01;
	
	
	//main screen
	SDL_Surface *screen;
	
	//SDL Image Surfaec
	SDL_Surface *shipDeath01;
	SDL_Surface *shipLife01;
	SDL_Surface *shipSheet01;
	SDL_Surface *shipSheetBooster01;
	
	SDL_Surface *bullet01;
	
	SDL_Surface *astroidSheetL01;
	SDL_Surface *astroidSheetM01;
	SDL_Surface *astroidSheetS01;
	
	SDL_Surface *astroidDeathL01;
	SDL_Surface *astroidDeathM01;
	SDL_Surface *astroidDeathS01;
	
	//SDL Text Surface
	SDL_Surface *textScore;
	SDL_Surface *textGameOver;
	
	//SDL Font
	TTF_Font *fontL;
	TTF_Font *fontS;
};


#endif //LEVEL_H