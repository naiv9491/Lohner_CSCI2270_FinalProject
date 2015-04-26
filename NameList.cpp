#include "NameList.h"
#include <iostream>

using namespace std;

nameList::nameList(){
    head = NULL;
}

nameList::~nameList(){

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
    while(temp->next != NULL){
        if(temp->name == name1){
            temp->counter++;
            return;
        }
        temp = temp->next;
    }
    Name *added = new Name;
    temp->next = added;
    added->previous = temp;
    added->name = name1;
    added->counter = 1;
    added->next = NULL;

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
