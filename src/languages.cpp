#include "languages.h"
using namespace std;

string getLanguageName(Language l) {
    switch(l) {
    case CPP:
        return "C++";
        break;
    case Python:
        return "Python";
        break;
    case Haskell:
        return "Haskell";
        break;
    default:
        return "Unknown";
    }
}

Language getLanguageFromFiles(list<string> files) {
    if(files.size() == 0) {
        return None;
    }
    auto finalType = getLanguageFromFile(files.front());
    for(auto file : files) {
        auto type = getLanguageFromFile(file);
        if(finalType != type) {
            return None;
        }
    }
    return finalType;
}

Language getLanguageFromFile(string fileName) {
    auto extensionI = fileName.rfind(".");
    if(extensionI >= fileName.size()) {
        return None;
    }
    auto extension = fileName.substr(extensionI);
    return getLanguageFromExtention(extension);
}

Language getLanguageFromExtention(string ext) {
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

Language getLanguageFromFile(boost::filesystem::path fileName) {
    auto extension = fileName.extension();
    if(extension.empty()) {
        return None;
    }
    return getLanguageFromExtention(extension);
}

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
