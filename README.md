<h1 align="center" font-size=100>Carbon Framework</h1>

<p align="center">
  <a href="#goals">Goals</a> |
  <a href="#getting-started">Getting Started</a> |
  <a href="#dependencies">Dependencies</a> |
  <a href="#examples">Examples</a> |
  <a href="#contribute">Contribute</a> |
  <a href="#donate">Donate</a>
</p>

## Overview
Carbon Framework is a powerful general-purpose library intended to extend the C Standard 
while abstracting the native, low-level function calls and platform-specific includes from developers.
<br/>
<br/>
It provides functionalities such as:
<br/>
 - Various internet utilities 
```c
#include <carbon/net/inet-utils.h>
```
 - File & Directory management without requiring any platform-specific headers 
```c
#include <carbon/sys/files.h>
#include <carbon/sys/dirs.h>
```
 - High-level wrappers for threads and processes
```c
#include <carbon/sys/thread.h>
#include <carbon/sys/process.h>
```
 - High-level wrappers for events and mutexes
```c
#include <carbon/sys/event.h>
#include <carbon/sys/mutex.h>
```
 - Support for string manipulation of UTF-8 and UNICODE path strings
```c
#include <carbon/sys/paths.h>
```
 - Support for string manipulation of UTF-8 and UNICODE strings 
```c
#include <carbon/util/strings.h>
```
 - [Experimental] Sockets
```c
#include <carbon/net/sockets.h>
```
 
## Goals
The goal for the project is to have a powerful cross-platform, pure-C library that allows for quick and efficient C development 
without additional dependencies.
<br/>
Currently only MS-Windows is supported, but the foundation for Android, iOS and Unix is laid.

## Getting Started
Everything is packed into one: one library, one include.
No need to deal with installing tools to install a tool. 
It's simple:
<br/>
To add Carbon to your project, simply download the project, open the Visual Studio solution file and build the static library. 
<br/>
To link the static library to your project:
```c
#pragma comment(lib, "Carbon Framework-x86.lib")
```

To include the main header:
```c
#include <carbon.h>
```
And you're done! 
<br/><br/>
For (your) safety, no pre-compiled library file is provided in the download package.

## Dependencies
As mentioned prior, 
Carbon is in itself dependent only on standard C-libraries and platform-specific libraries (e.g. kernel32.dll on MS-Windows platforms) 
so it's ready for out-of-the-box deployment.

## Examples
Build a random file path from 'C:' that is 10 characters long and prefixed with 'download':
```c
#include <carbon.h>

int main(){
	path_t file_path;
	uint_t file_path_length;

	memzero(file_path, sizeof file_path);

	path_build_random(file_path, &file_path_length, "C:", "download.", 10, ".zip");
	printf("%s\n", file_path);
	path_rmvextension(file_path, &file_path_length, 1);
	printf("%s\n", file_path);
	path_append(file_path, &file_path_length, "HelloWorld.txt");
	printf("%s\n", file_path);
}
```

```
>> C:\download.5iuo7OmqXq.zip
>> C:\download.GSn6hQTVLP
>> C:\download.GSn6hQTVLP\HelloWorld.txt
```

Iterate sub-paths of path:
```c
#include <carbon.h>

int main(){
	int    cursor;
	path_t file_path;
	bool   more;

	memzero(file_path, sizeof file_path);

	cursor = 0;

	while (path_iterate("C:\\Windows\\System32\\Drivers", file_path, NULL, &cursor, &more)) {
		printf("%s\n", file_path);

		if (!more) break;
	}
}
```

```
>> C:\
>> C:\Windows\
>> C:\Windows\System32\
>> C:\Windows\System32\Drivers
```

Play around with a string:
```c
#include <carbon.h>

int main(){
	char_t str[13 + 1];
	uint_t len;

	memzero(str, sizeof str);

	string_copy(str, "!dlroW olleH", &len);
	printf("%s\n", str);

	string_reverse(str);
	printf("%s\n", str);

	string_reduce_left(str, 6, &len);
	printf("%s\n", str);

	string_push(str, &len, "Thanks ", 0);
	printf("%s\n", str);

	string_reduce_right(str, 7, &len);
	string_append(str, &len, "!!!");
	printf("%s\n", str);
}
```

```
>> !dlroW olleH
>> Hello World!
>> World!
>> Thanks World!
>> Thanks!!
```

Check if file exists and securely replace data with zeroes:
```c
#include <carbon.h>

int main(){
	bool exists;

	if (file_exists("passwords.txt", &exists) && exists) {
		file_zero("passwords.txt");
	}
}
```
## Contribute
All who wish to pitch in on development of the project are more than welcome!

## Donate
Consider donating to support the development of the library!
<br/>
XMR: **8A2V2Kvr3qsYYmLBnJymXXRTjYt85FsudX7RBMyotwaLHWzaNqJQmHyUbAWqHEtLjAbpMstHinCnsa2HB8gT4zLY5GhRKoH**
