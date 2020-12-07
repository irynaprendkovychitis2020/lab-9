#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 9.2B/lab 9.2B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest92B
{
	TEST_CLASS(UnitTest92B)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Students* S = new Students[1];
			S->surname = "Petr";
			S->grade_ped = 5;
			S->grade_math = 4;
			S->grade_physics = 3;

			double functionResult = student_avarage_evaluation(S, 0);

			Assert::AreEqual(4, functionResult);
		}
	};
}
