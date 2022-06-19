// Matthew Delgado
// ECE 2552 Section 3
// Chapter 5 - Shared Printer
// 02-16-2022
/*
1. Create a class called Job
    a. Data members: comprising an ID for the job, the name of the user who submitted it, and the
    number of pages.
    b. The ID should be increased as a new job is instantiated, use a static data member count
    variable to make the update.
    c. Overload the cout stream operator “<<” that should be used to print information about the
Job class. Print information when the job is added and when the job is being processed. (See
the example results below)
2. Create a template class called Printer. The Printer template parameter should specify the maximum number of jobs and should be type size_T. The Printer class should use a STL <queue> as the internal data structure to store and process jobs. This will provide an interface to add new jobs and process all the jobs added so far.
3. To implement the Printer class, it will need to store all the pending jobs. We will implement a very basic strategy – first come, first served. Whoever submits the job first will be the first to get the job done.
4. Finally, simulate a scenario where multiple people are adding jobs to the printer, and the printer is processing them one by one.
*/

#ifndef SharedPrinter_hpp
#define SharedPrinter_hpp

#include <stdio.h>
#include <iostream>
#include <queue>

class Job{
public:
    // constructors
    Job(){}
    Job(std::string name, unsigned int pages){
        this->name = name;
        this->pages = pages;
        id = 0;
    }
    // get functions to return private member variables
    std::string getName() const { return name; }
    unsigned int getPages() const { return pages; }
    unsigned int getid() { return id; }
    
    void setid(unsigned int id) { this->id = id; }  // set job's ID
    
private:
    unsigned int id;
    std::string name;   // name of user
    unsigned int pages; // number of pages in job
};

template<size_t T>  // templated parinter class takes size_t to declare size of queue
class Printer{
public:
    Printer() : i{1} {} // constructor, printer object keeps track of which ID# to assign per job
    
    bool addNewJob(Job& j){ // add job to printer queue
        if(jobQueue.size() == T)    // printer queue is full
            return false;
        else{
            j.setid(i++);   // set proper ID#
            jobQueue.push(j);   // push to queue
        }
        std::cout << "Added job in the queue: ID: " << j.getid()
                  << ", User: " << j.getName()
                  << ", Number of Pages: " << j.getPages() << std::endl;
        return true;
    }
    
    void startPrinting(){
        while(!jobQueue.empty()){   // do until queue is empty
            std::cout << "Processing job in the queue: ID: " << jobQueue.front().getid()
                      << ", User: " << jobQueue.front().getName()
                      << ", Number of Pages: " << jobQueue.front().getPages() << std::endl;
            jobQueue.pop(); // removes next element and calls object's destructor
        }
    }
    
private:
    std::queue<Job> jobQueue;   // internal STL DS <queue>
    unsigned int i; // id counter, i is incremented when jobs are successfully added to queue
};

#endif /* SharedPrinter_hpp */
