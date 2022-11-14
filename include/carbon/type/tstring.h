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
#include <carbon/type/string.h>
#include <carbon/type/wstring.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#if __CHARSET == CHARSET_UNICODE
#define tstring_t					wstring_t
#define tstring_append				wstring_append
#define tstring_charat				wstring_charat		
#define tstring_compare				wstring_compare
#define tstring_compare_ic			wstring_compare_ic
#define tstring_comparex			wstring_comparex	
#define tstring_comparex_ic			wstring_comparex_ic	
#define tstring_concat				wstring_concat
#define tstring_contains			wstring_contains	
#define tstring_contains_ic			wstring_contains_ic	
#define tstring_copy				wstring_copy
#define tstring_copyx				wstring_copyx
#define tstring_endswith			wstring_endswith
#define tstring_equals				wstring_equals
#define tstring_equals_ic			wstring_equals_ic
#define tstring_find				wstring_find		
#define tstring_find_ic				wstring_find_ic		
#define tstring_isempty				wstring_isempty
#define tstring_length				wstring_length
#define tstring_lower				wstring_lower
#define tstring_push				wstring_push
#define tstring_reduce_left			wstring_reduce_left
#define tstring_reduce_right		wstring_reduce_right
#define tstring_reverse				wstring_reverse
//#define tstring_split				wstring_split
#define tstring_startswith			wstring_startswith
#define tstring_substring			wstring_substring	
#define tstring_upper				wstring_upper
#define tstring_zero				wstring_zero		
#else
#define tstring_t					string_t
#define tstring_append				string_append
#define tstring_charat				string_charat		
#define tstring_compare				string_compare
#define tstring_compare_ic			string_compare_ic
#define tstring_comparex			string_comparex	
#define tstring_comparex_ic			string_comparex_ic	
#define tstring_concat				string_concat
#define tstring_contains			string_contains	
#define tstring_contains_ic			string_contains_ic	
#define tstring_copy				string_copy
#define tstring_copy_lower			string_copy_lower	
#define tstring_copy_reverse		string_copy_reverse	
#define tstring_copy_upper			string_copy_upper	
#define tstring_copyx				string_copyx
#define tstring_endswith			string_endswith
#define tstring_equals				string_equals
#define tstring_equals_ic			string_equals_ic
#define tstring_find				string_find		
#define tstring_find_ic				string_find_ic		
#define tstring_isempty				string_isempty
#define tstring_length				string_length
#define tstring_lower				string_lower
#define tstring_lshift				string_lshift
#define tstring_push				string_push
#define tstring_reduce_left			string_reduce_left
#define tstring_reduce_right		string_reduce_right
#define tstring_reverse				string_reverse
//#define tstring_split				string_split
#define tstring_startswith			string_startswith
#define tstring_substring			string_substring	
#define tstring_upper				string_upper
#define tstring_zero				string_zero		
#endif // __CHARSET


