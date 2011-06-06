
/*
 *  Astroids
 *
 *  Created by arjun prakash on 5/30/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

//Headers
#include <string>
#include <iostream>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"

//windows
//#include "SDL/SDL_ttf.h"

#include "Timer.h"
#include "Inits.h"
#include "Loader.h"
#include "ApplySurface.h"
#include "Sprite.h"

//Screen attributes
const int SCREENWIDTH = 500;
const int SCREENHEIGHT = 375;
const int SCREENBPP = 32;

//Frames per second
const int FRAMESPERSECOND = 60;

//MAIN//
int main( int argc, char* args[] ) {
	
    //Initialize Window
    initSDLWindow( SCREENWIDTH, SCREENHEIGHT, SCREENBPP );
	
    //Load Files
	loadFiles();
	//Create Text
	createText();
	
	//Init classes
    Timer fps;
	Sprite *astroidLrg01;
	astroidLrg01 = new Sprite(astroidL01, screen, 0, -60, -60, 1);

	
    //GAME LOOP//
    while( run )
    {
        //Start the frame timer
        fps.start();
		
		//Init Events for keyboard 
		initSDLEvents();
		
        //Apply the background
        applySurface( 0, 0, background, screen, NULL );
		//MENU
		if (menu) {
			
			applySurface( ( SCREENWIDTH ) / 4, ( SCREENHEIGHT - message->h ) / 5, menuTitle, screen, NULL );
			applySurface( (( SCREENWIDTH ) / 24)*5.5, (( SCREENHEIGHT - message->h ) / 5)*4, menuScreen, screen, NULL );
			if (initSDLEvents() == 'g') {
				menu = 0;
				game = 1;
			}
	
		}//MENU END
		//GAME
		if (game) {
			//Apply the message
			applySurface( ( SCREENWIDTH - message->w ) / 2, ( ( SCREENHEIGHT + message->h * 2 ) / FRAMESPERSECOND ) * ( frame % FRAMESPERSECOND ) - message->h, message, screen, NULL );
			
			//Apply the surface
			astroidLrg01->draw(1,.6);	
		}//GAME END

        //Update the screen
        if( SDL_Flip( screen ) == -1 ) {
            return 1;
        }
		//Set frame rate
		setTimer( fps, FRAMESPERSECOND, frame, true );
		
    }//END GAME LOOP//
	
    //Clean up
	quitSDL();
	
    return 0;
}//END MAIN//
