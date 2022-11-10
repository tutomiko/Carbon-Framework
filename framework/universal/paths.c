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
#include <carbon/sys/paths.h>
#pragma endregion
#
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#include <assert.h>
#include <string.h>
#include <time.h>
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
string_t path_addextension(__inout string_t s_path, __inout_opt uint_t* _n_path_length, __in string_t const s_extension, __in_opt uint_t n_extension_length, __out_opt int_t* _n_delimiter) {
#pragma region <locals>
	int_t  n_delimiter;
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != s_extension);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	if (n_extension_length == 0) {
		n_extension_length = string_length(s_extension);
	}

	n_delimiter = n_path_length;

	if (!string_endswith(s_path, n_path_length, ".", 0) && !string_startswith(s_extension, n_extension_length, ".", 0)) {
		strcat(s_path, ".");
		n_path_length++;
	}

	strcat(s_path, s_extension);
	n_path_length += n_extension_length;
	s_path[n_path_length] = '\0';


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}

	if (NULL != _n_delimiter) {
		*_n_delimiter = n_delimiter;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
wstring_t path_addextension_w(__inout wstring_t s_path, __inout_opt uint_t* _n_path_length, __in wstring_t const s_extension, __in_opt uint_t n_extension_length, __out_opt int_t* _n_delimiter) {
#pragma region <locals>
	int_t  n_delimiter;
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != s_extension);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	if (n_extension_length == 0) {
		n_extension_length = wstring_length(s_extension);
	}

	n_delimiter = n_path_length;

	if (!wstring_endswith(s_path, n_path_length, L".", 0) && !wstring_startswith(s_extension, n_extension_length, L".", 0)) {
		wcscat(s_path, L".");
		n_path_length++;
	}

	wcscat(s_path, s_extension);
	n_path_length += n_extension_length;
	s_path[n_path_length] = L'\0';


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}

	if (NULL != _n_delimiter) {
		*_n_delimiter = n_delimiter;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
string_t path_append(__inout string_t s_dst_path, __inout_opt uint_t* _n_dst_path_length, __in string_t const s_src_path) {
#pragma region <locals>
	uint_t n_dst_path_length;
#pragma endregion


	assert(NULL != s_src_path);
	assert(NULL != s_dst_path);


	if (NULL != _n_dst_path_length)
		n_dst_path_length = *_n_dst_path_length;
	else {
		n_dst_path_length = 0;
	}

	if (n_dst_path_length == 0) {
		n_dst_path_length = string_length(s_dst_path);
	}
	
	if (n_dst_path_length == 0 || path_isdirectory(s_dst_path, 0)) 
		string_append(s_dst_path, &n_dst_path_length, s_src_path);
	else {
		string_append(s_dst_path, &n_dst_path_length, "\\");
		string_append(s_dst_path, &n_dst_path_length, s_src_path);
	}


#pragma region <returns>
	if (NULL != _n_dst_path_length) {
		*_n_dst_path_length = n_dst_path_length;
	}
#pragma endregion


	return s_dst_path;
}


FWEXPORT
wstring_t path_append_w(__inout wstring_t s_dst_path, __inout_opt uint_t* _n_dst_path_length, __in wstring_t const s_src_path) {
#pragma region <locals>
	uint_t n_dst_path_length;
#pragma endregion


	assert(NULL != s_src_path);
	assert(NULL != s_dst_path);


	if (NULL != _n_dst_path_length)
		n_dst_path_length = *_n_dst_path_length;
	else {
		n_dst_path_length = 0;
	}

	if (n_dst_path_length == 0) {
		n_dst_path_length = wstring_length(s_dst_path);
	}
	
	if (n_dst_path_length == 0 || path_isdirectory_w(s_dst_path, 0)) 
		wstring_append(s_dst_path, &n_dst_path_length, s_src_path);
	else {
		wstring_append(s_dst_path, &n_dst_path_length, L"\\");
		wstring_append(s_dst_path, &n_dst_path_length, s_src_path);
	}


#pragma region <returns>
	if (NULL != _n_dst_path_length) {
		*_n_dst_path_length = n_dst_path_length;
	}
#pragma endregion


	return s_dst_path;
}


FWEXPORT
string_t path_build(__inout string_t s_dst_path, __out_opt uint_t* _n_dst_path_length, __in_opt string_t const s_directory_path, __in_opt string_t const s_file_prefix, __in string_t const s_file_name, __in_opt string_t const s_file_extension) {
#pragma region <locals>
	uint_t n_dst_path_length = 0;
#pragma endregion

	
	assert(NULL != s_dst_path);
	assert(NULL != s_file_name);


	if (NULL != s_directory_path) {
		string_append(s_dst_path, &n_dst_path_length, s_directory_path);
	}

	if (n_dst_path_length > 0 && !path_isdirectory(s_dst_path, n_dst_path_length)) {
		path_todirectory(s_dst_path, &n_dst_path_length);
	}

	if (NULL != s_file_prefix) {
		string_append(s_dst_path, &n_dst_path_length, s_file_prefix);
	}

	string_append(s_dst_path, &n_dst_path_length, s_file_name);

	if (NULL != s_file_extension) {
		if (NULL != path_getextensionptr(s_file_name, 0, 0, NULL))
			path_setextension(s_dst_path, &n_dst_path_length, 0, s_file_extension, 0, NULL);
		else {
			path_addextension(s_dst_path, &n_dst_path_length, s_file_extension, 0, NULL);
		}
	}


#pragma region <returns>
	if (NULL != _n_dst_path_length) {
		*_n_dst_path_length = n_dst_path_length;
	}
#pragma endregion


	return s_dst_path;
}


FWEXPORT
wstring_t path_build_w(__inout wstring_t s_dst_path, __out_opt uint_t* _n_dst_path_length, __in_opt wstring_t const s_directory_path, __in_opt wstring_t const s_file_prefix, __in wstring_t const s_file_name, __in_opt wstring_t const s_file_extension) {
#pragma region <locals>
	uint_t n_dst_path_length = 0;
#pragma endregion

	
	assert(NULL != s_dst_path);
	assert(NULL != s_file_name);


	if (NULL != s_directory_path) {
		wstring_append(s_dst_path, &n_dst_path_length, s_directory_path);
	}

	if (n_dst_path_length > 0 && !path_isdirectory_w(s_dst_path, n_dst_path_length)) {
		path_todirectory_w(s_dst_path, &n_dst_path_length);
	}

	if (NULL != s_file_prefix) {
		wstring_append(s_dst_path, &n_dst_path_length, s_file_prefix);
	}

	wstring_append(s_dst_path, &n_dst_path_length, s_file_name);

	if (NULL != s_file_extension) {
		if (NULL != path_getextensionptr_w(s_file_name, 0, 0, NULL)) 
			path_setextension_w(s_dst_path, &n_dst_path_length, 0, s_file_extension, 0, NULL);
		else {
			path_addextension_w(s_dst_path, &n_dst_path_length, s_file_extension, 0, NULL);
		}
	}


#pragma region <returns>
	if (NULL != _n_dst_path_length) {
		*_n_dst_path_length = n_dst_path_length;
	}
#pragma endregion


	return s_dst_path;
}


FWEXPORT
string_t path_build_random(__inout string_t s_dst_path, __out_opt uint_t* _n_dst_path_length, __in_opt string_t const s_directory_path, __in_opt string_t const s_file_prefix, __in uint_t const n_file_name_length, __in_opt string_t const s_file_extension) {
#pragma region <locals>
	uint_t n_dst_path_length = 0;
	char_t s_file_name[_MAX_FNAME + 1];
#pragma endregion


	assert(NULL != s_dst_path);


	memzero(s_file_name, sizeof s_file_name);

	for (uint_t i = 0; i < n_file_name_length; i++) {
		char_t chr;

		srand(time(NULL) + i);

		do {
			chr = (char_t)rand();
		} while (!char_isalphabet(chr) && !(char_isnumber(chr) && (i > 0 || NULL != s_file_prefix)));

		s_file_name[i] = chr;
	}

	s_file_name[n_file_name_length] = '\0';

	path_build(s_dst_path, &n_dst_path_length, s_directory_path, s_file_prefix, s_file_name, s_file_extension);


#pragma region <returns>
	if (NULL != _n_dst_path_length) {
		*_n_dst_path_length = n_dst_path_length;
	}
#pragma endregion


	return s_dst_path;
}


FWEXPORT
wstring_t path_build_random_w(__inout wstring_t s_dst_path, __out_opt uint_t* _n_dst_path_length, __in_opt wstring_t const s_directory_path, __in_opt wstring_t const s_file_prefix, __in uint_t const n_file_name_length, __in_opt wstring_t const s_file_extension) {
#pragma region <locals>
	uint_t  n_dst_path_length = 0;
	wchar_t s_file_name[_MAX_FNAME + 1];
#pragma endregion


	assert(NULL != s_dst_path);


	memzero(s_file_name, sizeof s_file_name);

	for (uint_t i = 0; i < n_file_name_length; i++) {
		wchar_t chr;

		srand(time(NULL) + i);

		do {
			chr = (wchar_t)rand();
		} while (!wchar_isalphabet(chr) && !(wchar_isnumber(chr) && (i > 0 || NULL != s_file_prefix)));

		s_file_name[i] = chr;
	}

	s_file_name[n_file_name_length] = L'\0';

	path_build_w(s_dst_path, &n_dst_path_length, s_directory_path, s_file_prefix, s_file_name, s_file_extension);


#pragma region <returns>
	if (NULL != _n_dst_path_length) {
		*_n_dst_path_length = n_dst_path_length;
	}
#pragma endregion


	return s_dst_path;
}


FWEXPORT
bool_t path_equals(__in string_t const s_path1, __in string_t const s_path2) {
#pragma region <locals>
	bool   b_eval = false,
		   b_more;
	uint_t n_cursor1 = 0,
		   n_cursor2 = 0, 
		   n_file1_name_length,
		   n_file2_name_length;
	char_t s_file1_name[_MAX_FNAME + 1];
	char_t s_file2_name[_MAX_FNAME + 1];
#pragma endregion


	assert(NULL != s_path1);
	assert(NULL != s_path2);


$eval:
	memzero(s_file1_name, sizeof s_file1_name);

	if (path_iterate_names(s_path1, s_file1_name, &n_file1_name_length, &n_cursor1, &b_more)) {
		memzero(s_file2_name, sizeof s_file2_name);

		if (path_iterate_names(s_path2, s_file2_name, &n_file2_name_length, &n_cursor2, &b_more)) {
			if (string_equals_ic(s_file1_name, s_file2_name)) {
				if (b_more) 
					goto $eval;
				else {
					b_eval = true;
				}
			}
		}
	}

	return b_eval;
}


FWEXPORT
bool_t path_equals_w(__in wstring_t const s_path1, __in wstring_t const s_path2) {
#pragma region <locals>
	bool    b_eval = false,
		    b_more;
	uint_t  n_cursor1 = 0,
		    n_cursor2 = 0, 
		    n_file1_name_length,
		    n_file2_name_length;
	wchar_t s_file1_name[_MAX_FNAME + 1];
	wchar_t s_file2_name[_MAX_FNAME + 1];
#pragma endregion


	assert(NULL != s_path1);
	assert(NULL != s_path2);


$eval:
	memzero(s_file1_name, sizeof s_file1_name);

	if (path_iterate_names_w(s_path1, s_file1_name, &n_file1_name_length, &n_cursor1, &b_more)) {
		memzero(s_file2_name, sizeof s_file2_name);

		if (path_iterate_names_w(s_path2, s_file2_name, &n_file2_name_length, &n_cursor2, &b_more)) {
			if (wstring_equals_ic(s_file1_name, s_file2_name)) {
				if (b_more) 
					goto $eval;
				else {
					b_eval = true;
				}
			}
		}
	}

	return b_eval;
}


FWEXPORT
string_t path_getdrive(__in string_t const s_path, __inout string_t s_drive, __out_opt uint_t* _n_drive_length) {
#pragma region <locals>
	char_t c_drive;
	uint_t n_drive_length = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != s_drive);


	c_drive = path_getdriveletter(s_path);

	if (c_drive) {
		s_drive[n_drive_length] = c_drive;
		n_drive_length++;

		s_drive[n_drive_length] = ':';
		n_drive_length++;

		s_drive[n_drive_length] = '\\';
		n_drive_length++;

		s_drive[n_drive_length] = '\0';
	} else {
		s_drive = NULL;
	}


#pragma region <returns>
	if (NULL != _n_drive_length) {
		*_n_drive_length = n_drive_length;
	}
#pragma endregion


	return s_drive;
}


