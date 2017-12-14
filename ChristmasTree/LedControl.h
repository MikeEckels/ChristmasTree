#pragma once
#include "LedArrays.h"
#include "PortManipulation.h"

enum EColor
{
	BLUE,
	GREEN, // take the 0th index of BLeds array and add 1 to it
	RED // take the 0th index of BLeds array and add 2 to it
};

class Tree
{
public:
	Tree();
};

Tree::Tree()
{
	// setup pins
	initPortManip();
}

void LedOn(int ledIndex, EColor color)
{
	switch (color)
	{
	case EColor::BLUE:
		WriteBitsOn(BLEDS[ledIndex], BITS_PER_LED);
		break;
	case EColor::RED:
		WriteBitsOn(RLEDS[ledIndex], BITS_PER_LED);
		break;
	case EColor::GREEN:
		WriteBitsOn(GLEDS[ledIndex], BITS_PER_LED);
		break;
	}
}