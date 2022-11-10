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
#include <carbon/sys/security.h>
#pragma endregion
#
#pragma region "platform-dependent imports"
#include <Windows.h>
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
bool_t getcprocprivs(__out int_t* _access_level) {
	return getprocprivs(NULL, _access_level);
}


FWEXPORT __success(return) 
bool_t getprocprivs(__in_opt ulong_t const process_id, __out int_t* _access_level) {
#pragma region <locals>
	int_t                    access_level = ACCESS_LEVEL_USER;
	UCHAR                    bTokenUser[sizeof(TOKEN_USER) + 8 + 4 * SID_MAX_SUB_AUTHORITIES];
	ULONG                    cbSize;
	BOOL                     bSystem;
	HANDLE                   hProcess = INVALID_HANDLE_VALUE;
	HANDLE                   hToken = INVALID_HANDLE_VALUE;
	TOKEN_ELEVATION          o_token_elevation;
	PSID                     pSystemSid = NULL;
	PTOKEN_USER              pTokenUser = (PTOKEN_USER)bTokenUser;
	SID_IDENTIFIER_AUTHORITY siaNT = SECURITY_NT_AUTHORITY;
#pragma endregion


	if (NULL == process_id)
		hProcess = GetCurrentProcess();
	else {
		hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, process_id);
	}

	if (INVALID_HANDLE_VALUE == hProcess) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	if (!OpenProcessToken(hProcess, TOKEN_QUERY, &hToken)) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	/*
	 * Test for system-level access;
	 */
	if (access_level < ACCESS_LEVEL_KERNEL) {
		if (!GetTokenInformation(hToken, TokenUser, pTokenUser, sizeof(bTokenUser), &cbSize)) {
			switch (GetLastError()) {
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		}

		if (!AllocateAndInitializeSid(&siaNT, 1, SECURITY_LOCAL_SYSTEM_RID, 0, 0, 0, 0, 0, 0, 0, &pSystemSid)) {
			switch (GetLastError()) {
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		}

		if (EqualSid(pTokenUser->User.Sid, pSystemSid)) {
			access_level = ACCESS_LEVEL_KERNEL;
		}

		FreeSid(pSystemSid);
		pSystemSid = NULL;
	}

	/*
	 * Test for root-level access;
	 */
	if (access_level < ACCESS_LEVEL_ROOT) {
		cbSize = sizeof(TOKEN_ELEVATION);

		if (!GetTokenInformation(hToken, TokenElevation, &o_token_elevation, sizeof(o_token_elevation), &cbSize)) {
			switch (GetLastError()) {
			default:
				fw_error = FW_ERROR_UNKNOWN;

				goto $failure;
			}
		}

		if (o_token_elevation.TokenIsElevated) {
			access_level = ACCESS_LEVEL_ROOT;
		}
	}

	CloseHandle(hToken);
	hToken = INVALID_HANDLE_VALUE;


$success:
#pragma region <returns>
	*_access_level = access_level;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (NULL != pSystemSid) {
		FreeSid(pSystemSid);
	}

	if (INVALID_HANDLE_VALUE != hToken) {
		CloseHandle(hToken);
	}

	if (INVALID_HANDLE_VALUE != hProcess && NULL != process_id) {
		CloseHandle(hProcess);
	}
#pragma endregion


	return false;
}


FWEXPORT __success(return) 
bool_t isroot(__out bool_t* _b_is_root) {
#pragma region <locals>
	bool_t           b_is_root;
	DWORD            cbSize = 0L;
	HANDLE           hToken = NULL;
	TOKEN_ELEVATION  Token;
#pragma endregion


	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	cbSize = sizeof(TOKEN_ELEVATION);

	if (!GetTokenInformation(hToken, TokenElevation, &Token, sizeof(Token), &cbSize)) {
		switch (GetLastError()) {
		default:
			fw_error = FW_ERROR_UNKNOWN;

			goto $failure;
		}
	}

	CloseHandle(hToken);
	hToken = INVALID_HANDLE_VALUE;


	if (Token.TokenIsElevated) 
		b_is_root = true;
	else {
		b_is_root = false;
	}


$success:
#pragma region <returns>
	*_b_is_root = b_is_root;
#pragma endregion


	return true;
$failure:
#pragma region <cleanup>
	if (INVALID_HANDLE_VALUE != hToken) {
		CloseHandle(hToken);
	}
#pragma endregion


	return false;
}

