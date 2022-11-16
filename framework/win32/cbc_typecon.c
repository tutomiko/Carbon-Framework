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
#include <WinSock2.h>
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
CBCEXPORT
uint64_t htonetd(__in double_t const hostnum) {
	return htond(hostnum);
}


CBCEXPORT
uint32_t htonetl(__in ulong_t const hostnum) {
	return htonl(hostnum);
}


CBCEXPORT
uint64_t htonetll(__in ulonglong_t const hostnum) {
	return htonll(hostnum);
}


CBCEXPORT
uint16_t htonets(__in ushort_t const hostnum) {
	return htons(hostnum);
}


CBCEXPORT
double_t nettohd(__in uint32_t const netnum) {
	return ntohd(netnum);
}


CBCEXPORT
ulong_t nettohl(__in uint32_t const netnum) {
	return ntohl(netnum);
}


CBCEXPORT
ulonglong_t nettohll(__in uint64_t const netnum) {
	return ntohll(netnum);
}


CBCEXPORT
ushort_t nettohs(__in uint16_t const netnum) {
	return ntohs(netnum);
}

