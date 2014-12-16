#include <boost/filesystem.hpp>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "languages.h"
#include "functions.h"

#include "jm_ostream.h"

using namespace boost::filesystem;

std::vector<std::string> getRecursiveCodeFiles() {
    return getRecursiveCodeFiles(".");
}

// get all the code files from the
std::vector<std::string> getRecursiveCodeFiles(boost::filesystem::path path) {
    std::vector<std::string> result;
    for(auto file = directory_iterator(path); file != directory_iterator(); file++) {
        if(is_directory(*file)) {
            auto recurse = getRecursiveCodeFiles(*file);
            result.insert(result.end(), recurse.begin(), recurse.end());
        }
        else if (is_regular_file(*file) and getLanguageFromFile(*file) != NONE) {
            result.push_back(*file);
        }
    }

    return std::vector<std::string>();
}
