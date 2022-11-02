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
#include <fireworks/util/strings.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
/// <summary>
/// 
/// </summary>
typedef char_t path_t[_MAX_PATH + 1];


/// <summary>
/// 
/// </summary>
typedef wchar_t wpath_t[_MAX_PATH + 1];


FWIMPORT
string_t path_addextension(
	__inout     string_t       s_path, 
	__inout_opt uint_t*        _n_path_length, 
	__in        string_t const s_extension, 
	__in_opt    uint_t         n_extension_length, 
	__out_opt   int_t*         _n_delimiter
);


FWIMPORT
wstring_t path_addextension_w(
	__inout     wstring_t       s_path, 
	__inout_opt uint_t*         _n_path_length, 
	__in        wstring_t const s_extension, 
	__in_opt    uint_t          n_extension_length, 
	__out_opt   int_t*          _n_delimiter
);


/// <summary>
/// Appends a path string to another.
/// </summary>
/// <param name="s_dst_path">
/// path string to append to
/// </param>
/// <param name="_n_dst_path_length">
/// [optional]
/// pointer to length of *s_dst_path that will also receive its new length.
/// 
/// NOTE:
/// new length of *s_dst_path is returned even if *_n_dst_path_length points to zero
/// </param>
/// <param name="s_src_path">
/// path string to append to *s_dst_path
/// </param>
/// <returns>
/// *s_dst_path
/// </returns>
FWIMPORT
string_t path_append(
	__inout     string_t       s_dst_path,
	__inout_opt uint_t*        _n_dst_path_length,
	__in        string_t const s_src_path
);


/// <summary>
/// Appends a wide path string to another.
/// </summary>
/// <param name="s_dst_path">
/// wide path string to append to
/// </param>
/// <param name="_n_dst_path_length">
/// [optional]
/// pointer to length of *s_dst_path that will also receive its new length.
/// 
/// NOTE:
/// new length of *s_dst_path is returned even if *_n_dst_path_length points to zero
/// </param>
/// <param name="s_src_path">
/// wide path string to append to *s_dst_path
/// </param>
/// <returns>
/// *s_dst_path
/// </returns>
FWIMPORT
wstring_t path_append_w(
	__inout     wstring_t       s_dst_path, 
	__inout_opt uint_t*         _n_dst_path_length,
	__in        wstring_t const s_src_path
);


FWIMPORT 
string_t path_build(
	__inout   string_t       s_dst_path, 
	__out_opt uint_t*        _n_dst_path_length, 
	__in_opt  string_t const s_directory_path, 
	__in_opt  string_t const s_file_prefix, 
	__in_opt  string_t const s_file_name, 
	__in_opt  string_t const s_file_extension
);


FWIMPORT 
wstring_t path_build_w(
	__inout   wstring_t       s_dst_path, 
	__out_opt uint_t*         _n_dst_path_length, 
	__in_opt  wstring_t const s_directory_path, 
	__in_opt  wstring_t const s_file_prefix, 
	__in_opt  wstring_t const s_file_name, 
	__in_opt  wstring_t const s_file_extension
);


FWIMPORT
string_t path_build_random(
	__inout   string_t       s_dst_path, 
	__out_opt uint_t*        _n_dst_path_length, 
	__in_opt  string_t const s_directory_path, 
	__in_opt  string_t const s_file_prefix, 
	__in      uint_t const   n_file_name_length, 
	__in_opt  string_t const s_file_extension
);


FWIMPORT
wstring_t path_build_random_w(
	__inout   wstring_t       s_dst_path, 
	__out_opt uint_t*         _n_dst_path_length, 
	__in_opt  wstring_t const s_directory_path, 
	__in_opt  wstring_t const s_file_prefix, 
	__in      uint_t const    n_file_name_length, 
	__in_opt  wstring_t const s_file_extension
);


FWIMPORT
bool_t path_equals(
	__in string_t const s_path1,
	__in string_t const s_path2
);


FWIMPORT
bool_t path_equals_w(
	__in wstring_t const s_path1,
	__in wstring_t const s_path2
);


FWIMPORT
string_t path_getdrive(
	__in      string_t const s_path, 
	__inout   string_t       s_drive, 
	__out_opt uint_t*        _n_drive_length
);


