#include "NameList.h"
#include <iostream>

using namespace std;

nameList::nameList(){
    head = NULL;
}

nameList::~nameList(){
}

// sorts by pushing the most popular names to the end of the list
// an inefficient sorting algorithm
void nameList::bubbleSort(){

  Name* start = head;
  Name* curr = NULL;
  Name* trail = NULL;
  Name* temp = NULL;

  int count = namesCounter();

  for(int i = 0; i<count; ++i)
  { //for every element in the list

    curr = trail = head; //set curr and trail at the start node

    while (curr->next != NULL)
    { //for the rest of the elements in the list
        if(curr->counter > curr->next->counter)
        { //compare curr and curr->next
            temp = curr->next; //swap pointers for curr and curr->next
            curr->next = curr->next->next;
            temp->next = curr;

        //now we need to setup pointers for trail and possibly head
        if(curr == head)
        {
            head = trail = temp;
            //this is the case of the first element swapping to preserve the head pointer
        }
        else
        {
          trail->next = temp;
        } //setup trail correctly
        curr = temp; //update curr to be temp since the positions changed
      }
      //advance pointers
      trail = curr;
      curr = curr->next;
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

// Inserts name at the end of the linked list to create an unordered list
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

//counts number of times that a name occurs in the list
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

//deletes a node by checking the position and then relinking
void nameList::deleteName(string name1){
    Name* temp = head;
    while(temp != NULL){
        if(temp->name == name1){
            if(temp->previous == NULL){
                temp->next->previous = NULL;
                head = temp->next;
            }
            else if(temp->next != NULL){
                temp->next->previous = temp->previous;
                temp->previous->next = temp->next;
            }
            else if(temp->next == NULL)
            {
                temp->previous->next = NULL;
            }
            delete temp;
            return;
        }
        temp = temp->next;
    }
    cout << "Name not found" << endl;
}

// To help test the function. prints the name and the occurrence
void nameList::printList(Name* top){
    Name* temp = top;
    while(temp != NULL){
        cout << temp->name << " - " << temp->counter << endl;
        temp = temp->next;
    }
}

//looks through list to find name
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

//asks for number of names to print, checks for list size to verify that we don't overshoot and then prints.
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
        int j = i + 1;
        if(i == num-1){
            cout << j << ". " << temp->name << endl;
        }
        else{
            cout <<  j << ". " << temp->name << " " << endl;
        }
        temp = temp->previous;
    }

}

//Asks for number of names to print, checks for list size to verify that we don't overshoot and then prints.
void nameList::printBottomNames(int num){
    int listSize = namesCounter();
    if(num > listSize){
        cout << "The name list is not that large" << endl;
        return;
    }
    Name* temp = head;
    for(int i = 0; i < num; i++){
        int j = i + 1;
        if(i == num-1){
            cout << j << ". " << temp->name << endl;
        }
        else{
            cout << j << ". " << temp->name << " " << endl;
        }
        temp = temp->next;
    }

}

// looks for names with a certain count
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

// merge sort
Name* nameList::mergeSort(Name* node) {
    Name* secNode;

    if(node == NULL)
    {
        return NULL;
    }
    else if(node->next == NULL)
    {
        return node;
    }
    else
    {
        secNode = split(node);
        return merge(mergeSort(node), mergeSort(secNode));
    }
}

Name* nameList::merge(Name* firstNode, Name* secNode) {
    if(firstNode == NULL)
    {
        return secNode;
    }
    else if(secNode == NULL)
    {
        return firstNode;
    }
    else if(firstNode->counter <= secNode->counter)
    {
        firstNode->next = merge(firstNode->next, secNode);
        return firstNode;
    }
    else
    {
        secNode->next = merge(firstNode, secNode->next);
        return secNode;
    }
}

Name* nameList::split(Name* node){
    Name* secNode;

    if(node == NULL)
    {
        return NULL;
    }
    else if(node->next == NULL)
    {
        return NULL;
    }
    else
    {
        secNode = node->next;
        node->next = secNode->next;
        secNode->next = split(secNode->next);
        return secNode;
    }
}

Name* nameList::headReturner(){
    return head;
}

void nameList::setHead(Name* x){
    head = x;
}
