#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba 9.2 B/Laba 9.2 B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int N = 1;
            Student* s = new Student[N];

            std::stringstream input;
            input << "fff\n1\n0\n5\n4\n3\n";

            std::streambuf* originalCin = std::cin.rdbuf();
            std::cin.rdbuf(input.rdbuf());

            Create(s, N);

            std::cin.rdbuf(originalCin);

            Assert::AreEqual(std::string("ff"), s[0].surname);
            Assert::AreEqual(4, s[0].physics);
            Assert::AreEqual(4, s[0].math);
            Assert::AreEqual(4, s[0].it);
            delete[] s;
		}
	};
}
