#pragma once
#include "LedArrays.h"
#include "PortManipulation.h"

/**The first 15 bits control led color per-column, three bits per led (b,g,r). The current column color
is selected to be the color(s) that are set to zero . Ground line bits are directly after
the control bits with the last two bits unused. Ground lines are sinking ground when
a one is written. (So write 0 to turn an led color 'on' and write a 1 to turn it's ground 'on')**/
enum EColor : int8_t
{
	BLUE = (1 << 0),
	GREEN = (1 << 1), // take the 0th index of BLeds array and add 1 to it
	RED = (1 << 2) // take the 0th index of BLeds array and add 2 to it
};

static EColor operator|(EColor left, EColor right)
{
	return static_cast<EColor>(static_cast<int8_t>(left) | static_cast<int8_t>(right));
}

class Tree
{
public:
	Tree();
	// turn on or off a color channel of some led
	bool enableLed(const uint8_t pin, EColor color);
	bool disableLed(const uint8_t pin, EColor color);

	bool enableRow(const uint8_t row, EColor color);
	bool disableRow(const uint8_t row, EColor color);

	bool enableCol(const uint8_t col, EColor color);
	bool disableCol(const uint8_t col, EColor color);

	// write the current color states to hardware
	void shiftOut();

	// turn ground lines off, and all control lines off (to zero)
	void reset();
private:
	EColor ledClrStates[Leds::LED_ARR_SIZE];
};

Tree::Tree()
{
	// setup pins
	initPortManip();
	Serial.begin(115200);
}

