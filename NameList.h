#ifndef NAMELIST_H
#define NAMELIST_H

#include <iostream>

struct Name{
    std::string name;
    Name* next;
    Name* previous;
    int counter;
};

class nameList{
    public:
        nameList();
        ~nameList();
        void orderList(); // order the list by occurrence of names. Most popular to least
        void bubbleSort();
        void findName(std::string); // input is name to be found
        void nameOccurrence(std::string); // input name, outputs how many times that name has appeared
        void numOfOccurrences(std::string number);//Added a function that displays the names that occur a certain number of times (to fit option 7 in main menu)
        void printTopNames(int);  //input how many of the most popular names to print
        void printBottomNames(int);
        void deleteName(std::string);
        void insertName(std::string);
        void printList(Name* top);
        int namesCounter(); //counts the number of names in the list
        Name* mergeSort(Name* node);
        Name* merge(Name* firstNode, Name* secondNode);
        Name* split(Name* node);
        Name* headReturner();
        void setHead(Name*);
        void printByOcurrence(int);  //print all the names that appear a certain number of times
    protected:
    private:
        Name* head;


};

#endif // NAME_LIST
