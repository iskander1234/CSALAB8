
#include <avr/io.h>
#include <util/delay.h>


void lcdInitPin(int registerNumber){
	PORTB = 0x02;
	_delay_ms(100);
	PORTA = registerNumber;
	PORTB = 0x00;
	_delay_ms(100);
}

//void lcd_s1 (int register_number)
//{
	//PORTE = 0x02;
	//_delay_ms (100)
	//PORTD = register_number;
	//PORTE = 0x00;
//	_delay_ms (100)
//}


void lcdDisplayStr(char *str){
	lcdInitPin(0x30);
	lcdInitPin(0x0E);
	lcdInitPin(0x80);
	
	for(int i=0; str[i] != '\0'; i++)
	{
		lcdDisplayChar(str[i]);
	}
}

//void lcd_display_str2 (char * str1)
//{
//	lcd_s1 (0x38)
//	lcd_s1 (0x0E)
//	lcd_s1 (0xC0)
	
//	for (int a = 0; str1 [a]! = '\0'; a ++)
//	{
//		lcd_char(str1 [a])
//	}
//}

//void lcd_char (char * character)
//{
//	PORTB = 0x03;
//	PORTA = character;
//	_delay_ms (100)
//	PORTB = 0x01;
//}

void lcdDisplayChar(char *charcter){
	PORTB = 0x03;
	PORTA = charcter;
	_delay_ms(50);
	PORTB = 0x01;
}

int main(void)
{
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRD = 0xFF;
	DDRE = 0xFF;
	
	lcdDisplayStr("DOSGALI ISKANDER");
}


