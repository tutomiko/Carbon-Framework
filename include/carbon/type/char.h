/*
 * FileName: char.h
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

#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"

#pragma endregion
#
#pragma region "local imports"
#include <fwbase.h>
#include <carbon/util/charset.h>
#pragma endregion
#pragma endregion
#
#
/// <summary>
/// 8-bit character type.
/// </summary>
typedef char char_t;


FWIMPORT
bool_t char_isalphabet(
	__in char_t const chr
);


FWIMPORT
bool_t char_isalphanumeric(
	__in char_t const chr
);


FWIMPORT
bool_t char_islower(
	__in char_t const chr
);


FWIMPORT
bool_t char_isnumber(
	__in char_t const chr
);


FWIMPORT
bool_t char_isupper(
	__in char_t const chr
);


FWIMPORT
char_t char_tolower(
	__in char_t const chr
);


FWIMPORT
char_t char_toupper(
	__in char_t const chr
);


