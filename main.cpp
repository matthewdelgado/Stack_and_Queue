// Matthew Delgado
// ECE 2552 Section 3
// Chapter 5 - Shared Printer
// 02-16-2022

#include "SharedPrinter.hpp"

void RUN(){
    Printer<5> printer;
    Job j1("John", 10);
    Job j2("Jerry", 4);
    Job j3("Jimmy", 5);
    Job j4("George", 7);
    Job j5("Bill", 8);
    Job j6("Kenny", 10);
    printer.addNewJob(j1);
    printer.addNewJob(j2);
    printer.addNewJob(j3);
    printer.addNewJob(j4);
    printer.addNewJob(j5);
    if (not printer.addNewJob(j6)) // Can't add as queue is full.
    {
       std::cout << "Couldn't add 6th job" << std::endl;
    }
    printer.startPrinting();
    printer.addNewJob(j6); // Can add now, as queue got emptied
    printer.startPrinting();
}

int main(){
    RUN();
    return EXIT_SUCCESS;
}
