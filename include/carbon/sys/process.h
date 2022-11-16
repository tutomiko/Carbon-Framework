/*
 * FileName: process.h
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
#include <carbon/util/strings.h>
#include <carbon/sys/thread.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <process create option constant definitions>
#define PROCESS_CREATE_DETACHED			(1 << 2)
#define PROCESS_CREATE_NO_WINDOW		(1 << 1)
#pragma endregion


#pragma region <process open option flag constant definitions>
#define PROCESS_OPEN_GET_X64					(1 << 6)
#define PROCESS_OPEN_TERMINATE					(1 << 2)
#pragma endregion


/// <summary>
/// Process handle type.
/// </summary>
typedef void* process_t;


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_close(
	__in process_t const h_process
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_create(
	__in      string_t const s_file_path,
	__in      uint_t const   n_parameter_count,
	__in_opt  string_t*      a_s_parameters,
	__out     process_t*     _h_process,
	__out_opt thread_t*      _h_thread
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_create_w(
	__in      wstring_t const s_file_path,
	__in      uint_t const    n_parameter_count,
	__in_opt  wstring_t*      a_s_parameters,
	__out     process_t*      _h_process,
	__out_opt thread_t*       _h_thread
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_create_ex(
	__in      string_t const s_file_path,
	__in      uint_t const   n_parameter_count,
	__in_opt  string_t*      a_s_parameters,
	__in_opt  ulong_t const  options,
	__out     process_t*     _h_process,
	__out_opt thread_t*      _h_thread
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_create_ex_w(
	__in      wstring_t const s_file_path,
	__in      uint_t const    n_parameter_count,
	__in_opt  wstring_t*      a_s_parameters,
	__in_opt  ulong_t const   options,
	__out     process_t*      _h_process,
	__out_opt thread_t*       _h_thread
);


CBCIMPORT void process_current(
	__out process_t* _process
);


CBCIMPORT void process_exit(
	__in unsigned int const exitcode
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_get_id(
	__in_opt process_t const process,
	__out    ulong_t*        _process_id
);


/// <summary>
/// Tests whether or not a process is 64-bit.
/// </summary>
/// <param name="process">
/// [optional] process to test or current process if NULL
/// </param>
/// <param name="_b_x64">
/// pointer to receive whether or not process is 64-bit
/// </param>
/// <returns>
/// true on success, false on failure
/// </returns>
CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_get_x64(
	__in_opt process_t const process,
	__out    bool_t*         _b_x64
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_getbinpath(
	__in_opt    process_t const process, 
	__inout     char_t*         s_path, 
	__inout_opt uint_t*         _n_path_length
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_getbinpath_w(
	__in_opt    process_t const process, 
	__inout     wchar_t*        s_path, 
	__inout_opt uint_t*         _n_path_length
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_getcdirpath(
	__inout     string_t s_path, 
	__inout_opt uint_t*  _n_path_length
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_getcdirpath_w(
	__inout     wstring_t s_path, 
	__inout_opt uint_t*   _n_path_length
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_getcwd(
	__inout     string_t s_path, 
	__inout_opt uint_t*  _n_path_length
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_getcwd_w(
	__inout     wstring_t s_path, 
	__inout_opt uint_t*   _n_path_length
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_kill(
	__in process_t const process
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_open(
	__in  ulong_t const process_id, 
	__in  ulong_t const open_options,
	__out process_t*    _process
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_resolvepath(
	__in      string_t const s_path, 
	__in_opt  uint_t const   n_path_length, 
	__inout   string_t       s_abs_path, 
	__out_opt uint_t*        _n_abs_path_length
);


CBCIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
process_resolvepath_w(
	__in      wstring_t const s_path, 
	__in_opt  uint_t const    n_path_length, 
	__inout   wstring_t       s_abs_path, 
	__out_opt uint_t*         _n_abs_path_length
);


#if __CHARSET == CHARSET_UNICODE
#define process_create_t			process_create_w
#define process_create_ex_t			process_create_ex_w
#define process_getbinpath_t		process_getbinpath_w
#define process_getcdirpath_t		process_getcdirpath_w	
#define process_getcwd_t			process_getcwd_w
#define process_resolvepath_t		process_resolvepath_w
#elif __CHARSET == CHARSET_MULTIBYTE
#define process_create_t			process_create
#define process_create_ex_t			process_create_ex
#define process_getbinpath_t		process_getbinpath
#define process_getcdirpath_t		process_getcdirpath	
#define process_getcwd_t			process_getcwd
#define process_resolvepath_t		process_resolvepath
#endif // __CHARSET


