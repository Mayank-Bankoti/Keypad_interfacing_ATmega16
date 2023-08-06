/*
 * Keypad_interfacing.c
 *
 * Created: 8/1/2023 6:23:44 PM
 * Author : mayan
 */ 

#include <avr/io.h>
#include "LCD.h"


void LCD_cmd(unsigned char Command);
void LCD_data(unsigned char Data);
void LCD_init(void);

unsigned char i;
unsigned char j;

int main(void)
{
	DDRB = 0xFF;
	DDRA = 0xFF;
	DDRD =0x0F;
    LCD_init();

	unsigned char string[] = "Press any Key";
	while(1)
	{
    	while(string[i]!='\0')
    	{
	    	LCD_data(string[i]);
	    	i++;
			_delay_ms(1);
    	}
		
		for (j=0; j<4; j++)
		{
			PORTD = (0xF7>>j) | 0xF0;
			_delay_ms(1);
			LCD_cmd(0xc0);
			
			if(PIND == 0xEE)
			LCD_data('0');
			else if (PIND ==0xDE)
			LCD_data('1');
			else if(PIND ==0xBE)
			LCD_data('2');
			else if(PIND ==0x7E)
			LCD_data('3');
			else if(PIND ==0xED)
			LCD_data('4');
			else if(PIND ==0xDD)
			LCD_data('5');
			else if(PIND ==0xBD)
			LCD_data('6');
			else if(PIND ==0x7D)
			LCD_data('7');
			else if(PIND ==0xEB)
			LCD_data('8');
			else if(PIND ==0xDB)
			LCD_data('9');		
			else if(PIND ==0xBB)
			LCD_data('A');
			else if(PIND ==0x7B)
			LCD_data('B');
			else if(PIND ==0xE7)
			LCD_data('C');
			else if(PIND ==0xD7)
			LCD_data('D');
			else if(PIND ==0xB7)
			LCD_data('E');
			else if(PIND ==0x77)
			LCD_data('F');
			if (j==4)
			{
				j=0;
			}	
		}                                                                                                                                                                                                                                                                                                                                             
}
		}