void Tree::reset()
{
	ClearAllBits();
	int8_t ctlPins[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	WriteBitsOn(ctlPins, ARRAY_SIZE(ctlPins));
	WriteShiftData();
}

bool Tree::enableLed(const uint8_t pin, EColor color)
{
	if (pin < 0 || pin >= Leds::LED_ARR_SIZE)
		return false;

	ledClrStates[pin] = static_cast<EColor>(static_cast<int8_t>(ledClrStates[pin]) | static_cast<int8_t>(color));
	return true;
}

bool Tree::disableLed(const uint8_t pin, EColor color)
{
	if (pin < 0 || pin >= Leds::LED_ARR_SIZE)
		return false;

	ledClrStates[pin] = static_cast<EColor>(static_cast<int8_t>(ledClrStates[pin]) & ~static_cast<int8_t>(color));
	return true;
}

bool Tree::enableRow(const uint8_t row, EColor color)
{
	if (row < 0 || row > 6)
		return false;

	switch (row)
	{
	case 0:
		enableLed(0, color);
		break;
	case 1:
		enableLed(1, color);
		enableLed(2, color);
		enableLed(3, color);
		break;
	case 2:
		enableLed(4, color);
		enableLed(5, color);
		enableLed(6, color);
		enableLed(7, color);
		break;
	case 3:
		enableLed(8, color);
		enableLed(9, color);
		enableLed(10, color);
		break;
	case 4:
		enableLed(11, color);
		enableLed(12, color);
		enableLed(13, color);
		enableLed(14, color);
		break;
	case 5:
		enableLed(15, color);
		enableLed(16, color); 
		enableLed(17, color);
		break;
	case 6:
		enableLed(18, color);
		enableLed(19, color);
		enableLed(20, color);
		enableLed(21, color);
		enableLed(22, color);
		break;
	}
	return true;
}

bool Tree::disableRow(const uint8_t row, EColor color)
{
	if (row < 0 || row > 6)
		return false;

	switch (row)
	{
	case 0:
		disableLed(0, color);
		break;
	case 1:
		disableLed(1, color);
		disableLed(2, color);
		disableLed(3, color);
		break;
	case 2:
		disableLed(4, color);
		disableLed(5, color);
		disableLed(6, color);
		disableLed(7, color);
		break;
	case 3:
		disableLed(8, color);
		disableLed(9, color);
		disableLed(10, color);
		break;
	case 4:
		disableLed(11, color);
		disableLed(12, color);
		disableLed(13, color);
		disableLed(14, color);
		break;
	case 5:
		disableLed(15, color);
		disableLed(16, color);
		disableLed(17, color);
		break;
	case 6:
		disableLed(18, color);
		disableLed(19, color);
		disableLed(20, color);
		disableLed(21, color);
		disableLed(22, color);
		break;
	}
	return true;
}

bool Tree::enableCol(const uint8_t col, EColor color)
{
	if (col < 0 || col > 4)
		return false;
	switch(col)
	{ 
	case 0:
		enableLed(0, color);
		enableLed(3, color);
		enableLed(7, color);
		enableLed(10, color);
		enableLed(14, color);
		enableLed(17, color);
		enableLed(22, color);
		break;
	case 1:
		enableLed(2, color);
		enableLed(13, color);
		enableLed(17, color);
		enableLed(21, color);
		break;
	case 2:
		enableLed(1, color);
		enableLed(5, color);
		enableLed(9, color);
		enableLed(12, color);
		enableLed(16, color);
		enableLed(20, color);
		break;
	case 3:
		enableLed(4, color);
		enableLed(8, color);
		enableLed(11, color);
		enableLed(15, color);
		enableLed(19, color);
		break;
	case 4:
		enableLed(18, color);
		break;
	}
	return true;
}

bool Tree::disableCol(const uint8_t col, EColor color)
{
	if (col < 0 || col > 4)
		return false;
	switch (col)
	{
	case 0:
		disableLed(0, color);
		disableLed(3, color);
		disableLed(7, color);
		disableLed(10, color);
		disableLed(14, color);
		disableLed(17, color);
		disableLed(22, color);
		break;
	case 1:
		disableLed(2, color);
		disableLed(13, color);
		disableLed(17, color);
		disableLed(21, color);
		break;
	case 2:
		disableLed(1, color);
		disableLed(5, color);
		disableLed(9, color);
		disableLed(12, color);
		disableLed(16, color);
		disableLed(20, color);
		break;
	case 3:
		disableLed(4, color);
		disableLed(8, color);
		disableLed(11, color);
		disableLed(15, color);
		disableLed(19, color);
		break;
	case 4:
		disableLed(18, color);
		break;
	}
	return true;
}

void Tree::shiftOut()
{
	// TODO: Must unset bits if the color is not selected.
	// Cannot simply do an else because pins may overlap, must
	// keep internal state and only reset if state has changed.
	// for now just call reset() manually

	for (uint16_t led = 0; led < Leds::LED_ARR_SIZE; led++)
	{
		int8_t colorState = static_cast<int8_t>(ledClrStates[led]);

		int8_t tmpCtl[1] = { 0 };
		int8_t tmpGrd[1] = { 0 };

		if (colorState & EColor::BLUE)
		{
			tmpCtl[0] = Leds::BLEDS[led].controlPin;
			tmpGrd[0] = Leds::BLEDS[led].groundPin;

			WriteBitsOff(tmpCtl, ARRAY_SIZE(tmpCtl));
			WriteBitsOn(tmpGrd, ARRAY_SIZE(tmpGrd));
		} 

		if (colorState & EColor::GREEN)
		{
			tmpCtl[0] = Leds::GLEDS[led].controlPin;
			tmpGrd[0] = Leds::GLEDS[led].groundPin;

			WriteBitsOff(tmpCtl, ARRAY_SIZE(tmpCtl));
			WriteBitsOn(tmpGrd, ARRAY_SIZE(tmpGrd));
		}

		if (colorState & EColor::RED)
		{
			tmpCtl[0] = Leds::RLEDS[led].controlPin;
			tmpGrd[0] = Leds::RLEDS[led].groundPin;

			WriteBitsOff(tmpCtl, ARRAY_SIZE(tmpCtl));
			WriteBitsOn(tmpGrd, ARRAY_SIZE(tmpGrd));
		}
		WriteShiftData();
	}
}