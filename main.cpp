
/*
 *  Astroids
 *
 *  Created by arjun prakash on 5/30/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

//Headers
#include <string>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"

#include "Timer.h"
#include "Inits.h"
#include "Loader.h"

//Screen attributes
const int SCREENWIDTH = 640;
const int SCREENHEIGHT = 480;
const int SCREENBPP = 32;

//Frames per second
const int FRAMESPERSECOND = 120;

//MAIN//
int main( int argc, char* args[] ) {
	
    //Init classes
    Timer fps;
	
    //Initialize Window
    initSDLWindow( SCREENWIDTH, SCREENHEIGHT, SCREENBPP );
	
    //Load Files
	loadFiles();
	//Create Text
	createText();

    //GAME LOOP//
    while( run )
    {
        //Start the frame timer
        fps.start();
		
		//Init Events for keyboard 
		initSDLEvents();

        //Apply the background
        applySurface( 0, 0, background, screen, NULL );
		
        //Apply the message
        applySurface( ( SCREENWIDTH - message->w ) / 2, ( ( SCREENHEIGHT + message->h * 2 ) / FRAMESPERSECOND ) * ( frame % FRAMESPERSECOND ) - message->h, message, screen, NULL );
		
        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
		//Set frame rate
		setTimer( fps, FRAMESPERSECOND, frame, true );

    }//END GAME LOOP//
	
    //Clean up
	quitSDL();
	
    return 0;
}//END MAIN//

