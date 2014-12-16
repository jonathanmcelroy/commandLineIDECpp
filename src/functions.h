#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <boost/filesystem.hpp>
#include <string>
#include <vector>

std::vector<std::string> getRecursiveCodeFiles();
std::vector<std::string> getRecursiveCodeFiles(boost::filesystem::path path);

#endif // define FUNCTIONS_H
