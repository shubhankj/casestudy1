#pragma once
#include<fstream>
using namespace std;
class Utility
{
public:
	static bool IsColon(char ch);
	static bool IsComma(char ch);
	static bool WriteFileToCSV(const char* file, ofstream *myfile);
};

