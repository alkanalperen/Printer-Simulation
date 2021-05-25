/*
 * Title: Heaps
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 3
 * Description: main
 */
#include "simulator.h"
#include "Request.h"
#include "Printer.h"
#include <fstream>
#include <string>
#include <sstream>

simulator::simulator(string fileName, int maxAvTime) {
    ifstream file(fileName);
    string str;
    string line;

    int num;

    getline(file, str);
    requestNU = stoi(str);

    int counter = 0;
    while (getline(file, line, '\n') && counter < requestNU) {
        istringstream stringLine(line);
        Request *a = new Request();
        getline(stringLine, str, ' ');
        int id = stoi(str);
        getline(stringLine, str, ' ');
        int priority = stoi(str);
        getline(stringLine, str, ' ');
        int sendingTime = stoi(str);
        getline(stringLine, str, ' ');
        int processingTime = stoi(str);

        a->setId(id);
        a->setPriority(priority);
        a->setSendingTime(sendingTime);
        a->setProcessingTime(processingTime);

        items[counter] = *a;
        counter++;
        delete a;
    }
    sizeAll = counter;
    simulate(maxAvTime);
}
void simulator::simulate(int maxAvTime){
    //initiliaze the time and variables
    int time = 0;
    double sumWait = 0;
    double avgTime = 0;
    int n = 0;
    int printerNU = 1;
    string s = "";
    //create first printer
    Printer *printer;
    printer = new Printer();
    while (true) {
        for( int i = 0; i < sizeAll; i++) {
            //when sending times comes add to pq
            if (items[i].getSendingTime() == time) {
                priorityQueue.pqInsert(items[i]);
            }
        }
        for( int i = sizeAll; i > 0; i--) {
            for(int j = 0; j < printerNU; j++ ) {
                if (items[i].getSendingTime() <= time && printer[j].getReady()) {
                    n++;
                    Request a;
                    priorityQueue.pqDelete(a);
                    s +=  "Printer" + to_string(j) + " prints request " + to_string(a.getId()) + " at minute " + to_string(time) ;
                    printer[j].setStartTime(time);
                    printer[j].setEndTime(a.getProcessingTime() + printer[j].getStartTime());
                    int waitTime = printer[j].getStartTime() - a.getSendingTime();
                    sumWait += waitTime;
                    s+= " (wait : " + to_string(waitTime) + " mins) \n" ;
                    printer[j].setReady(false);

                }
                if (printer[j].getEndTime() == time) {
                    printer[j].setReady(true);
                }
            }
        }
        if(n==requestNU) {
            avgTime = sumWait / requestNU;
            if (avgTime <= maxAvTime) {
                cout << "\nMinimum number of printer = "<< printerNU<< endl;
                cout << "\nSimulation with " << printerNU << "printer:  \n" << endl;
                cout << s <<endl;
                cout<<"Average waiting time: " << avgTime<< " mins"<<endl;
                delete[] printer;
                break;
            }
            else{
                s = "";
                printerNU++;
                delete[] printer;
                printer = new Printer[printerNU];
                sumWait = 0;
                //get into loop again
                n = 0;
                time  = 0;
            }
        }
        time++;
    }
}