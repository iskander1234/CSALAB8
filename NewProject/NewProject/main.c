
#include <avr/io.h>
#include <util/delay.h>

void lcd_init_pin(int register_number){
	PORTB = 0x02;
	_delay_ms(100);
	PORTA = register_number;
	PORTB = 0x00;
	_delay_ms(100);
}


void lcd_display_str1(char *str){
	lcd_init_pin(0x38);
	lcd_init_pin(0x0E);
	lcd_init_pin(0x80);
	
	for(int i =0; str[i] != '\0'; i++){
		lcd_display_char(str[i]);
	}
	
}

void lcd_display_str2(char *str){
	lcd_init_pin(0x38);
	lcd_init_pin(0x0E);
	lcd_init_pin(0xC0);
	
	for(int i =0; str[i] != '\0'; i++){
		lcd_display_char(str[i]);
	}
	
}
void lcd_display_char(char *character){
	PORTB = 0x03;
	PORTA = character;
	_delay_ms(50);
	PORTB = 0x01;
}



void lcd_init_pin2(int register_number){
	PORTF= 0x02;
	_delay_ms(100);
	PORTE= register_number;
	PORTF= 0x00;
	_delay_ms(100);
}

void lcd_display_char2(char *character){
	PORTF= 0x03;
	PORTE= character;
	_delay_ms(50);
	PORTF= 0x01;
}

void lcd_display_str3(char *str){
	lcd_init_pin2(0x38);
	lcd_init_pin2(0x0E);
	lcd_init_pin2(0x80);
	
	for(int i =0; str[i] != '\0'; i++){
		lcd_display_char2(str[i]);
	}
	
}

void lcd_display_str4(char *str){
	lcd_init_pin2(0x38);
	lcd_init_pin2(0x0E);
	lcd_init_pin2(0xC0);
	for(int i =0; str[i] != '\0'; i++){
		lcd_display_char2(str[i]);
	}
}

void lcd_display_str6( char *str){
	lcd_init_pin2(0x38);
	lcd_init_pin2(0x0E);
	lcd_init_pin2(0xC0);
		for(int i =0; str[i] != '\0'; i++){
			lcd_display_char2(str[i]);
		}
}


int main(void)
{
	DDRA = 0xFF;
	DDRB = 0xFF;
	
	lcd_display_str1("Iskander");
	lcd_display_str2("Dosgali");
	
	DDRE =  0xFF;
	DDRF = 0xFF;
	
	lcd_display_str3("Iskander");
	//lcd_display_str4("Dosgali");
	//lcd_display_str5("Dosgaliuly");
	lcd_display_str6("IS-1801k");

}
