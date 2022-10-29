#include "./robot.h"
#include "pros/misc.h"
#include "pros/motors.hpp"

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

// moters
bool flywheelActive = false;
bool rollerActive = false;

// penumaics
bool endGamePushed = false;

void opcontrol() {
	// Controller master is the instance that run the code
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	// drive train
	pros::Motor left_mtr(LEFT_MTR_PORT);
	pros::Motor right_mtr(RIGHT_MTR_PORT, true);

	// moters
	pros::Motor flywheel_mtr(FLYWHEEL_MTR_PORT, true);
	pros::Motor roller_mtr(ROLLER_MTR_PORT);
	pros::Motor endgame_mtr(ENDGAME_MTR_PORT);

	// penumaics
	pros::ADIDigitalOut endgame_adi (ENDGAME_PENUMATIC_PORT);

	while (true) {

		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			if(flywheelActive == true){
				flywheel_mtr.brake();
				flywheelActive = false;
				pros::delay(300);
			}
			else {
				flywheel_mtr.move_voltage(12000);
				flywheelActive = true;
				pros::delay(300);
			}
		}

		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			if(rollerActive == true){
				roller_mtr.brake();
				rollerActive = false;
				pros::delay(300);
			}
			else {
				roller_mtr.move_voltage(10000);
				rollerActive = true;
				pros::delay(300);
			}
		}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
			if(endGamePushed == true){
				endgame_adi.set_value(false);
				endGamePushed = false;
				pros::delay(300);
			}
			else {
				endgame_adi.set_value(true);
				endGamePushed = true;
				pros::delay(300);
			}
		}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
			endgame_mtr.set_reversed(false);
			endgame_mtr.move_voltage(10000);
			pros::delay(100);
			endgame_mtr.brake();
		}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			endgame_mtr.set_reversed(true);
			endgame_mtr.move_voltage(10000);
			pros::delay(100);
			endgame_mtr.brake();
		}

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