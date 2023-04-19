#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_5/Lab_12_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab125
{
	TEST_CLASS(UnitTestLab125)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Elem* top = NULL;
            string expresn = "-a*+b-c-/da-bcd";
            Assert::AreEqual(eval(top, expresn, 1, 2, 3, 4), 1);
		}
	};
}
