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
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
typedef enum AccessLevel {
	ACCESS_LEVEL_KERNEL = 2,
	ACCESS_LEVEL_MOTHER = 4,
	ACCESS_LEVEL_ROOT = 1,
	ACCESS_LEVEL_USER = 0
};


typedef enum PlatformFamily {
	IOS = 0x06,
	LINUX = 0x04,
	MACINTOSH = 0x05,
	MS_WINDOWS = 0x02,
	UNIX = 0x03,
};


typedef enum PlatformModel {
	ANDROID = 0x10,
	BACKTRACK = 0x11,
	CHROME_OS = 0x13,
	DEBIAN = 0x03,
	FEDORA = 0x04,
	FREEBSD = 0x01,
	GENTOO = 0x05,
	KALI_LINUX = 0x14,
	NETBSD = 0x02,
	OSX = 0x15,
	PLAYSTATION3 = 0x12,
	PLAYSTATION4 = 0x17,
	TAILS = 0x16,
	UBUNTU = 0x06,
	XBOX_360_DB = 0x0E,
	XBOX_OS = 0x0F,
	WINDOWS_NT = 0x07,
	WINDOWS_XP = 0x08,
	WINDOWS_VISTA = 0x09,
	WINDOWS_7 = 0xA,
	WINDOWS_8 = 0xB,
	WINDOWS_8_1 = 0xC,
	WINDOWS_10 = 0xD,
};


typedef enum ProcessorArchitecture {
	AMD64 = 0x02,
	ARM = 0x03,
	ARM64 = 0x04,
	IA64 = 0x05,
	INTEL = 0x01,
};


typedef enum ProtectionRing {
	PROTECTION_RING_DRIVERS = 2,
	PROTECTION_RING_KERNEL = 0,
	PROTECTION_RING_HARDWARE = 1,
	PROTECTION_RING_MOTHERBOARD = -1,
	PROTECTION_RING_USER = 3
};


#if defined(_WIN32) 
#define __BUILD_PLATFORM		MS_WINDOWS
#else
#error unable to determine target platform
#endif


/// <summary>
/// Test whether or not current platform is 64-bit.
/// </summary>
/// <param name="_b_is_64bit">
/// pointer to receive whether or not current platform is 64-bit
/// </param>
/// <returns></returns>
FWIMPORT __success(return) 
bool_t platform_get_x64(
	__out bool_t* _b_is_64bit
);


/// <summary>
/// Get current processor architecture.
/// </summary>
/// <param name="_processor_architecture">
/// pointer to receive processor architecture
/// </param>
/// <returns></returns>
FWIMPORT __success(return) 
bool_t platform_get_architecture(
	__out int_t* _processor_architecture
);


/// <summary>
/// Get current platform family.
/// </summary>
/// <param name="_platform_family">
/// pointer to receive platform family
/// </param>
/// <returns></returns>
FWIMPORT __success(return) 
bool_t platform_get_family(
	__out int_t* _platform_family
);


/// <summary>
/// Get current platform model.
/// </summary>
/// <param name="_platform_model">
/// pointer to receive platform model
/// </param>
/// <param name="_platform_model2">
/// pointer to receive platform model 2 (only applicable on Microsoft Windows systems)
/// </param>
/// <returns></returns>
FWIMPORT __success(return) 
bool_t platform_get_model(
	__out     int_t* _platform_model,
	__out_opt int_t* _platform_model2
);


