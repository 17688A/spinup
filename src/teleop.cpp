#include "./robot.h"

/**
 *  __ ______ __   ___   ___          
 * /_ |____  / /  / _ \ / _ \   /\    
 *  | |   / / /_ | (_) | (_) | /  \   
 *  | |  / / '_ \ > _ < > _ < / /\ \  
 *  | | / /| (_) | (_) | (_) / ____ \ 
 *  |_|/_/  \___/ \___/ \___/_/    \_\
 *     CORONA DEL SOL HIGH SCHOOL
 *
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	// Controller master is the instance that run the code
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(1);
	pros::Motor right_mtr(2);
	// 2 lines above are the motor ports

	while (true) {
		// debugging
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y); // set the analog key to the variable
		int right = master.get_analog(ANALOG_RIGHT_Y); // set the analog key to the variable

		left_mtr = left; // set the motor to the variable
		right_mtr = right; // set the motor to the variable

		pros::delay(20); // dont hog the cpu
	}
}