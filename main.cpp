

//The headers
#include <string>

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"


#include "Timer.h"
#include "Inits.h"
#include "Loader.h"

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The frames per second
const int FRAMES_PER_SECOND = 20;

//MAIN//
int main( int argc, char* args[] ) {
	
    //Init classes
    Timer fps;
	
    //Initialize Window
    initSDLWindow( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP );
	
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
        applySurface( ( SCREEN_WIDTH - message->w ) / 2, ( ( SCREEN_HEIGHT + message->h * 2 ) / FRAMES_PER_SECOND ) * ( frame % FRAMES_PER_SECOND ) - message->h, message, screen, NULL );
		
        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
		//Set frame rate
		setTimer( fps, FRAMES_PER_SECOND, frame, true );

    }//END GAME LOOP//
	
    //Clean up
	quitSDL();
	
    return 0;
}//END MAIN//

