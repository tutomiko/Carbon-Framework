#
#pragma once
#
#pragma region <imports>
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif // __cplusplus
#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <carbon/cbcbase.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
CBCIMPORT
void cprintfx(
	__in const char* format, 
	__in_opt         ...
);


