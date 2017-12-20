/*
 Name:		ChristmasTree.ino
 Created:	12/14/2017 1:11:38 PM
 Author:	boysa
*/
#include "LedControl.h"

Tree tree;
void setup() {
	ClearAllBits();
	tree.enableLed(0, EColor::BLUE);
	tree.enableLed(2, EColor::RED);
	tree.enableLed(10, EColor::BLUE | EColor::RED | EColor::GREEN);
	tree.shiftOut();
}

void loop() {
	
}
