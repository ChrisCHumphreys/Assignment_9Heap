/*
 * Author: Chris Humphreys
 * Date: 04/16/18
 * File: heap.h
 * Description:  Main driver to thoroughly test heap function.
 */

#include <stdio.h>
#include <iostream>
#include <cstdlib>    // random numbers (rand())
#include <ctime>      // seeder for random nums (time())
#include "heap.h"

using namespace std;

int main()
{
    // create heap
    heap h;
    
    // generate a list of 20 random numbers
    // all between 0 and 100
    cout << h.size() << endl;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int temp = (rand() % 100) + 1;
        h.insert(temp);
        cout << temp << " ";
    }
    cout << endl;
    // print function
    h.print();
    
    cout << endl;
    
    h.remove_max();
    //h.remove_max();

    
    h.print();

    return 0;
}