FWEXPORT
wstring_t path_getdrive_w(__in wstring_t const s_path, __inout wstring_t s_drive, __out_opt uint_t* _n_drive_length) {
#pragma region <locals>
	wchar_t c_drive;
	uint_t  n_drive_length = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != s_drive);


	c_drive = path_getdriveletter_w(s_path);

	if (c_drive) {
		s_drive[n_drive_length] = c_drive;
		n_drive_length++;

		s_drive[n_drive_length] = L':';
		n_drive_length++;

		s_drive[n_drive_length] = L'\\';
		n_drive_length++;

		s_drive[n_drive_length] = L'\0';
	} else {
		s_drive = NULL;
	}


#pragma region <returns>
	if (NULL != _n_drive_length) {
		*_n_drive_length = n_drive_length;
	}
#pragma endregion


	return s_drive;
}


FWEXPORT
char_t path_getdriveletter(__in string_t const s_path) {
#pragma region <locals>
	char_t c_drive = 0;
#pragma endregion

	
	assert(NULL != s_path);


	for (int_t i = 0; i < _MAX_PATH; i++) {
		char_t chr;

		chr = s_path[i];

		if (chr == '\0') {
			break;
		}

		if (chr == ':') {
			if (i > 0) {
				c_drive = s_path[i - 1];
			}

			break;
		}
	}


	return c_drive;
}


FWEXPORT
wchar_t path_getdriveletter_w(__in wstring_t const s_path) {
#pragma region <locals>
	wchar_t c_drive = 0;
#pragma endregion

	
	assert(NULL != s_path);


	for (int_t i = 0; i < _MAX_PATH; i++) {
		wchar_t chr;

		chr = s_path[i];

		if (chr == L'\0') {
			break;
		}

		if (chr == L':') {
			if (i > 0) {
				c_drive = s_path[i - 1];
			}

			break;
		}
	}


	return c_drive;
}


FWEXPORT
string_t path_getextension(__in string_t const s_path, __in_opt uint_t n_path_length, __in uint_t const n_index, __inout string_t s_extension, __out_opt uint_t* _n_extension_length) {
#pragma region <locals>
	uint_t n_extension_length = 0;
	uint_t n_filename_begin = 0;
	int_t  n_position = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != s_extension);


	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	for (int_t i = n_path_length; i > 0; i--) {
		char_t chr;

		chr = s_path[i];

		if (chr == '\\' || chr == '/') {
			n_filename_begin = i;

			break;
		}
	}

	for (int_t i = (n_filename_begin + 1); i < n_path_length; i++) {
		char_t chr;

		chr = s_path[i];

		if (chr != '.') {
			continue;
		}

		if (n_position < ((int_t)n_index)) 
			n_position++;
		else {
			n_extension_length = (n_path_length - i);

			strcpy(s_extension, &(s_path[i]));

			break;
		}
	}

	if (n_extension_length == 0) 
		s_extension = NULL;
	else {
		s_extension[n_extension_length] = '\0';
	}


#pragma region <returns>
	if (NULL != _n_extension_length) {
		*_n_extension_length = n_extension_length;
	}
#pragma endregion


	return s_extension;
}


FWEXPORT
wstring_t path_getextension_w(__in wstring_t const s_path, __in_opt uint_t n_path_length, __in uint_t const n_index, __inout wstring_t s_extension, __out_opt uint_t* _n_extension_length) {
#pragma region <locals>
	uint_t n_extension_length = 0;
	uint_t n_filename_begin = 0;
	int_t  n_position = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != s_extension);


	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	for (int_t i = n_path_length; i > 0; i--) {
		wchar_t chr;

		chr = s_path[i];

		if (chr == L'\\' || chr == L'/') {
			n_filename_begin = i;

			break;
		}
	}

	for (int_t i = (n_filename_begin + 1); i < n_path_length; i++) {
		wchar_t chr;

		chr = s_path[i];

		if (chr != L'.') {
			continue;
		}

		if (n_position < ((int_t)n_index)) 
			n_position++;
		else {
			n_extension_length = (n_path_length - i);

			wcscpy(s_extension, &(s_path[i]));

			break;
		}
	}

	if (n_extension_length == 0) 
		s_extension = NULL;
	else {
		s_extension[n_extension_length] = L'\0';
	}


#pragma region <returns>
	if (NULL != _n_extension_length) {
		*_n_extension_length = n_extension_length;
	}
