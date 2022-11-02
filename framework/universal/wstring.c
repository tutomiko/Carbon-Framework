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
#include <fireworks/type/wstring.h>
#pragma endregion
#
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#include <assert.h>
#include <string.h>
#include <ctype.h>
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
FWEXPORT
wstring_t wstring_append(__inout wstring_t s_dst, __inout_opt uint_t* _n_dst_length, __in wstring_t const s_src) {
#pragma region <locals>
	uint_t n_dst_length;
#pragma endregion


	assert(NULL != s_src);
	assert(NULL != s_dst);


	if (NULL != _n_dst_length)
		n_dst_length = *_n_dst_length;
	else {
		n_dst_length = 0;
	}

	if (n_dst_length == 0) {
		n_dst_length = wcslen(s_dst);
	}

	for (int_t i = 0; i < _MAX_STRING; i++) {
		wchar_t chr;

		chr = s_src[i];

		if (chr == L'\0') {
			break;
		}

		s_dst[n_dst_length] = chr;
		n_dst_length++;
	}

	s_dst[n_dst_length] = L'\0';


#pragma region <returns>
	if (NULL != _n_dst_length) {
		*_n_dst_length = n_dst_length;
	}
#pragma endregion


	return s_dst;
}


FWEXPORT
wchar_t wstring_charat(__in wstring_t const s_string, __in uint_t const n_index) {
	assert(NULL != s_string);


	return s_string[n_index];
}


FWEXPORT
int_t wstring_compare(__in wstring_t const s_string1, __in wstring_t const s_string2) {
	assert(NULL != s_string1);
	assert(NULL != s_string2);


	return wcscmp(s_string1, s_string2);
}


FWEXPORT
int_t wstring_compare_ic(__in wstring_t const s_string1, __in wstring_t const s_string2) {
	assert(NULL != s_string1);
	assert(NULL != s_string2);


	return _wcsicmp(s_string1, s_string2);
}


FWEXPORT
int_t wstring_comparex(__in wstring_t const s_string1, __in wstring_t const s_string2, __in uint_t const n_count) {
	assert(NULL != s_string1);
	assert(NULL != s_string2);


	return wcsncmp(s_string1, s_string2, n_count);
}


FWEXPORT
int_t wstring_comparex_ic(__in wstring_t const s_string1, __in wstring_t const s_string2, __in uint_t const n_count) {
	assert(NULL != s_string1);
	assert(NULL != s_string2);


	return _wcsnicmp(s_string1, s_string2, n_count);
}


FWEXPORT
wstring_t wstring_concat(__inout wstring_t s_dst, __inout_opt uint_t* _n_dst_length, __in wstring_t const s_src) {
#pragma region <locals>
	uint_t n_dst_length;
#pragma endregion


	assert(NULL != s_src);
	assert(NULL != s_dst);
	assert(s_dst[0] != L'\0');


	if (NULL != _n_dst_length)
		n_dst_length = *_n_dst_length;
	else {
		n_dst_length = 0;
	}

	if (n_dst_length == 0) {
		n_dst_length = wcslen(s_dst);
	}

	for (int_t i = 0; i < _MAX_STRING; i++) {
		wchar_t chr;

		chr = s_src[i];

		if (chr == L'\0') {
			break;
		}

		s_dst[n_dst_length] = chr;
		n_dst_length++;
	}

	s_dst[n_dst_length] = L'\0';


#pragma region <returns>
	if (NULL != _n_dst_length) {
		*_n_dst_length = n_dst_length;
	}
#pragma endregion


	return s_dst;
}


FWEXPORT
bool_t wstring_contains(__in wstring_t const s_string, __in_opt uint_t n_string_length, __in wstring_t const s_substring, __in_opt uint_t n_substring_length) {
#pragma region <locals>
	bool_t b_contains = false;
#pragma endregion
	

	assert(NULL != s_string);
	assert(NULL != s_substring);

	
	if (n_string_length == 0) {
		n_string_length = _MAX_STRING;
	}

	if (n_substring_length == 0) {
		n_substring_length = wcslen(s_substring);
	}

	for (int_t i = 0; i < n_string_length; i++) {
		wchar_t chr;

		chr = s_string[i];

		if (chr == L'\0') {
			break;
		}

		if (chr != s_substring[0]) {
			continue;
		}

		if (wcsncmp(&(s_string[i]), s_substring, n_substring_length) == 0) {
			b_contains = true;

			break;
		}
	}


	return b_contains;
}


