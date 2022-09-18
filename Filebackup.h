#ifndef _FILEBACKUP_H
#define _FILEBACKUP_H

#include <iostream>
#include <string>
#include <filesystem>

#if __cplusplus >= 202002L

#include <format>

#else

#include <fmt/format.h>

#endif//C++20

#include <cstdlib>
#include <ctime>

void inputModification(std::filesystem::path &p);
void timePrint(unsigned delay);

#ifdef __unix__ 

//Linux system headers
#include "signal.h"
#include "unistd.h"

static volatile unsigned int flag = 1;

void signalHandler(int a);

#endif//Linux check

#ifdef _WIN32

//Windows system hearders
#include <Windows.h>

#endif//Windows check

#endif/* _FILEBACKUP.H */