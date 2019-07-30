#pragma once
class StaticCodeAnalyser
{
public:
	static bool PMDTool(const char * cmd);
	static bool SpotBugsTool(const char * cmd);
	static bool MergeReports(const char * file1, const char * file2, const char * outfile);
};

