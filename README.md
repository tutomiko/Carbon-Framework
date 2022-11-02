<h1 align="center" font-size=100>Fireworks Framework</h1>

<p align="center">
  <a href="#getting-started">Getting Started</a> |
  <a href="#dependencies">Dependencies</a> |
  <a href="#examples">Examples</a> |
  <a href="#issues">Issues</a> |
  <a href="#join">Join</a> |
  <a href="#donate">Donate</a>
</p>

## Overview
Fireworks Framework is a general-purpose library intended to extend the C Standard.
<br/>
It provides functionalities such as:
<br/>
 - Various internet utilities 
```c
#include <fireworks/net/inet-utils.h>
```
 - File & Directory management without requiring any platform-specific headers 
```c
#include <fireworks/sys/files.h>
#include <fireworks/sys/dirs.h>
```
 - High-level wrappers for threads and processes
```c
#include <fireworks/sys/thread.h>
#include <fireworks/sys/process.h>
```
 - High-level wrappers for events and mutexes
```c
#include <fireworks/sys/event.h>
#include <fireworks/sys/mutex.h>
```
 - Support for string manipulation of UTF-8 and UNICODE path string 
```c
#include <fireworks/sys/paths.h>
```
 - Support for string manipulation of UTF-8 and UNICODE strings 
```c
#include <fireworks/util/strings.h>
```
 - [Experimental] Sockets
```c
#include <fireworks/net/sockets.h>
```
 
## Goals
The goal for the project is to have a powerful cross-platform, pure-C library that allows for quick and efficient C development 
without additional dependencies.
<br/>
Currently only MS-Windows is supported, but the foundation for Android, iOS and Unix is laid.

## Getting Started
To add Fireworks to your project, simply download the project, open the Visual Studio solution file and build the static library. 
<br/>

To link the static library to your project:
```c
#pragma comment(lib, "Fireworks Framework-x86.lib")
```

To include the primary header:
```c
#include <fireworks.h>
```
And you're done! 

## Dependencies
As mentioned prior, 
Fireworks is in itself dependent only on standard C-libraries and platform-specific libraries (e.g. kernel32.dll on MS-Windows platforms) 
so it's ready for out-of-the-box deployment.

## Examples
```c
int main(){

}
```

## Issues
Time.
<br/>
Time is the main issue. 
The project is currently being maintained by just me, so the development is slow and any bug fixes or feature implementations may take a while. 

## Join
All who wish to pitch in on development of the project are more than welcome!<p>

## Donate
Feel free to donate to support the development of the library<p>
BTC: xxx<p>
ETH: xxx<p>
XMR: xxx<p>
