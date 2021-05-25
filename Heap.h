#include "Request.h"

//
// Created by Alperen Alkan on 14.04.2021.
//
const int MAX_HEAP = 1000;

#ifndef HW3_HEAP_H
#define HW3_HEAP_H


class Heap {
public:
    Heap();				// default constructor
    // copy constructor and destructor are supplied by the compiler

    bool heapIsEmpty() const;
    void heapInsert(const Request& newItem); //throw(HeapException);
    void heapDelete(Request& rootItem);// throw(HeapException);

protected:
    void heapRebuild(int root);		// Converts the semiheap rooted at
    // index root into a heap
private:
    Request items[MAX_HEAP];	// array of heap items
    int          size;            	// number of heap items

};


#endif //HW3_HEAP_H
