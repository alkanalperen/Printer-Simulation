/*
 * Title: Heaps
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 3
 * Description: main
 */
#include "Printer.h"
Printer::Printer(){
    startTime = 0;
    endTime = 0;
    request = Request();
    ready = true;
}
Printer::Printer(int startTime, int endTime, Request request) {
    this->startTime = startTime;
    this->endTime = endTime;
    this->request = request;
}
int Printer::getEndTime(){
    return endTime;
}
void Printer::setEndTime(int time) {
    endTime = time;
}
void Printer::calculateEndTime() {
    endTime = startTime + request.getProcessingTime();
}

int Printer::getStartTime() const {
    return startTime;
}

void Printer::setStartTime(int startTime) {
    Printer::startTime = startTime;
}

const Request &Printer::getRequest() const {
    return request;
}

void Printer::setRequest(const Request &request) {
    Printer::request = request;
}
bool Printer::getReady() {
    return ready;
}
void Printer::setReady(bool b) {
    ready = b;
}


