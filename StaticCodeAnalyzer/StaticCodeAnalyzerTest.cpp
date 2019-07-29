#include "stdafx.h"
#include<gtest\gtest.h>
#include "StaticCodeAnalyzer.h"

TEST(ToolTest, PMDToolTest)
{
	EXPECT_EQ(true, StaticCodeAnalyzer::IsColon(':'));
}

TEST(ToolTest, SpotBugsToolTest)
{
	EXPECT_EQ(true, StaticCodeAnalyzer::SpotBugsTool(R"(spotbugs-3.1.12\bin\spotbugs.bat -textui -maxHeap 1500 -nested:false -output SpotBugsReport.emacs -effort:max -low -sortByClass -emacs sourcepath HelloWorld)"));
}




