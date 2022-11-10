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
#pragma region <imports>
#pragma region "export header imports"
#include <carbon/net/inet-utils.h>
#pragma endregion
#
#pragma region "platform-dependent imports"
#if defined(_WIN32)
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#endif
#pragma endregion
#
#pragma region "platform-independent imports"
#include <assert.h>
#include <stdio.h>
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
bool_t addrtostr(__in struct _inet_address_storage* const o_address, __out string_t* _s_address, __out_opt size_t* _s_address_length, __in PFALLOCATOR f_allocator, __in PFDEALLOCATOR f_deallocator){
#pragma region <locals>
	string_t s_address = NULL;
	size_t   s_address_length;
#pragma endregion


	assert(NULL != o_address);
	assert(NULL != _s_address);
	assert(NULL != f_allocator && NULL != f_deallocator);

	
	switch (o_address->type) {
	case ADDRESS_TYPE_INET:
		s_address_length = _MAX_INET;
		s_address = (string_t)f_allocator((s_address_length + 1) * sizeof(char_t));

		if (!s_address) {
			fw_error = FW_ERROR_NOT_ENOUGH_MEMORY;

			goto $failure;
		}

		inet_ntop(AF_INET, &(o_address->inet), s_address, s_address_length);

		s_address_length = strlen(s_address);

		break;
	case ADDRESS_TYPE_INET6:
		s_address_length = _MAX_INET6;
		s_address = (string_t)f_allocator((s_address_length + 1) * sizeof(char_t));

		if (!s_address) {
			fw_error = FW_ERROR_NOT_ENOUGH_MEMORY;

			goto $failure;
		}

		inet_ntop(AF_INET6, &(o_address->inet6), s_address, s_address_length);

		s_address_length = strlen(s_address);

		break;
	case ADDRESS_TYPE_URL:
		s_address_length = o_address->url.length;
		s_address = (string_t)f_allocator((s_address_length + 1) * sizeof(char_t));

		if (!s_address) {
			fw_error = FW_ERROR_NOT_ENOUGH_MEMORY;

			goto $failure;
		}

		memcpy(s_address, o_address->url.name, o_address->url.length * sizeof(char_t));
		s_address[s_address_length] = 0x0;

		break;
	default:
		fw_error = FW_ERROR_INVALID_ADDRESS_TYPE;

		goto $failure;
	}


$success:
#pragma region <returns>
	*_s_address = s_address;

	if (NULL != _s_address_length) {
		*_s_address_length = s_address_length;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (NULL != s_address) {
		f_deallocator(s_address);
	}
#pragma endregion

	
	return false;
}


FWEXPORT __success(return) 
bool_t hntostr(__in struct _inet_endpoint* const o_hostname, __out string_t* _s_hostname, __out_opt size_t* _s_hostname_length, __in PFALLOCATOR f_allocator, __in PFDEALLOCATOR f_deallocator) {
#pragma region <locals>
	string_t s_address = NULL;
	size_t   s_address_length = 0;
	string_t s_hostname = NULL;
	size_t   s_hostname_length;
	string_t s_port = NULL;
	size_t   s_port_length;
#pragma endregion


	assert(NULL != o_hostname);
	assert(NULL != _s_hostname);
	assert(NULL != f_allocator && NULL != f_deallocator);


	if (!addrtostr(&(o_hostname->address), &s_address, &s_address_length, f_allocator, f_deallocator)) {
		goto $failure;
	}

	if (!portstr(o_hostname->port, &s_port, &s_port_length, f_allocator, f_deallocator)) {
		goto $failure;
	}

	s_hostname_length = 0;
	s_hostname_length += s_address_length;	// [addr]
	s_hostname_length++;					// ':'
	s_hostname_length += s_port_length;		// [port]
	s_hostname = (string_t)f_allocator((s_hostname_length + 1) * sizeof(char_t));

	if (NULL == s_hostname) {
		fw_error = FW_ERROR_NOT_ENOUGH_MEMORY;

		goto $failure;
	} else {
		sprintf(s_hostname, "%s:%s", s_address, s_port);
	}


$success:
#pragma region <returns>
	*_s_hostname = s_hostname;

	if (NULL != _s_hostname_length) {
		*_s_hostname_length = s_hostname_length;
	}
#pragma endregion


	return s_hostname;
$failure:
#pragma region <cleanup>
	if (NULL != s_address) {
		f_deallocator(s_address);
	}

	if (NULL != s_port) {
		f_deallocator(s_port);
	}
#pragma endregion


	return NULL;
}


FWEXPORT __success(return) 
bool_t inettostr(__in struct _inet_address* const o_address, __out string_t* _s_address, __out_opt size_t* _s_address_length, __in PFALLOCATOR f_allocator, __in PFDEALLOCATOR f_deallocator) {
#pragma region <locals>
	string_t s_address = NULL;
	size_t   s_address_length;
#pragma endregion


	assert(NULL != o_address);
	assert(NULL != _s_address);
	assert(NULL != f_allocator && NULL != f_deallocator);


	s_address_length = _MAX_INET;
	s_address = (string_t)f_allocator((s_address_length + 1) * sizeof(char_t));

	if (NULL == s_address) {
		fw_error = FW_ERROR_NOT_ENOUGH_MEMORY;

		goto $failure;
	}

	memzero(s_address, s_address_length * sizeof(char_t));
	sprintf(s_address, "%d.%d.%d.%d", o_address->S_un.S_un_b.s_b1, o_address->S_un.S_un_b.s_b2, o_address->S_un.S_un_b.s_b3, o_address->S_un.S_un_b.s_b4);
	
	if (NULL != _s_address_length) {
		s_address_length = strlen(s_address);
	}


$success:
#pragma region <returns>
	*_s_address = s_address;

	if (NULL != _s_address_length) {
		*_s_address_length = s_address_length;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (NULL != s_address) {
		f_deallocator(s_address);
	}
#pragma endregion


	return false;
}


FWEXPORT
__success(return) bool_t mactostr(__in struct _mac_address* const o_mac_address, __out string_t* _s_address, __out_opt size_t* _n_address_length, __in PFALLOCATOR f_allocator, __in PFDEALLOCATOR f_deallocator) {
#pragma region <locals>
	size_t   n_address_length;
	string_t s_address = NULL;
#pragma endregion

	
	assert(NULL != o_mac_address);
	assert(NULL != _s_address);
	assert(NULL != f_allocator);
	assert(NULL != f_deallocator);


	n_address_length = 18;
	s_address = (string_t)f_allocator(n_address_length * sizeof(char_t));

	if (NULL == s_address) {
		fw_error = FW_ERROR_NOT_ENOUGH_MEMORY;

		goto $failure;
	}
	
	snprintf(
		s_address, 
		n_address_length, 
		"%02x:%02x:%02x:%02x:%02x:%02x", 
		o_mac_address->b1, 
		o_mac_address->b2,
		o_mac_address->b3,
		o_mac_address->b4,
		o_mac_address->b5,
		o_mac_address->b6
	);


$success:
#pragma region <returns>
	*_s_address = s_address;

	if (NULL != _n_address_length) {
		*_n_address_length = n_address_length;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (NULL != s_address) {
		f_deallocator(s_address);
	}
#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t portstr(__in port_t const portnum, __out string_t* _s_port, __out_opt size_t* _s_port_length, __in PFALLOCATOR f_allocator, __in PFDEALLOCATOR f_deallocator) {
#pragma region <locals>
	string_t s_port = NULL;
	size_t   s_port_length;
#pragma endregion


	assert(NULL != _s_port);
	assert(NULL != f_allocator && NULL != f_deallocator);


	s_port_length = _MAX_PORT;
	s_port = (string_t)f_allocator((s_port_length + 1) * sizeof(char_t));

	if (NULL == s_port) {
		fw_error = FW_ERROR_NOT_ENOUGH_MEMORY;

		goto $failure;
	}

	memzero(s_port, s_port_length * sizeof(char_t));
	_itoa(portnum, s_port, 10);
	s_port_length = strlen(s_port);


$success:
#pragma region <returns>
	*_s_port = s_port;
	
	if (NULL != _s_port_length) {
		*_s_port_length = s_port_length;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (NULL != s_port) {
		f_deallocator(s_port);
	}
#pragma endregion


	return false;
}


FWEXPORT __success(return)  
bool_t strtoaddr(__in string_t const s_address, __inout_opt size_t* _s_address_length, __out struct _inet_address_storage* _o_address) {
#pragma region <locals>
	struct addrinfo*             addrinfo = NULL;
	struct addrinfo              hints;
	struct _inet_address_storage o_address;
	int                          ret;
	size_t                       s_address_length;
#pragma endregion


	assert(NULL != s_address);
	assert(NULL != _o_address);


	memzero(&o_address, sizeof o_address);
	memzero(&hints, sizeof hints);

	hints.ai_flags = AI_NUMERICHOST;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	ret = getaddrinfo(s_address, NULL, &hints, &addrinfo);

	if (NULL == _s_address_length)
		s_address_length = strlen(s_address);
	else {
		s_address_length = *_s_address_length;
	}
	
	if (ret == 0) { 
		// IPv4 address;
		o_address.type = ADDRESS_TYPE_INET;
		o_address.inet = *((struct _inet_address*)&(((struct sockaddr_in*)addrinfo->ai_addr)->sin_addr));
	} else {
		hints.ai_family = AF_INET6;
		
		ret = getaddrinfo(s_address, NULL, &hints, &addrinfo);

		if (ret == 0) { 
			// IPv6 address;
			o_address.type = ADDRESS_TYPE_INET6;
			o_address.inet6 = *((struct _inet6_address*)&(((struct sockaddr_in6*)addrinfo->ai_addr)->sin6_addr));
		} else {
			// URL
			o_address.type = ADDRESS_TYPE_URL;
			o_address.url.length = s_address_length;
			memcpy(o_address.url.name, s_address, s_address_length * sizeof(char_t));
		}
	}

	if (NULL != addrinfo) {
		freeaddrinfo(addrinfo);
	}

$success:
#pragma region <returns>
	*_o_address = o_address;

	if (NULL != _s_address_length) {
		*_s_address_length = s_address_length;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (NULL != addrinfo) {
		freeaddrinfo(addrinfo);
	}
#pragma endregion


	return false;
}


FWEXPORT __success(return)  
bool_t strtohn(__in string_t const s_hostname, __inout_opt size_t* _s_hostname_length, __out struct _inet_endpoint* _o_hostname) {
#pragma region <locals>
	string_t              s_address = NULL;
	size_t                s_address_length;
	size_t                s_hostname_length;
	char_t                s_port[_MAX_PORT + 1];
	size_t                s_port_length;
	struct _inet_endpoint o_hostname;
#pragma endregion


	assert(NULL != s_hostname);
	assert(NULL != _o_hostname);


	if (NULL == _s_hostname_length)
		s_hostname_length = strlen(s_hostname);
	else {
		s_hostname_length = *_s_hostname_length;
	}

	/*
	 * Get port;
	 */
	s_port_length = 0;

	for (char_t chr;; s_port_length++) {
		if (s_port_length >= s_hostname_length) {
			goto $failure;
		}
		
		chr = s_hostname[s_hostname_length - s_port_length - 1];

		if (chr == ':') {
			s_port[s_port_length] = 0;

			break;
		} else if (isdigit(chr)) {
			s_port[s_port_length] = chr;
		} else {
			fw_error = FW_ERROR_INVALID;

			goto $failure;
		}
	}

	string_reverse(s_port, &s_port_length);
	
	o_hostname.port = strtoul(s_port, NULL, 0);

	/*
	 * Get address string;
	 */
	s_address_length = ((s_hostname_length - 1) - s_port_length);
	s_address = (string_t)malloc((s_address_length + 1) * sizeof(char_t));

	if (NULL == s_address) {
		fw_error = FW_ERROR_NOT_ENOUGH_MEMORY;

		goto $failure;
	} else {
		memzero(s_address, s_address_length * sizeof(char_t));
		strncpy(s_address, s_hostname, s_address_length);
		s_address[s_address_length] = 0x0;
	}
	
	/* 
	 * ...
	 */
	if (!strtoaddr(s_address, &s_address_length, &(o_hostname.address))) {
		goto $failure;
	}

	/*
	 * ...
	 */
	free(s_address);
	s_address = NULL;


$success:
#pragma region <returns>
	*_o_hostname = o_hostname;

	if (NULL != _s_hostname_length) {
		*_s_hostname_length = s_hostname_length;
	}
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (NULL != s_address) {
		free(s_address);
	}
#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t strtoinet(__in string_t const s_address, __out struct _inet_address* _o_address) {
#pragma region <locals>
	struct _inet_address o_address;
#pragma endregion


	assert(NULL != s_address);
	assert(NULL != _o_address);


	inet_pton(AF_INET, s_address, &o_address);


$success:
#pragma region <returns>
	*_o_address = o_address;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>

#pragma endregion


	return false;
}

