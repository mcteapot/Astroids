/*
 *  Timer.h
 *  Astroids
 *
 *  Created by arjun prakash on 5/30/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef TIMER_H
#define TIMER_H

//The headers
#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"

class Timer {
private:
    //The clock time when the timer started
    int startTicks;
	
    //The ticks stored when the timer was paused
    int pausedTicks;
	
    //The timer status
    bool paused;
    bool started;
	
public:
    //Initializes variables
    Timer();
	
    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();
	
    //Gets the timer's time
	int getTicks();
	
    //Checks the status of the timer
	bool isStarted();
    bool isPaused();
};


void setTimer( Timer &fps,int FRAMES_PER_SECOND, int &frame, bool cap );


#endif //TIMER_H