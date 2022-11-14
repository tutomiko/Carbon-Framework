/*
 * FileName: thread.h
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
#include <fwbase.h>
#include <carbon/sys/time.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#ifdef __cplusplus
#define __THREAD_LOCAL		thread_local
#else
#if defined(_WIN32)
#define __THREAD_LOCAL		__declspec(thread)
#endif
#endif // __cplusplus

#define _thread_local		__THREAD_LOCAL


/// <summary>
/// Thread handle type.
/// </summary>
typedef void* thread_t;


FWIMPORT __success(return)
bool_t _CARBON_EXPERIMENTAL_API
thread_close(
	__in thread_t const thread
);


FWIMPORT __success(return)
bool_t _CARBON_EXPERIMENTAL_API
thread_create(
	__in      void*        f_runnable,
	__in_opt  void*        parameter,
	__in      bool_t const b_create_suspended,
	__out     thread_t*    _thread,
	__out_opt ulong_t*     _thread_id
);


FWIMPORT
void thread_current(
	__out thread_t* _thread
);


FWIMPORT
void thread_exit(
	__in unsigned long const exitcode
);


FWIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
thread_get_exit(
	__in  thread_t const h_thread,
	__out ulong_t*       _exitcode
);


FWIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
thread_get_id(
	__in_opt  thread_t const thread,
	__out     ulong_t*       _thread_id
);


FWIMPORT __success(return) 
bool_t _CARBON_EXPERIMENTAL_API
thread_join(
	__in thread_t const h_thread,
	__in ulong_t const  timeout_millis
);


FWIMPORT __success(return)
bool_t _CARBON_EXPERIMENTAL_API
thread_kill(
	__in thread_t const thread
);


FWIMPORT __success(return)
bool_t _CARBON_EXPERIMENTAL_API
thread_resume(
	__in thread_t const thread
);


FWIMPORT __success(return)
bool_t _CARBON_EXPERIMENTAL_API
thread_stop(
	__in thread_t const thread
);


