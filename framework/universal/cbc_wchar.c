/*
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
#pragma region <imports>
#pragma region "export header imports"
#include <carbon/type/wchar.h>
#pragma endregion
#
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#include <assert.h>
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
bool_t wchar_isalphabet(__in wchar_t const chr) {
	return (wchar_islower(chr) || wchar_isupper(chr));
}


FWEXPORT
bool_t wchar_isalphanumeric(__in wchar_t const chr) {
	return (wchar_isalphabet(chr) || wchar_isnumber(chr));
}


FWEXPORT
bool_t wchar_islower(__in wchar_t const chr) {
	return (chr >= L'a' && chr <= L'z');
}


FWEXPORT
bool_t wchar_isnumber(__in wchar_t const chr) {
	return (chr >= L'0' && chr <= L'9');
}


FWEXPORT
bool_t wchar_isupper(__in wchar_t const chr) {
	return (chr >= L'A' && chr <= L'Z');
}


FWEXPORT
wchar_t wchar_tolower(__in wchar_t const chr) {
	return ((char_t)towlower(chr));
}


FWEXPORT
wchar_t wchar_toupper(__in wchar_t const chr) {
	return ((char_t)towupper(chr));
}

