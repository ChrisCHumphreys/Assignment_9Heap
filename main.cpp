/*
 * Author: Chris Humphreys / Drew Presson
 * Date: 04/16/18
 * File: heap.h
 * Description:  Main driver to thoroughly test heap function.
 */


#include <iostream>   // STDIN, STDOUT
#include <cstdlib>    // random numbers (rand())
#include <ctime>      // seeder for random nums (time())
#include <string>     // string objects
#include "heap.h"     // heap objects


using namespace std;

int main()
{
    // create heaps
    // one of strings, one of ints, one of longs
    heap<string> stringHeap;
    heap<int> intHeap;
    heap<long> longHeap;
    
    // populate the string heap with names
    stringHeap.insert("Chris");
    stringHeap.insert("Carrie");
    stringHeap.insert("Brie");
    stringHeap.insert("Sierra");
    stringHeap.insert("Nevada");
    
    // print the string heap
    cout << "PRINT STRING HEAP" << endl;
    stringHeap.print();
    cout << endl;
    
    // print size of string heap
    cout << "PRINT SIZE OF STRING HEAP" << endl;
    cout << stringHeap.size() << endl;
    cout << endl;
    
    // print the string heap in order using max
    cout << "PRINT STRING HEAP IN ORDER" << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout << stringHeap.max() << " ";
        stringHeap.remove_max();
    }
    cout << endl;
    cout << endl;
    
    // Populate the integer heap
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        intHeap.insert(rand() % 100 + 1);
    }
    
    // print the integer heap
    cout << "PRINT INTEGER HEAP" << endl;
    intHeap.print();
    cout << endl;
    
    // print size of integer heap
    cout << "PRINT SIZE OF INTEGER HEAP" << endl;
    cout << intHeap.size() << endl;
    cout << endl;
    
    // print the integer heap in order
    cout << "PRINT INTEGER HEAP IN ORDER" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << intHeap.max() << " ";
        intHeap.remove_max();
    }
    cout << endl;
    cout << endl;
    
    // populate the long heap
    for (int i = 0; i < 10; i++)
    {
        longHeap.insert(rand()/100);
    }
    
    // print the long heap
    cout << "PRINT LONG HEAP" << endl;
    longHeap.print();
    cout << endl;
    
    // print size of long heap
    cout << "PRINT SIZE OF LONG HEAP" << endl;
    cout << longHeap.size() << endl;
    cout << endl;
    
    // print the long heap in order
    cout << "PRINT LONG HEAP IN ORDER" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << longHeap.max() << " ";
        longHeap.remove_max();
    }
    cout << endl;

    return 0;
}
