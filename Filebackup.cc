#include "Filebackup.h"

namespace fs = std::filesystem;
using std::string;
using fmt::print;

/**
 * @brief try to accept a new input in case of the path is invalide.
 * 
 * @param p old path
 */
void inputModification(fs::path &p)
{
    p.clear();
    string newPath;
    print("This path is invalide ! Please enter a valide path.");
    std::cin>>newPath;
    p.assign(newPath);
}

/**
 * @brief Print Current time and remind user when next backup will be saved.
 * 
 * @param delay 
 */
void timePrint(unsigned delay)
{
    auto t = time(NULL);
    auto tm = *localtime(&t);

    print("Save backuped at {0}/{1}/{2} {3}h{4}.\nNext Backup will be in {6} min.\n",
        tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, delay);            
}

#ifdef __unix__//Linux code

/**
 * @brief A signal handler, makes the program stop when recive Ctrl + C.
 * 
 * @param a 
 */
void signalHandler(int a)
{
        flag = 0;
}

#endif//Linux code