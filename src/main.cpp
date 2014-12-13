#include <iostream>
#include <string>
#include <regex>
#include <sstream>

#include "termcolor.h"

#include "init.h"
#include "languages.h"
using namespace std;

bool exitCommand(string);
ostream& prompt(ostream&);
void evaluateCommand(string);

const regex EXIT("(e|E)xit");
const regex INIT("(i|I)nit");

int main() {
    string input;
    while(prompt(cout) && getline(cin, input) && !exitCommand(input)) {
        evaluateCommand(input);
    }
    cout << "Bye!" << endl;
    return 0;
}

bool exitCommand(string input) {
    return regex_match(input, EXIT);
}

ostream& prompt(ostream& out) {
    return out << green << "-> " << clear;
}

void evaluateCommand(string line) {
    istringstream in(line);
    string command;
    in >> command;
    if(regex_match(command, INIT)) {
        initProject();
        cout << "Init the project" << endl;
    }
    else {
        cout << "Unrecognized command" << endl;
    }
}