FWIMPORT
wstring_t path_getdrive_w(
	__in      wstring_t const s_path, 
	__inout   wstring_t       s_drive, 
	__out_opt uint_t*         _n_drive_length
);


FWIMPORT
char_t path_getdriveletter(
	__in string_t const s_path
);


FWIMPORT
wchar_t path_getdriveletter_w(
	__in wstring_t const s_path
);


FWIMPORT
string_t path_getextension(
	__in      string_t const s_path, 
	__in_opt  uint_t         n_path_length, 
	__in      uint_t const   n_index, 
	__inout   string_t       s_extension, 
	__out_opt uint_t*        _n_extension_length
);


FWIMPORT
wstring_t path_getextension_w(
	__in      wstring_t const s_path, 
	__in_opt  uint_t          n_path_length, 
	__in      uint_t const    n_index, 
	__inout   wstring_t       s_extension, 
	__out_opt uint_t*         _n_extension_length
);


FWIMPORT
string_t path_getextensionptr(
	__in      string_t const s_path, 
	__in_opt  uint_t         n_path_length, 
	__in      uint_t const   n_index, 
	__out_opt uint_t*        _n_extension_length
);


FWIMPORT
wstring_t path_getextensionptr_w(
	__in      wstring_t const s_path, 
	__in_opt  uint_t          n_path_length, 
	__in      uint_t const    n_index, 
	__out_opt uint_t*         _n_extension_length
);


FWIMPORT 
string_t path_getfname(
	__in      string_t const s_path, 
	__inout   string_t       s_filename,
	__out_opt uint_t*        _n_filename_length
);


FWIMPORT 
wstring_t path_getfname_w(
	__in      wstring_t const s_path, 
	__inout   wstring_t       s_filename,
	__out_opt uint_t*         _n_filename_length
);


FWIMPORT 
string_t path_getfnameptr(
	__in      string_t const s_path, 
	__out_opt uint_t*        _n_filename_length
);


FWIMPORT 
wstring_t path_getfnameptr_w(
	__in      wstring_t const s_path, 
	__out_opt uint_t*         _n_filename_length
);


FWIMPORT
string_t path_getparent(
	__in      string_t s_path, 
	__in_opt  uint_t   n_path_length, 
	__inout   string_t s_directory_path, 
	__out_opt uint_t*  _n_directory_path_length
);


FWIMPORT
wstring_t path_getparent_w(
	__in      wstring_t s_path, 
	__in_opt  uint_t    n_path_length, 
	__inout   wstring_t s_directory_path, 
	__out_opt uint_t*   _n_directory_path_length
);


FWIMPORT
bool_t path_hasparent(
	__in string_t const s_path
);


FWIMPORT
bool_t path_hasparent_w(
	__in wstring_t const s_path
);


/// <summary>
/// Initializes a path string.
/// </summary>
/// <param name="s_dst">
/// path string to set
/// </param>
/// <param name="s_src">
/// path string to use
/// </param>
/// <param name="b_directory">
/// whether or not the path string is a directory
/// </param>
/// <param name="_n_length">
/// [optional]
/// pointer to receive length of *s_dst
/// </param>
/// <returns>
/// *s_dst
/// </returns>
FWIMPORT 
string_t path_init(
	__inout   string_t       s_dst, 
	__in      string_t const s_src, 
	__in      bool_t const   b_directory,
	__out_opt uint_t*        _n_length
);


/// <summary>
/// Initializes a wide path string.
/// </summary>
/// <param name="s_dst">
/// wide path string to set
/// </param>
/// <param name="s_src">
/// wide path string to use
/// </param>
/// <param name="b_directory">
/// whether or not the wide path string is a directory
/// </param>
/// <param name="_n_length">
/// [optional]
/// pointer to receive length of *s_dst
/// </param>
/// <returns>
/// *s_dst
/// </returns>
FWIMPORT 
wstring_t path_init_w(
	__inout   wstring_t       s_dst, 
	__in      wstring_t const s_src, 
	__in      bool_t const    b_directory,
	__out_opt uint_t*         _n_length
);


FWIMPORT
bool_t path_isabsolute(
	__in string_t const s_path
);


FWIMPORT
bool_t path_isabsolute_w(
	__in wstring_t const s_path
);


