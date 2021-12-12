#include "pch.h"
#include "CppUnitTest.h"
#include "LumArrays.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLumArrays
{
	TEST_CLASS(TestLumArrays)
	{
	public:
		
		TEST_METHOD(Test_sum1)
		{
			int vec[] = { 2, 3, -5, 1, 23 };
			unsigned int numElements = 5;
			int actual = sum(vec, numElements);
			int expected = 24;

			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(Test_sum2)
		{
			float vec[] = { 2, 3, -5, 1, 23 };
			unsigned int numElements = 5;
			float actual = sum(vec, numElements);
			float expected = 24;

			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(Test_average1)
		{
			int vec[] = { 2, 3, -5, 1, 23 };
			unsigned int numElements = 5;
			int actual = average(vec, numElements);
			int expected = 4;

			Assert::AreEqual(actual, expected);
		}
		
		TEST_METHOD(Test_average2)
		{
			float vec[] = { 2, 3, -5, 1, 23 };
			unsigned int numElements = 5;
			float actual = average(vec, numElements);
			float expected = 4.8;

			Assert::AreEqual(actual, expected);
		}
	};
}
