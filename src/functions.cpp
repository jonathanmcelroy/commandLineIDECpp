#include <boost/filesystem.hpp>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "languages.h"
#include "functions.h"

std::vector<boost::filesystem::path> getRecursiveCodeFiles() {
    return getRecursiveCodeFiles(".");
}

// get all the code files from the
std::vector<boost::filesystem::path> getRecursiveCodeFiles(boost::filesystem::path path) {
    using namespace boost::filesystem;
    std::vector<boost::filesystem::path> result;
    for(auto file = directory_iterator(path); file != directory_iterator(); file++) {
        if(is_directory(*file)) {
            auto recurse = getRecursiveCodeFiles(*file);
            result.insert(result.end(), recurse.begin(), recurse.end());
        }
        else if (is_regular_file(*file) and getLanguageFromFile(*file) != None) {
            result.push_back(file->path());
        }
    }

    return result;
}
