/*
 * Title: Heaps
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 3
 * Description: main
 */
#include <iostream>
#include "PriorityQueue.h"
using namespace std;
#ifndef HW3_SIMULATOR_H
#define HW3_SIMULATOR_H


class simulator {
public:
    simulator(); //default  constructor
    simulator(string fileName, int maxAvTime);// const
    void simulate(int maxAvTime);


private:
    PriorityQueue priorityQueue;// to store request that are waiting for a printer
    Request items[MAX_HEAP];// array of heap items
    int requestNU;
    int sizeAll;
};


#endif //HW3_SIMULATOR_H
