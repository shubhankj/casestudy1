// StaticCodeAnalyzer.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<string>
#include <algorithm> 
#include <regex>
#include <gtest/gtest.h>

using namespace std;

 class StaticCodeAnalyzer {

	public:

		static bool PMDTool(const char * cmd)
		{
			try {
				system(cmd);
				return true;
			}
			catch (exception e)
			{
				cout << e.what();
				return false;
			}
		}

		static bool SpotBugsTool(const char * cmd)
		{
			try {
				system(cmd);
				return true;
			}
			catch (exception e)
			{
				cout << e.what();
				return false;
			}
		}
		static bool IsColon(char ch)
		{
			return (ch == ':');
		}

		static bool IsComma(char ch)
		{
			return (ch == ',');
		}


		static bool PopulateNewReport(const char* file, ofstream *myfile)
		{
			try {
				ifstream infile;
				infile.open(file);
				string data;
				while (getline(infile, data))
				{
					//cout << data << endl;
					replace_if(data.begin(), data.end(), IsComma , '.');

					data = std::regex_replace(data, std::regex(":\\d+ .+:"), ",");
					replace_if(data.begin()+2, data.end(), IsColon, ',');

					*myfile << data << endl;
				}
				infile.close();
			}

			catch (exception e)
			{
				cout << e.what();
				return false;
			}
			return true;
		}
		static bool MergeReports(const char * file1, const char * file2, const char * outfile)
		{
			
			bool status1, status2;
			try
			{
			
				ofstream myfile(outfile);
				myfile << "SpotBugs:" << endl;
				status1=PopulateNewReport(file1, &myfile);
				
				myfile << endl << "PMD:" << endl;
				status2=PopulateNewReport(file2, &myfile);
			
				myfile.close();

			}
			catch (exception e)
			{
				cout << e.what();
				return false;
			}
			return status1 && status2; 
		}
	};

	int main(int argc, char* argv[])
	{
		testing::InitGoogleTest(&argc, argv);
		
		RUN_ALL_TESTS();

		bool PMDStatus = StaticCodeAnalyzer::PMDTool(R"(pmd-bin-6.16.0\bin\pmd.bat -d feereport -f text -R pmd-bin-6.16.0\bin\rulesets\java\quickstart.xml -r PMDReport.txt)");

		bool SpotBugsStatus = StaticCodeAnalyzer::SpotBugsTool(R"(spotbugs-3.1.12\bin\spotbugs.bat -textui -maxHeap 1500 -nested:false -output SpotBugsReport.emacs -effort:max -low -sortByClass -emacs sourcepath feereport)");

		bool MergeStatus = StaticCodeAnalyzer::MergeReports(R"(SpotBugsReport.emacs)", R"(PMDReport.txt)", R"(FinalReport.csv)");

		return PMDStatus && SpotBugsStatus && MergeStatus;
	}