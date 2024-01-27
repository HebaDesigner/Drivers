/*
 * Interface.h
 * Stepper driver for the microcontroller ATMega 32
 * Created on: Jun 10, 2023
 * Author: Heba Atef Ahmed
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_


#define Coils_Port Group_B
#define Coil_Blue DIO_u8_Pin_0
#define Coil_Pinc DIO_u8_Pin_1
#define Coil_Yellow DIO_u8_Pin_2
#define Coil_Orange DIO_u8_Pin_3
#define CW 0
#define CCW 1

void Stepper_Init__Full_Step(void);

void Stepper_Rotate_CW__Full_Step(void);

void Stepper_Rotate_CCW__Full_Step(void);
void Set_Angle(u32 angle, u8 Direction);


#endif /* STEPPER_INTERFACE_H_ */
