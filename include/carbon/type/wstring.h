/*
 * FileName: wstring.h
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
#ifdef __cplusplus
#include <cstdlib>
#include <cwchar>
#else
#include <stdlib.h>
#include <wchar.h>
#endif // __cplusplus
#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <fwbase.h>
#include <carbon/type/wchar.h>
#include <carbon/type/string.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
/// <summary>
/// string type consisting of "wide" [16-bit] characters.
/// </summary>
typedef wchar_t* wstring_t;


/// <summary>
/// string type consisting of 8-bit characters.
/// </summary>
typedef char_t* string_t;


FWIMPORT
wstring_t wstring_append(
	__inout     wstring_t       s_dst, 
	__inout_opt uint_t*         _n_dst_length,
	__in        wstring_t const s_src
);


FWIMPORT
wchar_t wstring_charat(
	__in wstring_t const s_string, 
	__in uint_t const    n_index
);


FWIMPORT
int_t wstring_compare(
	__in wstring_t const s_string1, 
	__in wstring_t const s_string2
);


FWIMPORT
int_t wstring_compare_ic(
	__in wstring_t const s_string1, 
	__in wstring_t const s_string2
);


FWIMPORT
int_t wstring_comparex(
	__in wstring_t const s_string1, 
	__in wstring_t const s_string2, 
	__in uint_t const    n_count
);


FWIMPORT
int_t wstring_comparex_ic(
	__in wstring_t const s_string1, 
	__in wstring_t const s_string2, 
	__in uint_t const    n_count
);


FWIMPORT
wstring_t wstring_concat(
	__inout     wstring_t       s_dst, 
	__inout_opt uint_t*         _n_dst_length,
	__in        wstring_t const s_src
);


FWIMPORT
bool_t wstring_contains(
	__in     wstring_t const s_string, 
	__in_opt uint_t          n_string_length,
	__in     wstring_t const s_substring,
	__in_opt uint_t          n_substring_length
);


FWIMPORT
bool_t wstring_contains_ic(
	__in     wstring_t const s_string,
	__in_opt uint_t          n_string_length,
	__in     wstring_t const s_substring,
	__in_opt uint_t          n_substring_length
);


FWIMPORT 
wstring_t wstring_copy(
	__inout   wstring_t       s_dst,
	__in      wstring_t const s_src,
	__out_opt uint_t*         _n_copied
);


FWIMPORT 
wstring_t wstring_copyx(
	__inout   wstring_t       s_dst,
	__in      wstring_t const s_src,
	__in      uint_t const    n_count,
	__out_opt uint_t*         _n_length
);


FWIMPORT
bool_t wstring_endswith(
	__in     wstring_t const s_string, 
	__in_opt uint_t          n_string_length, 
	__in     wstring_t const s_suffix, 
	__in_opt uint_t          n_suffix_length
);


FWIMPORT
bool_t wstring_equals(
	__in wstring_t const s_string1, 
	__in wstring_t const s_string2
);


FWIMPORT
bool_t wstring_equals_ic(
	__in wstring_t const s_string1, 
	__in wstring_t const s_string2
);


FWIMPORT
bool_t wstring_equalsx(
	__in wstring_t const s_string1, 
	__in wstring_t const s_string2, 
	__in uint_t const    n_count
);


FWIMPORT
bool_t wstring_equalsx_ic(
	__in wstring_t const s_string1, 
	__in wstring_t const s_string2, 
	__in uint_t const    n_count
);


FWIMPORT
wstring_t wstring_fill(
	__in wstring_t s_string,
	__in wchar_t   c_chr,
	__in uint_t    n_count
);


FWIMPORT
bool_t wstring_find(
	__in      wstring_t const s_string, 
	__in_opt  uint_t          n_string_length, 
	__in      wstring_t const s_substring, 
	__in_opt  uint_t          n_substring_length, 
	__out_opt int_t*          _n_first, 
	__out_opt int_t*          _n_last
);


FWIMPORT
bool_t wstring_find_ic(
	__in      wstring_t const s_string, 
	__in_opt  uint_t          n_string_length, 
	__in      wstring_t const s_substring, 
	__in_opt  uint_t          n_substring_length, 
	__out_opt int_t*          _n_first, 
	__out_opt int_t*          _n_last
);


FWIMPORT
bool_t wstring_isempty(
	__in wstring_t s_string
);


FWIMPORT
uint_t wstring_length(
	__in wstring_t const s_string
);


FWIMPORT
wstring_t wstring_lower(
	__inout     wstring_t s_string, 
	__inout_opt size_t*   _n_string_length
);


FWIMPORT 
wstring_t wstring_push(
	__inout     wstring_t       s_dst,
	__inout_opt uint_t*         _n_dst_length,
	__in        wstring_t const s_src,
	__in_opt    uint_t          n_src_length
);


FWIMPORT
wstring_t wstring_reduce_left(
	__inout     wstring_t    s_string,
	__in        uint_t const n_count,
	__inout_opt uint_t*      _n_string_length
);


FWIMPORT
wstring_t wstring_reduce_right(
	__inout     wstring_t    s_string, 
	__in        uint_t const n_count,
	__inout_opt uint_t*      _n_string_length
);


FWIMPORT
wstring_t wstring_reverse(
	__inout wstring_t s_string
);


FWIMPORT
bool_t wstring_startswith(
	__in     wstring_t const s_string, 
	__in_opt uint_t          n_string_length, 
	__in     wstring_t const s_prefix, 
	__in_opt uint_t          n_prefix_length
);


FWIMPORT
wstring_t wstring_substring(
	__in      wstring_t const s_string, 
	__in_opt  uint_t          n_string_length, 
	__in      uint_t          n_first, 
	__in      uint_t          n_last, 
	__inout   wstring_t       s_substring, 
	__out_opt uint_t*         _n_substring_length
);


FWIMPORT
char_t* wstring_tomb(
	__in     wstring_t const s_string_unicode,
	__inout  char_t*         s_string_multibyte,
	__in_opt uint_t          n_max_count
);


FWIMPORT
wstring_t wstring_upper(
	__inout     wstring_t s_string, 
	__inout_opt size_t*   _n_string_length
);


FWIMPORT
wstring_t wstring_zero(
	__inout     wstring_t s_string,
	__inout_opt size_t*  _n_string_length
);


