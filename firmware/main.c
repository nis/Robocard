/*
 *  motorControl.c
 *  RoboBil
 *
 *  Created by Nis Sarup on 13/08/10.
 *  Copyright 2010 Sarup. All rights reserved.
 *
 */


/* includes */
#include "avr/io.h"
#include <util/delay.h>

#include "motorControl.c"

int main(void)
{
	//////////////////////////////////////////////////////////////////
	// Setting up pins
	//////////////////////////////////////////////////////////////////
	
	DDRB |= _BV(1); // Motor 1 PWM (Timer 1)
	DDRB |= _BV(2); // Motor 2 PWM (Timer 1)
	DDRB |= _BV(0); // F/B out
	DDRB |= _BV(3);	// Brake
	
	//DDRD |= _BV(3); //PWM B out (Timer 2)
	
	DDRD &= ~_BV(0); //Input fra knapper
	DDRD &= ~_BV(1); //Input fra knapper
	
	
	//////////////////////////////////////////////////////////////////
	// Setting up timer 2 to gererate one pwm signal
	// Can be used to dim the led on PD3
	//////////////////////////////////////////////////////////////////
//	TCCR2A |= (1<<WGM21) | (1<<WGM20) | (1<<COM2B1) | (1<<COM2B0);
//	TCCR2B |= (1<<CS21) | (1<<CS20);
//	
//	OCR2B = 0xF0;      // duty cycle (Intensity of LED)
	
	
	//////////////////////////////////////////////////////////////////
	// Setting up timer 1 to gererate two pwm signals on PB1 and PB2
	//////////////////////////////////////////////////////////////////
	TCCR1A |= (1<<COM1A1);
	TCCR1A |= (1<<COM1B1);
	TCCR1A |= (1<<WGM11);
	
	TCCR1B = (1<<CS10)|(1<<WGM12)|(1<<WGM13);
	
	
	ICR1 = 0x0064; 	// top value
	OCR1A = 0; 	// duty cycle (Motor speed)
	OCR1B = 70;		// duty cycle (Motor speed)
	
	//////////////////////////////////////////////////////////////////
	// Button handler to change direction on motor A and to stop it
	//////////////////////////////////////////////////////////////////
	
	PORTB |= _BV(0);				// Forward set to 1
	PORTB &= ~(_BV(3));				// Brake set to 0
	
	//char m1UpDown = 0;							// 0 = count down, 1 = count up
	int mChangeDelay = 1000;					// The delay between each change of the LED's intensity
	char motorIncrementSize = 1;
	
	while (1)
	{
		if (PIND & 0b00000001)					// Is the button down?
		{
			m1GoFaster(motorIncrementSize);
			_delay_us(mChangeDelay);
		}
		
		if (PIND & 0b00000010)					// Is the button down?
		{
			m1GoSlower(motorIncrementSize);
			_delay_us(mChangeDelay);
		}
	}
	return 0;
}

