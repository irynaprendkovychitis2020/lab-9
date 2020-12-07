#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 9.2 A/lab 9.2 A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest92A
{
	TEST_CLASS(UnitTest92A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Students* S = new Students[1];
			S->surname = "Petr";
			S->grade_info = 5;
			S->grade_math = 4;
			S->grade_physics = 3;

			bool functionResult = b_search(S, 1, "Petr", 4, 4);
			
			Assert::AreEqual(false, functionResult);
		}
	};
}
