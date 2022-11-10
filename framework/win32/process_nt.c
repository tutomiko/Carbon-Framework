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
#include <carbon/sys/process.h>
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
#include <carbon/sys/platform.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
FWEXPORT __success(return) bool_t process_close(__in process_t const h_process) {
#pragma region <locals>

#pragma endregion


	CloseHandle(h_process);


$success:
#pragma region <returns>

#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWIMPORT __success(return) bool_t process_create(__in string_t const s_file_path, __in uint_t const n_parameter_count, __in_opt string_t* a_s_parameters, __out process_t* _h_process, __out_opt thread_t* _h_thread) {
#pragma region <locals>
	BOOL                b_created = FALSE;
	HANDLE              h_process = INVALID_HANDLE_VALUE;
	HANDLE              h_thread = INVALID_HANDLE_VALUE;
	uint_t              n_call_string_length = 0;
	uint_t              n_call_string_length_b = 0;
	PROCESS_INFORMATION o_process_info;
	STARTUPINFOA        o_startup_info;
	string_t            s_call_string = NULL;
#pragma endregion


	assert(NULL != s_file_path);
	assert(NULL != _h_process);


	/*
	 * Build call string;
	 */
	if (n_parameter_count > 0) {
		assert(NULL != a_s_parameters);

		n_call_string_length++;								// "
		n_call_string_length += string_length(s_file_path);	// <executable-file-path>
		n_call_string_length++;								// "
		n_call_string_length++;								// [space]

		for (int_t i = 0; i < n_parameter_count; i++) {
			string_t s_parameter;

			s_parameter = a_s_parameters[i];

			n_call_string_length++;								// "
			n_call_string_length += string_length(s_parameter);	// <parameter>
			n_call_string_length++;								// "

			if ((i + 1) < n_parameter_count) {
				n_call_string_length++;							// [space]
			}
		}

		s_call_string = (string_t)malloc((n_call_string_length + 1) * sizeof(char_t));

		if (NULL == s_call_string) {
			goto $failure;
		}

		memzero(s_call_string, (n_call_string_length + 1) * sizeof(char_t));

		string_append(s_call_string, &n_call_string_length_b, "\"");
		string_append(s_call_string, &n_call_string_length_b, s_file_path);
		string_append(s_call_string, &n_call_string_length_b, "\"");
		string_append(s_call_string, &n_call_string_length_b, " ");

		for (int_t i = 0; i < n_parameter_count; i++) {
			string_t s_parameter;

			s_parameter = a_s_parameters[i];

			string_append(s_call_string, &n_call_string_length_b, "\"");
			string_append(s_call_string, &n_call_string_length_b, s_parameter);
			string_append(s_call_string, &n_call_string_length_b, "\"");

			if ((i + 1) < n_parameter_count) {
				string_append(s_call_string, &n_call_string_length_b, " ");
			}
		}

		assert(n_call_string_length_b == n_call_string_length);
	}

	/*
	 * Create process;
	 */
	memzero(&o_startup_info, sizeof o_startup_info);
	memzero(&o_process_info, sizeof o_process_info);

	b_created = CreateProcessA(
		s_file_path,
		s_call_string,
		NULL,
		NULL,
		FALSE,
		0L,
		NULL,
		NULL,
		&o_startup_info,
		&o_process_info
	);

	if (!b_created) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	/*
	 * ...
	 */
	h_process = o_process_info.hProcess;
	h_thread = o_process_info.hThread;

	if (NULL == _h_thread) {
		CloseHandle(o_process_info.hThread);

		o_process_info.hThread = INVALID_HANDLE_VALUE;
	}

	/*
	 * ...
	 */
	if (NULL != s_call_string) {
		free(s_call_string);

		n_call_string_length = n_call_string_length_b = 0;
	}


$success:
#pragma region <returns>
	if (NULL != _h_process) {
		*_h_process = h_process;
	}

	if (NULL != _h_thread) {
		*_h_thread = h_thread;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (NULL != s_call_string) {
		free(s_call_string);
	}

	if (b_created) {
		if (INVALID_HANDLE_VALUE != h_thread) {
			CloseHandle(h_thread);
		}

		if (INVALID_HANDLE_VALUE != h_process) {
			CloseHandle(h_process);
		}
	}
#pragma endregion


	return false;
}


FWIMPORT __success(return) bool_t process_create_w(__in wstring_t const s_file_path, __in uint_t const n_parameter_count, __in_opt wstring_t* a_s_parameters, __out process_t* _h_process, __out_opt thread_t* _h_thread) {
#pragma region <locals>
	BOOL                b_created = FALSE;
	HANDLE              h_process = INVALID_HANDLE_VALUE;
	HANDLE              h_thread = INVALID_HANDLE_VALUE;
	uint_t              n_call_string_length = 0;
	uint_t              n_call_string_length_b = 0;
	PROCESS_INFORMATION o_process_info;
	STARTUPINFOW        o_startup_info;
	wstring_t           s_call_string = NULL;
#pragma endregion


	assert(NULL != s_file_path);
	assert(NULL != _h_process);


	/*
	 * Build call string;
	 */
	if (n_parameter_count > 0) {
		assert(NULL != a_s_parameters);

		n_call_string_length++;										// "
		n_call_string_length += wstring_length(s_file_path);		// <executable-file-path>
		n_call_string_length++;										// "
		n_call_string_length++;										// [space]

		for (int_t i = 0; i < n_parameter_count; i++) {
			wstring_t s_parameter;

			s_parameter = a_s_parameters[i];

			n_call_string_length++;									// "
			n_call_string_length += wstring_length(s_parameter);	// <parameter>
			n_call_string_length++;									// "

			if ((i + 1) < n_parameter_count) {
				n_call_string_length++;								// [space]
			}
		}

		s_call_string = (wstring_t)malloc((n_call_string_length + 1) * sizeof(wchar_t));

		if (NULL == s_call_string) {
			goto $failure;
		}

		memzero(s_call_string, (n_call_string_length + 1) * sizeof(wchar_t));

		wstring_append(s_call_string, &n_call_string_length_b, L"\"");
		wstring_append(s_call_string, &n_call_string_length_b, s_file_path);
		wstring_append(s_call_string, &n_call_string_length_b, L"\"");
		wstring_append(s_call_string, &n_call_string_length_b, L" ");

		for (int_t i = 0; i < n_parameter_count; i++) {
			wstring_t s_parameter;

			s_parameter = a_s_parameters[i];

			wstring_append(s_call_string, &n_call_string_length_b, L"\"");
			wstring_append(s_call_string, &n_call_string_length_b, s_parameter);
			wstring_append(s_call_string, &n_call_string_length_b, L"\"");

			if ((i + 1) < n_parameter_count) {
				wstring_append(s_call_string, &n_call_string_length_b, L" ");
			}
		}

		assert(n_call_string_length_b == n_call_string_length);
	}

	/*
	 * Create process;
	 */
	memzero(&o_startup_info, sizeof o_startup_info);
	memzero(&o_process_info, sizeof o_process_info);

	b_created = CreateProcessW(
		s_file_path,
		s_call_string,
		NULL,
		NULL,
		FALSE,
		0L,
		NULL,
		NULL,
		&o_startup_info,
		&o_process_info
	);

	if (!b_created) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	/*
	 * ...
	 */
	h_process = o_process_info.hProcess;
	h_thread = o_process_info.hThread;

	if (NULL == _h_thread) {
		CloseHandle(o_process_info.hThread);

		o_process_info.hThread = INVALID_HANDLE_VALUE;
	}

	/*
	 * ...
	 */
	if (NULL != s_call_string) {
		free(s_call_string);

		n_call_string_length = n_call_string_length_b = 0;
	}


$success:
#pragma region <returns>
	if (NULL != _h_process) {
		*_h_process = h_process;
	}

	if (NULL != _h_thread) {
		*_h_thread = h_thread;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (NULL != s_call_string) {
		free(s_call_string);
	}

	if (b_created) {
		if (INVALID_HANDLE_VALUE != h_thread) {
			CloseHandle(h_thread);
		}

		if (INVALID_HANDLE_VALUE != h_process) {
			CloseHandle(h_process);
		}
	}
#pragma endregion


	return false;
}


FWIMPORT __success(return) bool_t process_create_ex(__in string_t const s_file_path, __in uint_t const n_parameter_count, __in_opt string_t* a_s_parameters, __in_opt ulong_t const options, __out process_t* _h_process, __out_opt thread_t* _h_thread) {
#pragma region <locals>
	BOOL                b_created = FALSE;
	DWORD               flags = 0;
	HANDLE              h_process = INVALID_HANDLE_VALUE;
	HANDLE              h_thread = INVALID_HANDLE_VALUE;
	uint_t              n_call_string_length = 0;
	uint_t              n_call_string_length_b = 0;
	PROCESS_INFORMATION o_process_info;
	STARTUPINFOA        o_startup_info;
	string_t            s_call_string = NULL;
#pragma endregion


	assert(NULL != s_file_path);
	assert(NULL != _h_process);


	/*
	 * Build call string;
	 */
	if (n_parameter_count > 0) {
		assert(NULL != a_s_parameters);

		n_call_string_length++;								// "
		n_call_string_length += string_length(s_file_path);	// <executable-file-path>
		n_call_string_length++;								// "
		n_call_string_length++;								// [space]

		for (int_t i = 0; i < n_parameter_count; i++) {
			string_t s_parameter;

			s_parameter = a_s_parameters[i];

			n_call_string_length++;								// "
			n_call_string_length += string_length(s_parameter);	// <parameter>
			n_call_string_length++;								// "

			if ((i + 1) < n_parameter_count) {
				n_call_string_length++;							// [space]
			}
		}

		s_call_string = (string_t)malloc((n_call_string_length + 1) * sizeof(char_t));

		if (NULL == s_call_string) {
			goto $failure;
		}

		memzero(s_call_string, (n_call_string_length + 1) * sizeof(char_t));

		string_append(s_call_string, &n_call_string_length_b, "\"");
		string_append(s_call_string, &n_call_string_length_b, s_file_path);
		string_append(s_call_string, &n_call_string_length_b, "\"");
		string_append(s_call_string, &n_call_string_length_b, " ");

		for (int_t i = 0; i < n_parameter_count; i++) {
			string_t s_parameter;

			s_parameter = a_s_parameters[i];

			string_append(s_call_string, &n_call_string_length_b, "\"");
			string_append(s_call_string, &n_call_string_length_b, s_parameter);
			string_append(s_call_string, &n_call_string_length_b, "\"");

			if ((i + 1) < n_parameter_count) {
				string_append(s_call_string, &n_call_string_length_b, " ");
			}
		}

		assert(n_call_string_length_b == n_call_string_length);
	}

	/*
	 * ...
	 */
	if (options & PROCESS_CREATE_DETACHED)
		flags |= DETACHED_PROCESS;

	if (options & PROCESS_CREATE_NO_WINDOW)
		flags |= CREATE_NO_WINDOW;

	/*
	 * Create process;
	 */
	memzero(&o_startup_info, sizeof o_startup_info);
	memzero(&o_process_info, sizeof o_process_info);

	b_created = CreateProcessA(
		s_file_path,
		s_call_string,
		NULL,
		NULL,
		FALSE,
		flags,
		NULL,
		NULL,
		&o_startup_info,
		&o_process_info
	);

	if (!b_created) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	/*
	 * ...
	 */
	h_process = o_process_info.hProcess;
	h_thread = o_process_info.hThread;

	if (NULL == _h_thread) {
		CloseHandle(o_process_info.hThread);

		o_process_info.hThread = INVALID_HANDLE_VALUE;
	}

	/*
	 * ...
	 */
	if (NULL != s_call_string) {
		free(s_call_string);

		n_call_string_length = n_call_string_length_b = 0;
	}


$success:
#pragma region <returns>
	if (NULL != _h_process) {
		*_h_process = h_process;
	}

	if (NULL != _h_thread) {
		*_h_thread = h_thread;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (NULL != s_call_string) {
		free(s_call_string);
	}

	if (b_created) {
		if (INVALID_HANDLE_VALUE != h_thread) {
			CloseHandle(h_thread);
		}

		if (INVALID_HANDLE_VALUE != h_process) {
			CloseHandle(h_process);
		}
	}
#pragma endregion


	return false;
}


FWIMPORT __success(return) bool_t process_create_ex_w(__in wstring_t const s_file_path, __in uint_t const n_parameter_count, __in_opt wstring_t* a_s_parameters, __in_opt ulong_t const options, __out process_t* _h_process, __out_opt thread_t* _h_thread) {
#pragma region <locals>
	BOOL                b_created = FALSE;
	DWORD               flags = 0;
	HANDLE              h_process = INVALID_HANDLE_VALUE;
	HANDLE              h_thread = INVALID_HANDLE_VALUE;
	uint_t              n_call_string_length = 0;
	uint_t              n_call_string_length_b = 0;
	PROCESS_INFORMATION o_process_info;
	STARTUPINFOW        o_startup_info;
	wstring_t           s_call_string = NULL;
#pragma endregion


	assert(NULL != s_file_path);
	assert(NULL != _h_process);


	/*
	 * Build call string;
	 */
	if (n_parameter_count > 0) {
		assert(NULL != a_s_parameters);

		n_call_string_length++;										// "
		n_call_string_length += wstring_length(s_file_path);		// <executable-file-path>
		n_call_string_length++;										// "
		n_call_string_length++;										// [space]

		for (int_t i = 0; i < n_parameter_count; i++) {
			wstring_t s_parameter;

			s_parameter = a_s_parameters[i];

			n_call_string_length++;									// "
			n_call_string_length += wstring_length(s_parameter);	// <parameter>
			n_call_string_length++;									// "

			if ((i + 1) < n_parameter_count) {
				n_call_string_length++;								// [space]
			}
		}

		s_call_string = (wstring_t)malloc((n_call_string_length + 1) * sizeof(wchar_t));

		if (NULL == s_call_string) {
			goto $failure;
		}

		memzero(s_call_string, (n_call_string_length + 1) * sizeof(wchar_t));

		wstring_append(s_call_string, &n_call_string_length_b, L"\"");
		wstring_append(s_call_string, &n_call_string_length_b, s_file_path);
		wstring_append(s_call_string, &n_call_string_length_b, L"\"");
		wstring_append(s_call_string, &n_call_string_length_b, L" ");

		for (int_t i = 0; i < n_parameter_count; i++) {
			wstring_t s_parameter;

			s_parameter = a_s_parameters[i];

			wstring_append(s_call_string, &n_call_string_length_b, L"\"");
			wstring_append(s_call_string, &n_call_string_length_b, s_parameter);
			wstring_append(s_call_string, &n_call_string_length_b, L"\"");

			if ((i + 1) < n_parameter_count) {
				wstring_append(s_call_string, &n_call_string_length_b, L" ");
			}
		}

		assert(n_call_string_length_b == n_call_string_length);
	}

	/*
	 * ...
	 */
	if (options & PROCESS_CREATE_DETACHED)
		flags |= DETACHED_PROCESS;

	if (options & PROCESS_CREATE_NO_WINDOW)
		flags |= CREATE_NO_WINDOW;

	/*
	 * Create process;
	 */
	memzero(&o_startup_info, sizeof o_startup_info);
	memzero(&o_process_info, sizeof o_process_info);

	b_created = CreateProcessW(
		s_file_path,
		s_call_string,
		NULL,
		NULL,
		FALSE,
		flags,
		NULL,
		NULL,
		&o_startup_info,
		&o_process_info
	);

	if (!b_created) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	/*
	 * ...
	 */
	h_process = o_process_info.hProcess;
	h_thread = o_process_info.hThread;

	if (NULL == _h_thread) {
		CloseHandle(o_process_info.hThread);

		o_process_info.hThread = INVALID_HANDLE_VALUE;
	}

	/*
	 * ...
	 */
	if (NULL != s_call_string) {
		free(s_call_string);

		n_call_string_length = n_call_string_length_b = 0;
	}


$success:
#pragma region <returns>
	if (NULL != _h_process) {
		*_h_process = h_process;
	}

	if (NULL != _h_thread) {
		*_h_thread = h_thread;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (NULL != s_call_string) {
		free(s_call_string);
	}

	if (b_created) {
		if (INVALID_HANDLE_VALUE != h_thread) {
			CloseHandle(h_thread);
		}

		if (INVALID_HANDLE_VALUE != h_process) {
			CloseHandle(h_process);
		}
	}
#pragma endregion


	return false;
}


FWEXPORT void process_current(__out process_t* _process) {
	assert(NULL != _process);


	*_process = GetCurrentProcess();
}


FWEXPORT void process_exit(__in unsigned int const exitcode) {
	ExitProcess(exitcode);
}


FWEXPORT __success(return) bool_t process_get_id(__in_opt process_t const process, __out ulong_t* _process_id) {
#pragma region <locals>
	ulong_t process_id;
#pragma endregion


	assert(NULL != _process_id);

	
	if (NULL != process)
		process_id = GetProcessId(process);
	else {
		process_id = GetCurrentProcessId();
	}


$success:
#pragma region <returns>
	*_process_id = process_id;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) bool_t process_get_x64(__in_opt process_t const process, __out bool_t* _b_x64) {
#pragma region <locals>
	bool_t  b_x64;
	DWORD   e_binary_type;
	uint_t  n_executable_file_path_length;
	wchar_t s_executable_file_path[MAX_PATH + 1];
#pragma endregion


	n_executable_file_path_length = MAX_PATH;

	if (!process_getbinpath_w(process, s_executable_file_path, &n_executable_file_path_length)) {
		goto $failure;
	}

	if (!GetBinaryTypeW(s_executable_file_path, &e_binary_type)) {
		fw_error = FW_ERROR_UNKNOWN;

		goto $failure;
	}

	if (e_binary_type == SCS_64BIT_BINARY)
		b_x64 = true;
	else {
		b_x64 = false;
	}


$success:
#pragma region <returns>
	*_b_x64 = b_x64;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) bool_t process_getbinpath(__in_opt process_t const h_process, __inout char_t* s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	typedef DWORD(WINAPI* LPFN_GETMODULEFILENAMEEXA)(
		IN  HANDLE  hProcess,
		IN  HMODULE hModule,
		OUT LPSTR   lpFilename,
		IN  DWORD   nSize
	);


	LPFN_GETMODULEFILENAMEEXA fnGetModuleFileNameExA;
	HMODULE                   hModule = NULL;
	uint_t                    n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = MAX_PATH;
	}

	if (NULL == h_process) {
		n_path_length = GetModuleFileNameA(NULL, s_path, n_path_length);

		if (n_path_length <= 0) {
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		} else {
			goto $success;
		}
	}

	hModule = GetModuleHandleW(L"psapi.dll");

	if (NULL == hModule)
		hModule = LoadLibraryW(L"psapi.dll");

	if (NULL == hModule) {
		fw_error = FW_ERROR_UNKNOWN;

		goto $failure;
	}

	fnGetModuleFileNameExA = GetProcAddress(hModule, "GetModuleFileNameExW");

	if (NULL == fnGetModuleFileNameExA) {
		fw_error = FW_ERROR_UNKNOWN;

		goto $failure;
	}

	n_path_length = fnGetModuleFileNameExA(h_process, NULL, s_path, n_path_length);

	if (n_path_length <= 0) {
		fw_error = FW_ERROR_UNKNOWN;

		goto $failure;
	}


$success:
#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) bool_t process_getbinpath_w(__in_opt process_t const h_process, __inout wchar_t* s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	typedef DWORD(WINAPI* LPFN_GETMODULEFILENAMEEXW)(
		IN  HANDLE  hProcess,
		IN  HMODULE hModule,
		OUT LPWSTR  lpFilename,
		IN  DWORD   nSize
	);


	LPFN_GETMODULEFILENAMEEXW fnGetModuleFileNameExW;
	HMODULE                   hModule = NULL;
	uint_t                    n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = MAX_PATH;
	}

	if (NULL == h_process) {
		n_path_length = GetModuleFileNameW(NULL, s_path, n_path_length);

		if (n_path_length <= 0) {
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
		else {
			goto $success;
		}
	}

	hModule = GetModuleHandleW(L"psapi.dll");

	if (NULL == hModule)
		hModule = LoadLibraryW(L"psapi.dll");

	if (NULL == hModule) {
		fw_error = FW_ERROR_UNKNOWN;

		goto $failure;
	}

	fnGetModuleFileNameExW = GetProcAddress(hModule, "GetModuleFileNameExW");

	if (NULL == fnGetModuleFileNameExW) {
		fw_error = FW_ERROR_UNKNOWN;

		goto $failure;
	}

	n_path_length = fnGetModuleFileNameExW(h_process, NULL, s_path, n_path_length);

	if (n_path_length <= 0) {
		fw_error = FW_ERROR_UNKNOWN;

		goto $failure;
	}


$success:
#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) bool_t process_getcwd(__inout string_t s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = MAX_PATH;
	}

	n_path_length = GetCurrentDirectoryA(n_path_length, s_path);


$success:
#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) bool_t process_getcwd_w(__inout wstring_t s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = MAX_PATH;
	}

	n_path_length = GetCurrentDirectoryW(n_path_length, s_path);


$success:
#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) bool_t process_kill(__in process_t const process) {
#pragma region <locals>

#pragma endregion

	
	if (!TerminateProcess(process, EXIT_FAILURE)) {
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


FWEXPORT __success(return) bool_t process_open(__in ulong_t const process_id, __in ulong_t const open_options, __out process_t* _process) {
#pragma region <locals>
	HANDLE ProcessHandle = INVALID_HANDLE_VALUE;
	DWORD  WinOpenOptions = 0L;
#pragma endregion


	assert(NULL != _process);


	if (open_options & PROCESS_OPEN_GET_X64) {
		WinOpenOptions |= PROCESS_QUERY_INFORMATION;
	}

	if (open_options & PROCESS_OPEN_TERMINATE) {
		WinOpenOptions |= PROCESS_TERMINATE;
	}

	ProcessHandle = OpenProcess(WinOpenOptions, FALSE, process_id);

	if (INVALID_HANDLE_VALUE == ProcessHandle) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>
	*_process = (process_t)ProcessHandle;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (INVALID_HANDLE_VALUE != ProcessHandle) {
		CloseHandle(ProcessHandle);
	}
#pragma endregion


	return false;
}

