#ifndef CCore_H
#define CCore_H

#include <sampgdk.h>
#include <string>
#include <ctime>

#include <config.h>
#include <CLog.h>

extern CLog* Log;


using namespace std;


class CCore
{
public:
	CCore();
	void Init();
	void Destroy();
	void UpdateServerData();
	bool ShowInitMessage();
	bool ShowDestroyMessage();
private:
	const clock_t initTime;
	string gamemode;
	string hostname;
	string language;
	string weburl;
	string mapname;
};

#endif // CCore_H