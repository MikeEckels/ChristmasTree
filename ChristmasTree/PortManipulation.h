#pragma once
/**This class handles all the manual port manipulation logic. Manual port manip was chosen due to it's speed. Some of 
the pin mappings are specific to this christmas tree project, some parts are generic**/

#define ARRAY_SIZE(array) \
    (sizeof(array) / sizeof(array[0]))

//The arduino digital pin #
int Latch_Pin = 10;   //PB2
int Clock_Pin = 9;    //PB1
int Data_Pin = 8;     //PB0

const int SHFT_REG_COUNT = 3; // how many shift registers we have

// Shared state of all the leds
int SHFT_REG_DATA[SHFT_REG_COUNT] = { 0 };
struct bits {
	uint8_t b0 : 1;
	uint8_t b1 : 1;
	uint8_t b2 : 1;
	uint8_t b3 : 1;
	uint8_t b4 : 1;
	uint8_t b5 : 1;
	uint8_t b6 : 1;
	uint8_t b7 : 1;
} __attribute__((__packed__));
#define SBIT(port,pin) ((*(volatile struct bits*)&port).b##pin)

#define Data_Bit SBIT(PORTB, 0)
#define Clock_Bit SBIT(PORTB, 1)
#define Latch_Bit SBIT(PORTB, 2)

void initPortManip()
{
	pinMode(Latch_Pin, OUTPUT);
	pinMode(Clock_Pin, OUTPUT);
	pinMode(Data_Pin, OUTPUT);
}

// Shift out a single byte, bit by bit, to the hardware
void ShiftOutPORTMANIP(int val)
{
	for (int i = 0; i < 8; i++)
	{
		Data_Bit = !!(val & (1 << (7 - i)));
		Clock_Bit = 1;
		Clock_Bit = 0;
	}
}

// Write register buffer to hardware
void WriteShiftData()
{
	Latch_Bit = 0;
	for (int i = SHFT_REG_COUNT - 1; i >= 0; i--)
	{
		ShiftOutPORTMANIP(SHFT_REG_DATA[i]);
	}
	Latch_Bit = 1;
}

// bits[] is an array containing the zero-indexed bits that should be set
void WriteBitsOn(int8_t Bits[], int Len)
{
	for (int i = 0; i < Len; i++)
	{
		int ByteIndex = Bits[i] >> 3; // divide by 8
		bitSet(SHFT_REG_DATA[ByteIndex], Bits[i] % 8);
	}
}

// bits[] is an array containing the zero-indexed bits that should be cleared
void WriteBitsOff(int8_t Bits[], int Len)
{
	for (int i = 0; i < Len; i++)
	{
		int ByteIndex = Bits[i] >> 3; // divide by 8
		bitClear(SHFT_REG_DATA[ByteIndex], Bits[i] % 8);
	}
}

// specialization of above to avoid having to make temp arrays for single  bits
void WriteBitOn(int8_t Bit)
{
	int ByteIndex = Bit >> 3; // divide by 8
	bitSet(SHFT_REG_DATA[ByteIndex], Bit % 8);
}

// see WriteBitOn
void WriteBitOff(int8_t Bit)
{
	int ByteIndex = Bit >> 3;
	bitClear(SHFT_REG_DATA[ByteIndex], Bit % 8);
}

void ClearAllBits()
{
	int8_t AllBits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	WriteBitsOff(AllBits, 24);
}

void SetAllBits()
{
	int8_t AllBits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	WriteBitsOn(AllBits, 24);
}
