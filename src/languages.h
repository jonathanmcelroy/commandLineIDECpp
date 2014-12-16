#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <boost/filesystem.hpp>
#include <string>
#include <list>

enum Language {
    None,
    CPP,
    Python,
    Haskell
};

std::string getLanguageName(Language);
Language getLanguageFromName(std::string);

Language getLanguageFromFiles(std::list<boost::filesystem::path>);
Language getLanguageFromFile(boost::filesystem::path);
Language getLanguageFromExtention(boost::filesystem::path);

#endif // define LANGUAGES_H
