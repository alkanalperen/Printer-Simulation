/*
 * Title: Heaps
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 3
 * Description: main
 */

#ifndef HW3_PRINTER_H
#define HW3_PRINTER_H


#include "Request.h"
#include <iostream>
class Printer {
public:
    Printer();
    Printer(int startTime,int endTime, Request request);

    Printer(const Printer & printer);

    int getEndTime();
    void setEndTime(int time);
    int getStartTime() const;
    void setStartTime(int startTime);
    const Request &getRequest() const;
    void setRequest(const Request &request);
    bool getReady();
    void setReady(bool ready);
    void calculateEndTime();
private:
    int startTime;
    int endTime;
    Request request;
    bool ready;
};


#endif //HW3_PRINTER_H
