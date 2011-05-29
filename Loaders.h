/*
 *  Loaders.h
 *  Astroids
 *
 *  Created by arjun prakash on 5/28/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef LOADERS_H
#define LOADERS_H

#include <string>
#include <math.h>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"


SDL_Surface* loadImage( std::string filename, int alpha );

void applySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );



#endif //LOADERS_H