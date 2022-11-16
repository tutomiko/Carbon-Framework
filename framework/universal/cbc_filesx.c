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
CBCEXPORT __success(return) bool_t file_destroy(__in string_t const file_path) {
	return file_zero(file_path) && file_delete(file_path);
}


CBCEXPORT __success(return) bool_t file_destroy_w(__in wstring_t const file_path) {
	return file_zero_w(file_path) && file_delete_w(file_path);
}


CBCEXPORT __success(return) bool_t file_moveto(__in string_t const s_src_file_path, __in string_t const s_directory_path) {
#pragma region <locals>
	size_t n_dst_file_path_length;
	char_t s_dst_file_path[_MAX_PATH + 1];
#pragma endregion

	
	assert(NULL != s_src_file_path);
	assert(NULL != s_directory_path);


	memzero(s_dst_file_path, sizeof s_dst_file_path);
	string_copy(s_dst_file_path, s_src_file_path, &n_dst_file_path_length);

	if (NULL == path_setparent(s_dst_file_path, &n_dst_file_path_length, s_directory_path, NULL)) {
		goto $failure;
	}

	if (!file_rename(s_src_file_path, s_dst_file_path)) {
		goto $failure;
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


CBCEXPORT __success(return) bool_t file_moveto_w(__in wstring_t const s_src_file_path, __in wstring_t const s_directory_path) {
#pragma region <locals>
	size_t  n_dst_file_path_length;
	wpath_t s_dst_file_path;
#pragma endregion

	
	assert(NULL != s_src_file_path);
	assert(NULL != s_directory_path);


	memzero(s_dst_file_path, sizeof s_dst_file_path);
	wstring_copy(s_dst_file_path, s_src_file_path, &n_dst_file_path_length);

	if (NULL == path_setparent_w(s_dst_file_path, &n_dst_file_path_length, s_directory_path, NULL)) {
		goto $failure;
	}

	if (!file_rename_w(s_src_file_path, s_dst_file_path)) {
		goto $failure;
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

