#include "languages.h"
#include "state.h"

State::State() : language(None) {}

State::State(Language newLanguage) : language(newLanguage) {}

