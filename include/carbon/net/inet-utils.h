/*
 * FileName: inet-utils.h
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
#include <cinttypes>
#else
#include <inttypes.h>
#endif // __cplusplus
#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <carbon/cbcbase.h>
#include <carbon/util/memory.h>
#include <carbon/net/inet-types.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <known address constant definitions>
#define LOCALHOST_LOOPBACK			"127.0.0.1"
#pragma endregion


#pragma region <known port constant definitions>
#define PORT_ADB_CLIENT_TCP_MAX		5585
#define PORT_ADB_CLIENT_TCP_MIN		5555
#define PORT_ADB_SERVER_TCP			5037
#define PORT_AUTO					0
#define PORT_DEFAULT_WEBHOST		80
#define PORT_DEFAULT_WEBHOST2		8080
#define PORT_SECURE_STANDARD_PORT	443
#define PORT_SMB_NETBIOS			139
#define PORT_SMB_TCP				445
#define PORT_TELNET					23
#pragma endregion


CBCIMPORT
bool_t addrcmp(
	__in struct _inet_address_storage* const o_address1,
	__in struct _inet_address_storage* const o_address2
);



CBCIMPORT 
__success(return) bool_t addrtostr(
	__in      struct _inet_address_storage* const o_address,
	__out     string_t*                           _s_address,
	__out_opt size_t*                             _s_address_length,
	__in      PFALLOCATOR                         f_allocator,
	__in      PFDEALLOCATOR                       f_deallocator
);


CBCIMPORT
bool_t hncmp(
	__in struct _inet_endpoint* const o_name1, 
	__in struct _inet_endpoint* const o_name2
);


CBCIMPORT 
__success(return) bool_t hntostr(
	__in      struct _inet_endpoint* const o_hostname,
	__out     string_t*                    _s_hostname,
	__out_opt size_t*                      _s_hostname_length,
	__in      PFALLOCATOR                  f_allocator,
	__in      PFDEALLOCATOR                f_deallocator
);


CBCIMPORT
uint64_t htonetd(
	__in double_t const hostnum
);


CBCIMPORT
uint32_t htonetl(
	__in ulong_t const hostnum
);


CBCIMPORT
uint64_t htonetll(
	__in ulonglong_t const hostnum
);


CBCIMPORT
uint16_t htonets(
	__in ushort_t const hostnum
);


CBCIMPORT
bool_t inet6cmp(
	__in struct _inet6_address* const o_address1,
	__in struct _inet6_address* const o_address2
);


CBCIMPORT
bool_t inetcmp(
	__in struct _inet_address* const o_address1,
	__in struct _inet_address* const o_address2
);


CBCIMPORT
__success(return) bool_t inettostr(
	__in      struct _inet_address* const o_address,
	__out     string_t*                   _s_address,
	__out_opt size_t*                     _s_address_length,
	__in      PFALLOCATOR                 f_allocator,
	__in      PFDEALLOCATOR               f_deallocator
);


CBCIMPORT
__success(return) bool_t mactostr(
	__in      struct _mac_address* const o_mac_address,
	__out     string_t*                  _s_address,
	__out_opt size_t*                    _n_address_length,
	__in      PFALLOCATOR                f_allocator,
	__in      PFDEALLOCATOR              f_deallocator
);


CBCIMPORT
double_t nettohd(
	__in uint32_t const netnum
);


CBCIMPORT
ulong_t nettohl(
	__in uint32_t const netnum
);


CBCIMPORT
ulonglong_t nettohll(
	__in uint64_t const netnum
);


CBCIMPORT
ushort_t nettohs(
	__in uint16_t const netnum
);


CBCIMPORT __success(return)  
bool_t portstr(
	__in      port_t const  portnum,
	__out     string_t*     _s_port,
	__out_opt size_t*       _s_port_length,
	__in      PFALLOCATOR   f_allocator,
	__in      PFDEALLOCATOR f_deallocator
);


CBCIMPORT
struct _inet_address randip(void);


CBCIMPORT 
__success(return) bool_t strtoaddr(
	__in        string_t const                s_address,
	__inout_opt size_t*                       _s_address_length,
	__out       struct _inet_address_storage* _o_address
);


CBCIMPORT 
__success(return) bool_t strtohn(
	__in        string_t const         s_hostname,
	__inout_opt size_t*                _s_hostname_length,
	__out       struct _inet_endpoint* _o_hostname
);


CBCIMPORT 
__success(return) bool_t strtoinet(
	__in  string_t const        s_address,
	__out struct _inet_address* _o_address
);


CBCIMPORT
bool_t urlcmp(
	__in struct _url* const o_url1,
	__in struct _url* const o_url2
);


CBCIMPORT
bool_t urlscmp(
	__in string_t const s_url1,
	__in string_t const s_url2
);


