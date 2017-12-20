#pragma once
#include "LedArrays.h"
#include "PortManipulation.h"
#include "3rdParty\Array.h"

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

	// write the current color states to hardware
	void shiftOut();
private:
	EColor ledClrStates[Leds::LED_ARR_SIZE];
};

Tree::Tree()
{
	// setup pins
	initPortManip();
	Serial.begin(115200);
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

void Tree::shiftOut()
{
	for (uint16_t led = 0; led < Leds::LED_ARR_SIZE; led++)
	{
		int8_t colorState = static_cast<int8_t>(ledClrStates[led]);

		Array<int8_t, Leds::BITS_PER_LED> inversePins;
		bool subsequentReduce = false; // as soon as first color has pins written, set true to start reducing for additional colors

		/*The following is a 'reduce' algorithm. For each additional color
		state an LED is in, one less pin must be turned off. The only pins
		that must be written to 0 are the pins that each color array has in common.*/

		if (colorState & EColor::BLUE)
		{
			subsequentReduce = true;
			inversePins = Array<int8_t, Leds::BITS_PER_LED>(Leds::BLEDS[led]);
		}

		if (colorState & EColor::GREEN)
		{
			if (subsequentReduce)
			{
				Array<int8_t, Leds::BITS_PER_LED> tmpInvPins;
				for (int i = 0; i < inversePins.size(); i++)
				{
					for (int j = 0; j < Leds::BITS_PER_LED; j++)
					{
						// take the pins that are common between colors
						if (inversePins[i] == Leds::GLEDS[led][j])
							tmpInvPins.push_back(inversePins[i]);
					}
				}
				inversePins = tmpInvPins;
			}
			else {
				inversePins = Array<int8_t, Leds::BITS_PER_LED>(Leds::GLEDS[led]);
			}
			subsequentReduce = true;
		}

		if (colorState & EColor::RED)
		{
			if (subsequentReduce)
			{
				Array<int8_t, Leds::BITS_PER_LED> tmpInvPins;
				for (int i = 0; i < inversePins.size(); i++)
				{
					for (int j = 0; j < Leds::BITS_PER_LED; j++)
					{
						// take the pins that are common between colors
						if (inversePins[i] == Leds::RLEDS[led][j])
							tmpInvPins.push_back(inversePins[i]);
					}
				}
				inversePins = tmpInvPins;
			}
			else {
				inversePins = Array<int8_t, Leds::BITS_PER_LED>(Leds::RLEDS[led]);
			}
			subsequentReduce = true;
		}

		WriteBitsOn(inversePins.data(), inversePins.size());
	}
}