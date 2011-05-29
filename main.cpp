
/* Simple program:  Create a blank window, wait for keypress, quit.

   Please see the SDL documentation for details on using the SDL API:
   /Developer/Documentation/SDL/docs.html
*/
//IMPORTS   
#include <iostream>
#include <string>
#include <math.h>

#include "SDL/SDL.h"
#include "Inits.h"
#include "Loaders.h"

//MAIN//
int main(int argc, char *argv[])
{
	//Init SDL Window
	initSDLWindow(500, 375);
	
	//MAIN GAME LOOP
	while ( !done ) {
		//Init SDL events
		initSDLEvents();
	}
	
	//Init SDL Quit
	initSDLCleanUp();
	return(0);
}
//MAIN END//