#pragma endregion


	return s_extension;
}


FWEXPORT
string_t path_getextensionptr(__in string_t const s_path, __in_opt uint_t n_path_length, __in uint_t const n_index, __out_opt uint_t* _n_extension_length) {
#pragma region <locals>
	uint_t   n_extension_length = 0;
	uint_t   n_filename_begin = 0;
	int_t    n_position = 0;
	string_t s_extension = NULL;
#pragma endregion


	assert(NULL != s_path);


	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	for (int_t i = n_path_length; i > 0; i--) {
		char_t chr;

		chr = s_path[i];

		if (chr == '\\' || chr == '/') {
			n_filename_begin = i;

			break;
		}
	}

	for (int_t i = (n_filename_begin + 1); i < n_path_length; i++) {
		char_t chr;

		chr = s_path[i];

		if (chr != '.') {
			continue;
		}
		if (n_position < ((int_t)n_index)) 
			n_position++;
		else {
			n_extension_length = (n_path_length - i);

			s_extension = &(s_path[i]);

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_extension_length) {
		*_n_extension_length = n_extension_length;
	}
#pragma endregion


	return s_extension;
}


FWEXPORT
wstring_t path_getextensionptr_w(__in wstring_t const s_path, __in_opt uint_t n_path_length, __in uint_t const n_index, __out_opt uint_t* _n_extension_length) {
#pragma region <locals>
	uint_t    n_extension_length = 0;
	uint_t    n_filename_begin = 0;
	int_t     n_position = 0;
	wstring_t s_extension = NULL;
#pragma endregion


	assert(NULL != s_path);


	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	for (int_t i = n_path_length; i > 0; i--) {
		wchar_t chr;

		chr = s_path[i];

		if (chr == L'\\' || chr == L'/') {
			n_filename_begin = i;

			break;
		}
	}

	for (int_t i = (n_filename_begin + 1); i < n_path_length; i++) {
		wchar_t chr;

		chr = s_path[i];

		if (chr != L'.') {
			continue;
		}
		if (n_position < ((int_t)n_index)) 
			n_position++;
		else {
			n_extension_length = (n_path_length - i);

			s_extension = &(s_path[i]);

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_extension_length) {
		*_n_extension_length = n_extension_length;
	}
#pragma endregion


	return s_extension;
}


FWEXPORT 
string_t path_getfname(__in string_t const s_path, __inout string_t s_filename, __out_opt uint_t* _n_filename_length) {
#pragma region <locals>
	uint_t   n_filename_length;
	string_t s_filename_ptr;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != s_filename);


	s_filename_ptr = path_getfnameptr(s_path, &n_filename_length);

	if (NULL != s_filename_ptr) 
		string_copy(s_filename, s_filename_ptr, NULL);
	else {
		s_filename = NULL;
	}


#pragma region <returns>
	if (NULL != _n_filename_length) {
		*_n_filename_length = n_filename_length;
	}
#pragma endregion


	return s_filename;
}


FWEXPORT 
wstring_t path_getfname_w(__in wstring_t const s_path, __inout wstring_t s_filename, __out_opt uint_t* _n_filename_length) {
#pragma region <locals>
	uint_t    n_filename_length;
	wstring_t s_filename_ptr;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != s_filename);


	s_filename_ptr = path_getfnameptr_w(s_path, &n_filename_length);

	if (NULL != s_filename_ptr) 
		wstring_copy(s_filename, s_filename_ptr, NULL);
	else {
		s_filename = NULL;
	}


#pragma region <returns>
	if (NULL != _n_filename_length) {
		*_n_filename_length = n_filename_length;
	}
#pragma endregion


	return s_filename;
}


FWEXPORT 
string_t path_getfnameptr(__in string_t const s_path, __out_opt uint_t* _n_filename_length) {
#pragma region <locals>
	uint_t   n_filename_length = 0;
	uint_t   n_path_length = 0;
	int_t    n_separator_last = -1;
	int_t    n_separator_second_last = -1;
	string_t s_filename = NULL;
#pragma endregion


	assert(NULL != s_path);


	for (uint_t i = 0; i < _MAX_PATH; i++) {
		char_t chr;

		chr = s_path[i];

		if (chr == '\0') {
			n_path_length = i;

			break;
		}

		if (chr == '\\' || chr == '/') {
			if (n_separator_last != -1) {
				n_separator_second_last = n_separator_last;
			}

			n_separator_last = i;
		}
	}

	if (n_path_length > 0) {
		if (n_separator_last == (n_path_length - 1)) { // Path is directory;
			s_filename = &(s_path[n_separator_second_last + 1]);

			n_filename_length = ((n_path_length - n_separator_second_last) - 1);
		} else {
			s_filename = &(s_path[n_separator_last + 1]);

			n_filename_length = ((n_path_length - n_separator_last) - 1);
		}
	}


#pragma region <returns>
	if (NULL != _n_filename_length) {
		*_n_filename_length = n_filename_length;
	}
#pragma endregion


	return s_filename;
}


FWEXPORT 
wstring_t path_getfnameptr_w(__in wstring_t const s_path, __out_opt uint_t* _n_filename_length) {
#pragma region <locals>
	uint_t    n_filename_length = 0;
	uint_t    n_path_length = 0;
	int_t     n_separator_last = -1;
	int_t     n_separator_second_last = -1;
	wstring_t s_filename = NULL;
#pragma endregion


	assert(NULL != s_path);


	for (uint_t i = 0; i < _MAX_PATH; i++) {
		wchar_t chr;

		chr = s_path[i];

		if (chr == L'\0') {
			n_path_length = i;

			break;
		}

		if (chr == L'\\' || chr == L'/') {
			if (n_separator_last != -1) {
				n_separator_second_last = n_separator_last;
			}

			n_separator_last = i;
		}
	}

	if (n_path_length > 0) {
		if (n_separator_last == (n_path_length - 1)) { // Path is directory;
			s_filename = &(s_path[n_separator_second_last + 1]);

			n_filename_length = ((n_path_length - n_separator_second_last) - 1);
		} else {
			s_filename = &(s_path[n_separator_last + 1]);

			n_filename_length = ((n_path_length - n_separator_last) - 1);
		}
	}


#pragma region <returns>
	if (NULL != _n_filename_length) {
		*_n_filename_length = n_filename_length;
	}
#pragma endregion


	return s_filename;
}


FWEXPORT
string_t path_getparent(__in string_t const s_path, __in_opt uint_t n_path_length, __inout string_t s_directory_path, __out_opt uint_t* _n_directory_path_length) {
#pragma region <locals>
	uint_t n_directory_path_length = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != s_directory_path);


	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	for (int_t i = n_path_length; i >= 0; i--) {
		char_t chr;

		chr = s_path[i];

		if (i == 0) {
			s_directory_path = NULL;

			break;
		}

		if (chr == '\\' || chr == '/') {
			if (s_path[i + 1] == '\0') {
				n_directory_path_length = i;

				do i--; while (s_path[i] == '\\' || s_path[i] == '/');

				continue;
			}
			
			n_directory_path_length = (i + 1);

			strncpy(s_directory_path, s_path, n_directory_path_length);
			s_directory_path[n_directory_path_length] = '\0';

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_directory_path_length) {
		*_n_directory_path_length = n_directory_path_length;
	}
#pragma endregion


	return s_directory_path;
}


FWEXPORT
wstring_t path_getparent_w(__in wstring_t const s_path, __in_opt uint_t n_path_length, __inout wstring_t s_directory_path, __out_opt uint_t* _n_directory_path_length) {
#pragma region <locals>
	uint_t n_directory_path_length = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != s_directory_path);


	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	for (int_t i = n_path_length; i >= 0; i--) {
		wchar_t chr;

		chr = s_path[i];

		if (i == 0) {
			s_directory_path = NULL;

			break;
		}

		if (chr == L'\\' || chr == L'/') {
			if (s_path[i + 1] == L'\0') {
				n_directory_path_length = i;

				do i--; while (s_path[i] == L'\\' || s_path[i] == L'/');

				continue;
			}
			
			n_directory_path_length = (i + 1);

			wcsncpy(s_directory_path, s_path, n_directory_path_length);
			s_directory_path[n_directory_path_length] = L'\0';

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_directory_path_length) {
		*_n_directory_path_length = n_directory_path_length;
	}
#pragma endregion


	return s_directory_path;
}


