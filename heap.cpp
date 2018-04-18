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
    
    // if first entry - go back
    if (buffer.size() == 2)
    {
        return;
    }
    
    // account for being 0 indexed, but starting at 1.
    int parentIndex = (buffer.size() - 1) / 2;
    int insertIndex = buffer.size() - 1 ;

    // insert it
    insertHelper(parentIndex, insertIndex);
}

void heap::insertHelper(int parentIndex, int insertIndex)
{
    // get the values
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
        
        // check if parent above needs to be swapped out
        insertHelper(int (parentIndex/2), parentIndex);
    }
    return;
}

void heap::remove_max()
{
    int lastLeaf = buffer[buffer.size() - 1];
    
    // if no elements, just return
    if (buffer.size() == 1)
    {
        return;
    }
    
    // if only one element, just remove it and return
    else if (buffer.size() == 2)
    {
        buffer.pop_back();
        return;
    }
    
    // swap out last lear for root of heap
    buffer[1] = lastLeaf;
    // remove lastLeaf
    buffer.pop_back();
    
    max_helper(1);
}

void heap::max_helper(int index)
{
    // find two leafs
    int leftIndex = index * 2;
    int rightIndex = (index * 2) + 1;
    
    // if leafs are larger than size of array they dont
    // exist yet.
    if (leftIndex > buffer.size() - 1)
    {
        leftIndex = index;
    }
    if (rightIndex > buffer.size() - 1)
    {
        rightIndex = index;
    }
    
    int leftLeaf = buffer[leftIndex];
    int rightLeaf = buffer[rightIndex];
    
    // if bigger than both
    if ((buffer[index] < leftLeaf) && (buffer[index] < rightLeaf))
    {
        // find smallest
        if (rightLeaf > leftLeaf)
        {
            swap(index, rightIndex);
            max_helper(rightIndex);
        }
        else
        {
            swap (index, leftIndex);
            max_helper(leftIndex);
        }
    }
    else if (buffer[index] < leftLeaf)
    {
        swap(index, leftIndex);
        max_helper(leftIndex);
    }
    else if (buffer[index] < rightLeaf)
    {
        swap(index, rightIndex);
        max_helper(rightIndex);
    }
    return;
}

void heap::swap(int indexA, int indexB)
{
    int temp = buffer[indexA];
    buffer[indexA] = buffer[indexB];
    buffer[indexB] = temp;
}

int heap::max()
{
    // check to see there is a value in the heap
    if (buffer.size() >= 2)
    {
        return buffer[1];
    }
    else return 0;
}

void heap::print()
{
    for (int i = 1; i < buffer.size(); i++)
    {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;
}
