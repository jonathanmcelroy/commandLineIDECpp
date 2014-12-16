#include "languages.h"
using namespace std;

string getLanguageName(Language l) {
    switch(l) {
    case CPP:
        return "C++";
    case Python:
        return "Python";
    case Haskell:
        return "Haskell";
    default:
        return "Unknown";
    }
}

// return the language for all the files if it is the same for all. Otherwise return None
Language getLanguageFromFiles(list<boost::filesystem::path> paths) {
    Language language;
    // for each file
    for(auto path : paths) {
        Language tempLang = getLanguageFromFile(path);
        if(language == None) {
            language = tempLang;
        }
        else if(language != tempLang) {
            return None;
        }
    }

    return language;
}

// returns the language of the file based on the extention
Language getLanguageFromFile(boost::filesystem::path fileName) {
    auto extension = fileName.extension();
    if(extension.empty()) {
        return None;
    }
    return getLanguageFromExtention(extension);
}

// returns the langauge for the given extention
Language getLanguageFromExtention(boost::filesystem::path ext) {
    if(ext == ".cpp" || ext == ".h") {
        return CPP;
    }
    else if(ext == ".py") {
        return Python;
    }
    else if(ext == ".hs") {
        return Haskell;
    }
    else {
        return None;
    }
}
