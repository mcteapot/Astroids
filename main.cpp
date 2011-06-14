
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
#include <stdlib.h>
#include <ctime>
#include <vector>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"
//#include "SDL_gfx/SDL_rotozoom.h"

//windows
//#include "SDL/SDL_ttf.h"

#include "Timer.h"
#include "Inits.h"
#include "Loader.h"
#include "Utilities.h"
#include "Sprite.h"
#include "Ship.h"
#include "Astroid.h"
#include "Level.h"

//Screen attributes
const int SCREENWIDTH = 500;
const int SCREENHEIGHT = 375;
const int SCREENBPP = 32;

//Frames per second
const int FRAMESPERSECOND = 60;



//MAIN//
int main( int argc, char* args[] ) {
	//Init Rand to clock 
	srand ( time(NULL) );	
    //Initialize Window
    initSDLWindow( SCREENWIDTH, SCREENHEIGHT, SCREENBPP );
	
    //Load Files
	loadFiles();
	//Create Text
	createText();
	
	//Init classes
    Timer fps;
	Level *theLevel;


    //GAME LOOP//
    while( run ) {
        //Start the frame timer
        fps.start();

		//Init Events for keyboard 
		initSDLEvents();
		
        //Apply the background
        applySurface( 0, 0, background, screen, NULL );
		//MENU
		if ( menu ) {
			applySurface( ( SCREENWIDTH - menuTitle->w ) / 2, (SCREENHEIGHT / 5), menuTitle, screen, NULL );
			applySurface( ( SCREENWIDTH - menuScreen->w ) / 2, (SCREENHEIGHT / 6)*4, menuScreen, screen, NULL );
			if (initSDLEvents() == 'e') {
				menu = 0;
				game = 1;
				theLevel = new Level(screen, SCREENWIDTH, SCREENHEIGHT);
			}
	
		}//MENU END
		//GAME
		if ( game ) {
			
			if ((theLevel->play(frame)) == true) {
				menu = 1;
				game = 0;
				delete theLevel;
			}
			
		}//GAME END

        //Update the screen
        if( SDL_Flip( screen ) == -1 ) {
            return 1;
        }
		//Set frame rate
		setTimer( fps, FRAMESPERSECOND, frame, true );
		
		//check for quit
		checkQuit(initSDLEvents());	
    }//GAME LOOP END//
	
    //Clean up
	quitSDL();
	
    return 0;
}//END MAIN//