FWEXPORT
bool_t wstring_contains_ic(__in wstring_t const s_string, __in_opt uint_t n_string_length, __in wstring_t const s_substring, __in_opt uint_t n_substring_length) {
#pragma region <locals>
	bool_t b_contains = false;
#pragma endregion
	

	assert(NULL != s_string);
	assert(NULL != s_substring);


	if (n_string_length == 0) {
		n_string_length = _MAX_STRING;
	}

	if (n_substring_length == 0) {
		n_substring_length = wcslen(s_substring);
	}

	for (int_t i = 0; i < n_string_length; i++) {
		wchar_t chr;

		chr = s_string[i];

		if (chr == L'\0') {
			break;
		}

		if (wchar_tolower(chr) != wchar_tolower(s_substring[0])) {
			continue;
		}

		if (_wcsnicmp(&(s_string[i]), s_substring, n_substring_length) == 0) {
			b_contains = true;

			break;
		}
	}


	return b_contains;
}


FWEXPORT
wstring_t wstring_copy(__inout wstring_t s_dst, __in wstring_t const s_src, __out_opt uint_t* _n_copied) {
#pragma region <locals>
	uint_t n_copied = 0;
#pragma endregion


	assert(NULL != s_src);
	assert(NULL != s_dst);


	for (int_t i = 0; i < _MAX_STRING; i++) {
		wchar_t chr;

		chr = s_src[i];

		if (chr == L'\0') {
			n_copied = i;

			break;
		}

		s_dst[i] = chr;
	}

	s_dst[n_copied] = L'\0';


#pragma region <returns>
	if (NULL != _n_copied) {
		*_n_copied = n_copied;
	}
#pragma endregion


	return s_dst;
}


FWEXPORT
wstring_t wstring_copyx(__inout wstring_t s_dst, __in wstring_t const s_src, __in uint_t const n_count, __out_opt uint_t* _n_length) {
#pragma region <locals>
	uint_t n_length;
#pragma endregion


	assert(NULL != s_src);
	assert(NULL != s_dst);


	for (n_length = 0; n_length < n_count; n_length++) {
		wchar_t chr;

		chr = s_src[n_length];

		if (chr == L'\0') {
			break;
		}

		s_dst[n_length] = chr;
	}

	s_dst[n_length] = L'\0';


#pragma region <returns>
	if (NULL != _n_length) {
		*_n_length = n_length;
	}
#pragma endregion


	return s_dst;
}


FWEXPORT
bool_t wstring_endswith(__in wstring_t const s_string, __in_opt uint_t n_string_length, __in wstring_t const s_suffix, __in_opt uint_t n_suffix_length) {
#pragma region <locals>
	bool_t b_equals;
#pragma endregion


	assert(NULL != s_string);
	assert(NULL != s_suffix);


	if (n_string_length == 0) {
		n_string_length = wcslen(s_string);
	}

	if (n_suffix_length == 0) {
		n_suffix_length = wcslen(s_suffix);
	}
	
	if (n_string_length >= n_suffix_length)
		b_equals = (wcsncmp(&(s_string[n_string_length - n_suffix_length]), s_suffix, n_suffix_length) == 0);
	else {
		b_equals = false;
	}


	return b_equals;
}


FWEXPORT
bool_t wstring_equals(__in wstring_t const s_string1, __in wstring_t const s_string2) {
	assert(NULL != s_string1);
	assert(NULL != s_string2);


	return (wcscmp(s_string1, s_string2) == 0);
}


FWEXPORT
bool_t wstring_equals_ic(__in wstring_t const s_string1, __in wstring_t const s_string2) {
	assert(NULL != s_string1);
	assert(NULL != s_string2);


	return (_wcsicmp(s_string1, s_string2) == 0);
}


