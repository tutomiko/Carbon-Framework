/*
 * FileName: string.h
 *
 * Written by tutomiko <https://www.github.com/tutomiko>
 *
 * Copyright (c) 2022, Tuomas Kontiainen
 *
 * This file is a part of Fireworks Framework <https://github.com/tutomiko/Fireworks-Framework>
 * Fireworks Framework is a free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later versions.
 *
 * Fireworks Framework is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Fireworks Framework. If not,
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
#include <fireworks/util/error.h>
#include <fireworks/type/primitives.h>
#include <fireworks/type/bytearray.h>
#include <fireworks/type/string.h>
#include <fireworks/net/inet.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <ip protocol constant definitions>
#define IP_PROTOCOL_TCP			6
#define IP_PROTOCOL_UDP			17
#pragma endregion


#pragma region <connection type constant definitions>
#define SOCKET_TYPE_DGRAM		2
#define SOCKET_TYPE_STREAM		1
#pragma endregion


#pragma region <address family constant definitions>
#define ADDRESS_FAMILY_INET		2
#define ADDRESS_FAMILY_INET6	23
#pragma endregion


/// <summary>
/// Socket handle type.
/// </summary>
typedef int_t socket_t;


struct _socket_address {
	ushort_t sa_family;
	byte_t   sa_data[14];
} typedef SocketAddress;


struct _socket_address_in {
	ushort_t             sin_family;
	ushort_t             sin_port;
	struct _inet_address sin_addr;
	byte_t               sin_zero[8];
} typedef SocketAddressIn;


#ifdef _FIREWORKS_ENABLE_EXPERIMENTAL_FEATURES
FWIMPORT __success(return)
bool_t socket_accept(
	__in        socket_t const          server_socket,
	__out       socket_t*               _client_socket,
	__inout_opt struct _socket_address* _address,
	__inout_opt int_t*                  _address_size
);


FWIMPORT __success(return)  
bool_t socket_bind(
	__in socket_t const                connection,
	__in struct _socket_address* const name,
	__in uint_t const                  name_size
);


FWIMPORT __success(return)  
bool_t socket_close(
	__in socket_t connection	
);


FWIMPORT __success(return)  
bool_t socket_connect(
	__in socket_t const                connection,
	__in struct _socket_address* const name,
	__in uint_t const                  name_size
);


FWIMPORT __success(return) 
bool_t socket_create(
	__in  int_t const address_family,
	__in  int_t const socket_type,
	__in  int_t const protocol,
	__out socket_t*   _connection
);


FWIMPORT __success(return)  
bool_t socket_listen(
	__in socket_t const connection,
	__in uint_t const   backlog
);


FWIMPORT __success(return)  
bool_t socket_receive(
	__in    socket_t const connection,
	__inout byte_t*        buffer,
	__in    size_t const   buffer_size,
	__out   size_t*        _n_bytes_read
);


FWIMPORT __success(return)  
bool_t socket_receive_all(
	__in    socket_t const connection,
	__inout byte_t*        buffer,
	__in    size_t const   buffer_size
);


bool_t socket_receive_from();


bool_t socket_select();


FWIMPORT __success(return)  
bool_t socket_send(
	__in  socket_t const connection,
	__in  byte_t* const  buffer,
	__in  size_t const   buffer_size,
	__out size_t*        _n_bytes_sent
);


FWIMPORT __success(return)  
bool_t socket_send_all(
	__in socket_t const connection,
	__in byte_t* const  buffer,
	__in size_t const   buffer_size
);


bool_t socket_send_to();


FWIMPORT __success(return)  
bool_t socket_set_timeout(
	__in socket_t const connection, 
	__in ulong_t const  timeout
);


bool_t socket_shutdown(
	__in socket_t const connection
);
#endif // _FIREWORKS_ENABLE_EXPERIMENTAL_FEATURES


