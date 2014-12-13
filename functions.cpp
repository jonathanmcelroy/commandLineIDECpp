#include <dirent.h>
#include <iostream>

#include "languages.h"
#include "functions.h"

std::vector<std::string> getRecursiveCodeFiles() {
    auto dir = opendir(".");
    decltype(readdir(dir)) file;
    while((file = readdir(dir)) && file != NULL) {
        auto fileType = getLanguageFromFile(file->d_name);
        if(fileType != None) {
            std::cout << file->d_name << std::endl;
        }
    }

    closedir(dir);

    return std::vector<std::string>();
}
