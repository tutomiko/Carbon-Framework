/*
 * FileName: strings.h
 *
 * Written by Tuomas Kontiainen <https://www.github.com/tutomiko>
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
#ifdef __cplusplus
#include <cstdio>
#else
#include <stdio.h>
#endif // __cplusplus
#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <carbon/cbcbase.h>
#include <carbon/type/string.h>
#include <carbon/type/wstring.h>
#include <carbon/type/tstring.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <implicit macro definitions>
#define __QUOTE(S)			"\"" S "\""
#define __QUOTEW(S)			L"\"" S L"\""

#define __STRLEN(S)			((sizeof(S) / sizeof(char)) - 1)

#define __TSTRLEN(S)		((sizeof(S) / sizeof(tchar_t)) - 1)

#define __WSTRLEN(S)		((sizeof(S) / sizeof(wchar_t)) - 1)

#define __TOSTRING(T)		#T

#define __TOWSTRING(T)		L ## T

#if __CHARSET == CHARSET_UNICODE
#define __TSTRING(T)		L ## T
#elif __CHARSET == CHARSET_MULTIBYTE
#define __TSTRING(T)		T
#endif // __CHARSET
#pragma endregion


#pragma region <explicit macro definitions>
/// ...
#define QUOTE(S)			__QUOTE(S)

/// ...
#define QUOTEW(S)			__QUOTEW(S)

/// Get length of multibyte string at compile-time
#define STRLEN(S)			__STRLEN(S)

/// Get length of target charset-compatible string at compile-time
#define TSTRLEN(S)			__TSTRLEN(S)

/// Get length of unicode string at compile-time
#define WSTRLEN(S)			__WSTRLEN(S)

/// Compile-time variable to string
#define TOSTRING(T)			__TOSTRING(T)

/// Compile-time string quote (multibyte to unicode conversion)
#define TOWSTRING(T)		__TOWSTRING(T)

/// String to target charset-compatible string at compile-time
#define TSTRING(S)			__TSTRING(S)
#pragma endregion