FWIMPORT
bool_t path_isancestorof(
	__in string_t const s_path1,
	__in string_t const s_path2
);


FWIMPORT
bool_t path_isancestorof_w(
	__in wstring_t const s_path1,
	__in wstring_t const s_path2
);


FWIMPORT
bool_t path_isdescendantof(
	__in string_t const s_path1,
	__in string_t const s_path2
);


FWIMPORT
bool_t path_isdescendantof_w(
	__in wstring_t const s_path1,
	__in wstring_t const s_path2
);


FWIMPORT
bool_t path_isdirectory(
	__in     string_t const s_path, 
	__in_opt uint_t         n_path_length
);


FWIMPORT 
bool_t path_isdirectory_w(
	__in     wstring_t const s_path, 
	__in_opt uint_t          n_path_length
);


FWIMPORT 
bool_t path_isfile(
	__in        string_t const s_path, 
	__inout_opt uint_t*        _n_path_length
);


FWIMPORT 
bool_t path_isfile_w(
	__in        wstring_t const s_path, 
	__inout_opt uint_t*         _n_path_length
);


FWIMPORT
bool_t path_isparentof(
	__in string_t const s_path1,
	__in string_t const s_path2
);


FWIMPORT
bool_t path_isparentof_w(
	__in wstring_t const s_path1,
	__in wstring_t const s_path2
);


FWIMPORT
bool_t path_isrelative(
	__in string_t const s_path
);


FWIMPORT
bool_t path_isrelative_w(
	__in wstring_t const s_path
);


FWIMPORT 
bool_t path_iterate(
	__in      string_t const s_path, 
	__inout   string_t       s_file_path, 
	__out_opt uint_t*        _n_file_path_length, 
	__inout   uint_t*        _n_cursor,
	__out_opt bool_t*        _b_more
);


FWIMPORT 
bool_t path_iterate_w(
	__in      wstring_t const s_path, 
	__inout   wstring_t       s_file_path, 
	__out_opt uint_t*         _n_file_path_length, 
	__inout   uint_t*         _n_cursor,
	__out_opt bool_t*         _b_more
);


FWIMPORT 
bool_t path_iterate_names(
	__in      string_t const s_path, 
	__inout   string_t       s_file_name, 
	__out_opt uint_t*        _n_file_name_length, 
	__inout   uint_t*        _n_cursor,
	__out_opt bool_t*        _b_more
);


FWIMPORT 
bool_t path_iterate_names_w(
	__in      wstring_t const s_path, 
	__inout   wstring_t       s_file_name, 
	__out_opt uint_t*         _n_file_name_length, 
	__inout   uint_t*         _n_cursor,
	__out_opt bool_t*         _b_more
);


/// <summary>
/// Normalizes a path string.
/// </summary>
/// <param name="s_path">
/// path string to normalize
/// </param>
/// <param name="_n_path_length">
/// [optional]
/// pointer to receive new length of *s_path
/// </param>
/// <returns>
/// *s_path
/// </returns>
FWIMPORT
string_t path_normalize(
	__inout   string_t s_path, 
	__out_opt uint_t*  _n_path_length
);


/// <summary>
/// Normalizes a wide path string.
/// </summary>
/// <param name="s_path">
/// wide path string to normalize
/// </param>
/// <param name="_n_path_length">
/// [optional]
/// pointer to receive new length of *s_path
/// </param>
/// <returns>
/// *s_path
/// </returns>
FWIMPORT
wstring_t path_normalize_w(
	__inout   wstring_t s_path, 
	__out_opt uint_t*   _n_path_length
);


FWIMPORT
string_t path_resolve(
	__in      string_t const s_path, 
	__in_opt  uint_t         n_path_length, 
	__in      string_t const s_context_path, 
	__in_opt  uint_t         n_context_path_length, 
	__inout   string_t       s_absolute_path, 
	__out_opt uint_t*        _n_absolute_path_length
);


FWIMPORT
wstring_t path_resolve_w(
	__in      wstring_t const s_path, 
	__in_opt  uint_t          n_path_length, 
	__in      wstring_t const s_context_path, 
	__in_opt  uint_t          n_context_path_length, 
	__inout   wstring_t       s_absolute_path, 
	__out_opt uint_t*         _n_absolute_path_length
);


