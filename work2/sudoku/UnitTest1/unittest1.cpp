#include "stdafx.h"
#include "CppUnitTest.h"
#include "D:\ruangongshijian\�ڶ�����ҵ\sudoku\sudoku\generator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{	

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			generator g;
			g.solve(100);
		}

	}; 
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod2)
		{
			// TODO: �ڴ�������Դ���
			generator g;
			g.solve(10000);
		}

	}; 
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(TestMethod3)
		{
			// TODO: �ڴ�������Դ���
			generator g;
			g.solve(1000000);
		}

	};
	TEST_CLASS(UnitTest4)
	{
	public:

		TEST_METHOD(ZeroTest)
		{
			// TODO: �ڴ�������Դ���
			generator g;
			g.solve(0);
		}

	};
}