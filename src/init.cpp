#include <iostream>
#include <fstream>

#include "functions.h"
#include "languages.h"
#include "init.h"

bool initProject() {
    auto files = getRecursiveCodeFiles();
    Language language = getLanguageFromFiles(files);
    if(language == None) {
        std::cout << "More than one programming language in this directory" << std::endl;
        return false;
    }
    else {
        return initProject(language);
    }
}

bool initProject(Language l) {
    std::ofstream file(".project");
    if(!file) {
        return false;
    }
    file << "Language: ";
    file << getLanguageName(l) << std::endl;
    return true;
}
