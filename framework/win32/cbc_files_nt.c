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
#include <carbon/filesystem/files.h>
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
CBCEXPORT __success(return) bool_t file_delete(__in string_t const file_path) {
#pragma region <locals>

#pragma endregion


	if (!DeleteFileA(file_path)) {
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


CBCEXPORT __success(return) bool_t file_exists(__in string_t const s_file_path, __out bool_t* _b_exists) {
#pragma region <locals>
	bool_t b_exists;
	HANDLE h_file = INVALID_HANDLE_VALUE;
#pragma endregion


	assert(NULL != s_file_path);
	assert(NULL != _b_exists);


	h_file = CreateFileA(
		s_file_path,
		FILE_READ_ATTRIBUTES,
		FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (INVALID_HANDLE_VALUE == h_file) {
		switch (GetLastError()) {
		case ERROR_FILE_NOT_FOUND:
			b_exists = false;

			break;
		default:
			goto $failure;
		}
	} else {
		b_exists = true;
	}

	CloseHandle(h_file);
	h_file = INVALID_HANDLE_VALUE;


$success:
#pragma region <returns>
	*_b_exists = b_exists;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (INVALID_HANDLE_VALUE != h_file) {
		CloseHandle(h_file);
	}
#pragma endregion


	return false;
}


CBCEXPORT __success(return) bool_t file_delete_w(__in wstring_t const file_path) {
#pragma region <locals>

#pragma endregion


	if (!DeleteFileW(file_path)) {
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


CBCEXPORT __success(return) bool_t file_exists_w(__in wstring_t const s_file_path, __out bool_t* _b_exists) {
#pragma region <locals>
	bool_t b_exists;
	HANDLE h_file = INVALID_HANDLE_VALUE;
#pragma endregion


	assert(NULL != s_file_path);
	assert(NULL != _b_exists);


	h_file = CreateFileW(
		s_file_path,
		FILE_READ_ATTRIBUTES,
		FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (INVALID_HANDLE_VALUE == h_file) {
		switch (GetLastError()) {
		case ERROR_FILE_NOT_FOUND:
			b_exists = false;

			break;
		default:
			goto $failure;
		}
	} else {
		b_exists = true;
	}

	CloseHandle(h_file);
	h_file = INVALID_HANDLE_VALUE;


$success:
#pragma region <returns>
	*_b_exists = b_exists;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (INVALID_HANDLE_VALUE != h_file) {
		CloseHandle(h_file);
	}
#pragma endregion


	return false;
}


CBCEXPORT __success(return) bool_t file_rename(__in string_t const s_file_path, __in string_t const s_new_file_path) {
#pragma region <locals>

#pragma endregion


	if (!MoveFileA(s_file_path, s_new_file_path)) {
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


CBCEXPORT __success(return) bool_t file_rename_w(__in wstring_t const s_file_path, __in wstring_t const s_new_file_path) {
#pragma region <locals>

#pragma endregion


	if (!MoveFileW(s_file_path, s_new_file_path)) {
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


CBCEXPORT __success(return) bool_t file_zero(__in string_t const file_path) {
#pragma region <locals>
	HANDLE        FileHandle = INVALID_HANDLE_VALUE;
	LARGE_INTEGER FileSize;
	ULONGLONG     TotalBytesToWrite, 
		          TotalBytesWritten;
	CHAR          zero_buffer[512];
	DWORD         zero_buffer_size = (sizeof(zero_buffer) / sizeof(zero_buffer[0]));
#pragma endregion


	FileHandle = CreateFileA(
		file_path,
		FILE_READ_ATTRIBUTES | GENERIC_WRITE,
		0L,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (INVALID_HANDLE_VALUE == FileHandle) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


	if (!GetFileSizeEx(FileHandle, &FileSize)) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	RtlSecureZeroMemory(zero_buffer, sizeof zero_buffer);

	TotalBytesToWrite = FileSize.QuadPart;
	TotalBytesWritten = 0ULL;

	for (DWORD BytesToWrite, BytesWritten; TotalBytesWritten < FileSize.QuadPart; TotalBytesWritten += BytesWritten, TotalBytesToWrite -= BytesWritten) {
		if (TotalBytesToWrite < zero_buffer_size)
			BytesToWrite = (DWORD)TotalBytesToWrite;
		else {
			BytesToWrite = zero_buffer_size;
		}

		if (!WriteFile(FileHandle, zero_buffer, BytesToWrite, &BytesWritten, NULL)) {
			switch (GetLastError()) {
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		}
	}

	CloseHandle(FileHandle);
	FileHandle = INVALID_HANDLE_VALUE;


$success:
#pragma region <returns>

#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (INVALID_HANDLE_VALUE != FileHandle) {
		CloseHandle(FileHandle);
	}
#pragma endregion


	return false;
}


CBCEXPORT __success(return) bool_t file_zero_w(__in wstring_t const file_path) {
#pragma region <locals>
	HANDLE        FileHandle = INVALID_HANDLE_VALUE;
	LARGE_INTEGER FileSize;
	ULONGLONG     TotalBytesToWrite, 
		          TotalBytesWritten;
	CHAR          zero_buffer[512];
	DWORD         zero_buffer_size = (sizeof(zero_buffer) / sizeof(zero_buffer[0]));
#pragma endregion


	FileHandle = CreateFileW(
		file_path,
		FILE_READ_ATTRIBUTES | GENERIC_WRITE,
		0L,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (INVALID_HANDLE_VALUE == FileHandle) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


	if (!GetFileSizeEx(FileHandle, &FileSize)) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	RtlSecureZeroMemory(zero_buffer, sizeof zero_buffer);

	TotalBytesToWrite = FileSize.QuadPart;
	TotalBytesWritten = 0ULL;

	for (DWORD BytesToWrite, BytesWritten; TotalBytesWritten < FileSize.QuadPart; TotalBytesWritten += BytesWritten, TotalBytesToWrite -= BytesWritten) {
		if (TotalBytesToWrite < zero_buffer_size)
			BytesToWrite = (DWORD)TotalBytesToWrite;
		else {
			BytesToWrite = zero_buffer_size;
		}

		if (!WriteFile(FileHandle, zero_buffer, BytesToWrite, &BytesWritten, NULL)) {
			switch (GetLastError()) {
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		}
	}

	CloseHandle(FileHandle);
	FileHandle = INVALID_HANDLE_VALUE;


$success:
#pragma region <returns>

#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (INVALID_HANDLE_VALUE != FileHandle) {
		CloseHandle(FileHandle);
	}
#pragma endregion


	return false;
}

