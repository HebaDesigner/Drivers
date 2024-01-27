/*
 * main.c
 * Stepper driver for the microcontroller ATMega 32
 * Created on: Jun 10, 2023
 * Author: Heba Atef Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"avr/delay.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include"Stepper_Interface.h"

void main(void){
	Stepper_Init__Full_Step();
	Set_Angle(45, CCW);
	//Set_Angle(45, CW);
	while(1)
	{
		//Stepper_Rotate_CW__Full_Step();
		Stepper_Rotate_CCW__Full_Step();
	}
}

