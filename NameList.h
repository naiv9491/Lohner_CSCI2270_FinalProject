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
        void printTopNames(int);  //input how many of the most popular names to print
        void deleteName(std::string);
        void insertName(std::string);
        void printList();
        int namesCounter(); //counts the number of names in the list
        void printByOcurrence(int);  //print all the names that appear a certain number of times
    protected:
    private:
        Name* head;


};

#endif // NAME_LIST
