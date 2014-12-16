#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <boost/filesystem.hpp>
#include <string>
#include <list>
using namespace std;

enum Language {
    None,
    CPP,
    Python,
    Haskell
};

string getLanguageName(Language);

Language getLanguageFromFiles(list<boost::filesystem::path>);
Language getLanguageFromFile(boost::filesystem::path);
Language getLanguageFromExtention(boost::filesystem::path);

#endif // define LANGUAGES_H
