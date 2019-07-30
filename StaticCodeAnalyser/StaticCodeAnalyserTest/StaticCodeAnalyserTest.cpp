#include "pch.h"
#include "StaticCodeAnalyser.h"
#include "Utility.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("IsColonTest")
{
	REQUIRE(true == Utility::IsColon(':'));
	REQUIRE(false == Utility::IsColon(';'));
	REQUIRE(false == Utility::IsColon('1'));
	REQUIRE(false == Utility::IsColon('a'));
}

TEST_CASE("IsCommaTest")
{
	REQUIRE(true == Utility::IsComma(','));
	REQUIRE(false == Utility::IsComma('.'));
	REQUIRE(false == Utility::IsComma('1'));
	REQUIRE(false == Utility::IsComma('a'));
}

TEST_CASE("WriteFileToCSVTest")
{
	ofstream outfile("Random.csv");
	fstream infile("ExistingFile.txt",ios::out);
	REQUIRE(true == Utility::WriteFileToCSV("ExistingFile.txt", &outfile));
	remove("NonExistingFile.txt");
	REQUIRE(false == Utility::WriteFileToCSV("NonExistingFile.txt", &outfile));
	infile.close();
	outfile.close();
	remove("ExistingFile.txt");
	remove("Random.csv");
}

TEST_CASE("MergeReportsTest")
{
	fstream infile1("ExistingFile1.txt",ios::out);
	fstream infile2("ExistingFile2.txt",ios::out);
	REQUIRE(true == StaticCodeAnalyser::MergeReports("ExistingFile1.txt", "ExistingFile2.txt", "Random.csv"));
	REQUIRE(false == StaticCodeAnalyser::MergeReports("NonExistingFile1.txt", "ExistingFile2.txt", "Random.csv"));
	infile1.close();
	infile2.close();
	remove("ExistingFile1.txt");
	remove("ExistingFile2.txt");
	remove("Random.csv");
}

TEST_CASE("PMDToolTest")
{
	REQUIRE(true == StaticCodeAnalyser::PMDTool(R"(..\..\pmd-bin-6.16.0\bin\pmd.bat -d ..\..\feereport -f text -r PMDReport.txt -R ..\..\pmd-bin-6.16.0\bin\rulesets\java\quickstart.xml)"));
	remove("PMDReport.txt");
}

TEST_CASE("SpotBugsToolTest")
{
	REQUIRE(true == StaticCodeAnalyser::SpotBugsTool(R"(..\..\spotbugs-3.1.120\bin\spotbugs.bat -textui -maxHeap 1500 -nested:false -output SpotBugsReport.emacs -effort:max -low -sortByClass -emacs sourcepath ..\..\feereport)"));	//jugaad
	remove("SpotBugsReport.emacs");
}