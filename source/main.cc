#include "Filebackup.h"

namespace fs = std::filesystem;
using std::string;
using fmt::print;

int main()
{

    signal(SIGINT,signalHandler);

    const string newName = "save_";
    string source,destination;

    unsigned delay;
    
    /**
     * @brief input of source path.
     */
    print("Please enter the source path.\n");
    std::cin>>source;
    fs::path sourcePath(source);
    while(!exists(sourcePath))
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
        fs::create_directories(sourcePath/"Backups");
        string newPath = "/Backups/Save"+ std::to_string(flag); 
        fs::rename(sourcePath/"world",sourcePath/newPath);
        timePrint(delay);
        sleep(delay);
    }

    return 0;  
}