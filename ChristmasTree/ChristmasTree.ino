/*
 Name:		ChristmasTree.ino
 Created:	12/14/2017 1:11:38 PM
 Author:	boysa
*/
#include "LedControl.h"

Tree tree;
void setup() {
	ClearAllBits();

	for (int i = 0; i < 3; i++)
	{
		Serial.println(SHFT_REG_DATA[i]);
	}
}

void loop() {
	int bits[] = { 15,16,17,18};
	WriteBitsOn(bits, ARRAY_SIZE(bits));
}
