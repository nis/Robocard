/*
 *  motorControl.c
 *  RoboBil
 *
 *  Created by Nis Sarup on 13/08/10.
 *  Copyright 2010 Sarup. All rights reserved.
 *
 */


int m1GoFaster(howMuch) {
	//unsigned char i;
	unsigned char oldValue = OCR1A;
	unsigned int newValue = oldValue + howMuch;
	
	OCR1A = (newValue > 255) ? 255 : OCR1A + howMuch;
	
	return 0;
}

int m1GoSlower(howMuch) {
	char i;
	if (OCR1A > 0) {
		for (i = 1; i <= howMuch; i++) {
			OCR1A--;
		}
	}
	return 0;
}
