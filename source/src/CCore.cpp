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

bool CCore::ShowInitMessage()
{
	Log->write(LOG_INFO, (string)"»гровой режим был успешно загружен за <"
		+ to_string(clock() - this->initTime) + (string)"> мсек");

	#if defined(__DATE__) && defined(__TIME__)
	Log->write(LOG_DEBUG, (string)"¬рем€ компил€ции: " + __DATE__ + " " + __TIME__);
	#endif

	return true;
}

bool CCore::ShowDestroyMessage()
{
	Log->write(LOG_INFO, "»гровой режим был успешно выгружен");
	return true;
}
