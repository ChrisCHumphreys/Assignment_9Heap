#Assignment 9
 * Chris Humphreys
 * Drew Presson
 * 04/21/18
 * Readme.md
 * Readme file for Assignment 9 - Heap

#Description
  This is our submission for assignment 9, in which we create an array based heap data structure.  Since we implemented it as a templated class, a user can create a heap that canstore items of any 'type'.  We met all the requriements of the assignemnt.

#Files Needed
 * heap.h
 * main.cpp
 * Makefile
 * NOTE - There is not heap.cpp file becuase we made a templated container.

#How to run
 1. Ensure you have all the above files in a single location.
 2. Run `make` from the terminal.
 3. Run `./heap_driver` to see test output.  For different tests
    update main.cpp accordingly, and rebuild.

#Design Decisions
 We did create a templated heap container so that it is very versatile and can be use with any data type as long at the type knows how to compare to values using the '<', '>', and '=' comparison operators.  We decided to store it in a vector with the first element in the 1 index as opposed to the 0 index.  This made it easier as we could use integer division and easily find the floor or decimals when searching for parent and child nodes.
 We also made an additional private swap function that is a helper because we had to swap nodes so often in the code.  
 Finally, we tried to do everything recursively that could be done in that way to make the code easy to read, and to cut down on the actual amount of code required.  This necessitated making a few helper functions for functions like insert and remove_max().

#Bugs - Future Improvements
 We beleive that we have fixed any obviously apparent bugs, but there may be a small one or two that we are not aware of.  For the most part the program should run as expected, in most all circumstances.

#Extra Credit
 We did the extra credit and created a templated container.
