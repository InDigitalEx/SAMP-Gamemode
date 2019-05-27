#include "CPlayer.h"

bool CPlayer::Connect(int playerid)
{
	char name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, MAX_PLAYER_NAME);
	this->Name = name;

	return false;
}

bool CPlayer::Disconnect(int playerid, int reason)
{


	return false;
}
