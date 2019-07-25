#include "stdafx.h"
#include "CppUnitTest.h"
#include "../StaticCodeAnalyzer/StaticCodeAnalyzer.h"
#include<assert.h>

namespace StaticCodeAnalyzerTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			assert(StaticCodeAnalyzer::PMDTool(R"(pmd-bin-6.16.0\bin\pmd.bat -d HelloWorld -f text -R pmd-bin-6.16.0\bin\rulesets\java\quickstart.xml -r PMDReport.txt)"));
		}

	};
}