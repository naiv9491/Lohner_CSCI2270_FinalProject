#include "NameList.h"
#include <iostream>

using namespace std;

nameList::nameList(){
    head = NULL;
}

nameList::~nameList(){

}

void nameList::bubbleSort(){
    Name *i = head;
    int listSize = namesCounter();
    for(int l = 0; l < listSize -1; l++){
        Name* j = i;
        for(int k = 0; k < listSize - l - 1; k++){
            if(j->counter > j->next->counter){
                string tempName = j->name;
                int tempCount = j->counter;
                j->name = j->next->name;
                j->counter = j->next->counter;
                j->next->name = tempName;
                j->next->counter = tempCount;
            }
            if(j->next != NULL){
                j = j->next;
            }
        }
        if(i->previous != NULL){
            i = i->previous;
        }
        if(i->next != NULL){
            i = i->next;
        }
    }

}

//counts names in list, used in bubbleSort
int nameList::namesCounter(){
    int counter = 0;
    Name *temp = head;
    while(temp != NULL){
        counter++;
        temp = temp->next;
    }
    return counter;
}

// Inserts name at the end of the linked list
void nameList::insertName(string name1){
    Name* temp;
    if(head == NULL){
        temp = new Name;
        temp->name = name1;
        temp->counter = 1;
        temp->previous = NULL;
        temp->next = NULL;
        head = temp;
        return;
    }
    temp = head;
    while(temp != NULL){
        if(temp->name == name1){
            temp->counter++;
            return;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Name *added = new Name;
    temp->next = added;
    added->previous = temp;
    added->name = name1;
    added->counter = 1;
    added->next = NULL;

}


void nameList::nameOccurrence(string name1){
    Name* temp = head;
    while(temp != NULL){
        if(temp->name == name1){
            cout << temp->name << " occurs " << temp->counter << " times." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Name not found" << endl;
}

void nameList::deleteName(string name1){
    Name* temp = head;
    while(temp != NULL){
        if(temp->name == name1){
            if(temp->previous == NULL){
                temp->next->previous = NULL;
                head = temp->next;
            }
            if(temp->next != NULL){
                temp->next->previous = temp->previous;
            }
            delete temp;
            return;
        }
        temp = temp->next;
    }
    cout << "Name not found" << endl;
}

// To help test the function. prints the name and the occurrence
void nameList::printList(){
    Name* temp = head;
    while(temp != NULL){
        cout << temp->name << " - " << temp->counter << endl;
        temp = temp->next;
    }
}

void nameList::findName(string name1){
    Name* temp = head;
    while(temp != NULL){
        if(temp->name == name1){
            cout << "Name found " << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Name not found" << endl;
}

void nameList::printTopNames(int num){
    int listSize = namesCounter();
    if(num > listSize){
        cout << "The name list is not that large" << endl;
        return;
    }
    Name* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    for(int i = 0; i < num; i++){
        if(i == num-1){
            cout << temp->name << endl;
        }
        else{
            cout << temp->name << " " << endl;
        }
        temp = temp->previous;
    }

}

void nameList::printBottomNames(int num){
    int listSize = namesCounter();
    if(num > listSize){
        cout << "The name list is not that large" << endl;
        return;
    }
    Name* temp = head;
    for(int i = 0; i < num; i++){
        if(i == num-1){
            cout << temp->name << endl;
        }
        else{
            cout << temp->name << " " << endl;
        }
        temp = temp->next;
    }

}

void nameList::printByOcurrence(int count){
    Name* temp = head;
    bool foundCount = false;
    while(temp->next != NULL){
        if(temp->counter == count){
            cout << temp->name << endl;
            foundCount = true;
        }
        temp = temp->next;
    }
    if(foundCount == false){
        cout << "No name with that count was found." << endl;
    }
}


