/*
 * FileName: fwdef.h
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
#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif // __cplusplus
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
#pragma region <core annotation definitions>
#ifndef _CARBON_ENABLE_DEPRECATED_FEATURES
#define _CARBON_DEPRECATED_API __declspec(deprecated("function is deprecated and will be REMOVED: You can define _CARBON_ENABLE_DEPRECATED_FEATURES to acknowledge that you understand this and still want to enable its usage."))
#else
#define _CARBON_DEPRECATED_API
#endif // _CARBON_ENABLE_DEPRECATED_FEATURES

#ifndef _CARBON_ENABLE_EXPERIMENTAL_FEATURES
#define _CARBON_EXPERIMENTAL_API __declspec(deprecated("function is still in development and experimental: You can define _CARBON_ENABLE_EXPERIMENTAL_FEATURES to acknowledge that you understand this and still want to enable its usage."))
#else
#define _CARBON_EXPERIMENTAL_API
#endif // !_CARBON_ENABLE_EXPERIMENTAL_FEATURES

#define FWEXPORT		

#ifdef __cplusplus
#define FWIMPORT		extern "C"
#else
#define FWIMPORT		extern
#endif // __cplusplus

#define FWUNTESTED
#pragma endregion


#pragma region <parameter annotation definitions>
/// input
#define __IN			__in
/// input (optional)
#define __IN_OPT		__in_opt

/// input output
#define __INOUT			__inout
/// input output (optional)
#define __INOUT_OPT		__inout_opt

/// output
#define __OUT			__out
/// output (optional)
#define __OUT_OPT		__out_opt
#pragma endregion


