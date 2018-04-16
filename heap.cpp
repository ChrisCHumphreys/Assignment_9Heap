/*
 * Author: Chris Humphreys
 * Date: 04/16/18
 * File: heap.cpp
 * Description:  Implementation file for heap class.  Defines all 'heap' functions.
 */

#include "heap.h"

heap::heap()
{
    buffer.push_back(0);
}

int heap::size()
{
    return buffer.size() - 1;
}

void heap::insert(int value)
{
    buffer.push_back(value);
    
    // if first entry
    if (buffer.size() == 2)
    {
        return;
    }
    int parentIndex = (buffer.size() - 1) / 2;
    int insertIndex = buffer.size() - 1 ;

    insertHelper(parentIndex, insertIndex);
}

void heap::insertHelper(int parentIndex, int insertIndex)
{
    int parentValue = buffer[parentIndex];
    int insertValue = buffer[insertIndex];
    
    if (parentValue < insertValue)
    {
        // swap the two values
        buffer[parentIndex] = insertValue;
        buffer[insertIndex] = parentValue;
        
        // if at root, dont keep going up
        if (parentIndex/2 < 1)
        {
            return;
        }
        
        insertHelper(int (parentIndex/2), parentIndex);
    }
    return;
}

void heap::remove_max()
{
    //
}

int heap::max()
{
    // Sample
    return 1;
}

void heap::print()
{
    //
}
