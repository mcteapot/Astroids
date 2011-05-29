/*
 *  Astroids
 *
 *  Created by arjun prakash on 5/28/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

//IMPORTS   
#include <iostream>
#include <string>
#include <math.h>

#include "SDL/SDL.h"
#include "Inits.h"


//MAIN//
int main(int argc, char *argv[])
{
	//Init SDL Window
	initSDLWindow(500, 375, 32);
	//Load Files
	//loadFiles();
	//MAIN GAME LOOP
	while ( run ) {
		//Init SDL events
		initSDLEvents();
	}
	
	//Init SDL Quit
	initSDLCleanUp();
	return(0);
}
//MAIN END//