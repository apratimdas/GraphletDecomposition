#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "graphletCore.h"

namespace GraphletTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here

			Assert::IsTrue(graphlet::GraphletCore::unittestcheck());

		}

	};
}