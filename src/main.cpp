#include <iostream>
#include <string>
#include <regex>
#include <sstream>

#include "termcolor.h"
#include "state.h"

#include "init.h"
#include "languages.h"
using namespace std;

bool exitCommand(string);
ostream& prompt(ostream&, State);
bool evaluateCommand(string);

const regex EXIT("(e|E)xit");
const regex INIT("(i|I)nit");

int main() {
    // the state of the ide
    State state;

    // for each line, evaluate it as a command
    string line;
    while(prompt(cout, state) && getline(cin, line) && evaluateCommand(line)) {}

    cout << "Bye!" << endl;
    return 0;
}

// write the prompt
ostream& prompt(ostream& out, State state) {
    if(state.getLanguage() == None) {
        return out << green << "no language > " << clear;
    }
    else {
        return out << green << getLanguageName(state.getLanguage()) << " > " << clear;
    }
}

// evaluate the line as a command
bool evaluateCommand(string line) {
    // turn the line into a stream
    istringstream in(line);

    // get the command name
    string command;
    in >> command;

    // if the command is nothing, do nothing
    if(command == "") {}
    // if the command is exit, return false to exit
    else if(regex_match(command, EXIT)) {
        return false;
    }
    // if the command is init, initiate the project
    else if(regex_match(command, INIT)) {
        initProject();
        cout << "Init the project" << endl;
    }
    else {
        cout << "Unrecognized command: " << command << endl;
    }

    return true;
}
