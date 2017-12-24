#pragma once

namespace Leds {
	struct CtlGroup
	{
		CtlGroup(const int8_t ctlPin,const int8_t grdPin)
		{
			controlPin = ctlPin;
			groundPin = grdPin;
		}
		int8_t controlPin;
		int8_t groundPin;
	};

	const int BITS_PER_LED = 3; // it takes 9 bits spread across all 3 shift regs to uniquely identify a single led
	const int LED_ARR_SIZE = 23; // how many leds

	CtlGroup BLEDS[LED_ARR_SIZE] = {
		CtlGroup(0,15),
		CtlGroup(0,16),
		CtlGroup(3, 16),
		CtlGroup(6, 16),
		CtlGroup(0, 17),
		CtlGroup(3,17),
		CtlGroup(6,17),
		CtlGroup(9,17),
		CtlGroup(0,18),
		CtlGroup(6,18),
		CtlGroup(9,18),
		CtlGroup(0,19),
		CtlGroup(3,19),
		CtlGroup(6,19),
		CtlGroup(9,19),
		CtlGroup(3,20),
		CtlGroup(6,20),
		CtlGroup(9,20),
		CtlGroup(0,21),
		CtlGroup(3,21),
		CtlGroup(6,21),
		CtlGroup(9,21),
		CtlGroup(12,21)
	};

	CtlGroup GLEDS[] = {
		CtlGroup(1,15),
		CtlGroup(1,16),
		CtlGroup(4,16),
		CtlGroup(7,16),
		CtlGroup(1,17),
		CtlGroup(4,17),
		CtlGroup(7,17),
		CtlGroup(10,17),
		CtlGroup(1,18),
		CtlGroup(7,18),
		CtlGroup(10,18),
		CtlGroup(1,19),
		CtlGroup(4,19),
		CtlGroup(7,19),
		CtlGroup(10,19),
		CtlGroup(4,20),
		CtlGroup(7,20),
		CtlGroup(10,20),
		CtlGroup(1,21),
		CtlGroup(4,21),
		CtlGroup(7,21),
		CtlGroup(10,21),
		CtlGroup(13,21)
	};

	CtlGroup RLEDS[LED_ARR_SIZE] = {
		CtlGroup(2,12),
		CtlGroup(2,16),
		CtlGroup(5,16),
		CtlGroup(8,16),
		CtlGroup(2,17),
		CtlGroup(5,17),
		CtlGroup(8,17),
		CtlGroup(11,17),
		CtlGroup(2,18),
		CtlGroup(8,18),
		CtlGroup(11,18),
		CtlGroup(2,19),
		CtlGroup(5,19),
		CtlGroup(8,19),
		CtlGroup(11,19),
		CtlGroup(5,20),
		CtlGroup(8,20),
		CtlGroup(11,20),
		CtlGroup(2,21),
		CtlGroup(5,21),
		CtlGroup(8,21),
		CtlGroup(11,21),
		CtlGroup(14,21)
	};
}