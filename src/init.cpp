#include <iostream>
#include <fstream>

#include "functions.h"
#include "init.h"

bool initProject() {
    auto files = getRecursiveCodeFiles();
    return true;
}

bool initProject(Language l) {
    std::ofstream file(".project");
    if(!file) {
        return false;
    }
    file << "Language ";
    file << l << std::endl;
    return true;
}
