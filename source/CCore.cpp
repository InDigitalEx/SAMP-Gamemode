#include "CCore.h"

CCore::CCore() : initTime(clock())
{

}

void CCore::Init()
{
	EnableStuntBonusForAll(false);
	DisableInteriorEnterExits();

	this->gamemode = (string)SERVER_GAMEMODE;
	this->hostname = "hostname " + (string)SERVER_GAMEMODE;
	this->language = "language " + (string)SERVER_LANGUAGE;
	this->weburl = "weburl " + (string)SERVER_WEBURL;
	this->mapname = "mapname " + (string)SERVER_MAPNAME;

	this->UpdateServerData();
}

void CCore::Destroy()
{
	this->gamemode = "Loading..";
	this->hostname = "hostname Reload Role Play | Loading...";
	this->language = "language Loading..";
	this->weburl = "weburl Loading...";
	this->mapname = "mapname Loading..";

	this->UpdateServerData();
}

void CCore::UpdateServerData() {
	SetGameModeText(this->gamemode.c_str());
	SendRconCommand(this->hostname.c_str());
	SendRconCommand(this->language.c_str());
	SendRconCommand(this->weburl.c_str());
	SendRconCommand(this->mapname.c_str());
}

bool CCore::PrintInitMessage()
{
	sampgdk::logprintf("[Gamemode] »гровой режим был успешно загружен за <%d> мсек",
		clock()-this->initTime);

	#if defined(__DATE__) && defined(__TIME__)
		sampgdk::logprintf("¬рем€ компил€ции: %s %s", __DATE__, __TIME__);
	#endif

	return true;
}

bool CCore::PrintDestroyMessage()
{
	sampgdk::logprintf("[Gamemode] »гровой режим был успешно выгружен");
	return true;
}
