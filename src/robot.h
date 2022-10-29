#include "main.h" // PROS API

/**
 *  __ ______ __   ___   ___          
 * /_ |____  / /  / _ \ / _ \   /\    
 *  | |   / / /_ | (_) | (_) | /  \   
 *  | |  / / '_ \ > _ < > _ < / /\ \  
 *  | | / /| (_) | (_) | (_) / ____ \ 
 *  |_|/_/  \___/ \___/ \___/_/    \_\
 *     CORONA DEL SOL HIGH SCHOOL
 */

// set up smart ports
#define LEFT_MTR_PORT 1
#define RIGHT_MTR_PORT 2
#define FLYWHEEL_MTR_PORT 3
#define ROLLER_MTR_PORT 4
#define ENDGAME_MTR_PORT 5

// set up digital ports
#define ENDGAME_PENUMATIC_PORT 'A'

// events
void initialize();
void competition_initialize();

void autonomous();
void opcontrol();

void disabled();


// functions
void on_center_button();