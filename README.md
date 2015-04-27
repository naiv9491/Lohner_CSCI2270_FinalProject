# Lohner/Rhoda CSCI 2270 FinalProject

##Final Project for Data Structures

###Using a doubly linked list to order a list of names by occurrence.

Given a list of roughly 36,000 names we will use a doubly linked list to order them by order of occurrence. In doing so we will be able to run a variety of tests on them such as number of occurrences of a certain name, printing the most and least popular names, inserting new names, finding number of occurrences of names starting with a certain letter, etc. We believe that a doubly linked list will be a very computationally efficient way to preform this task given that insertion and deletion from the list should occur in O(1) time and most other functions should occur in O(n) time, giving an overall fair to good performance.

The main goal of this project is to showcase the difference in efficiency of different sorting algorithms.  After running both bubble or merge sorts you can see the time it took at the bottom of the newly sorted and printed list, you will notice that there is a gigantic difference in time taken.

Team is composed of Frederik Lohner and Chris Rhoda.

We've included an executable but if you wish to compile it yourself you can use g++ Namelist.cpp FinalDriver.cpp -std=c++11 -o Final

To execute run ./Final Names.txt
