#include <iostream>
#include <fstream>
#include "Trie.h"

using namespace std;

int main(int argc, char *argv[]){

    bool quit = false;

    while(!quit){

        cout << "======Main Menu======" << endl;
        cout << "1. Build Trie" << endl;
        cout << "2. Most popular name starting with a certain letter" << endl;
        cout << "3. Most popular name in the list" << endl;
        cout << "4. Quit" << endl;
        string response;
        getline(cin, response);
        if(response == "1"){

        }
        else if(response == "2"){

        }
        else if(response == "3"){

        }
        else if(response == "4"){
            quit = true;
        }
    }
}
