#ifndef STATE_H
#define STATE_H

#include "languages.h"

class State {
private:
    Language language;
public:
    State();
    State(Language newLanguage);
};

#endif // define STATE_H
