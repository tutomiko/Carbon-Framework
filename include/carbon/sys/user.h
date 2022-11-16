/*
 * FileName: security.h
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
#include <carbon/cbcbase.h>
#include <carbon/sys/platform.h>
#include <carbon/concurrency/concurrency.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
CBCIMPORT __success(return) 
bool_t _CARBON_DEPRECATED_API
getcprocprivs(
	__out int_t* _access_level
);


CBCIMPORT __success(return) 
bool_t _CARBON_DEPRECATED_API
getprocprivs(
	__in_opt ulong_t const process_id, 
	__out    int_t*        _access_level
);


CBCIMPORT __success(return) 
bool_t _CARBON_DEPRECATED_API
isroot(
	__out bool_t* _b_is_root
);


