#include <iostream>
#include <fstream>
#include <string>
#include "NameList.h"
#include <time.h>

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
    // NL.bubbleSort();
    bool sorted = false;
    bool quit = false;
    while(!quit){
        cout << "======Main Menu======" << endl;
        cout << "1. Print List" << endl;
        cout << "2. Print x most common names" << endl;
        cout << "3. Print x least common names" << endl;
        cout << "4. Print number of times name is found" << endl;
        cout << "5. Insert name" << endl;
        cout << "6. Delete name" << endl;
        cout << "7. Print all names that occur a certain number of times" << endl;
        cout << "8. Sort List (Bubble or Merge)" << endl;
        cout << "9. Quit" << endl;

        string response;
        getline(cin, response);
        if(response == "1"){
            NL.printList(NL.headReturner());
        }
        else if(response == "2"){
            if(sorted == true)
            {
                cout << "How many names to print?" << endl;
                getline(cin, response);
                NL.printTopNames(stoi(response));
            }
            else
            {
                cout << "List has not been sorted." << endl;
            }
        }
        else if(response == "3"){
            if(sorted == true)
            {
            cout << "How many names to print?" << endl;
            getline(cin, response);
            NL.printBottomNames(stoi(response));
            }
            else
            {
                cout << "List has not been sorted." << endl;
            }
        }
        else if(response == "4"){
            cout << "Name?" << endl;
            getline(cin, response);
            NL.nameOccurrence(response);
        }
        else if(response == "5"){
            cout << "What is the name to be inserted." << endl;
            getline(cin, response);
            NL.insertName(response);
            sorted = false;
        }
        else if(response == "6"){
            cout << "Name to be deleted?" << endl;
            getline(cin, response);
            NL.deleteName(response);
        }
        else if(response == "7"){
            cout << "What occurrence do you wish to check?" << endl;
            getline(cin, response);
            NL.numOfOccurrences(response);
            //NL.nameOccurrence(response);
        }
        else if(response == "8"){
            /*You can see that we used the clock function given by time.h to measure
            the difference between a bubble and a merge sort, this gives the user a
            very clear idea as to the differences in efficiency between the two. */
            cout << "Do you wish to sort using bubble (1) or merge (2)?" << endl;
            getline(cin, response);
            if(response == "1")
            {
                clock_t tStart = clock();
                NL.bubbleSort();
                //NL.printList(NL.headReturner());
                cout << endl;
                printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                cout << endl;
                sorted = true;
            }
            else if(response == "2")
            {
                clock_t tStart = clock();
                Name* sortedList = NL.mergeSort(NL.headReturner());
                //NL.printList(NL.headReturner());
                cout << endl;
                printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                cout << endl;
                NL.setHead(sortedList);
                sorted = true;
            }
            else
            {
                cout << "Incorrect command." << endl;
            }

        }
        else if(response == "9")
        {
            quit = true;
        }
    }
    cout << "Goodbye!" << endl;
}

