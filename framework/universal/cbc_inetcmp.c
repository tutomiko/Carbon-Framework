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
#include <carbon/net/inet-utils.h>
#pragma endregion
#
#pragma region "platform-dependent imports"

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
CBCEXPORT
bool_t addrcmp(__in struct _inet_address_storage* const o_address1, __in struct _inet_address_storage* const o_address2) {
	assert(NULL != o_address1);
	assert(NULL != o_address2);


	if (o_address1->type != o_address2->type) {
		return false;
	}

	switch (o_address1->type) {
	case ADDRESS_TYPE_INET:
		return inetcmp(&(o_address1->inet), &(o_address2->inet));
	case ADDRESS_TYPE_INET6:
		return inetcmp(&(o_address1->inet6), &(o_address2->inet6));
	case ADDRESS_TYPE_URL:
		return urlcmp(&(o_address1->url), &(o_address2->url));
	default:
		return false;
	}
}


CBCEXPORT
bool_t hncmp(__in struct _inet_endpoint* const o_name1, __in struct _inet_endpoint* const o_name2) {
	assert(NULL != o_name1);
	assert(NULL != o_name2);


	if (addrcmp(&(o_name1->address), &(o_name2->address)) && (o_name1->port == o_name2->port))
		return true;
	else {
		return false;
	}
}


CBCEXPORT
bool_t inet6cmp(__in struct _inet6_address* const o_address1, __in struct _inet6_address* const o_address2) {
	assert(NULL != o_address1);
	assert(NULL != o_address2);


	return (memcmp(o_address1, o_address2, sizeof(Inet6Address)) == 0);
}


CBCEXPORT
bool_t inetcmp(__in struct _inet_address* const o_address1, __in struct _inet_address* const o_address2) {
	assert(NULL != o_address1);
	assert(NULL != o_address2);


	return (memcmp(o_address1, o_address2, sizeof(InetAddress)) == 0);
}


CBCEXPORT
bool_t urlcmp(__in struct _url* const o_url1, __in struct _url* const o_url2) {
	assert(NULL != o_url1);
	assert(NULL != o_url2);


	return false;
}


CBCEXPORT
bool_t urlscmp(__in string_t const s_url1, __in string_t const s_url2) {
	assert(NULL != s_url1);
	assert(NULL != s_url2);


	return false;
}

