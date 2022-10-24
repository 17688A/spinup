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

// events
void initialize();
void competition_initialize();

void autonomous();
void opcontrol();

void disabled();


// functions
void on_center_button();