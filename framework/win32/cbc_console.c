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
#include <carbon/sys/console.h>
#pragma endregion
#
#pragma region "platform-dependent imports"
#include <Windows.h>
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
FWEXPORT __success(return)
bool_t console_set_title(__in string_t const s_title) {
#pragma region <locals>

#pragma endregion


	assert(NULL != s_title);


	if (!SetConsoleTitleA(s_title)) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>

#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t console_set_title_w(__in wstring_t const s_title) {
#pragma region <locals>

#pragma endregion


	assert(NULL != s_title);


	if (!SetConsoleTitleW(s_title)) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>

#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}

