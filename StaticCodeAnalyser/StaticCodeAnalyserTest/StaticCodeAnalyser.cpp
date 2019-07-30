#include "pch.h"
#include "StaticCodeAnalyser.h"
#include<fstream>
#include<iostream>
#include "Utility.h"

bool StaticCodeAnalyser::PMDTool(const char * cmd)
{
	try {
		return system(cmd);
	}
	catch (exception e)
	{
		cout << e.what();
		return false;
	}
}

bool StaticCodeAnalyser::SpotBugsTool(const char * cmd)
{
	try {
		return system(cmd);
	}
	catch (exception e)
	{
		cout << e.what();
		return false;
	}
}

bool StaticCodeAnalyser::MergeReports(const char * file1, const char * file2, const char * outfile)
{
	bool status1, status2;
	try
	{
		ofstream myfile(outfile);
		myfile << "SpotBugs:" << endl;
		status1 = Utility::WriteFileToCSV(file1, &myfile);

		myfile << endl << "PMD:" << endl;
		status2 = Utility::WriteFileToCSV(file2, &myfile);

		myfile.close();
	}
	catch (exception e)
	{
		cout << e.what();
		return false;
	}
	return status1 && status2;
}
