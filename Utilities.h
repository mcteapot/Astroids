/*
 *  ApplySurface.h
 *  Astroids
 *
 *  Created by arjun prakash on 6/5/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"



void applySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip );


char initSDLEvents();

void getSDLKeyStates();

#endif //UTILITIES_H