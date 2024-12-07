#include "pch.h"
#include "CppUnitTest.h"
#include "LumMisc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLumMisc
{
	TEST_CLASS(TestLumMisc)
	{
	public:
		
		TEST_METHOD(Test_BitMask)
		{
			unsigned char position = 0;
			unsigned char actual = 0b00000000;
			unsigned char expected = actual;
			
			position = 0;
			actual = BitMask(position);
			expected = 0b00000001;
			Assert::AreEqual(actual,expected);

			position = 1;
			actual = BitMask(position);
			expected = 0b00000010;
			Assert::AreEqual(actual,expected);

			position = 2;
			actual = BitMask(position);
			expected = 0b00000100;
			Assert::AreEqual(actual,expected);

			position = 3;
			actual = BitMask(position);
			expected = 0b00001000;
			Assert::AreEqual(actual,expected);

			position = 4;
			actual = BitMask(position);
			expected = 0b00010000;
			Assert::AreEqual(actual,expected);

			position = 5;
			actual = BitMask(position);
			expected = 0b00100000;
			Assert::AreEqual(actual,expected);

			position = 6;
			actual = BitMask(position);
			expected = 0b01000000;
			Assert::AreEqual(actual,expected);

			position = 7;
			actual = BitMask(position);
			expected = 0b10000000;
			Assert::AreEqual(actual,expected);
		}

		TEST_METHOD(Test_BitSetTo1)
		{
			unsigned char x = 0b11010101;
			unsigned char position = 0;
			unsigned char actual = 0;
			unsigned char expected = 0;

			position = 0;
			actual = BitSetTo1(x,position);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);

			position = 1;
			actual = BitSetTo1(x,position);
			expected = 0b11010111;
			Assert::AreEqual(actual,expected);

			position = 2;
			actual = BitSetTo1(x,position);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);

			position = 3;
			actual = BitSetTo1(x,position);
			expected = 0b11011101;
			Assert::AreEqual(actual,expected);

			position = 4;
			actual = BitSetTo1(x,position);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);

			position = 5;
			actual = BitSetTo1(x,position);
			expected = 0b11110101;
			Assert::AreEqual(actual,expected);

			position = 6;
			actual = BitSetTo1(x,position);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);

			position = 7;
			actual = BitSetTo1(x,position);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);
		}

		TEST_METHOD(Test_BitSetTo0)
		{
			unsigned char x = 0b11010101;
			unsigned char position = 0;
			unsigned char actual = 0;
			unsigned char expected = 0;

			position = 0;
			actual = BitSetTo0(x,position);
			expected = 0b11010100;
			Assert::AreEqual(actual,expected);

			position = 1;
			actual = BitSetTo0(x,position);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);

			position = 2;
			actual = BitSetTo0(x,position);
			expected = 0b11010001;
			Assert::AreEqual(actual,expected);

			position = 3;
			actual = BitSetTo0(x,position);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);

			position = 4;
			actual = BitSetTo0(x,position);
			expected = 0b11000101;
			Assert::AreEqual(actual,expected);

			position = 5;
			actual = BitSetTo0(x,position);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);

			position = 6;
			actual = BitSetTo0(x,position);
			expected = 0b10010101;
			Assert::AreEqual(actual,expected);

			position = 7;
			actual = BitSetTo0(x,position);
			expected = 0b01010101;
			Assert::AreEqual(actual,expected);
		}

		TEST_METHOD(Test_BitSetToValue)
		{
			unsigned char x = 0b11010101;
			unsigned char position = 0;
			unsigned char actual = 0;
			unsigned char expected = 0;
			bool value = false;

			position = 0;
			value = true;
			actual = BitSetToValue(x,position,value);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);

			position = 1;
			value = true;
			actual = BitSetToValue(x,position,value);
			expected = 0b11010111;
			Assert::AreEqual(actual,expected);

			position = 2;
			value = false;
			actual = BitSetToValue(x,position,value);
			expected = 0b11010001;
			Assert::AreEqual(actual,expected);

			position = 3;
			value = false;
			actual = BitSetToValue(x,position,value);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);

			position = 4;
			value = true;
			actual = BitSetToValue(x,position,value);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);

			position = 5;
			value = false;
			actual = BitSetToValue(x,position,value);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);

			position = 6;
			value = true;
			actual = BitSetToValue(x,position,value);
			expected = 0b11010101;
			Assert::AreEqual(actual,expected);

			position = 7;
			value = false;
			actual = BitSetToValue(x,position,value);
			expected = 0b01010101;
			Assert::AreEqual(actual,expected);
		}

		TEST_METHOD(Test_BitFlip)
		{
			unsigned char x = 0b11010101;
			unsigned char position = 0;
			unsigned char actual = 0;
			unsigned char expected = 0;

			position = 0;
			actual = BitFlip(x,position);
			expected = 0b11010100;
			Assert::AreEqual(actual,expected);

			position = 1;
			actual = BitFlip(x,position);
			expected = 0b11010111;
			Assert::AreEqual(actual,expected);

			position = 2;
			actual = BitFlip(x,position);
			expected = 0b11010001;
			Assert::AreEqual(actual,expected);

			position = 3;
			actual = BitFlip(x,position);
			expected = 0b11011101;
			Assert::AreEqual(actual,expected);

			position = 4;
			actual = BitFlip(x,position);
			expected = 0b11000101;
			Assert::AreEqual(actual,expected);

			position = 5;
			actual = BitFlip(x,position);
			expected = 0b11110101;
			Assert::AreEqual(actual,expected);

			position = 6;
			actual = BitFlip(x,position);
			expected = 0b10010101;
			Assert::AreEqual(actual,expected);

			position = 7;
			actual = BitFlip(x,position);
			expected = 0b01010101;
			Assert::AreEqual(actual,expected);
		}

		TEST_METHOD(Test_BitIs1)
		{
			unsigned char x = 0b11010101;
			unsigned char position = 0;
			bool actual = true;
			bool expected = true;

			position = 0;
			actual = BitIs1(x,position);
			expected = true;
			Assert::AreEqual(actual,expected);

			position = 1;
			actual = BitIs1(x,position);
			expected = false;
			Assert::AreEqual(actual,expected);

			position = 2;
			actual = BitIs1(x,position);
			expected = true;
			Assert::AreEqual(actual,expected);

			position = 3;
			actual = BitIs1(x,position);
			expected = false;
			Assert::AreEqual(actual,expected);

			position = 4;
			actual = BitIs1(x,position);
			expected = true;
			Assert::AreEqual(actual,expected);

			position = 5;
			actual = BitIs1(x,position);
			expected = false;
			Assert::AreEqual(actual,expected);

			position = 6;
			actual = BitIs1(x,position);
			expected = true;
			Assert::AreEqual(actual,expected);

			position = 7;
			actual = BitIs1(x,position);
			expected = true;
			Assert::AreEqual(actual,expected);
		}

		TEST_METHOD(Test_BitIs0)
		{
			unsigned char x = 0b11010101;
			unsigned char position = 0;
			bool actual = true;
			bool expected = true;

			position = 0;
			actual = BitIs0(x,position);
			expected = false;
			Assert::AreEqual(actual,expected);

			position = 1;
			actual = BitIs0(x,position);
			expected = true;
			Assert::AreEqual(actual,expected);

			position = 2;
			actual = BitIs0(x,position);
			expected = false;
			Assert::AreEqual(actual,expected);

			position = 3;
			actual = BitIs0(x,position);
			expected = true;
			Assert::AreEqual(actual,expected);

			position = 4;
			actual = BitIs0(x,position);
			expected = false;
			Assert::AreEqual(actual,expected);

			position = 5;
			actual = BitIs0(x,position);
			expected = true;
			Assert::AreEqual(actual,expected);

			position = 6;
			actual = BitIs0(x,position);
			expected = false;
			Assert::AreEqual(actual,expected);

			position = 7;
			actual = BitIs0(x,position);
			expected = false;
			Assert::AreEqual(actual,expected);
		}
	};
}
