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
#include <carbon/sys/thread.h>
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
CBCEXPORT __success(return) 
bool_t thread_close(__in thread_t const thread) {
#pragma region <locals>

#pragma endregion


	CloseHandle(thread);


$success:
#pragma region <returns>

#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


CBCEXPORT __success(return) 
bool_t thread_create(__in void* f_runnable, __in_opt void* parameter, __in bool_t const b_create_suspended, __out thread_t* _thread, __out_opt ulong_t* _thread_id) {
#pragma region <locals>
	DWORD  dwCreateFlags = 0UL,
	       dwThreadId;
	HANDLE hThread = INVALID_HANDLE_VALUE;
#pragma endregion


	assert(NULL != _thread);


	if (b_create_suspended) {
		dwCreateFlags |= CREATE_SUSPENDED;
	}

	hThread = CreateThread(
		NULL,
		0L,
		(LPTHREAD_START_ROUTINE)f_runnable,
		parameter,
		dwCreateFlags,
		&dwThreadId
	);

	if (INVALID_HANDLE_VALUE == hThread) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>
	*_thread = hThread;

	if (NULL != _thread_id) {
		*_thread_id = dwThreadId;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (INVALID_HANDLE_VALUE != hThread) {
		CloseHandle(hThread);
	}
#pragma endregion


	return false;
}


CBCEXPORT
void thread_current(__out thread_t* _thread) {
	assert(NULL != _thread);


	*_thread = GetCurrentThread();
}


CBCEXPORT
void thread_exit(__in unsigned long const exitcode) {
	ExitThread(exitcode);
}


CBCEXPORT 
__success(return) bool_t thread_get_exit(__in thread_t const h_thread, __out ulong_t* _exitcode) {
#pragma region <locals>
	ulong_t exitcode;
#pragma endregion


	assert(NULL != h_thread);
	assert(NULL != _exitcode);

	
	if (!GetExitCodeThread(h_thread, &exitcode)) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>
	*_exitcode = exitcode;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


CBCEXPORT 
__success(return) bool_t thread_get_id(__in_opt thread_t const thread, __out ulong_t* _thread_id) {
#pragma region <locals>
	ulong_t thread_id;
#pragma endregion


	assert(NULL != _thread_id);

	
	if (NULL != thread)
		thread_id = GetThreadId(thread);
	else {
		thread_id = GetCurrentThreadId();
	}


$success:
#pragma region <returns>
	*_thread_id = thread_id;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


CBCEXPORT __success(return) bool_t thread_join(__in thread_t const h_thread, __in ulong_t const timeout_millis) {
#pragma region <locals>
	DWORD dwReturn;
#pragma endregion


	assert(NULL != h_thread);


	if (timeout_millis == TIMEOUT_INFINITE) 
		dwReturn = WaitForSingleObject(h_thread, INFINITE);
	else {
		dwReturn = WaitForSingleObject(h_thread, timeout_millis);
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


CBCEXPORT __success(return)
bool_t thread_kill(__in thread_t const thread) {
#pragma region <locals>

#pragma endregion

	
	if (!TerminateThread(thread, EXIT_FAILURE)) {
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

