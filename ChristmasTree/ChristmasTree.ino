/*
 Name:		ChristmasTree.ino
 Created:	12/14/2017 1:11:38 PM
 Author:	boysa
*/
#include "LedControl.h"

Tree tree;
void setup() {
	tree.reset();

	tree.enableLed(0, EColor::BLUE);
	for (int i = 0; i < 23; i++)
	{
		tree.enableLed(i, EColor::BLUE);
		tree.shiftOut();
		delay(500);

		tree.disableLed(i, EColor::BLUE);
		tree.shiftOut();
		tree.reset();
	}
}

void loop() {
	
}
