// StaticCodeAnalyzer.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

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

		static bool MergeReports(const char * file1, const char * file2, const char * outfile)
		{
			string data;
			try
			{
				ifstream infile;
				ofstream myfile(outfile);
				myfile << "SpotBugs:" << endl;
				try
				{
					infile.open(file1);
				}
				catch (exception e)
				{
					cout << e.what();
					return false;
				}

				while (getline(infile, data))
				{
					//cout << data << endl;
					myfile << data << endl;
				}

				myfile << endl << "PMD:" << endl;
				try
				{
					infile.open(file2);
				}
				catch (exception e)
				{
					cout << e.what();
					return false;
				}

				while (getline(infile, data))
				{
					//cout << data << endl;
					myfile << data << endl;
				}

				infile.close();
				myfile.close();

			}
			catch (exception e)
			{
				cout << e.what();
				return false;
			}
			return true;
		}
	};

	int main()
	{
		bool PMDStatus = StaticCodeAnalyzer::PMDTool(R"(pmd-bin-6.16.0\bin\pmd.bat -d HelloWorld -f text -R pmd-bin-6.16.0\bin\rulesets\java\quickstart.xml -r PMDReport.txt)");

		bool SpotBugsStatus = StaticCodeAnalyzer::SpotBugsTool(R"(spotbugs-3.1.12\bin\spotbugs.bat -textui -maxHeap 1500 -nested:false -output SpotBugsReport.emacs -effort:max -low -sortByClass -emacs sourcepath HelloWorld)");

		bool MergeStatus = StaticCodeAnalyzer::MergeReports(R"(SpotBugsReport.emacs)", R"(PMDReport.txt)", R"(FinalReport.txt)");

		return PMDStatus && SpotBugsStatus && MergeStatus;
	}