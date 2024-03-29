#ifndef TERMCOLOR_H
#define TERMCOLOR_H

#include <iostream>

enum Color {
    FG_RED      = 31,
    FG_GREEN    = 32,
    FG_BLUE     = 34,
    FG_DEFAULT  = 39,
    BG_RED      = 41,
    BG_GREEN    = 42,
    BG_BLUE     = 44,
    BG_DEFAULT  = 49
};

class Modifier {
    private:
        Color color;
    public:
        Modifier(Color newColor) : color(newColor) {}
        friend std::ostream& operator<<(std::ostream& os, const Modifier& mod);
};

extern Modifier red;
extern Modifier green;
extern Modifier clear;

#endif // define TERMCOLOR_H
