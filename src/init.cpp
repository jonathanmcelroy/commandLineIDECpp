#include <fstream>

#include "functions.h"
#include "init.h"

bool initProject() {
    getRecursiveCodeFiles();
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
