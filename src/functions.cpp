#include <dirent.h>
#include <iostream>

#include "languages.h"
#include "functions.h"

#include "jm_ostream.h"

std::vector<std::string> getRecursiveCodeFiles() {
    return getRecursiveCodeFiles(".");
}

std::vector<std::string> getRecursiveCodeFiles(const char* path) {
    // open the path directory
    auto dir = opendir(path);

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
