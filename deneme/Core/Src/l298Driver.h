/*
 * l298Driver.h
 *
 *  Created on: Aug 15, 2023
 *      Author: LENOVO
 */

	#ifndef SRC_L298DRIVER_H_
	#define SRC_L298DRIVER_H_

	#define MOTOR_TURN_LEFT 	1
	#define MOTOR_TURN_RIGHT 	2

	#define MOTOR_COMMAND_OK 	0
	#define MOTOR_INV_COMMAND 	1

	#define MOTOR_ON	1
	#define MOTOR_OFF	2

    #define MOTOR_FREE  3

	#define MOTOR_1 	1
	#define MOTOR_2		2

	int motor_on_off(int motor_no, int ignition);

	int motor_turn(int motor_no, int direction);



#endif /* SRC_L298DRIVER_H_ */
