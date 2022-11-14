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
#include <carbon/util/strings.h>
#include <carbon/type/primitives.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
FWIMPORT __success(return) bool_t nct_int_cto_string(
	__in  int_t const num,
	__out char_t*     s_num
);


FWIMPORT __success(return) bool_t nct_int_cto_string_w(
	__in  int_t const num,
	__out wchar_t*    s_num
);


FWIMPORT __success(return) bool_t nct_long_cto_string(
	__in  long_t const num,
	__out char_t*      s_num
);


FWIMPORT __success(return) bool_t nct_long_cto_string_w(
	__in  long_t const num,
	__out wchar_t*     s_num
);


FWIMPORT __success(return) bool_t nct_short_cto_string(
	__in  short_t const num,
	__out char_t*       s_num
);


FWIMPORT __success(return) bool_t nct_short_cto_string_w(
	__in  short_t const num,
	__out wchar_t*      s_num
);


FWIMPORT __success(return) bool_t nct_ulong_cto_string(
	__in  ulong_t const num,
	__out char_t*       s_num
);


FWIMPORT __success(return) bool_t nct_ulong_cto_string_w(
	__in  ulong_t const num,
	__out wchar_t*      s_num
);


FWIMPORT __success(return) bool_t nct_ushort_cto_string(
	__in  ushort_t const num,
	__out char_t*        s_num
);


FWIMPORT __success(return) bool_t nct_ushort_cto_string_w(
	__in  ushort_t const num,
	__out wchar_t*       s_num
);


FWIMPORT __success(return) bool_t nct_string_cto_int(
	__in  string_t const s_num,
	__out int_t*         _num
);


FWIMPORT __success(return) bool_t nct_string_cto_int_w(
	__in  wstring_t const s_num,
	__out int_t*          _num
);


FWIMPORT __success(return) bool_t nct_string_cto_long(
	__in  string_t const s_num,
	__out long_t*        _num
);


FWIMPORT __success(return) bool_t nct_string_cto_long_w(
	__in  wstring_t const s_num,
	__out long_t*         _num
);


FWIMPORT __success(return) bool_t nct_string_cto_longlong(
	__in  string_t const s_num,
	__out longlong_t*    _num
);


FWIMPORT __success(return) bool_t nct_string_cto_longlong_w(
	__in  wstring_t const s_num,
	__out longlong_t*     _num
);


FWIMPORT __success(return) bool_t nct_string_cto_short(
	__in  string_t const s_num,
	__out short_t*       _num
);


FWIMPORT __success(return) bool_t nct_string_cto_short_w(
	__in  wstring_t const s_num,
	__out short_t*        _num
);


FWIMPORT __success(return) bool_t nct_string_cto_ulong(
	__in  string_t const s_num,
	__out ulong_t*       _num
);


FWIMPORT __success(return) bool_t nct_string_cto_ulong_w(
	__in  wstring_t const s_num,
	__out ulong_t*        _num
);


FWIMPORT __success(return) bool_t nct_string_cto_ushort(
	__in  string_t const s_num,
	__out ushort_t*      _num
);


FWIMPORT __success(return) bool_t nct_string_cto_ushort_w(
	__in  wstring_t const s_num,
	__out ushort_t*       _num
);


#if __CHARSET == CHARSET_MULTIBYTE
#define nct_int_cto_string_t			nct_int_cto_string
#define nct_long_cto_string_t			nct_long_cto_string
#define nct_short_cto_string_t			nct_short_cto_string
#define nct_ulong_cto_string_t			nct_ulong_cto_string
#define nct_ushort_cto_string_t			nct_ushort_cto_string
#define nct_string_cto_int_t			nct_string_cto_int
#define nct_string_cto_long_t			nct_string_cto_long
#define nct_string_cto_longlong_t		nct_string_cto_longlong
#define nct_string_cto_short_t			nct_string_cto_short
#define nct_string_cto_ulong_t			nct_string_cto_ulong
#define nct_string_cto_ushort_t			nct_string_cto_ushort
#elif __CHARSET == CHARSET_UNICODE
#define nct_int_cto_string_t			nct_int_cto_string_w
#define nct_long_cto_string_t			nct_long_cto_string_w
#define nct_short_cto_string_t			nct_short_cto_string_w
#define nct_ulong_cto_string_t			nct_ulong_cto_string_w
#define nct_ushort_cto_string_t			nct_ushort_cto_string_w
#define nct_string_cto_int_t			nct_string_cto_int_w
#define nct_string_cto_long_t			nct_string_cto_long_w
#define nct_string_cto_longlong_t		nct_string_cto_longlong_w
#define nct_string_cto_short_t			nct_string_cto_short_w
#define nct_string_cto_ulong_t			nct_string_cto_ulong_w
#define nct_string_cto_ushort_t			nct_string_cto_ushort_w
#endif // __CHARSET?


