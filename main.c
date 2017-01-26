#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL

#define START_COUNT (814*2)	//814 usec or 814*2 counts for prescalar = 8 and clk = 16MHz
#define LOW_COUNT (812*2)
#define START_COUNT_B (550*2-1)
#define LOW_COUNT_B (900*2-1)
// #define START_COUNT_B (814*2-1)
// #define LOW_COUNT_B (812*2-1)
#define PCHA 0	//pin channel A & B
#define PCHB 3
#define P_RPI_F 0
typedef enum {
	start,
	high,
	low,
	end
}status;

volatile unsigned char ack =1;
volatile unsigned int pwm[] = {2000*2,700*2,1000*2,2250*2,1000*2,630*2};
volatile status state = start;
volatile unsigned int count = 0;
volatile unsigned char toCount = 0;
volatile unsigned char rest = 0;
volatile unsigned char i = 0;
volatile status stateB = start;
volatile unsigned int countB = 0;
volatile unsigned char toCountB = 0;
volatile unsigned char restB = 0;
volatile unsigned char j = 3;
volatile unsigned char flagHalfCycle = 0;


void Timer1_init();
void Timer0_CTC_init();
void init_pwm();


int main(void)
{
	sei();
	DDRB |= (1<<PCHA)|(1<<(PCHA+1))|(1<<(PCHA+2));
	DDRB |= (1<<PCHB);
	DDRC |= (1<<P_RPI_F);
	Timer0_CTC_init();
	Timer1_init();
	while (1)
	{
	}
	
}

void Timer0_CTC_init(){
	//N = 8, CTC mode, OCA compare match interrupt enable
	TCCR0B |= (1<<CS01);
	TCCR0A |= (1<<WGM01);
	TIMSK0 |= (1<<OCIE0A);
	TIMSK0 |= (1<<OCIE0B);
	OCR0A = 0;
	OCR0B = 0;
	state = start;
	toCount = 0;
	stateB = start;
	toCountB = 0;
}
void Timer1_init(){
	//CTC OCR1A top,prescalar = 8 so tick = 0.5 usec
	TCCR1B |= (1<<WGM12);
	TCCR1B |= (1<<CS11);
	//enable interrupt
	TIMSK1 |= (1<<OCIE1A);
	OCR1A = 20000;
	//to imply 10 ms
	
}
ISR (TIMER1_COMPA_vect){
	if(flagHalfCycle==1){
	//ack = 0;
	//i2c interrupt enable
	/*TWCR |= (1<<TWIE);*/
	PORTC |=(1<<P_RPI_F);
	//mtnsish tnzliha zero ama td5oli l i2c
	flagHalfCycle = 0;
	}
	else {
		//e2fli i2c
		Timer0_CTC_init();
	}
	
}

ISR (TIMER0_COMPA_vect){
// 	if(ack==0){
// 		init_pwm();
// 	}
	switch (state){
		case start:
		PORTB &=~(1<<(PCHA+i));
		count = START_COUNT;
		if(toCount==1){
			state = high;
		}
		break;
		case high:
		PORTB |= (1<<(PCHA+i));
		count = pwm[i];
		if(toCount==1)
		state = low;
		break;
		
		case low:
		PORTB &=~(1<<(PCHA+i));
		count = LOW_COUNT;
		if(toCount==1){
			if(i==2) {	
				//fadlli a-count l rest w ab2a 5lst maximum 10 ms
				//w ana kda msh ha-count l rest fa fe safety 7etta
				//e2fli timer0 
				TIMSK0 &= ~(1<<OCIE0A);
				flagHalfCycle = 1;
			}
			else state = high;
			i = (i+1)%3;
		}
		break;
		case end:
		count = 20000;
		//10 msec
		if(toCount==1)
		state = start;
		break;
	}
	if(toCount==0){
		toCount = (count/256) +1;
		rest = (count%256)-1;
		if(toCount>0) OCR0A = 255;
		else if(toCount==0)	OCR0A = rest;	//bs case 8lt aslun mtnf3sh 3shan minimum 630*2
	}
	else if(toCount==1){
		OCR0A = rest;
	}
	else{
		OCR0A = 255;
	}
	toCount--;
	
}
ISR (TIMER0_COMPB_vect){
	switch (stateB){
		case start:
		PORTB &=~(1<<PCHB);
		countB = START_COUNT_B;
		if(toCountB==1){
			stateB = high;
		}
		break;
		case high:
		PORTB |= (1<<PCHB);
		countB = pwm[j];
		if(toCountB==1)
		stateB = low;
		break;
		case low:
		PORTB &=~(1<<PCHB);
		countB = LOW_COUNT_B;
		if(toCountB==1){
			if(j==5) {	//5llst cycle of 10 ms
				stateB = end;
				/*PORTC |=(1<<P_RPI_F);*/
			}
			else stateB = high;
			j = (j-2)%3+3;
		}
		break;
		case end:
		countB = 20000;
		//10 msec
		if(toCountB==1)
		stateB = start;
		break;
	}
	if(toCountB==0){
		toCountB = (countB/256) +1;
		restB = (countB%256)-1;
		if(toCountB>0) OCR0B = 255;
		else if(toCountB==0)	OCR0B = restB;	//bs case 8lt aslun mtnf3sh 3shan minimum 630*2
	}
	else if(toCountB==1){
		OCR0B = restB;
	}
	else{
		OCR0B = 255;
	}
	toCountB--;
}
