// Includes
#include <plugincommon.h>
#include <sampgdk.h>

#include <vector>

#include <CCore.h>
#include <CLog.h>
#include <CPlayer.h>

// Namespaces
using namespace std;

// Variables
extern void *pAMXFunctions;

CCore* Core = new CCore;
CLog* Log = new CLog(LOG_DEBUG);

// Callbacks
PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit() {
	Core->Init();
	return Core->ShowInitMessage();
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeExit() {
	Core->Destroy();
	return Core->ShowDestroyMessage();
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerConnect(int playerid) {
	return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerDisconnect(int playerid, int reason) {
	return true;
}

// Plugin ensures
PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
	return sampgdk::Supports() | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) {
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	return sampgdk::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
	delete Core;
	delete Log;
	sampgdk::Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
	sampgdk::ProcessTick();
}