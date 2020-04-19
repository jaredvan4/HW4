#include <iostream>
#include <string>
#include <cstdlib>
#include "Tree.h"
#include "DRT.h"
#include "PG4.h"
using namespace std;

int main(int argc, char** argv) {

    Studs = new Tree();
    while (ProcessCommand());
    delete Studs;
    return 0;
}

bool ProcessCommand() {

    string cmd;
    getline(cin, cmd);
    if (cmd == "EXIT") return false;
    if (cmd == "PRINT") Print();
    else if (cmd == "RPRINT") RPrint();
    else if (cmd.substr(0, 3) == "ADD") AddCommand(cmd);
    else if (cmd.substr(0, 6) == "REMOVE") RemoveCommand(cmd);
    else if (cmd.substr(0, 6) == "LOOKUP") LookupCommand(cmd);
    else cout << "Invalid Command!" << endl;
    return true;
}

void Print() {

    cout << "Printing list forwards:" << endl;
    DRT* T = Studs->search("");
    string k = T->getnext();
    while (k != "") {
        delete T;
        T = Studs->search(k);
        cout << "Name:  " << k << "\tCopies:  " << T->getdata() << endl;
        k = T->getnext();
    }
    delete T;
    cout << endl;
}

void RPrint() {

    cout << "Printing list backwards:" << endl;
    DRT* T = Studs->search("");
    string k = T->getprev();
    while (k != "") {
        delete T;
        T = Studs->search(k);
        cout << "Name:  " << k << "\tCopies:  " << T->getdata() << endl;
        k = T->getprev();
    }
    delete T;
    cout << endl;
}

void AddCommand(string cmd) {
    
}

void RemoveCommand(string cmd) {

    int q1, q2;
    for (q1 = 0; cmd[q1] != '\"'; q1++);
    for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
    string k = cmd.substr(q1 + 1, q2 - q1 - 1);
    DRT* T = Studs->search(k);
    if (T->getdata() == "")
        cout << "\"" << k << "\" does not exist in the library." << endl;
    else {
        if (T->getdata() == "1") {
            delete T;
            T = Studs->modify(k, "");
        }
        else {
            string d = to_string(stoi(T->getdata()) - 1);
            delete T;
            T = Studs->modify(k, d);
        }
        cout << "1 copy of \"" << k << "\" has been removed from the library." << endl;
        delete T;
    }
}

void LookupCommand(string cmd) {

}
