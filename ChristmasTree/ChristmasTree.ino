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

		for (int j = 0; j < 5; j++)
		{
			tree.enableRow(j, color);
			tree.shiftOut();
			delay(100);

			tree.disableRow(j, color);
			tree.shiftOut();
		}
	}
}
