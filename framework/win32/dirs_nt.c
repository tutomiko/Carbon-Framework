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
#include <carbon/sys/dirs.h>
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
FWEXPORT __success(return) bool_t directory_create(__in string_t const s_directory_path) {
#pragma region <locals>
	BOOL b_created;
#pragma endregion


	assert(NULL != s_directory_path);


	b_created = CreateDirectoryA(s_directory_path, NULL);

	if (!b_created) {
		switch (GetLastError()) {
		case ERROR_ACCESS_DENIED:
			fw_error = FW_ERROR_PREVENTED;

			goto $failure;
		case ERROR_ALREADY_EXISTS:
			fw_error = FW_ERROR_ALREADY_EXISTS;

			goto $failure;
		case ERROR_PATH_NOT_FOUND:
			fw_error = FW_ERROR_UNREACHABLE;

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


FWEXPORT __success(return) bool_t directory_create_w(__in wstring_t const s_directory_path) {
#pragma region <locals>
	BOOL b_created;
#pragma endregion


	assert(NULL != s_directory_path);


	b_created = CreateDirectoryW(s_directory_path, NULL);

	if (!b_created) {
		switch (GetLastError()) {
		case ERROR_ACCESS_DENIED:
			fw_error = FW_ERROR_PREVENTED;

			break;
		case ERROR_ALREADY_EXISTS:
			fw_error = FW_ERROR_ALREADY_EXISTS;

			goto $failure;
		case ERROR_PATH_NOT_FOUND:
			fw_error = FW_ERROR_UNREACHABLE;

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


FWEXPORT __success(return) bool_t directory_delete(__in string_t const s_directory_path) {
#pragma region <locals>
	BOOL b_removed;
#pragma endregion
	

	assert(NULL != s_directory_path);


	b_removed = RemoveDirectoryA(s_directory_path);

	if (!b_removed) {
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


FWEXPORT __success(return) bool_t directory_delete_w(__in wstring_t const s_directory_path) {
#pragma region <locals>
	BOOL b_removed;
#pragma endregion
	

	assert(NULL != s_directory_path);


	b_removed = RemoveDirectoryW(s_directory_path);

	if (!b_removed) {
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


FWEXPORT __success(return) bool_t directory_enum_contents(__in string_t const s_directory_path, __in DIRECTORY_CONTENTS_ENUMERATOR f_enum_proc) {
#pragma region <locals>
	BOOL             b_enum,
		             b_find;
	HANDLE           h_find = INVALID_HANDLE_VALUE;
	uint_t           n_file_name_length;
	uint_t           n_find_path_length;
	WIN32_FIND_DATAA o_find_data;
	char_t           s_file_name[_MAX_FNAME + 1];
	path_t           s_find_path;
#pragma endregion
	

	assert(NULL != s_directory_path);
	assert(NULL != f_enum_proc);


	/*
	 * Build search string;
	 */
	memzero(s_find_path, sizeof s_find_path);

	path_init(s_find_path, s_directory_path, true, &n_find_path_length);
	path_append(s_find_path, &n_find_path_length, "*");

	/*
	 * Iterate over each file in directory;
	 */
	h_find = FindFirstFileA(s_find_path, &o_find_data);

	if (INVALID_HANDLE_VALUE == h_find) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	for (b_find = true; b_find; b_find = FindNextFileA(h_find, &o_find_data)) {
		if (string_equals(o_find_data.cFileName, ".") || string_equals(o_find_data.cFileName, ".."))
			continue;

		memzero(s_file_name, sizeof s_file_name);
		string_copy(s_file_name, o_find_data.cFileName, &n_file_name_length);
		
		if (o_find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			string_concat(s_file_name, &n_file_name_length, "\\");
		}

		b_enum = f_enum_proc(s_directory_path, s_file_name);

		if (!b_enum)
			break;

		if (!b_find) {
			switch (GetLastError()) {
			case ERROR_NO_MORE_FILES:
				break;
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		}
	}

	/*
	 * Close and un-initialize find handle;
	 */
	FindClose(h_find);
	h_find = INVALID_HANDLE_VALUE;


$success:
#pragma region <returns>

#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (INVALID_HANDLE_VALUE != h_find) {
		FindClose(h_find);
	}
#pragma endregion


	return false;
}


FWEXPORT __success(return) bool_t directory_enum_contents_w(__in wstring_t const s_directory_path, __in DIRECTORY_CONTENTS_ENUMERATOR_W f_enum_proc) {
#pragma region <locals>
	BOOL             b_enum,
		             b_find;
	HANDLE           h_find = INVALID_HANDLE_VALUE;
	uint_t           n_file_name_length;
	uint_t           n_find_path_length;
	WIN32_FIND_DATAW o_find_data;
	wchar_t          s_file_name[_MAX_FNAME + 1];
	wpath_t          s_find_path;
#pragma endregion
	

	assert(NULL != s_directory_path);
	assert(NULL != f_enum_proc);


	/*
	 * Build search string;
	 */
	memzero(s_find_path, sizeof s_find_path);

	path_init_w(s_find_path, s_directory_path, true, &n_find_path_length);
	path_append_w(s_find_path, &n_find_path_length, L"*");

	/*
	 * Iterate over each file in directory;
	 */
	h_find = FindFirstFileW(s_find_path, &o_find_data);

	if (INVALID_HANDLE_VALUE == h_find) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	for (b_find = true; b_find; b_find = FindNextFileW(h_find, &o_find_data)) {
		if (wstring_equals(o_find_data.cFileName, L".") || wstring_equals(o_find_data.cFileName, L".."))
			continue;

		memzero(s_file_name, sizeof s_file_name);
		wstring_copy(s_file_name, o_find_data.cFileName, &n_file_name_length);
		
		if (o_find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			wstring_concat(s_file_name, &n_file_name_length, L"\\");
		}

		b_enum = f_enum_proc(s_directory_path, s_file_name);

		if (!b_enum)
			break;

		if (!b_find) {
			switch (GetLastError()) {
			case ERROR_NO_MORE_FILES:
				break;
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		}
	}

	/*
	 * Close and un-initialize find handle;
	 */
	FindClose(h_find);
	h_find = INVALID_HANDLE_VALUE;


$success:
#pragma region <returns>

#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (INVALID_HANDLE_VALUE != h_find) {
		FindClose(h_find);
	}
#pragma endregion


	return false;
}


FWEXPORT __success(return) bool_t directory_enum_contents_ex(__in string_t const s_directory_path, __in DIRECTORY_CONTENTS_ENUMERATOR_EX f_enum_proc) {
#pragma region <locals>
	BOOL             b_enum,
		             b_find;
	HANDLE           h_find = INVALID_HANDLE_VALUE;
	uint_t           n_file_name_length;
	uint_t           n_file_path_length;
	uint_t           n_find_path_length;
	WIN32_FIND_DATAA o_find_data;
	char_t           s_file_name[_MAX_FNAME + 1];
	path_t           s_file_path;
	path_t           s_find_path;
#pragma endregion


	assert(NULL != s_directory_path);
	assert(NULL != f_enum_proc);


	/*
	 * Build search string;
	 */
	memzero(s_find_path, sizeof s_find_path);

	path_init(s_find_path, s_directory_path, true, &n_find_path_length);
	path_append(s_find_path, &n_find_path_length, "*");

	/*
	 * Iterate over each file in directory;
	 */
	h_find = FindFirstFileA(s_find_path, &o_find_data);

	if (INVALID_HANDLE_VALUE == h_find) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	for (b_find = true; b_find; b_find = FindNextFileA(h_find, &o_find_data)) {
		if (string_equals(o_find_data.cFileName, ".") || string_equals(o_find_data.cFileName, ".."))
			continue;

		memzero(s_file_name, sizeof s_file_name);
		string_copy(s_file_name, o_find_data.cFileName, &n_file_name_length);

		if (o_find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			string_concat(s_file_name, &n_file_name_length, "\\");
		}

		memzero(s_file_path, sizeof s_file_path);
		path_build(s_file_path, &n_file_path_length, s_directory_path, NULL, s_file_name, NULL);

		b_enum = f_enum_proc(s_directory_path, s_file_name, s_file_path);

		if (!b_enum)
			break;

		if (!b_find) {
			switch (GetLastError()) {
			case ERROR_NO_MORE_FILES:
				break;
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		}
	}

	/*
	 * Close and un-initialize find handle;
	 */
	FindClose(h_find);
	h_find = INVALID_HANDLE_VALUE;


$success:
#pragma region <returns>

#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (INVALID_HANDLE_VALUE != h_find) {
		FindClose(h_find);
	}
#pragma endregion


	return false;
}


FWEXPORT __success(return) bool_t directory_enum_contents_ex_w(__in wstring_t const s_directory_path, __in DIRECTORY_CONTENTS_ENUMERATOR_EX_W f_enum_proc) {
#pragma region <locals>
	BOOL             b_enum,
		             b_find;
	HANDLE           h_find = INVALID_HANDLE_VALUE;
	uint_t           n_file_name_length;
	uint_t           n_file_path_length;
	uint_t           n_find_path_length;
	WIN32_FIND_DATAA o_find_data;
	wchar_t          s_file_name[_MAX_FNAME + 1];
	wpath_t          s_file_path;
	wpath_t          s_find_path;
#pragma endregion


	assert(NULL != s_directory_path);
	assert(NULL != f_enum_proc);


	/*
	 * Build search string;
	 */
	memzero(s_find_path, sizeof s_find_path);

	path_init_w(s_find_path, s_directory_path, true, &n_find_path_length);
	path_append_w(s_find_path, &n_find_path_length, L"*");

	/*
	 * Iterate over each file in directory;
	 */
	h_find = FindFirstFileW(s_find_path, &o_find_data);

	if (INVALID_HANDLE_VALUE == h_find) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	for (b_find = true; b_find; b_find = FindNextFileW(h_find, &o_find_data)) {
		if (wstring_equals(o_find_data.cFileName, L".") || wstring_equals(o_find_data.cFileName, L".."))
			continue;

		memzero(s_file_name, sizeof s_file_name);
		wstring_copy(s_file_name, o_find_data.cFileName, &n_file_name_length);

		if (o_find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			wstring_concat(s_file_name, &n_file_name_length, L"\\");
		}

		memzero(s_file_path, sizeof s_file_path);
		path_build_w(s_file_path, &n_file_path_length, s_directory_path, NULL, s_file_name, NULL);

		b_enum = f_enum_proc(s_directory_path, s_file_name, s_file_path);

		if (!b_enum)
			break;

		if (!b_find) {
			switch (GetLastError()) {
			case ERROR_NO_MORE_FILES:
				break;
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		}
	}

	/*
	 * Close and un-initialize find handle;
	 */
	FindClose(h_find);
	h_find = INVALID_HANDLE_VALUE;


$success:
#pragma region <returns>

#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (INVALID_HANDLE_VALUE != h_find) {
		FindClose(h_find);
	}
#pragma endregion


	return false;
}

