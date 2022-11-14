/*
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
#pragma region <imports>
#pragma region "export header imports"
#include <carbon/net/entity.h>
#pragma endregion
#
#pragma region "platform-dependent imports"
#include <Windows.h>
#include <WtsApi32.h>
#pragma comment(lib, "WtsApi32.lib")
#include <Psapi.h>
#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")
#pragma endregion
#
#pragma region "platform-independent imports"
#include <assert.h>
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
__success(return) bool_t getmac(__out struct _mac_address* o_mac_address) {
#pragma region <locals>
#if defined(_WIN32)
	PIP_ADAPTER_INFO AdapterInfoEntry = NULL;
	ULONG            SizePointer;
	ULONG            ulResult;
#endif
#pragma endregion


	assert(NULL != o_mac_address);


	AdapterInfoEntry = (PIP_ADAPTER_INFO)malloc(sizeof(IP_ADAPTER_INFO));

	if (NULL == AdapterInfoEntry) {
		fw_error = FW_ERROR_NOT_ENOUGH_MEMORY;

		goto $failure;
	}

	SizePointer = sizeof(IP_ADAPTER_INFO);
$GetAdaptersInfo:
	ulResult = GetAdaptersInfo(AdapterInfoEntry, &SizePointer);

	if (ERROR_SUCCESS != ulResult) {
		free(AdapterInfoEntry);

		AdapterInfoEntry = NULL;

		switch (ulResult) {
		case ERROR_BUFFER_OVERFLOW:
			AdapterInfoEntry = (PIP_ADAPTER_INFO)(malloc(SizePointer));

			if (NULL == AdapterInfoEntry) {
				fw_error = FW_ERROR_BUFFER_OVERFLOW;

				goto $failure;
			}

			goto $GetAdaptersInfo;
		case ERROR_INVALID_DATA:
			fw_error = FW_ERROR_INVALID;

			goto $failure;
		case ERROR_INVALID_PARAMETER:
			fw_error = FW_ERROR_INVALID;

			goto $failure;
		case ERROR_NOT_SUPPORTED:
			fw_error = FW_ERROR_UNSUPPORTED;

			goto $failure;
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	memzero(o_mac_address, sizeof(MacAddress));

	for (PIP_ADAPTER_INFO AdapterInfo = AdapterInfoEntry; NULL != AdapterInfo; AdapterInfo = AdapterInfo->Next) {
		if (strcmp(AdapterInfo->IpAddressList.IpAddress.String, "0.0.0.0") != 0) {
			memcpy(o_mac_address, AdapterInfo->Address, sizeof(MacAddress));

			break;
		}
	}

	free(AdapterInfoEntry);
	AdapterInfoEntry = NULL;


$success:
#pragma region <returns>

#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (NULL != AdapterInfoEntry) {
		free(AdapterInfoEntry);
	}
#pragma endregion


	return false;
}

