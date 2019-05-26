// Includes
#include <plugincommon.h>
#include <sampgdk.h>
#include <stdio.h>
#include <string>

#include "CCore.h"

// namespaces
using sampgdk::logprintf;
using namespace std;


// Variables
extern void* pAMXFunctions;

CCore* Core = new(CCore);

// Callbacks
PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit() {
	Core->Init();
	return Core->PrintInitMessage();
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeExit() {
	Core->Destroy();
	return Core->PrintDestroyMessage();
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
	sampgdk::Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
	sampgdk::ProcessTick();
}