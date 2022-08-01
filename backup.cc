#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <filesystem>

using namespace std;

#include "signal.h"
#include "unistd.h"


static volatile unsigned int flag = 1;

void signalHandler(int a)
{
        flag = 0;
}

int main()
{

    signal(SIGINT,signalHandler);

    auto t = time(NULL);
    auto tm = *localtime(&t);

    const string newName = "save_";

    string source,destination;
    cout<<"Please enter the source path."<<"\n";



    while(flag)
    {

        printf("%s\n",(newName + to_string(flag)).c_str());
        
        system("cp -r /home/huanghe/GithubRepo/MinecraftServerBackup/test/source/object /home/huanghe/GithubRepo/MinecraftServerBackup/test/destination");

        system("pwd");
        system("ls");

        system("cd test/destination");

        system("pwd");
        system("ls");

        rename("object",(newName + to_string(flag)).c_str());

        system("pwd");
        system("ls");

        system("cd /home/huanghe/GithubRepo/MinecraftServerBackup/test/source");
        
        t = time(NULL);
        tm = *localtime(&t);

        printf("Save backuped at %d/%02d/%02d %02dh%02d\nNext Backup will be in 10 min.\n",
                 tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
        

        sleep(15);

        flag ++;
    }
    return 0;  
}