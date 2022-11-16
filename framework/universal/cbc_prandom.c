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
#include <carbon/util/prandom.h>
#pragma endregion
#
#pragma region "platform-dependent imports"
#include <assert.h>
#pragma endregion
#
#pragma region "platform-independent imports"
#include <time.h>
#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <carbon/util/memory.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
CBCEXPORT
void prandom_init(__out struct _prandom_data* o_rand_data) {
	assert(NULL != o_rand_data);

	memzero(o_rand_data, sizeof *o_rand_data);

	o_rand_data->seed = time(NULL);
}


CBCEXPORT
unsigned long prandom_rand(__in struct _prandom_data* o_rand_data) {
	unsigned long val;

	assert(NULL != o_rand_data);

	// Get seed to generate random with;
	val = o_rand_data->seed;

	// Chunk least random bit;
	val = ((val >> 1) & 0x7fffffff);

	// Append new "random" value to seed;
	if ((o_rand_data->seed + val) < ULONG_MAX)
		o_rand_data->seed += val;
	else {
		o_rand_data->seed = val;
	}

	return val;
}


CBCEXPORT
void prandom_seed(__in struct _prandom_data* o_rand_data, __in unsigned long seed) {
	assert(NULL != o_rand_data);

	o_rand_data->seed = seed;
}

