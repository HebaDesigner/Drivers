/*
 * Program.c
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

void Stepper_Init__Full_Step(void){

	DIO_u8_SetPin_Dir(Coils_Port,Coil_Blue, DIO_u8_Output);
	DIO_u8_SetPin_Dir(Coils_Port,Coil_Pinc, DIO_u8_Output);
	DIO_u8_SetPin_Dir(Coils_Port,Coil_Yellow, DIO_u8_Output);
	DIO_u8_SetPin_Dir(Coils_Port,Coil_Orange, DIO_u8_Output);
}

void Stepper_Rotate_CW__Full_Step(void){
	DIO_u8_SetPin_value(Coils_Port,Coil_Blue, DIO_u8_High);
	DIO_u8_SetPin_value(Coils_Port,Coil_Pinc, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Yellow, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Orange, DIO_u8_Low);

	_delay_ms(10);

	DIO_u8_SetPin_value(Coils_Port,Coil_Blue, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Pinc, DIO_u8_High);
	DIO_u8_SetPin_value(Coils_Port,Coil_Yellow, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Orange, DIO_u8_Low);

	_delay_ms(10);

	DIO_u8_SetPin_value(Coils_Port,Coil_Blue, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Pinc, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Yellow, DIO_u8_High);
	DIO_u8_SetPin_value(Coils_Port,Coil_Orange, DIO_u8_Low);

	_delay_ms(10);

	DIO_u8_SetPin_value(Coils_Port,Coil_Blue, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Pinc, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Yellow, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Orange, DIO_u8_High);

	_delay_ms(10);

}

void Stepper_Rotate_CCW__Full_Step(void){
	DIO_u8_SetPin_value(Coils_Port,Coil_Blue, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Pinc, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Yellow, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Orange, DIO_u8_High);

	_delay_ms(10);

	DIO_u8_SetPin_value(Coils_Port,Coil_Blue, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Pinc, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Yellow, DIO_u8_High);
	DIO_u8_SetPin_value(Coils_Port,Coil_Orange, DIO_u8_Low);

	_delay_ms(10);

	DIO_u8_SetPin_value(Coils_Port,Coil_Blue, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Pinc, DIO_u8_High);
	DIO_u8_SetPin_value(Coils_Port,Coil_Yellow, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Orange, DIO_u8_Low);

	_delay_ms(10);

	DIO_u8_SetPin_value(Coils_Port,Coil_Blue, DIO_u8_High);
	DIO_u8_SetPin_value(Coils_Port,Coil_Pinc, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Yellow, DIO_u8_Low);
	DIO_u8_SetPin_value(Coils_Port,Coil_Orange, DIO_u8_Low);

	_delay_ms(10);

}

void Set_Angle(u32 angle, u8 Direction)
{
	u32 steps = (angle*2048)/(360);
	u32 loops = steps/4;

	if(Direction == CW)
	{
		for(u32 i =0; i<loops; i++)
		{
			Stepper_Rotate_CW__Full_Step();
		}
	}else
	{
		for(u32 i =0; i<loops; i++)
		{
			Stepper_Rotate_CCW__Full_Step();
		}
	}
}







