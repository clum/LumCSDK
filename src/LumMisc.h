#ifndef GUARD_LUMMISC_H
#define GUARD_LUMMISC_H

unsigned char BitMask(unsigned char position);

unsigned char BitSetTo1(unsigned char x, unsigned char position);
unsigned char BitSetTo0(unsigned char x, unsigned char position);
unsigned char BitSetToValue(unsigned char x, unsigned char position, bool value);
unsigned char BitFlip(unsigned char x, unsigned char position);

bool BitIs1(unsigned char x, unsigned char position);
bool BitIs0(unsigned char x, unsigned char position);

#endif
