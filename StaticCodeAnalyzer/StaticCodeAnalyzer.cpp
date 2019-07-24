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
	char data[100];
	string file1 = "..\\ReportFile.emacs";
	string file2 = "..\\output.txt";
	ifstream infile1, infile2;
	infile1.open(file1);
	infile2.open(file2);
	while(infile1)
	{

	infile1 >> data;
	cout << data;
		
	}
	cout << endl;
	infile2 >> data;
	cout << data<<endl;


	

    return 0;
}