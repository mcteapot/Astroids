/*
 *  Collision.h
 *  Astroids
 *
 *  Created by arjun prakash on 6/14/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef COLLISION_H
#define COLLISION_H

//Headers
#include <string>
#include <iostream>
#include <math.h>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"

#include "Sprite.h"
#include "Ship.h"
#include "Astroid.h"
#include "Bullet.h"


class Collision {
public:
	Collision();
	~Collision();
protected:
};
#endif	//COLLISION_H