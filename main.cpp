#include <iostream>
#include "simulator.h"
/*
 * Title: Heaps
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 3
 * Description: main
 */
int main(int argc, char **argv) {
    string fileName = argv[1];
    int avTime = atoi(argv[2]);
    simulator s(fileName,avTime);
    return 0;
}
