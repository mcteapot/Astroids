/*
 *  Loaders.c
 *  Astroids
 *
 *  Created by arjun prakash on 5/28/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#include "Loaders.h"

//SDL_Surface* loadImage( std::string filename, int alpha ) :
SDL_Surface* loadImage( std::string filename, int alpha ) {
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
	
    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;
	
    //Load the image
    loadedImage = IMG_Load( filename.c_str() );
	
    //If the image loaded
    if( loadedImage != NULL ) {
        //Create an optimized surface
		if (alpha = 0) {
			optimizedImage = SDL_DisplayFormat( loadedImage );
		}
		if (alpha = 1) {
			optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		}
		
        //Free surface
        SDL_FreeSurface( loadedImage );
		
        //If the surface was optimized
        if( optimizedImage != NULL ) {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }
	
    //Return the optimized surface
    return optimizedImage;
}

//applySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
void applySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip) {
    //Holds offsets
    SDL_Rect offset;
	
    //Get offsets
    offset.x = x;
    offset.y = y;
	
    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}


