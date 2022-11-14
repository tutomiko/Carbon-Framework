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
#include <carbon/sys/files.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <forward declaration of internal functions>
static bool_t enum_clear_contents(
	__in string_t const s_directory_path,
	__in string_t const s_file_name,
	__in string_t const s_file_path
);


static bool_t enum_clear_contents_w(
	__in wstring_t const s_directory_path,
	__in wstring_t const s_file_name,
	__in wstring_t const s_file_path
);


static bool_t enum_destroy_contents(
	__in string_t const s_directory_path,
	__in string_t const s_file_name,
	__in string_t const s_file_path
);


static bool_t enum_destroy_contents_w(
	__in wstring_t const s_directory_path,
	__in wstring_t const s_file_name,
	__in wstring_t const s_file_path
);
#pragma endregion


FWEXPORT __success(return) bool_t directory_build_path(__in string_t const s_directory_path) {
#pragma region <locals>
	bool_t b_create,
		   b_more,
		   b_iterate;
	uint_t n_cursor = 0;
	uint_t n_file_path_length;
	char_t s_file_path[_MAX_FNAME + 1];
#pragma endregion


	assert(NULL != s_directory_path);


$next:
	memzero(s_file_path, sizeof s_file_path);

	b_iterate = path_iterate(s_directory_path, s_file_path, &n_file_path_length, &n_cursor, &b_more);

	if (!b_iterate) {
		fw_error = FW_ERROR_INVALID_PATH;

		goto $failure;
	}

	b_create = directory_create(s_file_path);

	if (!b_create) {
		switch (fw_error) {
		case FW_ERROR_ALREADY_EXISTS:
			if (b_more) 
				break;
			else {
				goto $failure;
			}
		case FW_ERROR_PREVENTED:
			if (b_more)
				break;
			else {
				goto $failure;
			}
		default:
			goto $failure;
		}
	}

	if (b_more) {
		goto $next;
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


FWEXPORT __success(return) bool_t directory_build_path_w(__in wstring_t const s_directory_path) {
#pragma region <locals>
	bool_t  b_create,
	        b_more,
		    b_iterate;
	uint_t  n_cursor = 0;
	uint_t  n_file_path_length;
	wchar_t s_file_path[_MAX_FNAME + 1];
#pragma endregion


	assert(NULL != s_directory_path);


$next:
	memzero(s_file_path, sizeof s_file_path);

	b_iterate = path_iterate_w(s_directory_path, s_file_path, &n_file_path_length, &n_cursor, &b_more);

	if (!b_iterate) {
		fw_error = FW_ERROR_INVALID_PATH;

		goto $failure;
	}

	b_create = directory_create_w(s_file_path);

	if (!b_create) {
		switch (fw_error) {
		case FW_ERROR_ALREADY_EXISTS:
			if (b_more)
				break;
			else {
				goto $failure;
			}
		case FW_ERROR_PREVENTED:
			if (b_more)
				break;
			else {
				goto $failure;
			}
		default:
			goto $failure;
		}
	}

	if (b_more) {
		goto $next;
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


FWEXPORT __success(return) bool_t directory_clear_contents(__in string_t const s_directory_path) {
	return directory_enum_contents_ex(s_directory_path, enum_clear_contents);
}


FWEXPORT __success(return) bool_t directory_clear_contents_w(__in wstring_t const s_directory_path) {
	return directory_enum_contents_ex_w(s_directory_path, enum_clear_contents_w);
}


FWIMPORT __success(return) bool_t directory_create_ex(__in string_t const s_directory_path, __in bool_t const b_build_path) {
	if (b_build_path)
		return directory_build_path(s_directory_path);
	else {
		return directory_create(s_directory_path);
	}
}


FWIMPORT __success(return) bool_t directory_create_ex_w(__in wstring_t const s_directory_path, __in bool_t const b_build_path) {
	if (b_build_path)
		return directory_build_path_w(s_directory_path);
	else {
		return directory_create_w(s_directory_path);
	}
}


FWEXPORT __success(return) bool_t directory_destroy(__in string_t const s_directory_path) {
	return directory_destroy_contents(s_directory_path) && directory_delete(s_directory_path);
}


FWEXPORT __success(return) bool_t directory_destroy_w(__in wstring_t const s_directory_path) {
	return directory_destroy_contents_w(s_directory_path) && directory_delete_w(s_directory_path);
}


FWEXPORT __success(return) bool_t directory_destroy_contents(__in string_t const s_directory_path) {
	return directory_enum_contents_ex(s_directory_path, enum_destroy_contents);
}


FWEXPORT __success(return) bool_t directory_destroy_contents_w(__in wstring_t const s_directory_path) {
	return directory_enum_contents_ex_w(s_directory_path, enum_destroy_contents_w);
}


bool_t enum_clear_contents(__in string_t const s_directory_path, __in string_t const s_file_name, __in string_t const s_file_path) {
	if (path_isdirectory(s_file_path, 0))
		return directory_clear_contents(s_file_path) && directory_delete(s_file_path);
	else {
		return file_delete(s_file_path);
	}
}


bool_t enum_clear_contents_w(__in wstring_t const s_directory_path, __in wstring_t const s_file_name, __in wstring_t const s_file_path) {
	if (path_isdirectory_w(s_file_path, 0))
		return directory_clear_contents_w(s_file_path) && directory_delete_w(s_file_path);
	else {
		return file_delete_w(s_file_path);
	}
}


bool_t enum_destroy_contents(__in string_t const s_directory_path, __in string_t const s_file_name, __in string_t const s_file_path) {
	if (path_isdirectory(s_file_path, 0))
		return directory_destroy(s_file_path);
	else {
		return file_destroy(s_file_path);
	}
}


bool_t enum_destroy_contents_w(__in wstring_t const s_directory_path, __in wstring_t const s_file_name, __in wstring_t const s_file_path) {
	if (path_isdirectory_w(s_file_path, 0))
		return directory_destroy_w(s_file_path);
	else {
		return file_destroy_w(s_file_path);
	}
}

