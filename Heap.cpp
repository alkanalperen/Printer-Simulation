//
// Created by Alperen Alkan on 14.04.2021.
//

#include "Heap.h"
Heap::Heap() : size(0) {
}

bool Heap::heapIsEmpty() const {
    return (size == 0);
}
void Heap::heapInsert(const Request& newItem)  {


    // Place the new item at the end of the heap
    items[size] = newItem;

    // Trickle new item up to its proper position
    int place = size;
    int parent = (place - 1)/2;
    while ( (place > 0) && (items[place].getPriority() > items[parent].getPriority() )){
        Request temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }
    ++size;
}
void Heap::heapDelete(Request& rootItem)  {
    if (heapIsEmpty());
        //throwHeapException("HeapException: Heap empty");;
    else {
        if(items[0].getPriority()==items[2].getPriority() && items[2].getSendingTime()<items[0].getSendingTime() ){
            if(items[2].getSendingTime() <= items[1].getSendingTime() && items[2].getPriority() <= items[1].getPriority() ) {
                Request temp = items[0];
                items[0] = items[2];
                items[2] = temp;
            }
        }else if(items[0].getPriority()== items[1].getPriority() && items[0].getSendingTime()<items[1].getSendingTime() ){
            if(items[1].getSendingTime() <= items[2].getSendingTime() && items[1].getPriority() <= items[2].getPriority() ) {
                Request temp = items[0];
                items[0] = items[1];
                items[1] = temp;
            }
        }
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }
}

void Heap::heapRebuild(int root) {
    int child = 2 * root + 1;    // index of root's left child, if any
    if (child < size) {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;    // index of a right child, if any
        // If root has right child, find larger child
        if ((rightChild < size) &&
            (items[rightChild].getPriority() > items[child].getPriority()))
            child = rightChild;    // index of larger child

        // If root’s item is smaller than larger child, swap values
        if (items[root].getPriority() < items[child].getPriority()) {
            Request temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}
