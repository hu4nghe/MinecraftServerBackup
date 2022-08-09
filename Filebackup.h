#ifndef _FILEBACKUP_H
#define _FILEBACKUP_H

//C++ Headers
#include <iostream>
#include <string>
#include <filesystem>

#if __cplusplus >= 202002L

//libfmt becomes a part of std in C++20
#include <format>

#else

#include <fmt/format.h>

#endif//C++20

#include <cstdlib>
#include <ctime>

#ifdef __unix__ 

//Linux system headers
#include "signal.h"
#include "unistd.h"

#endif//Linux check

#ifdef _WIN32

//Windows system hearders
#include <Windows.h>

#endif//Windows check

#endif/* _FILEBACKUP.H */