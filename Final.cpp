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




/*
int main()
{
    char keys[][8] = {"she", "sells", "sea", "shore", "the", "by", "sheer"};
    trie_t trie;
 
    initialize(&trie);
 
    for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        insert(&trie, keys[i]);
    }
 
    deleteKey(&trie, keys[0]);
 
    printf("%s %s\n", "she", search(&trie, "she") ? "Present in trie" : "Not present in trie");
 
    return 0;
}
*/
