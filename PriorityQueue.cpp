/*
 * Title: Heaps
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 3
 * Description: main
 */
#include "PriorityQueue.h"
bool PriorityQueue::pqIsEmpty() const {
    return h.heapIsEmpty();
}

void PriorityQueue::pqInsert(const Request& newItem) {
        h.heapInsert(newItem);
}

void PriorityQueue::pqDelete(Request& priorityItem) {
        h.heapDelete(priorityItem);


}