#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <boost/filesystem.hpp>
#include <string>
#include <vector>

std::vector<boost::filesystem::path> getRecursiveCodeFiles();
std::vector<boost::filesystem::path> getRecursiveCodeFiles(boost::filesystem::path path);

#endif // define FUNCTIONS_H
