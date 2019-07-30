#include "pch.h"
#include "Utility.h"
#include<iostream>
#include <fstream>
#include<algorithm>
#include<string>
#include<regex>

bool Utility::IsColon(char ch)
{
	return (ch == ':');
}

bool Utility::IsComma(char ch)
{
	return (ch == ',');
}

bool Utility::WriteFileToCSV(const char* file, ofstream *myfile)
{
	ifstream infile;
	infile.open(file);
	if (!infile) 
	{
		return false;
	}

	string data;
	while (getline(infile, data))
	{
		//cout << data << endl;
		replace_if(data.begin(), data.end(), IsComma, '.');

		data = std::regex_replace(data, std::regex(":\\d+ .+:"), ",");
		replace_if(data.begin() + 2, data.end(), IsColon, ',');

		*myfile << data << endl;
	}
	infile.close();
	return true;
}