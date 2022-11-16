/*
 * FileName: dirs.h
 *
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
#include <carbon/cbcbase.h>
#include <carbon/type/bool.h>
#include <carbon/type/string.h>
#include <carbon/filesystem/paths.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
/// <summary>
/// Directory handle type.
/// 
/// Acts as a wrapper for native handles.
/// </summary>
struct _dir_ob_wrapper {
	void* nt_handle;
} typedef *directory_t;


typedef bool_t(*DIRECTORY_CONTENTS_ENUMERATOR)(
	__in string_t const s_directory_path,
	__in string_t const s_file_name
);


typedef bool_t(*DIRECTORY_CONTENTS_ENUMERATOR_W)(
	__in wstring_t const s_directory_path,
	__in wstring_t const s_file_name
);


typedef bool_t(*DIRECTORY_CONTENTS_ENUMERATOR_EX)(
	__in string_t const s_directory_path,
	__in string_t const s_file_name,
	__in string_t const s_file_path
);


typedef bool_t(*DIRECTORY_CONTENTS_ENUMERATOR_EX_W)(
	__in wstring_t const s_directory_path,
	__in wstring_t const s_file_name,
	__in wstring_t const s_file_path
);



CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_build_path(
	__in string_t const s_directory_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_build_path_w(
	__in wstring_t const s_directory_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_clear_contents(
	__in string_t const s_directory_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_clear_contents_w(
	__in wstring_t const s_directory_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_create(
	__in string_t const s_directory_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_create_w(
	__in wstring_t const s_directory_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_create_ex(
	__in string_t const s_directory_path,
	__in bool_t const   b_build_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_create_ex_w(
	__in wstring_t const s_directory_path,
	__in bool_t const    b_build_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_delete(
	__in string_t const s_directory_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_delete_w(
	__in wstring_t const s_directory_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_destroy(
	__in string_t const s_directory_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_destroy_w(
	__in wstring_t const s_directory_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_destroy_contents(
	__in string_t const s_directory_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_destroy_contents_w(
	__in wstring_t const s_directory_path
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_enum_contents(
	__in string_t const                s_directory_path,
	__in DIRECTORY_CONTENTS_ENUMERATOR f_enum_proc
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_enum_contents_w(
	__in wstring_t const                 s_directory_path,
	__in DIRECTORY_CONTENTS_ENUMERATOR_W f_enum_proc
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_enum_contents_ex(
	__in string_t const                   s_directory_path,
	__in DIRECTORY_CONTENTS_ENUMERATOR_EX f_enum_proc
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
directory_enum_contents_ex_w(
	__in wstring_t const                    s_directory_path,
	__in DIRECTORY_CONTENTS_ENUMERATOR_EX_W f_enum_proc
);


#if __CHARSET == CHARSET_UNICODE
#define directory_build_path_t				directory_build_path_w
#define directory_clear_contents_t			directory_clear_contents_w
#define directory_create_t					directory_create_w
#define directory_create_ex_t				directory_create_ex_w
#define directory_delete_t					directory_delete_w
#define directory_destroy_t					directory_destroy_w
#define directory_destroy_contents_t		directory_destroy_contents_w
#define directory_enum_contents_t			directory_enum_contents_w
#define directory_enum_contents_ex_t		directory_enum_contents_ex_w
#elif __CHARSET == CHARSET_MULTIBYTE
#define directory_build_path_t				directory_build_path
#define directory_clear_contents_t			directory_clear_contents
#define directory_create_t					directory_create
#define directory_create_ex_t				directory_create_ex
#define directory_delete_t					directory_delete
#define directory_destroy_t					directory_destroy
#define directory_destroy_contents_t		directory_destroy_contents
#define directory_enum_contents_t			directory_enum_contents
#define directory_enum_contents_ex_t		directory_enum_contents_ex
#endif // __CHARSET