FWEXPORT
bool_t path_hasparent(__in string_t const s_path) {
#pragma region <locals>
	bool_t b_eval = false;
#pragma endregion


	assert(NULL != s_path);
	

	for (int_t i = 0; i < _MAX_PATH; i++) {
		char_t chr;

		chr = s_path[i];

		if (chr == '\0') {
			break;
		}

		if ((chr == '\\' || chr == '/') && (i > 0 && (s_path[i - 1] != '\\' && s_path[i - 1] != '/'))) {
			do i++; while (s_path[i] == '\\' || s_path[i] == '/');

			if (s_path[i] != '\0') {
				b_eval = true;
			}

			break;
		}
	}


	return b_eval;
}


FWEXPORT
bool_t path_hasparent_w(__in wstring_t const s_path) {
#pragma region <locals>
	bool_t b_eval = false;
#pragma endregion


	assert(NULL != s_path);
	

	for (int_t i = 0; i < _MAX_PATH; i++) {
		wchar_t chr;

		chr = s_path[i];

		if (chr == L'\0') {
			break;
		}

		if ((chr == L'\\' || chr == L'/') && (i > 0 && (s_path[i - 1] != L'\\' && s_path[i - 1] != L'/'))) {
			do i++; while (s_path[i] == L'\\' || s_path[i] == L'/');

			if (s_path[i] != L'\0') {
				b_eval = true;
			}

			break;
		}
	}


	return b_eval;
}


FWEXPORT 
string_t path_init(__inout string_t s_dst, __in string_t const s_src, __in bool_t const b_directory, __out_opt uint_t* _n_length) {
#pragma region <locals>
	uint_t n_length;
#pragma endregion


	assert(NULL != s_dst);
	assert(NULL != s_src);


	string_copy(s_dst, s_src, &n_length);

	if (b_directory && !path_isdirectory(s_dst, n_length)) 
		path_todirectory(s_dst, &n_length);
	else if (!b_directory && path_isdirectory(s_dst, n_length)) {
		path_tofile(s_dst, &n_length);
	}


#pragma region <returns>
	if (NULL != _n_length) {
		*_n_length = n_length;
	}
#pragma endregion


	return s_dst;
}


FWEXPORT 
wstring_t path_init_w(__inout wstring_t s_dst, __in wstring_t const s_src, __in bool_t const b_directory, __out_opt uint_t* _n_length) {
#pragma region <locals>
	uint_t n_length;
#pragma endregion


	assert(NULL != s_dst);
	assert(NULL != s_src);


	wstring_copy(s_dst, s_src, &n_length);

	if (b_directory && !path_isdirectory_w(s_dst, n_length)) 
		path_todirectory_w(s_dst, &n_length);
	else if (!b_directory && path_isdirectory_w(s_dst, n_length)) {
		path_tofile_w(s_dst, &n_length);
	}


#pragma region <returns>
	if (NULL != _n_length) {
		*_n_length = n_length;
	}
#pragma endregion


	return s_dst;
}


FWEXPORT
bool_t path_isabsolute(__in string_t const s_path) {
#pragma region <locals>
	bool_t b_is_absolute;
#pragma endregion


	assert(NULL != s_path);


	if (// Relative from drive;
		(s_path[0] == '\\' || s_path[0] == '/')
		 ||
		// Relative from current directory;
		(s_path[0] == '.' && (s_path[1] == '\\' || s_path[1] == '/'))
		 || 
		// Relative parent from current directory;
		(s_path[0] == '.' && s_path[1] == '.')
	) {
		b_is_absolute = false;
	} else {
		b_is_absolute = true;
	}


	return b_is_absolute;
}


FWEXPORT
bool_t path_isabsolute_w(__in wstring_t const s_path) {
#pragma region <locals>
	bool_t b_is_absolute;
#pragma endregion


	assert(NULL != s_path);


	if (// Relative from drive;
		(s_path[0] == L'\\' || s_path[0] == L'/')
		 ||
		// Relative from current directory;
		(s_path[0] == L'.' && (s_path[1] == L'\\' || s_path[1] == L'/'))
		 || 
		// Relative parent from current directory;
		(s_path[0] == L'.' && s_path[1] == L'.')
	) {
		b_is_absolute = false;
	} else {
		b_is_absolute = true;
	}


	return b_is_absolute;
}


FWEXPORT
bool_t path_isancestorof(__in string_t const s_path1, __in string_t const s_path2) {
#pragma region <locals>
	bool_t b_eval = false,
		   b_more;
	uint_t n_cursor = 0;
	uint_t n_file_path_length;
	char_t s_file_path[_MAX_PATH + 1];
#pragma endregion


	assert(NULL != s_path1);
	assert(NULL != s_path2);


$eval:
	memzero(s_file_path, sizeof s_file_path);

	if (path_iterate(s_path2, s_file_path, &n_file_path_length, &n_cursor, &b_more)) {
		b_eval = path_equals(s_path1, s_file_path);

		if (b_eval && b_more) {
			goto $eval;
		}
	}


	return b_eval;
}


FWEXPORT
bool_t path_isancestorof_w(__in wstring_t const s_path1, __in wstring_t const s_path2) {
#pragma region <locals>
	bool_t b_eval = false,
		   b_more;
	uint_t n_cursor = 0;
	uint_t n_file_path_length;
	char_t s_file_path[_MAX_PATH + 1];
#pragma endregion


	assert(NULL != s_path1);
	assert(NULL != s_path2);


$eval:
	memzero(s_file_path, sizeof s_file_path);

	if (path_iterate_w(s_path2, s_file_path, &n_file_path_length, &n_cursor, &b_more)) {
		b_eval = path_equals_w(s_path1, s_file_path);

		if (b_eval && b_more) {
			goto $eval;
		}
	}


	return b_eval;
}


FWEXPORT
bool_t path_isdescendantof(__in string_t const s_path1, __in string_t const s_path2) {
#pragma region <locals>
	bool_t b_eval = false,
		   b_more;
	uint_t n_cursor = 0;
	uint_t n_file_path_length;
	char_t s_file_path[_MAX_PATH + 1];
#pragma endregion


	assert(NULL != s_path1);
	assert(NULL != s_path2);


$eval:
	memzero(s_file_path, sizeof s_file_path);

	if (path_iterate(s_path1, s_file_path, &n_file_path_length, &n_cursor, &b_more)) {
		b_eval = path_equals(s_path2, s_file_path);

		if (b_eval && b_more) {
			goto $eval;
		}
	}


	return b_eval;
}


FWEXPORT
bool_t path_isdescendantof_w(__in wstring_t const s_path1, __in wstring_t const s_path2) {
#pragma region <locals>
	bool_t  b_eval = false,
		    b_more;
	uint_t  n_cursor = 0;
	uint_t  n_file_path_length;
	wchar_t s_file_path[_MAX_PATH + 1];
#pragma endregion


	assert(NULL != s_path1);
	assert(NULL != s_path2);


$eval:
	memzero(s_file_path, sizeof s_file_path);

	if (path_iterate_w(s_path1, s_file_path, &n_file_path_length, &n_cursor, &b_more)) {
		b_eval = path_equals_w(s_path2, s_file_path);

		if (b_eval && b_more) {
			goto $eval;
		}
	}


	return b_eval;
}


FWEXPORT
bool_t path_isdirectory(__in string_t const s_path, __in_opt uint_t n_path_length) {
#pragma region <locals>
	bool_t b_is_directory;
#pragma endregion


	assert(NULL != s_path);


	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	if (n_path_length > 0 && (s_path[n_path_length - 1] == '\\' || s_path[n_path_length - 1] == '/')) 
		b_is_directory = true;
	else {
		b_is_directory = false;
	}


	return b_is_directory;
}


FWEXPORT
bool_t path_isdirectory_w(__in wstring_t const s_path, __in_opt uint_t n_path_length) {
#pragma region <locals>
	bool_t b_is_directory;
#pragma endregion


	assert(NULL != s_path);


	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	if (n_path_length > 0 && (s_path[n_path_length - 1] == L'\\' || s_path[n_path_length - 1] == L'/')) 
		b_is_directory = true;
	else {
		b_is_directory = false;
	}


	return b_is_directory;
}


FWEXPORT
bool_t path_isfile(__in string_t const s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	bool_t b_is_file;
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length) 
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	if (n_path_length > 0 && (s_path[n_path_length - 1] == '\\' || s_path[n_path_length - 1] == '/')) 
		b_is_file = false;
	else {
		b_is_file = true;
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return b_is_file;
}


FWEXPORT
bool_t path_isfile_w(__in wstring_t const s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	bool_t b_is_file;
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length) 
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	if (n_path_length > 0 && (s_path[n_path_length - 1] == L'\\' || s_path[n_path_length - 1] == L'/')) 
		b_is_file = false;
	else {
		b_is_file = true;
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return b_is_file;
}


