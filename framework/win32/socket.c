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
#pragma region <imports>
#pragma region "export header imports"
#include <fireworks/net/socket.h>
#pragma endregion
#
#pragma region "platform-dependent imports"
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
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
FWEXPORT __success(return) 
bool_t socket_accept(__in socket_t const server_socket, __out socket_t* _client_socket, __inout_opt struct _socket_address* _address, __inout_opt int_t* _address_size){
#pragma region <locals>
	socket_t client_socket = INVALID_SOCKET;
#pragma endregion


	assert(NULL != server_socket);
	assert(NULL != _client_socket);


	client_socket = accept(server_socket, (struct sockaddr*)_address, _address_size);
	
	if (INVALID_SOCKET == client_socket) {
		switch (WSAGetLastError()) {
		case WSAETIMEDOUT:
			fw_error = FW_ERROR_TIMEOUT;

			goto $failure;
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

$success:
#pragma region <returns>
	*_client_socket = client_socket;
#pragma endregion
	

	return true;
$failure:
#pragma region <cleanup>
	if (INVALID_SOCKET != client_socket) {
		closesocket(client_socket);
	}
#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t socket_bind(__in socket_t const connection, __in struct _socket_address* const name, __in uint_t const name_size){
#pragma region <locals>
	int ret;
#pragma endregion


	ret = bind(connection, (struct sockaddr*)name, name_size);

	if (SOCKET_ERROR == ret) {
		switch (WSAGetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>

#pragma endregion
	

	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t socket_close(__in socket_t connection){
#pragma region <locals>
	int ret;
#pragma endregion


	ret = closesocket(connection);

	if (SOCKET_ERROR == ret) {
		switch (WSAGetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>

#pragma endregion
	

	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t socket_connect(__in socket_t const connection, __in struct _socket_address* const name, __in uint_t const name_size){
#pragma region <locals>
	int ret;
#pragma endregion


	ret = connect(connection, (struct sockaddr*)name, name_size);

	if (SOCKET_ERROR == ret) {
		switch (WSAGetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>

#pragma endregion
	

	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return)
bool_t socket_create(__in int_t const address_family, __in int_t const socket_type, __in int_t const protocol, __out socket_t* _connection) {
#pragma region <locals>
	socket_t connection = INVALID_SOCKET;
#pragma endregion


	connection = socket(address_family, socket_type, protocol);

	if (INVALID_SOCKET == connection) {
		switch (WSAGetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>
	*_connection = connection;
#pragma endregion
	

	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t socket_listen(__in socket_t const connection, __in uint_t const backlog){
#pragma region <locals>
	int ret;
#pragma endregion


	ret = listen(connection, backlog);

	if (SOCKET_ERROR == ret) {
		switch (WSAGetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>

#pragma endregion
	

	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t socket_receive(__in socket_t const connection, __inout byte_t* buffer, __in size_t const buffer_length, __out size_t* _n_bytes_read){
#pragma region <locals>
	size_t n_bytes_read;
#pragma endregion


	n_bytes_read = recv(connection, buffer, buffer_length, 0);

	if (n_bytes_read == 0) {
		fw_error = FW_ERROR_CONNECTION_RESET;

		goto $failure;
	}

	if (SOCKET_ERROR == n_bytes_read) {
		switch (WSAGetLastError()) {
		case WSAECONNRESET:
			fw_error = FW_ERROR_CONNECTION_RESET;

			goto $failure;
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>
	*_n_bytes_read = n_bytes_read;
#pragma endregion
	

	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t socket_receive_all(__in socket_t const connection, __inout byte_t* buffer, __in size_t const buffer_length){
#pragma region <locals>
	size_t n_bytes_read = 0,
	 	   n_bytes_read_total = 0,
		   n_bytes_to_read = 0;
#pragma endregion


	do {
		n_bytes_to_read = (buffer_length - n_bytes_read_total);

		if (n_bytes_to_read == 0) {
			break;
		}

		n_bytes_read = recv(connection, &(buffer[n_bytes_read_total]), n_bytes_to_read, 0);

		if (SOCKET_ERROR == n_bytes_read)
			switch (WSAGetLastError()) {
			case WSAECONNRESET:
				fw_error = FW_ERROR_CONNECTION_RESET;

				goto $failure;
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		else {
			n_bytes_read_total += n_bytes_read;
		}
	} while (n_bytes_read_total < buffer_length);


$success:
#pragma region <returns>

#pragma endregion
	

	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t socket_send(__in socket_t const connection, __in byte_t* const buffer, __in size_t const buffer_size, __out size_t* _n_bytes_sent){
#pragma region <locals>
	size_t n_bytes_sent;
#pragma endregion


	n_bytes_sent = send(connection, buffer, buffer_size, 0);

	if (n_bytes_sent == 0) {
		fw_error = FW_ERROR_CONNECTION_RESET;

		goto $failure;
	}

	if (SOCKET_ERROR == n_bytes_sent) {
		switch (WSAGetLastError()) {
		case WSAECONNRESET:
			fw_error = FW_ERROR_CONNECTION_RESET;

			goto $failure;
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}


$success:
#pragma region <returns>
	*_n_bytes_sent = n_bytes_sent;
#pragma endregion
	

	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t socket_send_all(__in socket_t const connection, __in byte_t* const buffer, __in size_t const buffer_size) {
#pragma region <locals>
	size_t n_bytes_to_write = 0,
		   n_bytes_written = 0,
		   n_bytes_written_total = 0;
#pragma endregion


	do {
		n_bytes_to_write = (buffer_size - n_bytes_written_total);

		if (n_bytes_to_write == 0)
			break;
		else {
			n_bytes_written = send(connection, &(buffer[n_bytes_written_total]), n_bytes_to_write, 0);
		}

		if (SOCKET_ERROR == n_bytes_written)
			goto $failure;
		else {
			n_bytes_written_total += n_bytes_written;
		}
	} while (n_bytes_written_total < buffer_size);


$success:
#pragma region <returns>

#pragma endregion
	

	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t socket_set_timeout(__in socket_t const connection, __in ulong_t const timeout) {
#pragma region <locals>

#pragma endregion


	setsockopt(connection, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof timeout);


$success:
#pragma region <returns>

#pragma endregion
	

	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}

