/*
 * FileName: string.h
 *
 * Written by tutomiko <https://www.github.com/tutomiko>
 *
 * Copyright (c) 2022, Tuomas Kontiainen
 *
 * This file is a part of Fireworks Framework <https://github.com/tutomiko/Fireworks-Framework>
 * Fireworks Framework is a free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later versions.
 *
 * Fireworks Framework is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Fireworks Framework. If not,
 * see <http://www.gnu.org/licenses/>.
 */
#
#pragma region <imports>
#pragma region "export header imports"
#include <fireworks/sys/event.h>
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
bool_t event_close(__in event_t h_event) {
#pragma region <locals>

#pragma endregion


	assert(NULL != h_event);


	if (!CloseHandle(h_event)) {
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
bool_t event_create(__out event_t* _h_event, __in bool_t const b_manual_reset, __in bool_t const b_initial_set) {
#pragma region <locals>
	HANDLE h_event = INVALID_HANDLE_VALUE;
#pragma endregion


	assert(NULL != _h_event);


	h_event = CreateEventW(NULL, b_manual_reset, b_initial_set, NULL);

	if (INVALID_HANDLE_VALUE == h_event) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>
	*_h_event = h_event;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return)
bool_t event_reset(__in event_t const h_event) {
#pragma region <locals>

#pragma endregion


	assert(NULL != h_event);


	if (!ResetEvent(h_event)) {
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
bool_t event_set(__in event_t const h_event) {
#pragma region <locals>

#pragma endregion


	assert(NULL != h_event);


	if (!SetEvent(h_event)) {
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


FWEXPORT __success(return) bool_t event_wait(__in event_t const h_event, __in ulong_t const timeout_millis) {
#pragma region <locals>
	DWORD dwReturn;
#pragma endregion


	assert(NULL != h_event);


	if (timeout_millis == TIMEOUT_INFINITE)
		dwReturn = WaitForSingleObject(h_event, INFINITE);
	else {
		dwReturn = WaitForSingleObject(h_event, timeout_millis);
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

