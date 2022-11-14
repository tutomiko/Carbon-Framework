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
#include <carbon/error.h>
#pragma endregion
#
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
#include <carbon/sys/concurrency.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <globals>
_thread_local static fw_error_t g_error_code = FW_ERROR_SUCCESS;
_thread_local static fw_error_t g_pcall_stat;
#pragma endregion


FWEXPORT
void FWClearLastError(void) {
	FWSetLastError(FW_ERROR_SUCCESS);
}


FWEXPORT
fw_error_t FWGetLastError(void) {
	return g_error_code;
}


FWEXPORT
fw_error_t* FWGetLastErrorStorage(void) {
	return &g_error_code;
}


FWEXPORT
void FWProtCallBegin(void) {
	g_pcall_stat = FWGetLastError();
}


FWEXPORT
void FWProtCallEnd(void) {
	FWSetLastError(g_pcall_stat);
}


FWEXPORT
void FWSetLastError(__in fw_error_t const NewErrorCode) {
	g_error_code = NewErrorCode;
}