FWIMPORT
string_t path_rmvdrive(
	__inout     string_t s_path, 
	__inout_opt uint_t*  _n_path_length
);


FWIMPORT
wstring_t path_rmvdrive_w(
	__inout     wstring_t s_path, 
	__inout_opt uint_t*   _n_path_length
);


FWIMPORT
string_t path_rmvextension(
	__inout     string_t     s_path, 
	__inout_opt uint_t*      _n_path_length, 
	__in        uint_t const n_index
);


FWIMPORT
wstring_t path_rmvextension_w(
	__inout     wstring_t    s_path, 
	__inout_opt uint_t*      _n_path_length, 
	__in        uint_t const n_index
);


FWIMPORT
string_t path_setdrive(
	__inout     string_t       s_path, 
	__inout_opt uint_t*        _n_path_length, 
	__in_opt    string_t const s_drive
);


FWIMPORT
wstring_t path_setdrive_w(
	__inout     wstring_t       s_path, 
	__inout_opt uint_t*         _n_path_length, 
	__in_opt    wstring_t const s_drive
);


FWIMPORT
string_t path_setextension(
	__inout     string_t       s_path, 
	__inout_opt uint_t*        _n_path_length, 
	__in        int_t const    n_index, 
	__in_opt    string_t const s_extension, 
	__in_opt    uint_t         n_extension_length, 
	__out_opt   int_t*         _n_delimiter
);


FWIMPORT
wstring_t path_setextension_w(
	__inout     wstring_t       s_path, 
	__inout_opt uint_t*         _n_path_length, 
	__in        int_t const     n_index, 
	__in_opt    wstring_t const s_extension, 
	__in_opt    uint_t          n_extension_length, 
	__out_opt   int_t*          _n_delimiter
);


FWIMPORT
string_t path_setfname(
	__inout     string_t       s_path, 
	__inout_opt uint_t*        _n_path_length, 
	__in        string_t const s_file_name, 
	__in_opt    uint_t         n_file_name_length
);


FWIMPORT
wstring_t path_setfname_w(
	__inout     wstring_t       s_path, 
	__inout_opt uint_t*         _n_path_length, 
	__in        wstring_t const s_file_name, 
	__in_opt    uint_t          n_file_name_length
);


FWIMPORT
string_t path_setparent(
	__in        string_t       s_path, 
	__inout_opt uint_t*        _n_path_length, 
	__in_opt    string_t const s_directory_path, 
	__in_opt    uint_t         n_directory_path_length
);


FWIMPORT
wstring_t path_setparent_w(
	__in        wstring_t       s_path, 
	__inout_opt uint_t*         _n_path_length, 
	__in_opt    wstring_t const s_directory_path, 
	__in_opt    uint_t          n_directory_path_length
);


/// <summary>
/// Transforms a path string to a directory name.
/// </summary>
/// <param name="s_path">
/// path string to transform
/// </param>
/// <param name="_n_path_length">
/// [optional]
/// pointer to length of *s_path that will also receive its length.
/// 
/// NOTE:
/// length of *s_path is returned even if *_n_path_length points to zero
/// </param>
/// <returns>
/// *s_path
/// </returns>
FWIMPORT
string_t path_todirectory(
	__inout     string_t s_path, 
	__inout_opt uint_t*  _n_path_length
);


/// <summary>
/// Transforms a wide path string to a directory name.
/// </summary>
/// <param name="s_path">
/// wide path string to transform
/// </param>
/// <param name="_n_path_length">
/// [optional]
/// pointer to length of *s_path that will also receive its length.
/// 
/// NOTE:
/// length of *s_path is returned even if *_n_path_length points to zero
/// </param>
/// <returns>
/// *s_path
/// </returns>
FWIMPORT 
wstring_t path_todirectory_w(
	__inout     wstring_t s_path, 
	__inout_opt uint_t*   _n_path_length
);


/// <summary>
/// Transforms a path string to a file name.
/// </summary>
/// <param name="s_path">
/// path string to transform
/// </param>
/// <param name="_n_path_length">
/// [optional]
/// pointer to length of *s_path that will also receive its length.
/// 
/// NOTE:
/// length of *s_path is returned even if *_n_path_length points to zero
/// </param>
/// <returns>
/// *s_path
/// </returns>
FWIMPORT 
string_t path_tofile(
	__inout     string_t s_path, 
	__inout_opt uint_t*  _n_path_length
);


