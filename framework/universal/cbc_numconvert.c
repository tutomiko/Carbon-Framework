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
#include <carbon/util/numconvert.h>
#pragma endregion
#
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

#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
CBCEXPORT __success(return) bool_t nct_int_cto_string(__in int_t const num, __out char_t* s_num) {
	return (NULL != _itoa(num, s_num, 10));
}


CBCEXPORT __success(return) bool_t nct_int_cto_string_w(__in int_t const num, __out wchar_t* s_num) {
	return (NULL != _itow(num, s_num, 10));
}


CBCEXPORT __success(return) bool_t nct_long_cto_string(__in long_t const num, __out char_t* s_num) {
	return (NULL != _ltoa(num, s_num, 10));
}


CBCEXPORT __success(return) bool_t nct_long_cto_string_w(__in long_t const num, __out wchar_t* s_num) {
	return (NULL != _ltow(num, s_num, 10));
}


CBCEXPORT __success(return) bool_t nct_short_cto_string(__in short_t const num, __out char_t* s_num) {
	return (NULL != _itoa(num, s_num, 10));
}


CBCEXPORT __success(return) bool_t nct_short_cto_string_w(__in short_t const num, __out wchar_t* s_num) {
	return (NULL != _itow(num, s_num, 10));
}


CBCEXPORT __success(return) bool_t nct_ulong_cto_string(__in ulong_t const num, __out char_t* s_num) {
	return (NULL != _ultoa(num, s_num, 10));
}


CBCEXPORT __success(return) bool_t nct_ulong_cto_string_w(__in ulong_t const num, __out wchar_t* s_num) {
	return (NULL != _ultow(num, s_num, 10));
}


CBCEXPORT __success(return) bool_t nct_ushort_cto_string(__in ushort_t const num, __out char_t * s_num) {
	return (NULL != _itoa(num, s_num, 10));
}


CBCEXPORT __success(return) bool_t nct_ushort_cto_string_w(__in ushort_t const num, __out wchar_t* s_num) {
	return (NULL != _itow(num, s_num, 10));
}


CBCEXPORT __success(return) bool_t nct_string_cto_int(__in string_t const s_num, __out int_t* _num) {
	int_t num;

	num = atoi(s_num);

	if ((num == 0) && !string_equals(s_num, "0"))
		return false;
	else {
		*_num = num;

		return true;
	}
}


CBCEXPORT __success(return) bool_t nct_string_cto_int_w(__in wstring_t const s_num, __out int_t* _num) {
	int_t num;

	num = _wtoi(s_num);

	if ((num == 0) && !wstring_equals(s_num, L"0"))
		return false;
	else {
		*_num = num;

		return true;
	}
}


CBCEXPORT __success(return) bool_t nct_string_cto_long(__in string_t const s_num, __out long_t* _num) {
	long_t num;

	num = atol(s_num);

	if ((num == 0) && !string_equals(s_num, "0"))
		return false;
	else {
		*_num = num;

		return true;
	}
}


CBCEXPORT __success(return) bool_t nct_string_cto_long_w(__in wstring_t const s_num, __out long_t* _num) {
	long_t num;

	num = _wtol(s_num);

	if ((num == 0) && !wstring_equals(s_num, L"0"))
		return false;
	else {
		*_num = num;

		return true;
	}
}


CBCEXPORT __success(return) bool_t nct_string_cto_longlong(__in string_t const s_num, __out longlong_t * _num) {
	longlong_t num;

	num = atoll(s_num);

	if ((num == 0) && !string_equals(s_num, "0"))
		return false;
	else {
		*_num = num;

		return true;
	}
}


CBCEXPORT __success(return) bool_t nct_string_cto_longlong_w(__in wstring_t const s_num, __out longlong_t * _num) {
	longlong_t num;

	num = _wtoll(s_num);

	if ((num == 0) && !wstring_equals(s_num, L"0"))
		return false;
	else {
		*_num = num;

		return true;
	}
}


CBCEXPORT __success(return) bool_t nct_string_cto_short(__in string_t const s_num, __out short_t* _num) {
	short_t num;

	num = atoi(s_num);

	if ((num == 0) && !string_equals(s_num, "0"))
		return false;
	else {
		*_num = num;

		return true;
	}
}


CBCEXPORT __success(return) bool_t nct_string_cto_short_w(__in wstring_t const s_num, __out short_t* _num) {
	short_t num;

	num = _wtoi(s_num);

	if ((num == 0) && !wstring_equals(s_num, L"0"))
		return false;
	else {
		*_num = num;

		return true;
	}
}


CBCEXPORT __success(return) bool_t nct_string_cto_ushort(__in string_t const s_num, __out ushort_t* _num) {
	ushort_t num;

	num = atoi(s_num);

	if ((num == 0) && !string_equals(s_num, "0"))
		return false;
	else {
		*_num = num;

		return true;
	}
}


CBCEXPORT __success(return) bool_t nct_string_cto_ushort_w(__in wstring_t const s_num, __out ushort_t* _num) {
	ushort_t num;

	num = _wtoi(s_num);

	if ((num == 0) && !wstring_equals(s_num, L"0"))
		return false;
	else {
		*_num = num;

		return true;
	}
}


CBCEXPORT __success(return) bool_t nct_string_cto_ulong(__in string_t const s_num, __out ulong_t* _num) {
	ulong_t num;

	num = atoll(s_num);

	if ((num == 0) && !string_equals(s_num, "0"))
		return false;
	else {
		*_num = num;

		return true;
	}
}


CBCEXPORT __success(return) bool_t nct_string_cto_ulong_w(__in wstring_t const s_num, __out ulong_t* _num) {
	ulong_t num;

	num = _wtoll(s_num);

	if ((num == 0) && !wstring_equals(s_num, L"0"))
		return false;
	else {
		*_num = num;

		return true;
	}
}

