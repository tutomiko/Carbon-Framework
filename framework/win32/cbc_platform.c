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
#include <carbon/sys/platform.h>
#pragma endregion
#
#pragma region "platform-dependent imports"
#include <Windows.h>
#include <sysinfoapi.h>
#include <VersionHelpers.h>
#pragma endregion
#
#pragma region "platform-independent imports"

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
FWEXPORT __success(return) 
bool_t platform_get_x64(__out bool_t* _b_is_64bit) {
#pragma region <locals>
	bool    b_is_64bit;
	HMODULE hModule = NULL;
#pragma endregion


#ifdef _WIN64
	b_is_64bit = true;
#else
	hModule = GetModuleHandleW(L"ntdll.dll");

	if (NULL == hModule) {
		hModule = LoadLibraryW(L"ntdll.dll");

		if (NULL == hModule) {
			switch (GetLastError()) {
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		}
	}

	if (NULL == GetProcAddress(hModule, "IsWow64Process"))
		b_is_64bit = false;
	else if (!IsWow64Process(GetCurrentProcess(), &b_is_64bit)) {// Should never fail for CP: maybe someone injected / modified it?
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}
#endif // _WIN64


$success:
#pragma region <returns>
	*_b_is_64bit = b_is_64bit;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t platform_get_architecture(__out int_t* _processor_architecture) {
#pragma region <locals>
	int_t       processor_architecture;
	SYSTEM_INFO SystemInfo;
#pragma endregion


	RtlSecureZeroMemory(&SystemInfo, sizeof SystemInfo);
	GetSystemInfo(&SystemInfo);

	switch (SystemInfo.wProcessorArchitecture) {
	case PROCESSOR_ARCHITECTURE_AMD64:
		processor_architecture = AMD64;
	case PROCESSOR_ARCHITECTURE_ARM:
		processor_architecture = ARM;
	case PROCESSOR_ARCHITECTURE_ARM64:
		processor_architecture = ARM64;
	case PROCESSOR_ARCHITECTURE_IA64:
		processor_architecture = IA64;
	case PROCESSOR_ARCHITECTURE_INTEL:
		processor_architecture = INTEL;
	case PROCESSOR_ARCHITECTURE_UNKNOWN: default:
		processor_architecture = -1;
	}


$success:
#pragma region <returns>
	*_processor_architecture = processor_architecture;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t platform_get_family(__out int_t* _platform_family) {
#pragma region <locals>
	int_t platform_family;
#pragma endregion


	platform_family = MS_WINDOWS;


$success:
#pragma region <returns>
	*_platform_family = platform_family;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t platform_get_model(__out int_t* _platform_model, __out_opt int_t* _platform_model2) {
#pragma region <locals>
	typedef NTSTATUS(WINAPI* RtlGetVersion)(LPOSVERSIONINFOEX);
	typedef NTSTATUS(WINAPI* GetVersionExW)(LPOSVERSIONINFOEX);

	HMODULE          hModule = NULL;
	FARPROC          lpFunction = NULL;
	OSVERSIONINFOEXW OSInfo;
	int_t            platform_model,
		             platform_model2;
#pragma endregion


	hModule = GetModuleHandleW(L"ntdll");

	if (NULL == hModule) {
		hModule = LoadLibraryW(L"ntdll.dll");

		if (NULL == hModule) {
			switch (GetLastError()) {
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		}
	}

	RtlSecureZeroMemory(&OSInfo, sizeof OSInfo);
	OSInfo.dwOSVersionInfoSize = sizeof(OSInfo);

	lpFunction = GetProcAddress(hModule, "RtlGetVersion");

	if (NULL == lpFunction) {
		lpFunction = GetProcAddress(hModule, "GetVersionExW");

		if (NULL == lpFunction) {
			switch (GetLastError()) {
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		} else {
			((GetVersionExW)lpFunction)(&OSInfo);
		}
	} else {
		((RtlGetVersion)lpFunction)(&OSInfo);
	}

	if (OSInfo.dwMajorVersion == 10) {
		// Windows 10 # 10.0
		platform_model = WINDOWS_10;
	} else if (OSInfo.dwMajorVersion == 6) {
		if (OSInfo.dwMinorVersion == 3) {
			// Windows 8.1 # 6.3
			platform_model = WINDOWS_8_1;
		} else if (OSInfo.dwMinorVersion == 2) {
			// Windows 8 # 6.2
			platform_model = WINDOWS_8;
		} else if (OSInfo.dwMinorVersion == 1) {
			// Windows 7 # 6.1
			platform_model = WINDOWS_7;
		} else {
			// Windows Vista # 6.0
			platform_model = WINDOWS_VISTA;
		}
	} else if (OSInfo.dwMajorVersion == 5 && OSInfo.dwMinorVersion == 1) {
		// Windows XP # 5.1
		platform_model = WINDOWS_XP;
	} else {
		// Windows 2000 # 5.0 ...
		// But we don't really care about any Windows Nt OS prior to Windows XP
		// due to their limited capabilities and lack of widespread.
		platform_model = WINDOWS_NT;
	}


	if (NULL != _platform_model2) {
		if (IsWindows10OrGreater())
			platform_model2 = WINDOWS_10;
		else if (IsWindows8Point1OrGreater())
			platform_model2 = WINDOWS_8_1;
		else if (IsWindows8OrGreater())
			platform_model2 = WINDOWS_8;
		else if (IsWindows7OrGreater())
			platform_model2 = WINDOWS_7;
		else if (IsWindowsVistaOrGreater())
			platform_model2 = WINDOWS_VISTA;
		else if (IsWindowsXPOrGreater())
			platform_model2 = WINDOWS_XP;
		else {
			platform_model2 = WINDOWS_NT;
		}
	}


$success:
#pragma region <returns>
	*_platform_model = platform_model;

	if (NULL != _platform_model2) {
		*_platform_model2 = platform_model2;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}

