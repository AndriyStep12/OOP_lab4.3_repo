#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../Decimal.h"
#include "../BitString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestLab4_3)
	{
	public:

		TEST_METHOD(TestDecimalAddition)
		{
			Decimal d1("123");
			Decimal d2("987");
			Decimal expected("1110");

			Array* result = d1.add(&d2);

			Decimal* decResult = dynamic_cast<Decimal*>(result);

			Assert::IsNotNull(decResult);

			Assert::IsTrue(*decResult == expected);

			delete result;
		}

		TEST_METHOD(TestBitStringAddition)
		{
			BitString b1("1010");
			BitString b2("0111");

			Array* result = b1.add(&b2);

			Assert::AreEqual(5, result->getSize());

			Assert::AreEqual((unsigned char)1, (*result)[0]);
			Assert::AreEqual((unsigned char)0, (*result)[1]);
			Assert::AreEqual((unsigned char)0, (*result)[2]);
			Assert::AreEqual((unsigned char)0, (*result)[3]);
			Assert::AreEqual((unsigned char)1, (*result)[4]);

			delete result;
		}

		TEST_METHOD(TestArrayRangeCheck)
		{
			Decimal d("123");

			Assert::ExpectException<std::out_of_range>([&] {
				unsigned char val = d[5];
				});

			Assert::ExpectException<std::out_of_range>([&] {
				unsigned char val = d[-1];
				});
		}
	};
}