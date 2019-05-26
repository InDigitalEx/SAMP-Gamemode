#include "CLog.h"

CLog::CLog()
{
	this->logLevel = LOG_INFO;
}

CLog::CLog(LOG_LEVELS level)
{
	this->logLevel = level;
}

bool CLog::write(LOG_LEVELS level, string info)
{
	string message = "[GameMode: ";

	switch (level)
	{
	case LOG_INFO:
		if (this->logLevel < LOG_INFO) return false;
		message += "Info] ";
		break;
	case LOG_WARNING:
		if (this->logLevel < LOG_WARNING) return false;
		message += "Warning] ";
		break;
	case LOG_ERROR:
		if (this->logLevel < LOG_ERROR) return false;
		message += "Error] ";
		break;
	case LOG_DEBUG:
		if (this->logLevel < LOG_DEBUG) return false;
		message += "Debug] ";
		break;
	default:
		return false;
	}

	message += info;
	sampgdk::logprintf(message.c_str());
	return true;
}

bool CLog::setLogLevel(LOG_LEVELS level)
{
	this->logLevel = level;
	return false;
}
