#ifndef CCore_H
#define CCore_H

#include <sampgdk.h>
#include <config.h>
#include <ctime>
#include <string>

using namespace std;


class CCore
{
public:
	CCore();
	void Init();
	void Destroy();
	void UpdateServerData();
	bool PrintInitMessage();
	bool PrintDestroyMessage();
private:
	const clock_t initTime;
	string gamemode;
	string hostname;
	string language;
	string weburl;
	string mapname;
};

#endif // CCore_H