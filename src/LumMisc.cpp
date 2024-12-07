#include "LumMisc.h"

/// <summary>
/// Create a bit mask with a 1 at the specified position and 0s everywhere else.
/// 
/// Christopher Lum
/// lum@uw.edu
/// </summary>
/// <param name="position">0-based position in range [0,7] (0 = 1st (LSB) bit, 7 = 8th (MSB) bit)</param>
/// <returns>An 8 bit mask</returns>
unsigned char BitMask(unsigned char position) {
	//Version History
	//12/06/24: Created
	unsigned char x = 0b00000001;
	unsigned char mask = x << position;
	return mask;
}

/// <summary>
/// Sets the specified bit to 1.
/// 
/// Christopher Lum
/// lum@uw.edu
/// </summary>
/// <param name="x">original value</param>
/// <param name="position">0-based position in range [0,7] (0 = 1st (LSB) bit, 7 = 8th (MSB) bit)</param>
/// <returns>modified value with bit set to 1.</returns>
unsigned char BitSetTo1(unsigned char x, unsigned char position) {
	//Version History
	//12/06/24: Created
	unsigned char mask = BitMask(position);
	unsigned char ret = x | mask;
	return ret;
}

/// <summary>
/// Sets the specified bit to 0.
/// 
/// Christopher Lum
/// lum@uw.edu
/// </summary>
/// <param name="x">original value</param>
/// <param name="position">0-based position in range [0,7] (0 = 1st (LSB) bit, 7 = 8th (MSB) bit)</param>
/// <returns>modified value with bit set to 0.</returns>
unsigned char BitSetTo0(unsigned char x, unsigned char position) {
	//Version History
	//12/06/24: Created
	unsigned char mask = BitMask(position);
	unsigned char ret = x & ~mask;
	return ret;
}

/// <summary>
/// Sets the specified bit to either 0 or 1.
/// 
/// Christopher Lum
/// lum@uw.edu
/// </summary>
/// <param name="x">original value</param>
/// <param name="position">0-based position in range [0,7] (0 = 1st (LSB) bit, 7 = 8th (MSB) bit)</param>
/// <param name="value">true = 1, false = 0</param>
/// <returns>modified value with bit set to 1.</returns>
unsigned char BitSetToValue(unsigned char x, unsigned char position, bool value) {
	//Version History
	//12/06/24: Created
	if (value) {
		return BitSetTo1(x, position);
	}
	else 
	{
		return BitSetTo0(x, position);
	}
}

/// <summary>
/// Flips the specified bit to its opposite value.
/// 
/// Christopher Lum
/// lum@uw.edu
/// </summary>
/// <param name="x">original value</param>
/// <param name="position">0-based position in range [0,7] (0 = 1st (LSB) bit, 7 = 8th (MSB) bit)</param>
/// <returns>modified value with bit at position flipped.</returns>
unsigned char BitFlip(unsigned char x, unsigned char position) {
	//Version History
	//12/06/24: Created
	unsigned char mask = BitMask(position);
	unsigned char ret = x ^ mask;
	return ret;
}

/// <summary>
/// Determine if a bit is 1 or not.
/// 
/// Christopher Lum
/// lum@uw.edu
/// </summary>
/// <param name="x">value to check</param>
/// <param name="position">0-based position in range [0,7] (0 = 1st (LSB) bit, 7 = 8th (MSB) bit)</param>
/// <returns>true is bit at position is 1, false otherwise.</returns>
bool BitIs1(unsigned char x, unsigned char position) {
	//Version History
	//12/06/24: Created
	unsigned char shifted = x >> position;
	unsigned char ret = shifted & 0b00000001;
	return ret;
}

/// <summary>
/// Determine if a bit is 0 or not.
/// 
/// Christopher Lum
/// lum@uw.edu
/// </summary>
/// <param name="x">value to check</param>
/// <param name="position">0-based position in range [0,7] (0 = 1st (LSB) bit, 7 = 8th (MSB) bit)</param>
/// <returns>true is bit at position is 0, false otherwise.</returns>
bool BitIs0(unsigned char x, unsigned char position) {
	//Version History
	//12/06/24: Created
	return !BitIs1(x,position);
}
