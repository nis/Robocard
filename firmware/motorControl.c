/*
 *  motorControl.c
 *  RoboBil
 *
 *  Created by Nis Sarup on 13/08/10.
 *  Copyright 2010 Sarup. All rights reserved.
 *
 */


int m1GoFaster(howMuch) {
	char i;
	if (OCR1A < 255) {
		for (i = 1; i <= howMuch; i++) {
			OCR1A++;
		}
	}
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
