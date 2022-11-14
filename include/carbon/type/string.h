/*
 * FileName: string.h
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
#include <carbon/util/memory.h>
#include <carbon/type/bytearray.h>
#include <carbon/util/charset.h>
#include <carbon/type/char.h>
#include <carbon/type/wchar.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <string max constant definitions>
#define _MAX_STRING			32767
#pragma endregion


/// <summary>
/// string type consisting of 8-bit characters.
/// </summary>
typedef char_t* string_t;


FWIMPORT
string_t string_append(
	__inout     string_t       s_dst, 
	__inout_opt uint_t*        _n_dst_length,
	__in        string_t const s_src
);


/// <summary>
/// Returns a character in a string, at a select position.
/// </summary>
/// <param name="s_string">
/// String to get character from.
/// </param>
/// <param name="n_index">
/// Index of character to get from @s_string.
/// </param>
/// <returns>
/// Character at @n_index in @s_string.
/// </returns>
FWIMPORT
char_t string_charat(
	__in string_t const s_string, 
	__in uint_t const   n_index
);


FWIMPORT
int_t string_compare(
	__in string_t const s_string1, 
	__in string_t const s_string2
);


FWIMPORT
int_t string_compare_ic(
	__in string_t const s_string1, 
	__in string_t const s_string2
);


FWIMPORT
int_t string_comparex(
	__in string_t const s_string1, 
	__in string_t const s_string2, 
	__in uint_t const   n_count
);


FWIMPORT
int_t string_comparex_ic(
	__in string_t const s_string1, 
	__in string_t const s_string2, 
	__in uint_t const   n_count
);


/// <summary>
/// Concatenates a string into another.
/// </summary>
/// <param name="s_dst">
/// String to append @s_src to.
/// </param>
/// <param name="_n_dst_length">
/// [optional] 
/// Pointer to length of @s_dst that will receive length of @s_dst with 
/// @s_src appended.
/// If the value pointed to is zero the length is nevertheless returned.
/// </param>
/// <param name="s_src">
/// String to append to the end of @s_dst.
/// </param>
/// <returns>
/// @s_dst
/// </returns>
FWIMPORT
string_t string_concat(
	__inout     string_t       s_dst, 
	__inout_opt uint_t*        _n_dst_length,
	__in        string_t const s_src
);


FWIMPORT
bool_t string_contains(
	__in     string_t const s_string, 
	__in_opt uint_t         n_string_length,
	__in     string_t const s_substring,
	__in_opt uint_t         n_substring_length
);


FWIMPORT
bool_t string_contains_ic(
	__in     string_t const s_string,
	__in_opt uint_t         n_string_length,
	__in     string_t const s_substring,
	__in_opt uint_t         n_substring_length
);


/// <summary>
/// Copies a string into another.
/// </summary>
/// <param name="s_src">
/// String to copy to @s_dst.
/// </param>
/// <param name="s_dst">
/// String to copy @s_src to.
/// </param>
/// <param name="_copied">
/// [optional] 
/// Pointer to receive number of characters copied.
/// If the value pointed to is zero the length is nevertheless returned.
/// </param>
/// <returns>
/// @s_dst
/// </returns>
FWIMPORT 
string_t string_copy(
	__inout   string_t       s_dst,
	__in      string_t const s_src,
	__out_opt uint_t*        _n_copied
);


FWIMPORT 
string_t string_copyx(
	__inout   string_t       s_dst,
	__in      string_t const s_src,
	__in      uint_t const   n_count,
	__out_opt uint_t*        _n_length
);


FWIMPORT
bool_t string_endswith(
	__in     string_t const s_string, 
	__in_opt uint_t         n_string_length, 
	__in     string_t const s_suffix, 
	__in_opt uint_t         n_suffix_length
);


FWIMPORT
bool_t string_equals(
	__in string_t const s_string1, 
	__in string_t const s_string2
);


FWIMPORT
bool_t string_equals_ic(
	__in string_t const s_string1, 
	__in string_t const s_string2
);


FWIMPORT
bool_t string_equalsx(
	__in string_t const s_string1, 
	__in string_t const s_string2, 
	__in uint_t const   n_count
);


FWIMPORT
bool_t string_equalsx_ic(
	__in string_t const s_string1, 
	__in string_t const s_string2, 
	__in uint_t const   n_count
);


FWIMPORT
string_t string_fill(
	__in string_t s_string, 
	__in char_t   c_chr, 
	__in uint_t   n_count
);


FWIMPORT
bool_t string_find(
	__in      string_t const s_string, 
	__in_opt  uint_t         n_string_length, 
	__in      string_t const s_substring, 
	__in_opt  uint_t         n_substring_length, 
	__out_opt int_t*         _n_first, 
	__out_opt int_t*         _n_last
);


FWIMPORT
bool_t string_find_ic(
	__in      string_t const s_string, 
	__in_opt  uint_t         n_string_length, 
	__in      string_t const s_substring, 
	__in_opt  uint_t         n_substring_length, 
	__out_opt int_t*         _n_first, 
	__out_opt int_t*         _n_last
);


FWIMPORT
bool_t string_isempty(
	__in string_t s_string
);


FWIMPORT
uint_t string_length(
	__in string_t const s_string
);


FWIMPORT
string_t string_lower(
	__inout     string_t s_string, 
	__inout_opt size_t*  _n_string_length
);


FWIMPORT 
string_t string_push(
	__inout     string_t       s_dst,
	__inout_opt uint_t*        _n_dst_length,
	__in        string_t const s_src,
	__in_opt    uint_t         n_src_length
);


FWIMPORT
string_t string_reduce_left(
	__inout     string_t     s_string,
	__in        uint_t const n_count,
	__inout_opt uint_t*      _n_string_length
);


FWIMPORT
string_t string_reduce_right(
	__inout     string_t     s_string, 
	__in        uint_t const n_count,
	__inout_opt uint_t*      _n_string_length
);


/// <summary>
/// Reverses a given string.
/// </summary>
/// <param name="s_string">
/// The string to reverse.
/// </param>
/// <returns>
/// @s_string reversed.
/// </returns>
FWIMPORT
string_t string_reverse(
	__inout string_t s_string
);


FWIMPORT
bool_t string_startswith(
	__in     string_t const s_string, 
	__in_opt uint_t         n_string_length, 
	__in     string_t const s_prefix, 
	__in_opt uint_t         n_prefix_length
);


FWIMPORT
string_t string_substring(
	__in      string_t const s_string, 
	__in_opt  uint_t         n_string_length, 
	__in      uint_t         n_first, 
	__in      uint_t         n_last, 
	__inout   string_t       s_substring, 
	__out_opt uint_t*        _n_substring_length
);


FWIMPORT
wchar_t* string_towide(
	__in     string_t const s_string_multibyte,
	__inout  wchar_t*       s_string_unicode,
	__in_opt uint_t         n_max_count
);


FWIMPORT
string_t string_upper(
	__inout     string_t s_string, 
	__inout_opt size_t*  _n_string_length
);


/// <summary>
/// Replaces each character before a null-terminator in a string with zero
/// ("zeroes" it).
/// </summary>
/// <param name="s_string">
/// String to zero.
/// </param>
/// <returns>
/// @s_string zeroed.
/// </returns>
FWIMPORT
string_t string_zero(
	__inout     string_t s_string,
	__inout_opt size_t*  _n_string_length
);


