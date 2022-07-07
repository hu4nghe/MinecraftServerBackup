#include "stdlib.h"
#include "stdio.h"
#include "signal.h"
#include "unistd.h"
#include "time.h"

static volatile unsigned int flag = 1;

void signalHandler(int a)
{
    flag = 0;
}

int main()
{
    signal(SIGINT,signalHandler);

    time_t t = time(NULL);
    
    struct tm tm = *localtime(&t);
    
    while(flag)
    {
        system("cp -r /home/huanghe/minecraft/world /home/huanghe/minecraft/backup");
        t = time(NULL);
        tm = *localtime(&t);
        printf("Save backuped at %d/%02d/%02d/ %02d:%02d:%02d\nNext Backup will be in 10 min.\n",
                 tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
        //backupfile
        sleep(6000);
        flag += 1;
    }
    return 0;  
}