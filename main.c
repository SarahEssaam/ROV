/*
 * I2c_bs.c
 *
 * Created: 26-Jan-17 8:11:09 PM
 * Author : Dell
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#define ADDRESS 1
volatile unsigned char F_ADD_Rx = 0;
volatile unsigned char k =0;
volatile unsigned int pwm[6] = {7,0,0,0,0,0};


void I2c_init(){
	TWAR |= ((ADDRESS & 0xFF)<<1)|(1<<0);
	TWCR |= (1<<TWEN)|(1<<TWEA)|(1<<TWIE)|(TWINT);
}

int main(void)
{
	sei();
    I2c_init();
	DDRD = 0xFF;
    while (1) 
    {
		_delay_ms(1000);
		PORTD = pwm[5];
    }
}

ISR(TWI_vect){
	if((TWSR&0xF8)==0x60){
		//own address received
		F_ADD_Rx = 1; 
		TWCR |= (1<<TWEN)|(TWINT);
	}
	if(((TWSR&0xF8)==0x80)&&(F_ADD_Rx==1)){
		//data received
		pwm[k] = TWDR;
		if(k<5){
		TWCR |= (1<<TWEN)|(TWINT);
		}
		k = (k+1)%6;
	}
}