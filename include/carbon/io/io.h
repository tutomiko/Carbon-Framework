/*
 * FileName: io.h
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
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <misc constant definitions>
#define LINE_TERMINATOR				"\r\r\n"
#pragma endregion


#pragma region <TCS macro definitions>
#if __CHARSET == CHARSET_UNICODE
#define tprintf						wprintf
#define tprintln(FORMAT, ...)		wprintf(FORMAT TOWSTRING(LINE_TERMINATOR), ##__VA_ARGS__)
#define tsprintf					swprintf
#elif __CHARSET == CHARSET_MULTIBYTE
#define tprintf						printf
#define tprintln(FORMAT, ...)		printf(FORMAT LINE_TERMINATOR, ##__VA_ARGS__)
#define tsprintf					sprintf
#endif // __CHARSET
#pragma endregion


