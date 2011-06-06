/*
 *  ApplySurface.c
 *  Astroids
 *
 *  Created by arjun prakash on 6/5/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#include "ApplySurface.h"

//void applySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip ) : apply surface
void applySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip ) {
    //Holds offsets
    SDL_Rect offset;
	
    //Get offsets
    offset.x = x;
    offset.y = y;
	
    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
