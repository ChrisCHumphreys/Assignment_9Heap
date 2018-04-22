/*
 * Author: Chris Humphreys / Drew Presson
 * Date: 04/16/18
 * File: heap.h
 * Description:  Header file for heap class.  Declares and defines
 *               all 'heap' attributes and functions.
 */

#ifndef heap_h
#define heap_h

#include<vector>   //vector data structure
#include<iostream> //STDIN, STDOUT

template <class type>
class heap {
/*
 * Description:
 *   Heap class template.  Creates a heap data structure that works with
 *   any of the c++ standard types.  Can also be used for custom made classea/types
 *   as long as the user has defined the comparison operators for the class
 *   that they want to put into the heap.
 */
    
private:
    std::vector<type> buffer;
    void insertHelper(int parentIndex, int insertIndex);
    /*
     * Description:
     *   Called by the public insert function, allows values to be inserted recursively.
     *   Argumens are the index of the parent of the insert index and the index of the
     *   item being inserted into the list.
     *
     * Inputs:
     *   int parentIndex
     *     an integer
     *   int insertIndex
     *     an integer
     *
     * Outputs:
     *   None
     */
    
    void max_helper(int index);
    /*
     * Description:
     *   Called by the public remove_max function, allows max_value to be removed recursively.
     *   Argument is the index of the item being removed.
     *
     * Inputs:
     *   int index
     *     an integer
     *
     * Outputs:
     *   None
     */
    
    void swap(int indexA, int indexB);
    /*
     * Description:
     *   Takes in the indexs of the two values in the vector that are to be swapped.
     *   Swaps the values.
     *
     * Inputs:
     *   int indexA
     *     an integer
     *   int indexB
     *     an integer
     *
     * Outputs:
     *   None
     */
    
public:
    heap();
    /*
     * Description:
     *   Default constructor for heap class.  Creates a an empty vector of the appropriate
     *   type.
     *
     * Inputs:
     *   None
     *
     * Outputs:
     *   None
     */
    
    int size();
    /*
     * Description:
     *   Returns the size of the current tree as an integer representing the number of nodes
     *   in the heap.
     *
     * Inputs:
     *   None
     *
     * Outputs:
     *   None
     */
    
    void insert(type value);
    /*
     * Description:
     *   Allows a user to enter a new node into the heap.
     *
     * Inputs:
     *   type value
     *     an object of they 'type' specified by the heap
     *
     * Outputs:
     *   None
     */
    
    void remove_max();
    /*
     * Description:
     *   Removes the largest value from the heap, and reorganizes the heap
     *   to ensure that it stays a valid heap data structure.
     *
     * Inputs:
     *   None
     *
     * Outputs:
     *   None
     */
    
    type max();
    /*
     * Description:
     *   Returns a copy of the largest value in the heap.  DOES NOT remove
     *   the max value, just makes a copy and returns that to the user.
     *
     * Inputs:
     *   None
     *
     * Outputs:
     *   None
     */
    
    void print();
    /*
     * Description:
     *   Prints to console out the items in the vector being used to contain
     *   the heaps data.  Prints out the values to one line with each value
     *   seperated by a 'space' character.
     *
     * Inputs:
     *   None
     *
     * Outputs:
     *   None
     */
};

template <class type>
heap<type>::heap()
{
    // just makes it large enough to hold one value
    buffer.resize(1);
}

template <class type>
int heap<type>::size()
{
    // return to user the number of items in the heap
    return buffer.size() - 1;
}

template <class type>
void heap<type>::insert(type value)
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

template <class type>
void heap<type>::insertHelper(int parentIndex, int insertIndex)
{
    // get the values
    type parentValue = buffer[parentIndex];
    type insertValue = buffer[insertIndex];
    
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

template <class type>
void heap<type>::remove_max()
{
    type lastLeaf = buffer[buffer.size() - 1];
    
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

template <class type>
void heap<type>::max_helper(int index)
{
    // find two leafs
    int leftIndex = index * 2;
    int rightIndex = (index * 2) + 1;
    
    // if leafs are larger than size of array they dont
    // exist yet.
    if (leftIndex > int(buffer.size()) - 1)
    {
        leftIndex = index;
    }
    if (rightIndex > int(buffer.size()) - 1)
    {
        rightIndex = index;
    }
    
    type leftLeaf = buffer[leftIndex];
    type rightLeaf = buffer[rightIndex];
    
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

template <class type>
void heap<type>::swap(int indexA, int indexB)
{
    // simple swap function just made to save time
    type temp = buffer[indexA];
    buffer[indexA] = buffer[indexB];
    buffer[indexB] = temp;
}

template <class type>
type heap<type>::max()
{
    // check to see there is a value in the heap
    if (buffer.size() >= 2)
    {
        return buffer[1];
    }
    else return 0;
}

template <class type>
void heap<type>::print()
{
    // just loop through and print all the values in the heap
    for (int i = 1; i < int(buffer.size()); i++)
    {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;
}

#endif /* heap_h */
