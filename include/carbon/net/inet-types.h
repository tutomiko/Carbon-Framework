/*
 * FileName: inet-types.h
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
#include <carbon/type/string.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <string max definitions>
#define _MAX_INET					22
#define _MAX_INET6					65
#define _MAX_MAC					-1
#define _MAX_MAC64					-1
#define _MAX_PORT					5 // Without null-terminator
#define _MAX_URL					260
#pragma endregion


#pragma region <portnum constraint constant definitions>
#define PORT_MAX					65535
#define PORT_MIN					1
#pragma endregion


typedef ushort_t port_t;


enum address_type {
	ADDRESS_TYPE_INET = 1,
	ADDRESS_TYPE_INET6 = 2,
	ADDRESS_TYPE_URL = 3,
} typedef AddressType;


struct _inet_address {
	union {
		struct {
			byte_t s_b1;
			byte_t s_b2;
			byte_t s_b3;
			byte_t s_b4;
		} S_un_b;

		struct {
			ushort_t s_w1;
			ushort_t s_w2;
		} S_un_w;

		uint_t S_addr;
	} S_un;
} typedef InetAddress;


struct _inet6_address {
	union {
		byte_t Byte[16];
		ushort_t Word[8];
	} u;
} typedef Inet6Address;


typedef char_t urlstring[_MAX_URL + 1];

struct _url {
	byte_t length;
	char_t name[_MAX_URL];
} typedef Url;


struct _inet_address_storage {
	byte_t type;

	union {
		struct _inet_address  inet;
		struct _inet6_address inet6;
		struct _url           url;
	};
} typedef InetAddressStorage;


struct _inet_endpoint {
	struct _inet_address_storage address;

	port_t port;
} typedef InetEndpoint;


struct _mac_address {
	byte_t b1;
	byte_t b2;
	byte_t b3;
	byte_t b4;
	byte_t b5;
	byte_t b6;
	byte_t b7;
	byte_t b8;
} typedef MacAddress;