FWEXPORT
bool_t path_isparentof(__in string_t const s_path1, __in string_t const s_path2) {
#pragma region <locals>
	bool_t b_eval = false;
	uint_t n_directory_path_length;
	char_t s_directory_path[_MAX_PATH + 1];
#pragma endregion


	assert(NULL != s_path1);
	assert(NULL != s_path2);


	memzero(s_directory_path, sizeof s_directory_path);

	if (path_getparent(s_path2, 0, s_directory_path, &n_directory_path_length)) {
		if (path_equals(s_path1, s_directory_path)) {
			b_eval = true;
		}
	}


	return b_eval;
}


FWEXPORT
bool_t path_isparentof_w(__in wstring_t const s_path1, __in wstring_t const s_path2) {
#pragma region <locals>
	bool_t  b_eval = false;
	uint_t  n_directory_path_length;
	wchar_t s_directory_path[_MAX_PATH + 1];
#pragma endregion


	assert(NULL != s_path1);
	assert(NULL != s_path2);


	memzero(s_directory_path, sizeof s_directory_path);

	if (path_getparent_w(s_path2, 0, s_directory_path, &n_directory_path_length)) {
		if (path_equals_w(s_path1, s_directory_path)) {
			b_eval = true;
		}
	}


	return b_eval;
}


FWEXPORT
bool_t path_isrelative(__in string_t const s_path) {
#pragma region <locals>
	bool_t b_is_relative;
#pragma endregion


	assert(NULL != s_path);


	if (// Relative from drive;
		(s_path[0] == '\\' || s_path[0] == '/')
		 ||
		// Relative from current directory;
		(s_path[0] == '.' && (s_path[1] == '\\' || s_path[1] == '/'))
		 || 
		// Relative parent from current directory;
		(s_path[0] == '.' && s_path[1] == '.')
	) {
		b_is_relative = true;
	} else {
		b_is_relative = false;
	}


	return b_is_relative;
}


FWEXPORT
bool_t path_isrelative_w(__in wstring_t const s_path) {
#pragma region <locals>
	bool_t b_is_relative;
#pragma endregion


	assert(NULL != s_path);


	if (// Relative from drive;
		(s_path[0] == L'\\' || s_path[0] == L'/')
		 ||
		// Relative from current directory;
		(s_path[0] == L'.' && (s_path[1] == L'\\' || s_path[1] == L'/'))
		 || 
		// Relative parent from current directory;
		(s_path[0] == L'.' && s_path[1] == L'.')
	) {
		b_is_relative = true;
	} else {
		b_is_relative = false;
	}


	return b_is_relative;
}


FWEXPORT
bool_t path_iterate(__in string_t const s_path, __inout string_t s_file_path, __out_opt uint_t* _n_file_path_length, __inout uint_t* _n_cursor, __out_opt bool_t* _b_more) {
#pragma region <locals>
	bool_t b_more = false,
		   b_return = false;
	uint_t n_cursor;
	uint_t n_file_path_length = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != _n_cursor);
	

	for (n_cursor = *_n_cursor; n_cursor < _MAX_PATH; n_cursor++) {
		char_t chr;

		chr = s_path[n_cursor];

		if (chr == '\\' || chr == '/' || chr == '\0') {
			if (chr == '\0')
				n_file_path_length = n_cursor;
			else {
				while (s_path[n_cursor + 1] == '\\' || s_path[n_cursor + 1] == '/') {
					n_cursor++;
				}

				n_file_path_length = (n_cursor + 1);
			}

			if (n_file_path_length == 0) {
				break;
			}

			if (n_file_path_length == 1 && (chr == '\\' || chr == '/')) {
				if (s_file_path[n_cursor + 1] == '\0')
					continue;
				else {
					break;
				}
			}

			string_copyx(s_file_path, s_path, n_file_path_length, NULL);

			if ((s_path[n_cursor] == '\\' || s_path[n_cursor] == '/') && s_path[n_cursor + 1] != '\0') {
				b_more = true;
			}

			n_cursor++;

			b_return = true;

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_file_path_length) {
		*_n_file_path_length = n_file_path_length;
	}

	*_n_cursor = n_cursor;

	if (NULL != _b_more) {
		*_b_more = b_more;
	}
#pragma endregion


	return b_return;
}


FWEXPORT
bool_t path_iterate_w(__in wstring_t const s_path, __inout wstring_t s_file_path, __out_opt uint_t* _n_file_path_length, __inout uint_t* _n_cursor, __out_opt bool_t* _b_more) {
#pragma region <locals>
	bool_t b_more = false,
		   b_return = false;
	uint_t n_cursor;
	uint_t n_file_path_length = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != _n_cursor);
	

	for (n_cursor = *_n_cursor; n_cursor < _MAX_PATH; n_cursor++) {
		wchar_t chr;

		chr = s_path[n_cursor];

		if (chr == L'\\' || chr == L'/' || chr == L'\0') {
			if (chr == L'\0')
				n_file_path_length = n_cursor;
			else {
				while (s_path[n_cursor + 1] == L'\\' || s_path[n_cursor + 1] == L'/') {
					n_cursor++;
				}

				n_file_path_length = (n_cursor + 1);
			}

			if (n_file_path_length == 0) {
				break;
			}

			if (n_file_path_length == 1 && (chr == L'\\' || chr == L'/')) {
				if (s_file_path[n_cursor + 1] == L'\0')
					continue;
				else {
					break;
				}
			}

			wstring_copyx(s_file_path, s_path, n_file_path_length, NULL);

			if ((s_path[n_cursor] == L'\\' || s_path[n_cursor] == L'/') && s_path[n_cursor + 1] != L'\0') {
				b_more = true;
			}

			n_cursor++;

			b_return = true;

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_file_path_length) {
		*_n_file_path_length = n_file_path_length;
	}

	*_n_cursor = n_cursor;

	if (NULL != _b_more) {
		*_b_more = b_more;
	}
#pragma endregion


	return b_return;
}


FWEXPORT
bool_t path_iterate_names(__in string_t const s_path, __inout string_t s_file_name, __out_opt uint_t* _n_file_name_length, __inout uint_t* _n_cursor, __out_opt bool_t* _b_more) {
#pragma region <locals>
	bool_t b_more = false,
		   b_return = false;
	uint_t n_cursor;
	uint_t n_file_name_length = 0;
	uint_t n_last_delimiter = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != _n_cursor);

	
	for (n_cursor = *_n_cursor; n_cursor < _MAX_PATH; n_cursor++) {
		char_t chr;

		chr = s_path[n_cursor];

		if (chr == '\\' || chr == '/' || chr == '\0') {
			if (n_last_delimiter == 0 && n_cursor > 0) {
				for (n_last_delimiter = (n_cursor - 1); n_last_delimiter > 0; n_last_delimiter--) {
					chr = s_path[n_last_delimiter];

					if (chr == '\\' || chr == '/') {
						n_last_delimiter++;

						break;
					}
				}
			}

			if (n_last_delimiter > 0)
				n_file_name_length = (n_cursor - n_last_delimiter);
			else {
				n_file_name_length = n_cursor;
			}

			if (n_file_name_length == 0 || (n_file_name_length == 1 && (chr == '\\' || chr == '/'))) {
				if (s_path[n_cursor + 1] != '\0') {
					n_last_delimiter++;

					continue;
				} else {
					break;
				}
			}

			string_copyx(s_file_name, &(s_path[n_last_delimiter]), n_file_name_length, NULL);

			if ((s_path[n_cursor] == '\\' || s_path[n_cursor] == '/') && s_path[n_cursor + 1] != '\0') {
				b_more = true;
			}

			n_cursor++;

			b_return = true;

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_file_name_length) {
		*_n_file_name_length = n_file_name_length;
	}

	*_n_cursor = n_cursor;

	if (NULL != _b_more) {
		*_b_more = b_more;
	}
#pragma endregion


	return b_return;
}


