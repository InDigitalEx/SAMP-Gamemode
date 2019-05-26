#pragma once

#include <sampgdk.h>
#include <string>

using namespace std;

enum LOG_LEVELS
{
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR,
	LOG_DEBUG
};

class CLog
{
public:
	CLog();
	CLog(LOG_LEVELS level);
	bool write(LOG_LEVELS level, string info);
	bool setLogLevel(LOG_LEVELS level);
private:
	LOG_LEVELS logLevel;
};