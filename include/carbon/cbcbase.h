/*
 * FileName: cbcbase.h
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

#if defined(_CARBON_DYNAMIC_LINKAGE)
#if defined(_WIN32)
#define CBCEXPORT		__declspec(dllexport)
#ifdef __cplusplus
#define CBCIMPORT		extern "C" __declspec(dllimport)
#else
#define CBCIMPORT		extern __declspec(dllimport)
#endif // __cplusplus
#else
#define CBCEXPORT		
#ifdef __cplusplus
#define CBCIMPORT		extern "C"
#else
#define CBCIMPORT		extern
#endif // __cplusplus
#endif
#elif defined(_CARBON_STATIC_LINKAGE)
#define CBCEXPORT		
#ifdef __cplusplus
#define CBCIMPORT		extern "C"
#else
#define CBCIMPORT		extern
#endif // __cplusplus
#else
#error No build option defined: define _CARBON_DYNAMIC_LINKAGE for dynamic linkage or _CARBON_STATIC_LINKAGE for static linkage.
#endif
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


#pragma region <error constant definitions>
#pragma region <io error constants>
// range: 128 - 255
#define FW_ERROR_BUFFER_OVERFLOW		255
#define FW_ERROR_INVALID_PATH			128
#define FW_ERROR_PREVENTED				200
#define FW_ERROR_TIMEOUT				166
#define FW_ERROR_UNKNOWN_DATA			222
#pragma endregion


#pragma region <memory error constants>
// range: 32 - 127
#define FW_ERROR_NOT_ENOUGH_MEMORY		 65
#define FW_ERROR_OUT_OF_MEMORY			 64
#pragma endregion


#pragma region <networking error constants>
// range: 255 - 511
#define FW_ERROR_CONNECTION_RESET		200
#define FW_ERROR_HOST_UNREACHABLE		201
#define FW_ERROR_INVALID_ADDRESS_TYPE	266
#define FW_ERROR_NETWORK_UNREACHABLE	202
#define FW_ERROR_NOT_CONNECTED			203
#define FW_ERROR_PROTOCOL				300
#define FW_ERROR_REFUSED				203
#pragma endregion


#pragma region <type error constants>
// range: 512-1023
/// Improperly terminated string
#define FW_ERROR_INVALID_STRING			555
#pragma endregion


#pragma region <contextual error constants>
// range: 0-31
#define FW_ERROR_AGAIN					  2
#define FW_ERROR_ALREADY_EXISTS			 28
#define FW_ERROR_INITIALIZE				 10
#define FW_ERROR_INVALID				  3
#define FW_ERROR_RESERVED				 31
#define FW_ERROR_SUCCESS				  0
#define FW_ERROR_UNKNOWN				  1
#define FW_ERROR_UNREACHABLE			 27
#define FW_ERROR_UNSUPPORTED			 12
#pragma endregion
#pragma endregion


#ifdef CBCIMPORT
/// <summary>
/// Error code type for Carbon Framework.
/// </summary>
typedef int fw_error_t;


CBCIMPORT
void FWClearLastError(void);


CBCIMPORT
fw_error_t FWGetLastError(void);


CBCIMPORT
fw_error_t* FWGetLastErrorStorage(void);


CBCIMPORT
void FWProtCallBegin(void);


CBCIMPORT
void FWProtCallEnd(void);


CBCIMPORT
void FWSetLastError(
	__in fw_error_t const NewErrorCode
);


#define FW_FAILED(E)			(FW_ERROR_SUCCESS != E)
#define FW_SUCCEEDED(E)			(FW_ERROR_SUCCESS == E)

#define fw_error				(*FWGetLastErrorStorage())

#define fwpcall_begin			FWProtCallBegin
#define fwpcall_end				FWProtCallEnd

#define ____fwpcall_begin		fwpcall_begin();
#define ____fwpcall_end			fwpcall_end();

/* Call an FW API function without setting the @fw_error var */
#define fwpcall(F)				(fwpcall_begin(), F, fwpcall_end())		// {auto __ecall = fw_error; F; fw_error = __ecall;}
#endif // CBCIMPORT


