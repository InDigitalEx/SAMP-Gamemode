project(Gamemode)

cmake_minimum_required(VERSION 2.8)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(AMXConfig)
include(AddSAMPPlugin)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/includes
	${CMAKE_CURRENT_SOURCE_DIR}/includes/sampgdk
	${CMAKE_CURRENT_SOURCE_DIR}/includes/plugin-sdk
	${CMAKE_CURRENT_SOURCE_DIR}/includes/plugin-sdk/amx
)

add_definitions(-DSAMPGDK_AMALGAMATION)

add_samp_plugin(Gamemode
	${CMAKE_CURRENT_SOURCE_DIR}/includes/plugin-sdk/amxplugin.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/includes/sampgdk/sampgdk.c
	plugin.def
	main.cpp
)

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../plugins)