/*
 * FileName: error.h
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
#include <fwdef.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
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


/// <summary>
/// Error code type for Carbon Framework.
/// </summary>
typedef int fw_error_t;


FWIMPORT 
void FWClearLastError(void);


FWIMPORT  
fw_error_t FWGetLastError(void);


FWIMPORT  
fw_error_t* FWGetLastErrorStorage(void);


FWIMPORT 
void FWProtCallBegin(void);


FWIMPORT  
void FWProtCallEnd(void);


FWIMPORT  
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

