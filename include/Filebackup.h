/**this file is a little tool that helps minecraft server owners to backup the save profil.
 * written by HUANG He.
 */
#ifndef _FILEBACKUP_H
#define _FILEBACKUP_H

#include <iostream>
#include <string>
#include <filesystem>

/**
 * @brief libfmt has became a part of std in C++20
 * 
 */
#if __cplusplus >= 202002L

#include <format>

#else

#include <fmt/format.h>

#endif//C++20

#include <cstdlib>
#include <ctime>

/**
 * @brief demande user to change directory in case of the path is invalide
 * 
 * @param p file path
 */
void inputModification(std::filesystem::path &p);
/**
 * @brief print current time and the time interval of autosave.
 * 
 * @param delay time interval of autosave.
 */
void timePrint(unsigned delay);

/**
 * @brief system using check
 * 
 */
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