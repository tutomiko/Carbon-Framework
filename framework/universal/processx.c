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
#include <carbon/sys/paths.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
FWEXPORT __success(return) bool_t process_getcdirpath(__inout string_t s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = _MAX_PATH;
	}

	if (!process_getbinpath(NULL, s_path, &n_path_length)) {
		goto $failure;
	}

	path_toparent(s_path, &n_path_length);


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


FWEXPORT __success(return) bool_t process_getcdirpath_w(__inout wstring_t s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = _MAX_PATH;
	}

	if (!process_getbinpath_w(NULL, s_path, &n_path_length)) {
		goto $failure;
	}

	path_toparent_w(s_path, &n_path_length);


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

