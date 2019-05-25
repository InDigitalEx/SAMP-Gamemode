// Includes
#include <plugincommon.h>
#include <sampgdk.h>
#include <stdio.h>
#include <string>

#include "config.h"

// namespaces
using sampgdk::logprintf;
using namespace std;


// Callbacks
PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit() {
	auto lasttime = GetTickCount();




	// TODO: ������� �� � CCore
	logprintf("[Gamemode] ������� ����� ��� ������� �������� �� <%d> ����",
		GetTickCount()-lasttime);

	#ifdef __DATE__ && __TIME__
	logprintf("����� ����������: %s %s", __DATE__, __TIME__);
	#endif

	return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeExit() {
	auto lasttime = GetTickCount();




	// TODO: ������� �� � CCore
	logprintf("[Gamemode] ������� ����� ��� ������� �������� �� <%d> ����",
		GetTickCount() - lasttime);

	return true;
}

// Plugin ensures
PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
	return sampgdk::Supports() | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) {
	return sampgdk::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
	sampgdk::Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
	sampgdk::ProcessTick();
}