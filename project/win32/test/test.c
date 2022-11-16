#
#pragma region <imports>
#pragma region "export header imports"

#pragma endregion
#
#pragma region "platform-dependent imports"
#include <Windows.h>
#pragma endregion
#
#pragma region "platform-independent imports"
#include <stdio.h>
#pragma endregion
#
#pragma region "3rd-party imports"
//#define _CARBON_DYNAMIC_LINKAGE
#define _CARBON_STATIC_LINKAGE
#define _CARBONPLUS_ENABLE_DEPRECATED_FEATURES
#define _CARBONPLUS_ENABLE_EXPERIMENTAL_FEATURES
#include "../../../include/carbon.h"

#if defined(_CARBON_DYNAMIC_LINKAGE)
#pragma comment(lib, "../../../dist/carbon-x86 (Debug).lib")
#elif defined(_CARBON_STATIC_LINKAGE)
#pragma comment(lib, "../../../lib/carbon-x86 (Debug).lib")
#endif
#pragma endregion
#
#pragma region "shared imports"

#pragma endregion
#
#pragma region "local imports"

#pragma endregion         
#pragma endregion
#
#
int _cdecl main(int argc, char** argv) {

}