#include <boost/filesystem.hpp>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "languages.h"
#include "functions.h"

std::list<boost::filesystem::path> getRecursiveCodeFiles() {
    return getRecursiveCodeFiles(".");
}

// get all the code files from the path
std::list<boost::filesystem::path> getRecursiveCodeFiles(boost::filesystem::path path) {
    using namespace boost::filesystem;
    std::list<boost::filesystem::path> result;
    // for each child in the directory
    for(auto file = directory_iterator(path); file != directory_iterator(); file++) {
        // if the child is a directory
        if(is_directory(*file)) {
            // get its children
            auto recurse = getRecursiveCodeFiles(*file);
            result.insert(result.end(), recurse.begin(), recurse.end());
        }
        // if the child is a code file
        else if (is_regular_file(*file) and getLanguageFromFile(*file) != None) {
            // add it
            result.push_back(file->path());
        }
    }

    return result;
}
