#include "l298Driver.h"
#include "main.h"

/*
 * l298Driver.c
 *
 *  Created on: Aug 15, 2023
 *      Author: LENOVO
 */

int motor_on_off(int motor_no, int ignition){

		int error = 0;

		if(MOTOR_ON == ignition)
		{

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);  //ENA
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  //ENB

			error = MOTOR_COMMAND_OK;

		}
		else if(MOTOR_OFF == ignition)
		{

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);  //ENA
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  //ENB

			error = MOTOR_COMMAND_OK;

		}
		else if(MOTOR_FREE == ignition)
		{

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);

		}
		else
		{
			error = MOTOR_INV_COMMAND;
		}

		return error;
	}

	int motor_turn(int motor_no, int direction)
	{
		if(MOTOR_TURN_LEFT == direction)
		{
			if(MOTOR_1 == motor_no)
			{
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
			}
			else if(MOTOR_2 == motor_no)
			{
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			}
		}
		else if(MOTOR_TURN_RIGHT == direction)
		{
			if(MOTOR_1 == motor_no)
			{
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
			}
			else if(MOTOR_2 == motor_no)
			{
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
			}
		}

	}


