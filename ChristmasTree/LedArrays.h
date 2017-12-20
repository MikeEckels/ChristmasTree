#pragma once

namespace Leds {
	const int BITS_PER_LED = 3; // it takes 9 bits spread across all 3 shift regs to uniquely identify a single led
	const int LED_ARR_SIZE = 24; // how many leds

	// These arrays store the bits that must be set to 1. The actual hardware turns on the colors that are 0. So in the example 
	// {1, 2, 15} will turn pin 1 blue because the 0 bit is NOT turned on and it's associated ground (15) is.
	int BLEDS[][BITS_PER_LED] = {
		{ 1, 2, 15 }, //GND is 15
		{ 1, 2, 16 }, //GND is 16
		{ 4, 5, 16 }, //GND is 16
		{ 7, 8, 16 }, //GND is 16
		{ 1, 2, 17 }, //GND is 17
		{ 4, 5, 17 }, //GND is 17
		{ 7, 8, 17 }, //GND is 17
		{ 10, 11, 17}, //GND is 17
		{ 1, 2, 18 }, //GND is 18
		{ 7, 8, 18 }, //GND is 18
		{ 10, 11, 18 }, //GND is 18
		{ 1, 2, 19 }, //GND is 19
		{ 4, 5, 19 }, //GND is 19
		{ 7, 8, 19 }, //GND is 19
		{ 10, 11, 19 }, //GND is 19
		{ 4, 5, 20 }, //GND is 20
		{ 7, 8, 20 }, //GND is 20
		{ 10, 11, 20 }, //GND is 20
		{ 1, 2, 21}, //GND is 21
		{ 4, 5, 21 }, //GND is 21
		{ 7, 8, 21 }, //GND is 21
		{ 10, 11, 21 }, //GND is 21
		{ 13, 14, 21} //GND is 21
	};

	int GLEDS[][BITS_PER_LED] = {
		{0, 2, 15 }, //GND is 15
		{0, 2, 16 }, //GND is 16
		{3, 5, 16 }, //GND is 16
		{6, 8, 16 }, //GND is 16
		{0, 2, 17 }, //GND is 17
		{3, 5, 17 }, //GND is 17
		{6, 8, 17 }, //GND is 17
		{9, 11, 17 }, //GND is 17
		{0, 2, 18 }, //GND is 18
		{6, 8, 18 }, //GND is 18
		{9, 11, 18 }, //GND is 18
		{0, 2, 19 }, //GND is 19
		{3, 5, 19 }, //GND is 19
		{6, 8, 19 }, //GND is 19
		{9, 11, 19 }, //GND is 19
		{3, 5, 20 }, //GND is 20
		{6, 8, 20 }, //GND is 20
		{9, 11, 20 }, //GND is 20
		{0, 2, 21 }, //GND is 21
		{3, 5, 21 }, //GND is 21
		{6, 8, 21 }, //GND is 21
		{9, 11, 21 }, //GND is 21
		{12, 14, 21 } //GND is 21
	};

	int RLEDS[][BITS_PER_LED] = {
		{ 0, 1, 15 }, //GND is 15
		{ 0, 1, 16 }, //GND is 16
		{ 3, 4, 16 }, //GND is 16
		{ 6, 7, 16 }, //GND is 16
		{ 0, 1, 17 }, //GND is 17
		{ 3, 4, 17 }, //GND is 17
		{ 6, 7, 17 }, //GND is 17
		{ 9, 10, 17 }, //GND is 17
		{ 0, 1, 18 }, //GND is 18
		{ 6, 7, 18 }, //GND is 18
		{ 9, 10, 18 }, //GND is 18
		{ 0, 1, 19 }, //GND is 19
		{ 3, 4, 19 }, //GND is 19
		{ 6, 7, 19 }, //GND is 19
		{ 9, 10, 19 }, //GND is 19
		{ 3, 4, 20 }, //GND is 20
		{ 6, 7, 20 }, //GND is 20
		{ 9, 10, 20 }, //GND is 20
		{ 0, 1, 21 }, //GND is 21
		{ 3, 4, 21 }, //GND is 21
		{ 6, 7, 21 }, //GND is 21
		{ 9, 10, 21 }, //GND is 21
		{ 12, 13, 21 } //GND is 21
	};
}