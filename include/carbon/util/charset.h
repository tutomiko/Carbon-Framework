/*
 * FileName: string.h
 *
 * Written by tutomiko <https://www.github.com/tutomiko>
 *
 * Copyright (c) 2022, Tuomas Kontiainen
 *
 * This file is a part of Carbon Framework <https://github.com/tutomiko/Carbon-Framework>
 * Carbon Framework is a free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later versions.
 *
 * Carbon Framework is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Carbon Framework. If not,
 * see <http://www.gnu.org/licenses/>.
 */
#
#pragma once
#
#pragma region <imports>
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"

#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <fwbase.h>
#include <carbon/type/char.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <charset constant definitions>
#define CHARSET_MULTIBYTE		1
#define CHARSET_UNICODE			2
#pragma endregion


#pragma region <charset string constant definitions>
#define S_CHARSET_MULTIBYTE		"UTF-8"
#define S_CHARSET_UNICODE		"UTF-16"
#pragma endregion



#ifdef __CHARSET
#error '__CHARSET' definition prior to evaluation: undefine to build successfully
#endif // __CHARSET

#if defined(_MBCS) && _MBCS == 1
#define __CHARSET		CHARSET_MULTIBYTE
#define __S_CHARSET		S_CHARSET_MULTIBYTE
#elif defined(_UNICODE) && _UNICODE == 1
#define __CHARSET		CHARSET_UNICODE
#define __S_CHARSET		S_CHARSET_UNICODE
#else
#error no charset defined: define '__CHARSET' to build successfully
#endif


__inline static const char* charsetstr(__in int charset) {
	switch (charset){
	case CHARSET_MULTIBYTE:
		return S_CHARSET_MULTIBYTE;
	case CHARSET_UNICODE:
		return S_CHARSET_UNICODE;
	default:
		return NULL;
	}
}


