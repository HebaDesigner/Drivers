#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "avr/delay.h"
#include "DIO_Interface.h"
#include "CLCD_Interface.h"
#include "KPD_Interface.h"


void main(void)
{
	u8 Key_Value;
	CLCD_voidInit();
	KPD_Void_Init();
	while(1)
	{
		do
		{
			Key_Value = KPD_voidGet_KPD_Status();

		}while(Key_Value == 0xff);

		CLCD_voidWriteNumber(Key_Value);
	}

}


/*void main(void){

	DIO_u8_SetPin_Dir(Group_C,DIO_u8_Pin_7,DIO_u8_Output);
	DIO_u8_SetPin_Dir(Group_B,DIO_u8_Pin_7,DIO_u8_Output);

	u8 arr[16];

	KPD_Void_Init();
	LCD_void_int_8Bit();

		LCD_u8_Write_Number(645,0,0);

		_delay_ms(1000);

		LCD_u8_Write_Number(730,0,0);

		_delay_ms(1000);

	while(1){

		//KPD_voidGet_KPD_Status(arr);

		if(arr[0] == 0){
			//LCD_Void_Write_String("motor Anti clockwise", 0,0);

			LCD_u8_Write_Number(32,0,0);

			DIO_u8_SetPin_value(Group_C,DIO_u8_Pin_7,DIO_u8_Low);
			DIO_u8_SetPin_value(Group_B,DIO_u8_Pin_7,DIO_u8_High);

		}else if(arr[1] == 0)
		{
			LCD_Void_Write_String("motor clockwise", 0,0);

			DIO_u8_SetPin_value(Group_C,DIO_u8_Pin_7,DIO_u8_High);
			DIO_u8_SetPin_value(Group_B,DIO_u8_Pin_7,DIO_u8_Low);


		}else{
			LCD_Void_Write_cmd(0b00000001);

			DIO_u8_SetPin_value(Group_C,DIO_u8_Pin_7,DIO_u8_Low);
			DIO_u8_SetPin_value(Group_B,DIO_u8_Pin_7,DIO_u8_Low);

		}
	}

}*/