FWEXPORT
bool_t path_iterate_names_w(__in wstring_t const s_path, __inout wstring_t s_file_name, __out_opt uint_t* _n_file_name_length, __inout uint_t* _n_cursor, __out_opt bool_t* _b_more) {
#pragma region <locals>
	bool_t b_more = false,
		   b_return = false;
	uint_t n_cursor;
	uint_t n_file_name_length = 0;
	uint_t n_last_delimiter = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(NULL != _n_cursor);

	
	for (n_cursor = *_n_cursor; n_cursor < _MAX_PATH; n_cursor++) {
		wchar_t chr;

		chr = s_path[n_cursor];

		if (chr == L'\\' || chr == L'/' || chr == L'\0') {
			if (n_last_delimiter == 0 && n_cursor > 0) {
				for (n_last_delimiter = (n_cursor - 1); n_last_delimiter > 0; n_last_delimiter--) {
					chr = s_path[n_last_delimiter];

					if (chr == L'\\' || chr == L'/') {
						n_last_delimiter++;

						break;
					}
				}
			}

			if (n_last_delimiter > 0)
				n_file_name_length = (n_cursor - n_last_delimiter);
			else {
				n_file_name_length = n_cursor;
			}

			if (n_file_name_length == 0 || (n_file_name_length == 1 && (chr == L'\\' || chr == L'/'))) {
				if (s_path[n_cursor + 1] != L'\0') {
					n_last_delimiter++;

					continue;
				} else {
					break;
				}
			}

			wstring_copyx(s_file_name, &(s_path[n_last_delimiter]), n_file_name_length, NULL);

			if ((s_path[n_cursor] == L'\\' || s_path[n_cursor] == L'/') && s_path[n_cursor + 1] != L'\0') {
				b_more = true;
			}

			n_cursor++;

			b_return = true;

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_file_name_length) {
		*_n_file_name_length = n_file_name_length;
	}

	*_n_cursor = n_cursor;

	if (NULL != _b_more) {
		*_b_more = b_more;
	}
#pragma endregion


	return b_return;
}


FWEXPORT
string_t path_normalize(__inout string_t s_path, __out_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length = _MAX_PATH;
#pragma endregion


	assert(NULL != s_path);


	for (int_t i = 0; i < _MAX_PATH; i++) {
		char_t chr;

		chr = s_path[i];

		if (chr == '\0') {
			n_path_length = i;

			break;
		}

		if (chr == '/') {
			s_path[i] = '\\';
		}

		if (i > 0 && (chr == '\\' || chr == '/') && (s_path[i - 1] == '\\' || s_path[i - 1] == '/')) {
			for (int_t n_reductions = 0;; n_reductions++) {
				if (s_path[i + n_reductions] != '\\' && s_path[i + n_reductions] != '/') {
					string_reduce_left(&(s_path[i]), n_reductions, &n_path_length);

					i -= n_reductions;

					break;
				}
			}
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
wstring_t path_normalize_w(__inout wstring_t s_path, __out_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length = _MAX_PATH;
#pragma endregion


	assert(NULL != s_path);


	for (int_t i = 0; i < _MAX_PATH; i++) {
		wchar_t chr;

		chr = s_path[i];

		if (chr == L'\0') {
			n_path_length = i;

			break;
		}

		if (chr == L'/') {
			s_path[i] = L'\\';
		}

		if (i > 0 && (chr == L'\\' || chr == L'/') && (s_path[i - 1] == L'\\' || s_path[i - 1] == L'/')) {
			for (int_t n_reductions = 0;; n_reductions++) {
				if (s_path[i + n_reductions] != '\\' && s_path[i + n_reductions] != L'/') {
					wstring_reduce_left(&(s_path[i]), n_reductions, &n_path_length);

					i -= n_reductions;

					break;
				}
			}
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
string_t path_resolve(__in string_t const s_path, __in_opt uint_t n_path_length, __in string_t const s_context_path, __in_opt uint_t n_context_path_length, __inout string_t s_absolute_path, __out_opt uint_t* _n_absolute_path_length) {
#pragma region <locals>
	uint_t n_absolute_path_length;
	uint_t n_cursor;
	uint_t n_last_delimiter;
#pragma endregion


	assert(NULL != s_context_path);
	assert(NULL != s_path);
	assert(NULL != s_absolute_path);


	if (n_context_path_length == 0) {
		n_context_path_length = string_length(s_context_path);
	}

	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	memzero(s_absolute_path, sizeof s_absolute_path);
	
	// Relative from drive;
	if (s_path[0] == '\\' || s_path[0] == '/') {
		path_getdrive(s_context_path, s_absolute_path, &n_absolute_path_length);

		n_last_delimiter = n_cursor = 1;
	}
	// Relative from current directory;
	else if (s_path[0] == '.' && (s_path[1] == '\\' || s_path[1] == '/')) {
		string_copy(s_absolute_path, s_context_path , &n_absolute_path_length);

		n_last_delimiter = n_cursor = 2;
	}
	// Relative parent from current directory;
	else if (s_path[0] == '.' && s_path[1] == '.') {
		path_getparent(s_context_path, n_context_path_length, s_absolute_path, &n_absolute_path_length);

		n_last_delimiter = n_cursor = 3;
	}
	// ...
	else {
		string_copy(s_absolute_path, s_context_path, &n_absolute_path_length);

		n_last_delimiter = n_cursor = 0;
	}

	for (; n_cursor < (n_path_length + 1); n_cursor++) {
		char_t chr;

		chr = s_path[n_cursor];

		if (chr == '\\' || chr == '/' || chr == '\0') {
			uint_t n_filename_length;
			char_t s_filename[_MAX_FNAME + 1];

			if (n_last_delimiter > 0)
				n_filename_length = (n_cursor - n_last_delimiter);
			else {
				n_filename_length = n_cursor;
			}

			if (n_filename_length == 0) {
				if (chr != '\0')
					continue;
				else {
					path_todirectory(s_absolute_path, &n_absolute_path_length);

					break;
				}
			}

			memzero(s_filename, sizeof s_filename);

			string_copyx(s_filename, &(s_path[n_last_delimiter]), n_filename_length, &n_filename_length);
			
			if (string_equals(s_filename, "..")) 
				path_toparent(s_absolute_path, &n_absolute_path_length);
			else if (!string_equals(s_filename, ".")) {
				path_append(s_absolute_path, &n_absolute_path_length, s_filename);
			}
			
			n_last_delimiter = (n_cursor + 1);
		}
	}

	s_absolute_path[n_absolute_path_length] = '\0';


#pragma region <returns>
	if (NULL != _n_absolute_path_length) {
		*_n_absolute_path_length = n_absolute_path_length;
	}
#pragma endregion


	return s_absolute_path;
}


FWEXPORT
wstring_t path_resolve_w(__in wstring_t const s_path, __in_opt uint_t n_path_length, __in wstring_t const s_context_path, __in_opt uint_t n_context_path_length, __inout wstring_t s_absolute_path, __out_opt uint_t* _n_absolute_path_length) {
#pragma region <locals>
	uint_t n_absolute_path_length;
	uint_t n_cursor;
	uint_t n_last_delimiter;
#pragma endregion


	assert(NULL != s_context_path);
	assert(NULL != s_path);
	assert(NULL != s_absolute_path);


	if (n_context_path_length == 0) {
		n_context_path_length = wstring_length(s_context_path);
	}

	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	memzero(s_absolute_path, sizeof s_absolute_path);
	
	// Relative from drive;
	if (s_path[0] == L'\\' || s_path[0] == L'/') {
		path_getdrive_w(s_context_path, s_absolute_path, &n_absolute_path_length);

		n_last_delimiter = n_cursor = 1;
	}
	// Relative from current directory;
	else if (s_path[0] == L'.' && (s_path[1] == L'\\' || s_path[1] == L'/')) {
		wstring_copy(s_absolute_path, s_context_path , &n_absolute_path_length);

		n_last_delimiter = n_cursor = 2;
	}
	// Relative parent from current directory;
	else if (s_path[0] == L'.' && s_path[1] == L'.') {
		path_getparent_w(s_context_path, n_context_path_length, s_absolute_path, &n_absolute_path_length);

		n_last_delimiter = n_cursor = 3;
	} 
	// ...
	else {
		wstring_copy(s_absolute_path, s_context_path, &n_absolute_path_length);

		n_last_delimiter = n_cursor = 0;
	}

	for (; n_cursor < (n_path_length + 1); n_cursor++) {
		wchar_t chr;

		chr = s_path[n_cursor];

		if (chr == L'\\' || chr == L'/' || chr == L'\0') {
			uint_t  n_filename_length;
			wchar_t s_filename[_MAX_FNAME + 1];

			if (n_last_delimiter > 0)
				n_filename_length = (n_cursor - n_last_delimiter);
			else {
				n_filename_length = n_cursor;
			}

			if (n_filename_length == 0) {
				if (chr != L'\0')
					continue;
				else {
					path_todirectory_w(s_absolute_path, &n_absolute_path_length);

					break;
				}
			}

			memzero(s_filename, sizeof s_filename);

			wstring_copyx(s_filename, &(s_path[n_last_delimiter]), n_filename_length, &n_filename_length);
			
			if (wstring_equals(s_filename, L"..")) 
				path_toparent_w(s_absolute_path, &n_absolute_path_length);
			else if (!wstring_equals(s_filename, L".")) {
				path_append_w(s_absolute_path, &n_absolute_path_length, s_filename);
			}
			
			n_last_delimiter = (n_cursor + 1);
		}
	}

	s_absolute_path[n_absolute_path_length] = L'\0';


#pragma region <returns>
	if (NULL != _n_absolute_path_length) {
		*_n_absolute_path_length = n_absolute_path_length;
	}
#pragma endregion


	return s_absolute_path;
}


FWEXPORT
string_t path_rmvdrive(__inout string_t s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	for (int_t i = 0; i < _MAX_PATH; i++) {
		char_t chr;

		chr = s_path[i];

		if (chr == '\0') {
			break;
		}

		if (chr == ':') {
			uint_t n_reduction;

			n_reduction = (i + 1);

			while (s_path[n_reduction] == '\\' || s_path[n_reduction] == '/') n_reduction++;

			string_reduce_left(s_path, n_reduction, &n_path_length);

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
wstring_t path_rmvdrive_w(__inout wstring_t s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	for (int_t i = 0; i < _MAX_PATH; i++) {
		wchar_t chr;

		chr = s_path[i];

		if (chr == L'\0') {
			break;
		}

		if (chr == L':') {
			uint_t n_reduction;

			n_reduction = (i + 1);

			while (s_path[n_reduction] == L'\\' || s_path[n_reduction] == L'/') n_reduction++;

			wstring_reduce_left(s_path, n_reduction, &n_path_length);

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
string_t path_rmvextension(__inout string_t s_path, __inout_opt uint_t* _n_path_length, __in uint_t const n_index) {
#pragma region <locals>
	uint_t n_filename_begin = 0;
	uint_t n_path_length;
	int_t  n_position = 0;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	for (int_t i = n_path_length; i > 0; i--) {
		char_t chr;

		chr = s_path[i];

		if (chr == '\\' || chr == '/') {
			n_filename_begin = i;

			break;
		}
	}

	for (int_t i = (n_filename_begin + 1); i < n_path_length; i++) {
		char_t chr;

		chr = s_path[i];

		if (chr != '.') {
			continue;
		}

		if (n_position < ((int_t)n_index))
			n_position++;
		else {
			n_path_length = i;

			s_path[n_path_length] = '\0';

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
wstring_t path_rmvextension_w(__inout wstring_t s_path, __inout_opt uint_t* _n_path_length, __in uint_t const n_index) {
#pragma region <locals>
	uint_t n_filename_begin = 0;
	uint_t n_path_length;
	int_t  n_position = 0;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	for (int_t i = n_path_length; i > 0; i--) {
		wchar_t chr;

		chr = s_path[i];

		if (chr == L'\\' || chr == L'/') {
			n_filename_begin = i;

			break;
		}
	}

	for (int_t i = (n_filename_begin + 1); i < n_path_length; i++) {
		wchar_t chr;

		chr = s_path[i];

		if (chr != L'.') {
			continue;
		}

		if (n_position < ((int_t)n_index))
			n_position++;
		else {
			n_path_length = i;

			s_path[n_path_length] = L'\0';

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
string_t path_setdrive(__inout string_t s_path, __inout_opt uint_t* _n_path_length, __in_opt string_t const s_drive) {
#pragma region <locals>
	char_t c_drive;
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	if (NULL == s_drive || string_isempty(s_drive))
		path_rmvdrive(s_path, &n_path_length);
	else {
		if (s_drive[1] == '\0')
			c_drive = s_drive[0];
		else {
			c_drive = path_getdriveletter(s_drive);
		}

		for (int_t i = 0; i < _MAX_PATH; i++) {
			char_t chr;

			chr = s_path[i];

			if (chr == '\0') {
				if (!string_startswith(s_path, n_path_length, "\\", 1) && !string_startswith(s_path, n_path_length, "/", 1)) {
					string_push(s_path, &n_path_length, "\\", 1);
				}

				string_push(s_path, &n_path_length, ":", 1);

				string_push(s_path, &n_path_length, &c_drive, 1);

				break;
			}

			if (chr == ':') {
				if (i > 0) 
					s_path[i - 1] = c_drive;
				else {
					string_push(s_path, &n_path_length, &c_drive, 1);
				}

				break;
			}
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
wstring_t path_setdrive_w(__inout wstring_t s_path, __inout_opt uint_t* _n_path_length, __in_opt wstring_t const s_drive) {
#pragma region <locals>
	wchar_t c_drive;
	uint_t  n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	if (NULL == s_drive || wstring_isempty(s_drive))
		path_rmvdrive_w(s_path, &n_path_length);
	else {
		if (s_drive[1] == L'\0')
			c_drive = s_drive[0];
		else {
			c_drive = path_getdriveletter_w(s_drive);
		}

		for (int_t i = 0; i < _MAX_PATH; i++) {
			wchar_t chr;

			chr = s_path[i];

			if (chr == L'\0') {
				if (!wstring_startswith(s_path, n_path_length, L"\\", 1) && !wstring_startswith(s_path, n_path_length, L"/", 1)) {
					wstring_push(s_path, &n_path_length, L"\\", 1);
				}

				wstring_push(s_path, &n_path_length, L":", 1);

				wstring_push(s_path, &n_path_length, &c_drive, 1);

				break;
			}

			if (chr == L':') {
				if (i > 0) 
					s_path[i - 1] = c_drive;
				else {
					wstring_push(s_path, &n_path_length, &c_drive, 1);
				}

				break;
			}
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
string_t path_setextension(__inout string_t s_path, __inout_opt uint_t* _n_path_length, __in int_t const n_index, __in_opt string_t const s_extension, __in_opt uint_t n_extension_length, __out_opt int_t* _n_delimiter) {
#pragma region <locals>
	int_t  n_delimiter = -1;
	uint_t n_filename_begin = 0;
	uint_t n_path_length;
	int_t  n_position = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(n_extension_length == 0 || NULL != s_extension);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (NULL == s_extension)
		path_rmvextension(s_path, &n_path_length, n_index);
	else if (n_index == -1)
		path_addextension(s_path, &n_path_length, s_extension, n_extension_length, &n_delimiter);
	else {
		assert(n_index >= 0);

		if (n_path_length == 0) {
			n_path_length = string_length(s_path);
		}

		if (n_extension_length == 0) {
			n_extension_length = string_length(s_extension);
		}

		for (int_t i = n_path_length; i > 0; i--) {
			char_t chr;

			chr = s_path[i];

			if (chr == '\\' || chr == '/') {
				n_filename_begin = i;

				break;
			}
		}

		for (int_t i = (n_filename_begin + 1); i < n_path_length; i++) {
			char_t chr;

			chr = s_path[i];

			if (chr != '.') {
				continue;
			}

			if (n_position < ((int_t)n_index))
				n_position++;
			else if (n_position > ((int_t)n_index))
				break;
			else {
				n_delimiter = i;

				if (string_startswith(s_extension, n_extension_length, ".", 0)) {
					n_delimiter--;
				}

				n_path_length = (n_delimiter + 1);

				memcpy(&(s_path[n_path_length]), s_extension, n_extension_length);

				n_path_length += n_extension_length;

				s_path[n_path_length] = '\0';

				break;
			}
		}

		if (n_position == n_index && n_delimiter == -1) {
			n_delimiter = n_path_length;

			path_addextension(s_path, &n_path_length, s_extension, n_extension_length, &n_delimiter);
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}

	if (NULL != _n_delimiter) {
		*_n_delimiter = n_delimiter;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
wstring_t path_setextension_w(__inout wstring_t s_path, __inout_opt uint_t* _n_path_length, __in int_t const n_index, __in_opt wstring_t const s_extension, __in_opt uint_t n_extension_length, __out_opt int_t* _n_delimiter) {
#pragma region <locals>
	int_t  n_delimiter = -1;
	uint_t n_filename_begin = 0;
	uint_t n_path_length;
	int_t  n_position = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(n_extension_length == 0 || NULL != s_extension);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (NULL == s_extension)
		path_rmvextension_w(s_path, &n_path_length, n_index);
	else if (n_index == -1)
		path_addextension_w(s_path, &n_path_length, s_extension, n_extension_length, &n_delimiter);
	else {
		assert(n_index >= 0);

		if (n_path_length == 0) {
			n_path_length = wstring_length(s_path);
		}

		if (n_extension_length == 0) {
			n_extension_length = wstring_length(s_extension);
		}

		for (int_t i = n_path_length; i > 0; i--) {
			wchar_t chr;

			chr = s_path[i];

			if (chr == L'\\' || chr == L'/') {
				n_filename_begin = i;

				break;
			}
		}

		for (int_t i = (n_filename_begin + 1); i < n_path_length; i++) {
			wchar_t chr;

			chr = s_path[i];

			if (chr != L'.') {
				continue;
			}

			if (n_position < ((int_t)n_index))
				n_position++;
			else if (n_position > ((int_t)n_index))
				break;
			else {
				n_delimiter = i;

				if (wstring_startswith(s_extension, n_extension_length, L".", 0)) {
					n_delimiter--;
				}

				n_path_length = (n_delimiter + 1);

				wmemcpy(&(s_path[n_path_length]), s_extension, n_extension_length);

				n_path_length += n_extension_length;

				s_path[n_path_length] = L'\0';

				break;
			}
		}

		if (n_position == n_index && n_delimiter == -1) {
			n_delimiter = n_path_length;

			path_addextension_w(s_path, &n_path_length, s_extension, n_extension_length, &n_delimiter);
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}

	if (NULL != _n_delimiter) {
		*_n_delimiter = n_delimiter;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
string_t path_setfname(__inout string_t s_path, __inout_opt uint_t* _n_path_length, __in string_t const s_file_name, __in_opt uint_t n_file_name_length) {
#pragma region <locals>
	uint_t n_path_length;
	int_t  n_position = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(n_file_name_length == 0 || NULL != s_file_name);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	for (int_t i = n_path_length; i >= 0; i--) {
		char_t chr;

		chr = s_path[i];

		if (i == 0) {
			n_path_length = 0;

			s_path[n_file_name_length] = '\0';

			if (NULL != s_file_name) {
				string_copy(s_path, s_file_name, &n_path_length);
			}

			break;
		}

		if (chr == '\\' || chr == '/') {
			if (NULL == s_file_name) 
				string_reduce_right(s_path, (n_path_length - (i + 1)), &n_path_length);
			else {
				if (n_file_name_length == 0) {
					n_file_name_length = string_length(s_file_name);
				}

				memcpy(&(s_path[i + 1]), s_file_name, n_file_name_length);

				n_path_length = (i + 1 + n_file_name_length);

				s_path[n_path_length] = '\0';
			}

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
wstring_t path_setfname_w(__inout wstring_t s_path, __inout_opt uint_t* _n_path_length, __in wstring_t const s_file_name, __in_opt uint_t n_file_name_length) {
#pragma region <locals>
	uint_t n_path_length;
	int_t  n_position = 0;
#pragma endregion


	assert(NULL != s_path);
	assert(n_file_name_length == 0 || NULL != s_file_name);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	for (int_t i = n_path_length; i >= 0; i--) {
		wchar_t chr;

		chr = s_path[i];

		if (i == 0) {
			n_path_length = 0;

			s_path[n_file_name_length] = L'\0';

			if (NULL != s_file_name) {
				wstring_copy(s_path, s_file_name, &n_path_length);
			}

			break;
		}

		if (chr == L'\\' || chr == L'/') {
			if (NULL == s_file_name) 
				wstring_reduce_right(s_path, (n_path_length - (i + 1)), &n_path_length);
			else {
				if (n_file_name_length == 0) {
					n_file_name_length = wstring_length(s_file_name);
				}

				wmemcpy(&(s_path[i + 1]), s_file_name, n_file_name_length);

				n_path_length = (i + 1 + n_file_name_length);

				s_path[n_path_length] = L'\0';
			}

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
string_t path_setparent(__in string_t s_path, __inout_opt uint_t* _n_path_length, __in_opt string_t const s_directory_path, __in_opt uint_t n_directory_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);
	assert(n_directory_path_length == 0 || NULL != s_directory_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	for (int_t i = n_path_length; i >= 0; i--) {
		char_t chr;

		chr = s_path[i];

		if (i == 0) {
			if (NULL != s_directory_path) {
				if (!path_isdirectory(s_directory_path, n_directory_path_length)) {
					string_push(s_path, &n_path_length, "\\", 1);
				}

				string_push(s_path, &n_path_length, s_directory_path, n_directory_path_length);
			}

			break;
		}

		if (chr == '\\' || chr == '/') {
			string_reduce_left(s_path, (i + 1), &n_path_length);

			if (NULL != s_directory_path) {
				if (!path_isdirectory(s_directory_path, n_directory_path_length)) {
					string_push(s_path, &n_path_length, "\\", 1);
				}

				string_push(s_path, &n_path_length, s_directory_path, n_directory_path_length);
			}

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
wstring_t path_setparent_w(__in wstring_t s_path, __inout_opt uint_t* _n_path_length, __in_opt wstring_t const s_directory_path, __in_opt uint_t n_directory_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);
	assert(n_directory_path_length == 0 || NULL != s_directory_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	for (int_t i = n_path_length; i >= 0; i--) {
		wchar_t chr;

		chr = s_path[i];

		if (i == 0) {
			if (NULL != s_directory_path) {
				if (!path_isdirectory_w(s_directory_path, n_directory_path_length)) {
					wstring_push(s_path, &n_path_length, L"\\", 1);
				}

				wstring_push(s_path, &n_path_length, s_directory_path, n_directory_path_length);
			}

			break;
		}

		if (chr == L'\\' || chr == L'/') {
			wstring_reduce_left(s_path, (i + 1), &n_path_length);

			if (NULL != s_directory_path) {
				if (!path_isdirectory_w(s_directory_path, n_directory_path_length)) {
					wstring_push(s_path, &n_path_length, L"\\", 1);
				}

				wstring_push(s_path, &n_path_length, s_directory_path, n_directory_path_length);
			}

			break;
		}
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
string_t path_todirectory(__inout string_t s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	if (!string_isempty(s_path) && !path_isdirectory(s_path, n_path_length)) {
		string_append(s_path, &n_path_length, "\\");
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
wstring_t path_todirectory_w(__inout wstring_t s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	if (!wstring_isempty(s_path) && !path_isdirectory_w(s_path, n_path_length)) {
		wstring_append(s_path, &n_path_length, L"\\");
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
string_t path_tofile(__inout string_t s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	if (n_path_length > 0 && (s_path[n_path_length - 1] == '\\' || s_path[n_path_length - 1] == '/')) {
		do {
			n_path_length--;
		} while (s_path[n_path_length - 1] == '\\' || s_path[n_path_length - 1] == '/');

		s_path[n_path_length] = '\0';
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
wstring_t path_tofile_w(__inout wstring_t s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length)
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	if (n_path_length > 0 && (s_path[n_path_length - 1] == L'\\' || s_path[n_path_length - 1] == L'/')) {
		do {
			n_path_length--;
		} while (s_path[n_path_length - 1] == L'\\' || s_path[n_path_length - 1] == L'/');

		s_path[n_path_length] = L'\0';
	}


#pragma region <returns>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
string_t path_toparent(__inout string_t s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length) 
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = string_length(s_path);
	}

	for (uint_t i = n_path_length; i > 0; i--) {
		char_t chr;

		chr = s_path[i];

		if ((chr == '\\' || chr == '/') && (i != (n_path_length - 1))) {
			n_path_length = (i + 1);
			s_path[n_path_length] = '\0';

			break;
		}
	}


#pragma region <locals>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}


FWEXPORT
wstring_t path_toparent_w(__inout wstring_t s_path, __inout_opt uint_t* _n_path_length) {
#pragma region <locals>
	uint_t n_path_length;
#pragma endregion


	assert(NULL != s_path);


	if (NULL != _n_path_length) 
		n_path_length = *_n_path_length;
	else {
		n_path_length = 0;
	}

	if (n_path_length == 0) {
		n_path_length = wstring_length(s_path);
	}

	for (uint_t i = n_path_length; i > 0; i--) {
		wchar_t chr;

		chr = s_path[i];

		if ((chr == L'\\' || chr == L'/') && (i != (n_path_length - 1))) {
			n_path_length = (i + 1);
			s_path[n_path_length] = L'\0';

			break;
		}
	}


#pragma region <locals>
	if (NULL != _n_path_length) {
		*_n_path_length = n_path_length;
	}
#pragma endregion


	return s_path;
}

