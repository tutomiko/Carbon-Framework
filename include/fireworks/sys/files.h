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
#pragma once
#
#pragma region <imports>
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"

#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <fwbase.h>
#include <fireworks/util/error.h>
#include <fireworks/type/bool.h>
#include <fireworks/type/string.h>
#include <fireworks/sys/paths.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
/// <summary>
/// File handle type.
/// 
/// Acts as a wrapper for native handles.
/// </summary>
struct _file_ob_wrapper {
	void* nt_handle;
} typedef *file_t;


FWIMPORT __success(return) bool_t file_delete(
	__in string_t const s_file_path
);


FWIMPORT __success(return) bool_t file_delete_w(
	__in wstring_t const s_file_path
);


/// <summary>
/// Zeroes and deletes a file.
/// </summary>
/// <param name="s_file_path">
/// path to file to destroy
/// </param>
/// <returns>
/// true on success, false otherwise
/// </returns>
FWIMPORT __success(return)  bool_t file_destroy(
	__in string_t const s_file_path
);


/// <summary>
/// Zeroes and deletes a file.
/// </summary>
/// <param name="s_file_path">
/// path to file to destroy
/// </param>
/// <returns>
/// true on success, false otherwise
/// </returns>
FWIMPORT __success(return) bool_t file_destroy_w(
	__in wstring_t const s_file_path
);


FWIMPORT __success(return) bool_t file_exists(
	__in  string_t const s_file_path, 
	__out bool_t*        _b_exists
);


FWIMPORT __success(return) bool_t file_exists_w(
	__in  wstring_t const s_file_path,
	__out bool_t * _b_exists
);


FWIMPORT __success(return) bool_t file_moveto(
	__in string_t const s_src_file_path, 
	__in string_t const s_directory_path
);


FWIMPORT __success(return) bool_t file_moveto_w(
	__in wstring_t const s_src_file_path,
	__in wstring_t const s_directory_path
);


FWIMPORT __success(return) bool_t file_rename(
	__in string_t const s_file_path,
	__in string_t const new_file_path
);


FWIMPORT __success(return) bool_t file_rename_w(
	__in wstring_t const s_file_path,
	__in wstring_t const s_new_file_path
);


FWIMPORT __success(return) bool_t file_truncate(
	__in     string_t const s_file_path,
	__in_opt size_t const   new_size
);


FWIMPORT __success(return) bool_t file_truncate_w(
	__in     wstring_t const s_file_path,
	__in_opt size_t const    new_size
);


/// <summary>
/// Replaces a file's contents with zeroes.
/// </summary>
/// <param name="s_file_path">
/// path to file to zero
/// </param>
/// <returns>
/// true on success, false on error
/// </returns>
FWIMPORT __success(return) bool_t file_zero(
	__in string_t const s_file_path
);


/// <summary>
/// Replaces a file's contents with zeroes.
/// </summary>
/// <param name="s_file_path">
/// path to file to zero
/// </param>
/// <returns>
/// true on success, false on error
/// </returns>
FWIMPORT __success(return) bool_t file_zero_w(
	__in wstring_t const s_file_path
);


#if __CHARSET == CHARSET_UNICODE
#define fopen_t				_wfopen

#define file_delete_t		file_delete_w
#define file_destroy_t		file_destroy_w
#define file_exists_t		file_exists_w
#define file_moveto_t		file_moveto_w
#define file_rename_t		file_rename_w
#define file_truncate_t		file_truncate_w
#define file_zero_t			file_zero_w
#elif __CHARSET == CHARSET_MULTIBYTE
#define fopen_t				fopen

#define file_delete_t		file_delete
#define file_destroy_t		file_destroy
#define file_exists_t		file_exists
#define file_moveto_t		file_moveto
#define file_rename_t		file_rename
#define file_truncate_t		file_truncate
#define file_zero_t			file_zero
#endif // __CHARSET


