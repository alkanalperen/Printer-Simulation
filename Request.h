/*
 * Title: Heaps
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 3
 * Description: main
 */

#ifndef HW3_REQUEST_H
#define HW3_REQUEST_H


class Request {
public:
    Request();
    int getId();
    int getPriority();
    int getSendingTime();
    int getProcessingTime();
    void setId(int id);
    void setPriority(int priority);
    void setSendingTime(int sendingTime);
    void setProcessingTime(int processingTime);
private:
    int id;
    int priority;
    int sendingTime;
    int processingTime;
};


#endif //HW3_REQUEST_H
