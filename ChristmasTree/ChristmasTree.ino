/*
 Name:		ChristmasTree.ino
 Created:	12/14/2017 1:11:38 PM
 Author:	boysa
*/
#include "LedControl.h"

Tree tree;
void setup() {
	tree.reset();
}

void loop() {
	//Leds::LED_ARR_SIZE
	for(int i = 0; i < 3; i++)
	{
		EColor color = (EColor)(1 << i);
		for (int j = 0; j < Leds::LED_ARR_SIZE; j++)
		{
			tree.enableLed(j, color);
			tree.shiftOut();
			delay(100);

			tree.disableLed(j, color);
			tree.shiftOut();
		}
	}
}