/// <summary>
/// Transforms a wide path string to a file name.
/// </summary>
/// <param name="s_path">
/// wide path string to transform
/// </param>
/// <param name="_n_path_length">
/// [optional]
/// pointer to length of *s_path that will also receive its length.
/// 
/// NOTE:
/// length of *s_path is returned even if *_n_path_length points to zero
/// </param>
/// <returns>
/// *s_path
/// </returns>
FWIMPORT 
wstring_t path_tofile_w(
	__inout     wstring_t s_path, 
	__inout_opt uint_t*   _n_path_length
);


FWIMPORT
string_t path_toparent(
	__inout     string_t s_path, 
	__inout_opt uint_t*  _n_path_length
);


FWIMPORT
wstring_t path_toparent_w(
	__inout     wstring_t s_path, 
	__inout_opt uint_t*   _n_path_length
);


#if __CHARSET == CHARSET_UNICODE
#define tpath_t						wpath_t
#define path_addextension_t			path_addextension_w
#define path_append_t				path_append_w
#define path_build_t				path_build_w
#define path_build_random_t			path_build_random_w
#define path_equals_t				path_equals_w
#define path_getdrive_t				path_getdrive_w
#define path_getdriveletter_t		path_getdriveletter_w
#define path_getfname_t				path_getfname_w
#define path_getfnameptr_t			path_getfnameptr_w
#define path_getextension_t			path_getextension_w
#define path_getextensionptr_t		path_getextensionptr_w
#define path_getparent_t			path_getparent_w
#define path_hasparent_t			path_hasparent_w
#define path_isabsolute_t			path_isabsolute_w
#define path_isancestorof_t			path_isancestorof_w
#define path_isdescendantof_t		path_isdescendantof_w
#define path_isdirectory_t			path_isdirectory_w
#define path_isfile_t				path_isfile_w
#define path_isparentof_t			path_isparentof_w
#define path_isrelative_t			path_isrelative_w
#define path_iterate_names_t		path_iterate_names_w
#define path_iterate_t				path_iterate_w
#define path_normalize_t			path_normalize_w
#define path_resolve_t				path_resolve_w
#define path_rmvdrive_t				path_rmvdrive_w
#define path_rmvextension_t			path_rmvextension_w
#define path_setdrive_t				path_setdrive_w
#define path_setextension_t			path_setextension_w
#define path_setfname_t				path_setfname_w
#define path_setparent_t			path_setparent_w
#define path_todirectory_t			path_todirectory_w
#define path_tofile_t				path_tofile_w
#define path_toparent_t				path_toparent_w
#elif __CHARSET == CHARSET_MULTIBYTE
#define tpath_t						path_t
#define path_addextension_t			path_addextension
#define path_append_t				path_append
#define path_build_t				path_build
#define path_build_random_t			path_build_random
#define path_equals_t				path_equals
#define path_getdrive_t				path_getdrive
#define path_getdriveletter_t		path_getdriveletter
#define path_getfname_t				path_getfname
#define path_getfnameptr_t			path_getfnameptr
#define path_getextension_t			path_getextension
#define path_getextensionptr_t		path_getextensionptr
#define path_getparent_t			path_getparent
#define path_hasparent_t			path_hasparent
#define path_isabsolute_t			path_isabsolute
#define path_isancestorof_t			path_isancestorof
#define path_isdescendantof_t		path_isdescendantof
#define path_isdirectory_t			path_isdirectory
#define path_isfile_t				path_isfile
#define path_isparentof_t			path_isparentof
#define path_isrelative_t			path_isrelative
#define path_iterate_names_t		path_iterate_names
#define path_iterate_t				path_iterate
#define path_normalize_t			path_normalize
#define path_resolve_t				path_resolve
#define path_rmvdrive_t				path_rmvdrive
#define path_rmvextension_t			path_rmvextension
#define path_setdrive_t				path_setdrive
#define path_setextension_t			path_setextension
#define path_setfname_t				path_setfname
#define path_setparent_t			path_setparent
#define path_todirectory_t			path_todirectory
#define path_tofile_t				path_tofile
#define path_toparent_t				path_toparent
#endif // __CHARSET


