#include <iostream>
#include <fstream>

#include "functions.h"
#include "init.h"

#include "jm_ostream.h"
bool initProject() {
    std::cout << getRecursiveCodeFiles();
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
