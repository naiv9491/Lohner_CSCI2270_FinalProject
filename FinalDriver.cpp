#include <iostream>
#include <fstream>
#include "NameList.h"

using namespace std;

int main(int argc, char* argv[]){
    nameList NL;

    ifstream file;
    file.open(argv[1]);
    if(!file.is_open()){
        cout << "Error opening file" << endl;
    }
    string word;
    while(file >> word){
        NL.insertName(word);
    }
    file.close();

    bool quit = false;
    while(!quit){
        cout << "======Main Menu======" << endl;
        cout << "1. Order List" << endl;
        cout << "2. Find name" << endl;
        cout << "3. Print top names" << endl;
        cout << "4. Print name occurrence" << endl;
        cout << "5. Insert name" << endl;
        cout << "6. Delete name" << endl;
        cout << "7. Quit" << endl;

        string response;
        getline(cin, response);
        if(response == "1"){
            NL.bubbleSort();
        }
        else if(response == "2"){
            NL.printList();
        }
        else if(response == "3"){
            
        }
        else if(response == "4"){
            cout << "Name?" << endl;
            getline(cin, response);
            NL.nameOccurrence(response);
        }
        else if(response == "5"){

        }
        else if(response == "6"){
            cout << "Name to be deleted?" << endl;
            getline(cin, response);
            NL.deleteName(response);
        }
        else if(response == "7"){
            quit = true;
        }

    }
    cout << "Goodbye!" << endl;
}
