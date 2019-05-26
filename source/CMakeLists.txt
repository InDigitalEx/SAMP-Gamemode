project(Gamemode)

cmake_minimum_required(VERSION 2.8)

# CMake модули
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(AMXConfig)
include(AddSAMPPlugin)

# Включение инклудов и библиотек
set(INCLUDES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/includes)
set(CLASSES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CLASSES_PATH}
	${INCLUDES_PATH}
	${INCLUDES_PATH}/sampgdk
	${INCLUDES_PATH}/plugin-sdk
	${INCLUDES_PATH}/plugin-sdk/amx
)

# Подключение файлов проекта
set(Gamemode_SOURCE
	${INCLUDES_PATH}/plugin-sdk/amxplugin.cpp
	${INCLUDES_PATH}/sampgdk/sampgdk.c
	main.cpp
	${CLASSES_PATH}/CLog.cpp
	${CLASSES_PATH}/CCore.cpp
	${CLASSES_PATH}/CPlayer.cpp
)

if(WIN32)
	list(APPEND Gamemode_SOURCE plugin.def)
endif()

add_samp_plugin(Gamemode ${Gamemode_SOURCE})

# Определения для проекта
add_definitions(-DSAMPGDK_AMALGAMATION)

if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# Выходной каталог для плагина
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../plugins)