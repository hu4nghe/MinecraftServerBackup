#include <fmt/core.h>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main() 
{   
    fs::path pTs("/home/huanghe/GithubRepo/MinecraftServerBackup");
    std::string s = pTs.filename();
    fmt::print("Current path is{1}\n",s);

    return 0;
}
//