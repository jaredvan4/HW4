//Jared VanEnkevort
#include <iostream>
#include <string>
using namespace std;
#include "HW4.h"

int main(int argc, char* argv[]){
    while (true) {
        string input; 
        getline(cin, input);
        handleRequest(input);
    }
}

void handleRequest(string input){
    if (input.substr(0, input.find(" ")) == "ADD"){
        cout << "Add requested!\n";
        int beg = input.find('"')+1;
        string request = input.substr(beg, input.length() - beg - 1);
        cout << request << "\n";
    }
    else if (input == "PRINT") {
        cout << "print requested!\n";
    }
    else if (input == "RPRINT") {
        cout << "rprint requested!\n";
    }
    else if (input.substr(0, input.find(" ")) == "REMOVE") {
        cout << "Remove requested!\n";
        int beg = input.find('"') + 1;
        string request = input.substr(beg, input.length() - beg - 1);
        cout << request << "\n";
    }
    else if (input.substr(0, input.find(" ")) == "LOOKUP") {
        cout << "Lookup requested!\n";
        int beg = input.find('"') + 1;
        string request = input.substr(beg, input.length() - beg - 1);
        cout << request << "\n";
    }
    else if (input == "EXIT") {
        cout << "Exiting...\n";
        exit(0);
    }
}
