#include "pch.h"
#include "StaticCodeAnalyser.h"
#include "Utility.h"

int main()
{
	bool PMDStatus = StaticCodeAnalyser::PMDTool(R"(..\..\pmd-bin-6.16.0\bin\pmd.bat -d ..\..\feereport -f text -R ..\..\pmd-bin-6.16.0\bin\rulesets\java\quickstart.xml -r ..\..\PMDReport.txt)");

	bool SpotBugsStatus = StaticCodeAnalyser::SpotBugsTool(R"(..\..\spotbugs-3.1.12\bin\spotbugs.bat -textui -maxHeap 1500 -nested:false -output ..\..\SpotBugsReport.emacs -effort:max -low -sortByClass -emacs sourcepath ..\..\feereport)");

	bool MergeStatus = StaticCodeAnalyser::MergeReports(R"(..\..\SpotBugsReport.emacs)", R"(..\..\PMDReport.txt)", R"(..\..\FinalReport.csv)");

	return PMDStatus && SpotBugsStatus && MergeStatus;
}