FWEXPORT
bool_t wstring_equalsx(__in wstring_t const s_string1, __in wstring_t const s_string2, __in uint_t const n_count) {
	assert(NULL != s_string1);
	assert(NULL != s_string2);


	return (wcsncmp(s_string1, s_string2, n_count) == 0);
}


FWEXPORT
bool_t wstring_equalsx_ic(__in wstring_t const s_string1, __in wstring_t const s_string2, __in uint_t const n_count) {
	assert(NULL != s_string1);
	assert(NULL != s_string2);


	return (_wcsnicmp(s_string1, s_string2, n_count) == 0);
}


FWEXPORT
wstring_t wstring_fill(__in wstring_t s_string, __in wchar_t c_chr, __in uint_t n_count) {
	assert(NULL != s_string);


	for (int_t i = 0; i < n_count; i++) s_string[i] = c_chr;

	s_string[n_count] = L'\0';

	return s_string;
}


FWEXPORT
bool_t wstring_find(__in wstring_t const s_string, __in_opt uint_t n_string_length, __in wstring_t const s_substring, __in_opt uint_t n_substring_length, __out_opt int_t* _n_first, __out_opt int_t* _n_last) {
#pragma region <locals>
	bool_t b_found = false;
	int_t  n_first = -1,
		   n_last = -1;
#pragma endregion
	

	assert(NULL != s_string);
	assert(NULL != s_substring);


	if (n_string_length == 0) {
		n_string_length = _MAX_STRING;
	}

	if (n_substring_length == 0) {
		n_substring_length = wcslen(s_substring);
	}

	for (int_t i = 0; i < n_string_length; i++) {
		wchar_t chr;

		chr = s_string[i];

		if (chr == L'\0') {
			break;
		}

		if (chr != s_substring[0]) {
			continue;
		}
		
		if (wcsncmp(&(s_string[i]), s_substring, n_substring_length) == 0) {
			b_found = true;
			n_first = i;
			n_last = (i + n_substring_length);

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_first) {
		*_n_first = n_first;
	}

	if (NULL != _n_last) {
		*_n_last = n_last;
	}
#pragma endregion


	return b_found;
}


FWEXPORT
bool_t wstring_find_ic(__in wstring_t const s_string, __in_opt uint_t n_string_length, __in wstring_t const s_substring, __in_opt uint_t n_substring_length, __out_opt int_t* _n_first, __out_opt int_t* _n_last) {
#pragma region <locals>
	bool_t b_found = false;
	int_t  n_first = -1,
		   n_last = -1;
#pragma endregion
	

	assert(NULL != s_string);
	assert(NULL != s_substring);


	if (n_string_length == 0) {
		n_string_length = _MAX_STRING;
	}

	if (n_substring_length == 0) {
		n_substring_length = wcslen(s_substring);
	}

	for (int_t i = 0; i < n_string_length; i++) {
		wchar_t chr;

		chr = s_string[i];

		if (chr == L'\0') {
			break;
		}
		
		if (wchar_tolower(chr) != wchar_tolower(s_substring[0])) {
			continue;
		}

		if (_wcsnicmp(&(s_string[i]), s_substring, n_substring_length) == 0) {
			b_found = true;
			n_first = i;
			n_last = (i + n_substring_length);

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_first) {
		*_n_first = n_first;
	}

	if (NULL != _n_last) {
		*_n_last = n_last;
	}
#pragma endregion


	return b_found;
}


FWEXPORT
bool_t wstring_isempty(__in wstring_t s_string) {
	assert(NULL != s_string);


	return (s_string[0] == L'\0');
}


FWEXPORT
uint_t wstring_length(__in wstring_t const s_string) {
#pragma region <locals>
	uint_t n_string_length;
#pragma endregion


	assert(NULL != s_string);


	for (n_string_length = 0; (n_string_length < _MAX_STRING); n_string_length++) {
		if (s_string[n_string_length] == L'\0') {
			break;
		}
	}


	return n_string_length;
}


FWEXPORT
wstring_t wstring_lower(__inout wstring_t s_string, __inout_opt size_t* _n_string_length) {
#pragma region <locals>
	uint_t n_string_length;
#pragma endregion


	assert(NULL != s_string);


	if (NULL != _n_string_length)
		n_string_length = *_n_string_length;
	else {
		n_string_length = 0;
	}

	if (n_string_length == 0) {
		n_string_length = _MAX_STRING;
	}

	for (int_t i = 0; i < n_string_length; i++) {
		wchar_t chr;

		chr = s_string[i];

		if (chr == L'\0') {
			n_string_length = i;

			break;
		}

		s_string[i] = wchar_tolower(chr);
	}


#pragma region <returns>
	if (NULL != _n_string_length) {
		*_n_string_length = n_string_length;
	}
#pragma endregion


	return s_string;
}


FWEXPORT
wstring_t wstring_push(__inout wstring_t s_dst, __inout_opt uint_t* _n_dst_length, __in wstring_t const s_src, __in_opt uint_t n_src_length) {
#pragma region <locals>
	uint_t n_dst_length;
#pragma endregion


	assert(NULL != s_src);
	assert(NULL != s_dst);


	if (NULL != _n_dst_length)
		n_dst_length = *_n_dst_length;
	else {
		n_dst_length = 0;
	}

	if (n_dst_length == 0) {
		n_dst_length = wcslen(s_dst);
	}

	if (n_src_length == 0) {
		n_src_length = wcslen(s_src);
	}

	for (int_t i = n_dst_length; i >= 0; i--) {
		wchar_t chr;

		chr = s_dst[i];

		s_dst[i + n_src_length] = chr;
	}
	
	for (uint_t i = 0; i < n_src_length; i++) {
		wchar_t chr;

		chr = s_src[i];

		s_dst[i] = chr;
	}

	n_dst_length += n_src_length;
	s_dst[n_dst_length] = L'\0';


#pragma region <returns>
	if (NULL != _n_dst_length) {
		*_n_dst_length = n_dst_length;
	}
#pragma endregion


	return s_dst;
}


FWEXPORT
wstring_t wstring_reduce_left(__inout wstring_t s_string, __in uint_t const n_count, __inout_opt uint_t* _n_string_length) {
#pragma region <locals>
	uint_t n_string_length;
#pragma endregion


	assert(NULL != s_string);


	if (NULL != _n_string_length)
		n_string_length = *_n_string_length;
	else {
		n_string_length = 0;
	}

	if (n_string_length == 0) {
		n_string_length = _MAX_STRING;
	}

	for (int_t i = 0; i < n_string_length; i++) {
		wchar_t chr;

		chr = s_string[i + n_count];

		s_string[i] = chr;

		if (chr == L'\0') {
			n_string_length = i;

			break;
		}
	}

	s_string[n_string_length] = L'\0';


#pragma region <returns>
	if (NULL != _n_string_length) {
		*_n_string_length = n_string_length;
	}
#pragma endregion


	return s_string;
}


FWEXPORT
wstring_t wstring_reduce_right(__inout wstring_t s_string, __in uint_t const n_count, __inout_opt uint_t* _n_string_length) {
#pragma region <locals>
	uint_t n_string_length;
#pragma endregion
	

	assert(NULL != s_string);


	if (NULL != _n_string_length) 
		n_string_length = *_n_string_length;
	else {
		n_string_length = 0;
	}

	if (n_string_length == 0) {
		n_string_length = wcslen(s_string);
	}

	assert(n_count <= n_string_length);

	n_string_length -= n_count;
	s_string[n_string_length] = L'\0';


#pragma region <returns>
	if (NULL != _n_string_length) {
		*_n_string_length = n_string_length;
	}
#pragma endregion


	return s_string;
}


FWEXPORT
wstring_t wstring_reverse(__inout wstring_t s_string) {
	assert(NULL != s_string);

	
	return _wcsrev(s_string);
}


FWEXPORT
bool_t wstring_startswith(__in wstring_t const s_string, __in_opt uint_t n_string_length, __in wstring_t const s_prefix, __in_opt uint_t n_prefix_length) {
#pragma region <locals>
	bool_t b_equals;
#pragma endregion


	assert(NULL != s_string);
	assert(NULL != s_prefix);


	if (n_string_length == 0) {
		n_string_length = wcslen(s_string);
	}

	if (n_prefix_length == 0) {
		n_prefix_length = wcslen(s_prefix);
	}

	b_equals = (wcsncmp(s_string, s_prefix, n_prefix_length) == 0);


	return b_equals;
}


FWIMPORT
wstring_t wstring_substring(__in wstring_t const s_string, __in_opt uint_t n_string_length, __in uint_t n_first, __in uint_t n_last, __inout wstring_t s_substring, __out_opt uint_t* _n_substring_length) {
#pragma region <locals>
	uint_t n_substring_length;
#pragma endregion

	
	assert(NULL != s_string);
	assert(NULL != s_substring);
	assert(!(n_first >= n_last));


	if (n_string_length == 0) {
		n_string_length = wcslen(s_string);
	}

	if (n_last == 0) {
		n_last = n_string_length;
	}

	n_substring_length = (n_last - n_first);

	assert(n_substring_length < n_string_length);

	if (n_substring_length > 0) {
		wcsncpy(s_substring, &(s_string[n_first]), n_substring_length);
	}


#pragma region <returns>
	if (NULL != _n_substring_length) {
		*_n_substring_length = n_substring_length;
	}
#pragma endregion


	return s_substring;
}


FWIMPORT
char_t* wstring_tomb(__in wstring_t const s_string_unicode, __inout char_t* s_string_multibyte, __in_opt uint_t n_max_count) {
#pragma region <locals>

#pragma endregion


	assert(NULL != s_string_unicode);
	assert(NULL != s_string_multibyte);


	if (n_max_count == 0) {
		n_max_count = _MAX_STRING;
	}

	for (int_t i = 0; i < n_max_count; i++) {
		char_t  chr_multibyte;
		wchar_t chr_unicode;

		chr_unicode = s_string_unicode[i];

		if (chr_unicode == L'\0') {
			break;
		}

		wctomb(&chr_multibyte, chr_unicode);

		s_string_multibyte[i] = chr_multibyte;
	}


	return s_string_multibyte;
}


FWEXPORT
wstring_t wstring_upper(__inout wstring_t s_string, __inout_opt size_t* _n_string_length) {
#pragma region <locals>
	uint_t n_string_length;
#pragma endregion


	assert(NULL != s_string);


	if (NULL != _n_string_length)
		n_string_length = *_n_string_length;
	else {
		n_string_length = 0;
	}

	if (n_string_length == 0) {
		n_string_length = _MAX_STRING;
	}

	for (int_t i = 0; i < n_string_length; i++) {
		wchar_t chr;

		chr = s_string[i];

		if (chr == L'\0') {
			n_string_length = i;

			break;
		}

		s_string[i] = wchar_toupper(chr);
	}


#pragma region <returns>
	if (NULL != _n_string_length) {
		*_n_string_length = n_string_length;
	}
#pragma endregion


	return s_string;
}


FWEXPORT
wstring_t wstring_zero(__inout wstring_t s_string, __inout_opt size_t* _n_string_length) {
#pragma region <locals>
	size_t n_string_length;
#pragma endregion


	assert(NULL != s_string);


	if (NULL != _n_string_length)
		n_string_length = *_n_string_length;
	else {
		n_string_length = 0;
	}

	if (n_string_length == 0) {
		n_string_length = _MAX_STRING;
	}

	for (int_t i = 0; i < n_string_length; i++) {
		wchar_t chr;

		chr = s_string[i];

		if (chr == L'\0') {
			n_string_length = i;

			break;
		}

		s_string[i] = L'\0';
	}


#pragma region <returns>
	if (NULL != _n_string_length) {
		*_n_string_length = n_string_length;
	}
#pragma endregion


	return s_string;
}

