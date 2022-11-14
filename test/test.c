#
#pragma region <imports>
#pragma region "export header imports"

#pragma endregion
#
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
//#include <stdio.h>
#pragma endregion
#
#pragma region "3rd-party imports"
#include "../include/carbon.h"
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
int _cdecl main(int argc, char** argv) {
#ifdef EXAMPLE1
	path_t file_path;
	uint_t file_path_length;

	memzero(file_path, sizeof file_path);

	// Builds random file path from C: that is 10 characters long that is prefixed with 'download'
	path_build_random(file_path, &file_path_length, "C:", "download.", 10, ".zip");
	printf("%s\n", file_path);	// -> C:\download.5iuo7OmqXq.zip
	path_rmvextension(file_path, &file_path_length, 1);
	printf("%s\n", file_path);	// -> C:\download.GSn6hQTVLP
	path_append(file_path, &file_path_length, "HelloWorld.txt");
	printf("%s\n", file_path);	// -> C:\download.GSn6hQTVLP\HelloWorld.txt	
#endif

#ifdef EXAMPLE2
	int    cursor;
	path_t file_path;
	bool   more;

	memzero(file_path, sizeof file_path);

	cursor = 0;

	while (path_iterate("C:\\Windows\\System32\\Drivers", file_path, NULL, &cursor, &more)) {
		printf("%s\n", file_path);

		if (!more) break;
	}

	// OUTPUT:
	// >> C:\
	// >> C:\Windows\
	// >> C:\Windows\System32\
	// >> C:\Windows\System32\Drivers	 
#endif

#ifndef EXAMPLE3
	char_t str[255 + 1];
	uint_t len;

	memzero(str, sizeof str);

	string_copy(str, "Saippuakauppias", &len);
	printf("%s\n", str);	// >> !dlroW olleH

	string_reverse(str);
	printf("%s\n", str);	// >> Hello World!

	string_reduce_left(str, 6, &len);
	printf("%s\n", str);	// >> World!

	string_push(str, &len, "Thanks ", 0);
	printf("%s\n", str);	// >> Thanks World!

	string_reduce_right(str, 7, &len);
	string_append(str, &len, "!!!");
	printf("%s\n", str);	// >> Thanks!!!
#endif



#ifdef EXAMPLE4
	bool exists;

	if (file_exists("passwords.txt", &exists) && exists) {
		file_zero("passwords.txt");
	}


	_thread_local static int x;
#endif

}