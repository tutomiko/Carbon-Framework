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
#include <carbon/sys/mutex.h>
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
bool_t mutex_close(__in mutex_t mutex) {
#pragma region <locals>

#pragma endregion


	if (!CloseHandle(mutex)) {
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
bool_t mutex_create(__out mutex_t* _mutex, __in bool_t const b_initial_owner) {
#pragma region <locals>
	HANDLE hMutex = INVALID_HANDLE_VALUE;
#pragma endregion


	assert(NULL != _mutex);


	hMutex = CreateMutex(NULL, b_initial_owner, NULL);

	if (INVALID_HANDLE_VALUE == hMutex) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>
	*_mutex = (mutex_t)hMutex;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return)
bool_t mutex_release(__in mutex_t const mutex) {
#pragma region <locals>

#pragma endregion


	if (!ReleaseMutex(mutex)) {
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


FWEXPORT __success(return) bool_t mutex_wait(__in mutex_t const h_mutex, __in ulong_t const timeout_millis) {
#pragma region <locals>
	DWORD dwReturn;
#pragma endregion


	assert(NULL != h_mutex);


	if (timeout_millis == TIMEOUT_INFINITE)
		dwReturn = WaitForSingleObject(h_mutex, INFINITE);
	else {
		dwReturn = WaitForSingleObject(h_mutex, timeout_millis);
	}

	if (dwReturn != WAIT_ABANDONED && dwReturn != WAIT_OBJECT_0) {
		switch (dwReturn) {
		case WAIT_TIMEOUT:
			fw_error = FW_ERROR_TIMEOUT;

			goto $failure;
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

