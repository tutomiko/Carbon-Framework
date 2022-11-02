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
#include <fireworks/sys/process.h>
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
#include <fireworks/sys/paths.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
FWEXPORT __success(return) bool_t process_resolvepath(__in string_t const s_path, __in_opt uint_t const n_path_length, __inout string_t s_abs_path, __out_opt uint_t* _n_abs_path_length) {
#pragma region <locals>
	uint_t n_abs_path_length;
	uint_t n_cwd_path_length;
	path_t s_cwd_path;
#pragma endregion


	
	assert(NULL != s_path);
	assert(NULL != s_abs_path);


	memzero(s_cwd_path, sizeof s_cwd_path);
	n_cwd_path_length = _MAX_PATH;
	process_getcwd(s_cwd_path, &n_cwd_path_length);

	path_resolve(s_path, n_path_length, s_cwd_path, n_cwd_path_length, s_abs_path, &n_abs_path_length);
	

$success:
#pragma region <returns>
	if (NULL != _n_abs_path_length) {
		*_n_abs_path_length = n_abs_path_length;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) bool_t process_resolvepath_w(__in wstring_t const s_path, __in_opt uint_t const n_path_length, __inout wstring_t s_abs_path, __out_opt uint_t* _n_abs_path_length) {
#pragma region <locals>
	uint_t  n_abs_path_length;
	uint_t  n_cwd_path_length;
	wpath_t s_cwd_path;
#pragma endregion


	
	assert(NULL != s_path);
	assert(NULL != s_abs_path);


	memzero(s_cwd_path, sizeof s_cwd_path);
	n_cwd_path_length = _MAX_PATH;
	process_getcwd_w(s_cwd_path, &n_cwd_path_length);

	path_resolve_w(s_path, n_path_length, s_cwd_path, n_cwd_path_length, s_abs_path, &n_abs_path_length);
	

$success:
#pragma region <returns>
	if (NULL != _n_abs_path_length) {
		*_n_abs_path_length = n_abs_path_length;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}

