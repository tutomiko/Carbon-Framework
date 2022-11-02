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
#include <fireworks/sys/time.h>
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
typedef void* event_t;


FWIMPORT __success(return)
bool event_close(
	__in event_t const h_event
);


FWIMPORT __success(return)
bool event_create(
	__out event_t*     _h_event,
	__in  bool_t const b_manual_reset,
	__in  bool_t const b_initial_set
);


FWIMPORT __success(return)
bool event_reset(
	__in event_t const h_event
);


FWIMPORT __success(return)
bool event_set(
	__in event_t const h_event
);


FWIMPORT __success(return) bool_t event_wait(
	__in event_t const h_event, 
	__in ulong_t const timeout_millis
);


