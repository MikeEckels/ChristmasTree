/*
 Name:		ChristmasTree.ino
 Created:	12/14/2017 1:11:38 PM
*/

#include "LedControl.h"

Tree tree;

int colorTimer = 1000;
unsigned long currentTime = 0;
EColor color = EColor::RED;

void setup() {
	tree.reset();
}

void loop() {

	currentTime = millis();
	//Leds::LED_ARR_SIZE
	while (millis() < currentTime + colorTimer) {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < Leds::LED_ARR_SIZE; j++)
			{
				tree.enableLed(j, color);
				tree.shiftOut();
				//delay(1000);
				tree.disableLed(j, color);
				tree.shiftOut();
			}
		}
	}
	color = (EColor)(color + 1);
}
