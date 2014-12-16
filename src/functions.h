#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <boost/filesystem.hpp>
#include <string>
#include <list>

std::list<boost::filesystem::path> getRecursiveCodeFiles();
std::list<boost::filesystem::path> getRecursiveCodeFiles(boost::filesystem::path path);

#endif // define FUNCTIONS_H
