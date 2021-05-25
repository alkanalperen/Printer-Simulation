/*
 * Title: Heaps
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 3
 * Description: main
 */
#include "Request.h"
Request::Request() {
    id=0;
    priority=0;
    processingTime=0;
    sendingTime=0;
}
int Request::getId() {return id;}
int Request::getPriority() {return priority;}
int Request::getProcessingTime() {return processingTime;}
int Request::getSendingTime() {return sendingTime;}
void Request::setId(int id){ this->id = id;}
void Request::setPriority(int priority) { this->priority=priority;}
void Request::setProcessingTime(int processingTime) {this->processingTime=processingTime;}
void Request::setSendingTime(int sendingTime) { this->sendingTime=sendingTime;}