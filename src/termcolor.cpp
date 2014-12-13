#include <iostream>

#include "termcolor.h"

std::ostream& operator<<(std::ostream& os, const Modifier& mod) {
    return os << "\033[" << mod.color << 'm';
}

Modifier red(FG_RED);
Modifier green(FG_GREEN);
Modifier clear(FG_DEFAULT);
