#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <filesystem>
#include <fmt/core.h>

using namespace std;

#include "signal.h"
#include "unistd.h"


static volatile unsigned int flag = 1;

void timePrint();
void signalHandler(int a);


int main()
{

    signal(SIGINT,signalHandler);

    const string newName = "save_";
    int delay;

    string source,destination;
    fmt::print("Please enter the source path.\n");
    cin>>source;
    fmt::print("Please enter the destination path.\n");
    cin>>destination;
    fmt::print("Please enter autosave time interval(in second).");
    cin>>delay;

    

    while(flag)
    {

        printf("%s\n",(newName + to_string(flag)).c_str());
        
        system("cp -r /home/huanghe/GithubRepo/MinecraftServerBackup/test/source/object /home/huanghe/GithubRepo/MinecraftServerBackup/test/destination");

        timePrint(delay);

        sleep(15);

        flag ++;
    }
    return 0;  
}

/**
 * @brief Print Current time and remind user when next backup will be saved.
 * 
 * @param delay 
 */
void timePrint(int delay)
{
    auto t = time(NULL);
    auto tm = *localtime(&t);

    fmt::print("Save backuped at {0}/{1}/{2} {3}h{4}.\nNext Backup will be in {6} min.\n",
                tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min,delay);            
}

/**
 * @brief A signal handler, makes the program stop when recive Ctrl + C.
 * 
 * @param a 
 */
void signalHandler(int a)
{
        flag = 0;
}