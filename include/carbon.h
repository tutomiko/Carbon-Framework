/*
 * FileName: carbon.h
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
#include "carbon/cbcbase.h"

#if !defined(_CARBON_DYNAMIC_LINKAGE) && !defined(_CARBON_STATIC_LINKAGE)
#error No build option defined: define _CARBON_DYNAMIC_LINKAGE for dynamic linkage or _CARBON_STATIC_LINKAGE for static linkage.
#else
// type headers
#include "carbon/type/primitives.h"

// util headers
#include "carbon/util/printfx.h"
#include "carbon/util/prandom.h"
#include "carbon/util/memory.h"
#include "carbon/util/strings.h"

// concurrency headers
#include "carbon/concurrency/concurrency.h"

// io headers
#include "carbon/io/io.h"

// filesystem headers
#include "carbon/filesystem/filesystem.h"

// sys headers
#include "carbon/sys/platform.h"
#include "carbon/sys/console.h"

// net headers
#include "carbon/net/entity.h"
#include "carbon/net/inet.h"
#include "carbon/net/sockets.h"
#endif
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#


