#ifndef LANGUAGES_H
#define LANGUAGES_H

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
Language getLanguageFromFiles(list<string>);
Language getLanguageFromFile(string);
Language getLanguageFromExtention(string);

#endif // define LANGUAGES_H
