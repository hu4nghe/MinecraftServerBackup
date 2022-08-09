#include "Filebackup.h"

namespace fs = std::filesystem;
using std::string;
using fmt::print;

#ifdef __unix__//Linux code

static volatile unsigned int flag = 1;

void timePrint(unsigned delay);
void backUp(unsigned delay);
void signalHandler(int a);
void inputModification(fs::path &p);
bool checkIfLeagal(fs::path &p);

int main()
{

    signal(SIGINT,signalHandler);

    const string newName = "save_";
    string source,destination;

    unsigned delay;
    bool valid = false;
    
    /**
     * @brief input of source path.
     */
    print("Please enter the source path.\n");
    std::cin>>source;
    fs::path sourcePath(source);
    valid = checkIfLeagal(sourcePath);
    while(!valid)
    {
        inputModification(sourcePath);        
    }

    /**
     * @brief input of time interval between two backup.
     */
    print("Please enter autosave time interval(in second).");
    std::cin>>delay;

    while(flag)
    {
        fs::create_directories(sourcePath/"backUps");
        string newPath = "/backUps/Save"+ std::to_string(flag); 
        fs::rename(sourcePath/"world",sourcePath/newPath);
        timePrint(delay);
        sleep(delay);
    }

    return 0;  
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

bool checkIfLeagal(fs::path &p)
{
    if(exists(p)) return true;
    else return false;
}

void inputModification(fs::path &p)
{
    p.clear();
    string newPath;
    print("This path is invalide ! Please enter a valide path.");
    std::cin>>newPath;
    p.assign(newPath);
}

#endif//Linux code