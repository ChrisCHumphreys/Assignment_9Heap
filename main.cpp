//
//  main.cpp
//  Assignment_9Heap
//
//  Created by Chris Humphreys on 4/16/18.
//  Copyright © 2018 Chris Humphreys. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "heap.h"

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    
    heap h;
    
    cout << h.size() << endl;
    h.insert(6);
    h.insert(7);
    h.insert(8);
    h.insert(9);
    h.insert(4);
    
    cout << h.size() << endl;

    return 0;
}
