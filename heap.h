/*
 * Author: Chris Humphreys
 * Date: 04/16/18
 * File: heap.h
 * Description:  Header file for heap class.  Declars all 'heap' attributes
 *               and functions.
 */

#ifndef heap_h
#define heap_h

#include<vector>   //vector data structure
#include<iostream> //STDIN, STDOUT

class heap {
private:
    std::vector<int> buffer;
    void insertHelper(int parentIndex, int insertIndex);
    void max_helper(int index);
    void swap(int indexA, int indexB);
    
public:
    heap();
    int size();
    void insert(int value);
    void remove_max();
    int max();
    void print();
};

#endif /* heap_h */
