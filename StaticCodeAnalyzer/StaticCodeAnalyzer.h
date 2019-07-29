#pragma once
#include <fstream>

class StaticCodeAnalyzer
{
public:
	static bool IsColon(char ch);
	static bool IsComma(char ch);
	static bool PMDTool(const char * cmd);
	static bool SpotBugsTool(const char * cmd);
	static bool MergeReports(const char * file1, const char * file2, const char * outfile);
	static bool PopulateNewReport(const char* file, std::ofstream *myfile);
};
