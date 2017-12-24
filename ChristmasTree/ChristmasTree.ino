/*
 Name:		ChristmasTree.ino
 Created:	12/14/2017 1:11:38 PM
 Author:	boysa
*/
#include "LedControl.h"

Tree tree;
void setup() {
	ClearAllBits();
	int8_t ctlPins[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	WriteBitsOn(ctlPins, ARRAY_SIZE(ctlPins));
	//tree.enableLed(0, EColor::BLUE);
	tree.enableLed(2, EColor::RED);
	tree.enableLed(10, EColor::BLUE);
	tree.shiftOut();
}

void loop() {
	
}
