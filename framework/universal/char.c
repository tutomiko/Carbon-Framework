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
#pragma region <imports>
#pragma region "export header imports"
#include <carbon/type/char.h>
#pragma endregion
#
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#include <assert.h>
#include <ctype.h>
#pragma endregion
#
#pragma region "3rd-party imports"

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
FWEXPORT
bool_t char_isalphabet(__in char_t const chr) {
	return (char_islower(chr) || char_isupper(chr));
}


FWEXPORT
bool_t char_isalphanumeric(__in char_t const chr) {
	return (char_isalphabet(chr) || char_isnumber(chr));
}


FWEXPORT
bool_t char_islower(__in char_t const chr) {
	return (chr >= 'a' && chr <= 'z');
}


FWEXPORT
bool_t char_isnumber(__in char_t const chr) {
	return (chr >= '0' && chr <= '9');
}


FWEXPORT
bool_t char_isupper(__in char_t const chr) {
	return (chr >= 'A' && chr <= 'Z');
}


FWEXPORT
char_t char_tolower(__in char_t const chr) {
	return ((char_t)tolower(chr));
}


FWEXPORT
char_t char_toupper(__in char_t const chr) {
	return ((char_t)toupper(chr));
}

