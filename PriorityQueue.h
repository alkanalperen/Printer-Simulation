/*
 * Title: Heaps
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 3
 * Description: main
 */
#ifndef HW3_PRIORITYQUEUE_H
#define HW3_PRIORITYQUEUE_H


#include "Heap.h"
#include "Request.h"

class PriorityQueue {
public:
    // default constructor, copy constructor, and destructor
    // are supplied by the compiler

    // priority-queue operations:
    bool pqIsEmpty() const;
    void pqInsert(const Request& newItem); //throw (PQException);
    void pqDelete( Request& priorityItem); //throw (PQException);

private:
    Heap h;
};


#endif //HW3_PRIORITYQUEUE_H
