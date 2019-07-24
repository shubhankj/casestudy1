// StaticCodeAnalyzer.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string data;
	string file1 = "..\\ReportFile.emacs";
	string file2 = "..\\output.txt";
	string outfile = "..\\FinalReport.txt";
	ifstream infile1, infile2;
	ofstream myfile(outfile);

	myfile << "SpotBugs:" << endl;
	infile1.open(file1);
	while (getline(infile1, data))
	{
		cout << data << endl;
		myfile << data << endl;
	}

	myfile <<endl<< "PMD:" << endl;
	infile2.open(file2);
	while (getline(infile2, data))
	{
		cout << data << endl;
		myfile << data << endl;
	}
	infile1.close();
	infile2.close();
	myfile.close();
	return 0;
}