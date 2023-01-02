/*
 * File: pqueue.cpp (array version)
 * --------------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file implements the pqueue.h interface using a dynamic array as
 * the underlying representation.  Most of the code is already in place.
 * The only thing that is missing is the implementation of the actual
 * commands.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include "error.h"
#include "pqueue.h"
using namespace std;

PriorityQueue::PriorityQueue() {
    input = new string[initial_size];
    Priority = new double[initial_size];
    start=end=0;
}

PriorityQueue::~PriorityQueue() {
   delete[] input;
   delete[] Priority;
}

int PriorityQueue::size() {

   return end-start;
}

bool PriorityQueue::isEmpty() {
   if(start!=end)return  false;
   return true;
}

void PriorityQueue::clear() {
   delete[] input;
    delete [] Priority;
    input = new string[initial_size];
    Priority = new double[initial_size];
    start=end=0;
    //PriorityQueue()

}

void PriorityQueue::enqueue(string value, double priority) {
   if(end==initial_size){
       expandCapacity();
   }
    if(end==0){
        input[end]=value;
        Priority[end]=priority;
    }else{



        int insert_index=end-1;
        while(Priority[insert_index]>priority ){
            input[insert_index+1]=input[insert_index];
            Priority[insert_index+1]=Priority[insert_index];

            insert_index--;
            if(insert_index<0)break;

        }
        input[insert_index+1]=value;
        Priority[insert_index+1]=priority;

    }
    end++;
}

string PriorityQueue::dequeue() {
   string dequeued_value="Empty queue \n";
   if(end!=0){
        dequeued_value= input[0];
        end--;
        int i=0;
        while(i<end){//not sure
            input[i]= input[i+1];
            Priority[i]= Priority[i+1];
            i++;
       }
   }

    return dequeued_value;
}

string PriorityQueue::peek() {
  string peeked_value ="Empty queue \n";
  if(end!=0){
    peeked_value=input[0];
  }
    return peeked_value;  // TODO: Replace this line with the necessary code
}

double PriorityQueue::peekPriority() {
   double peeked_priority=-1;

   if(end==0){
    cout<<"Empy queue"<<endl;
   }else{
    peeked_priority= Priority[0];
   }
    return peeked_priority;  // TODO: Replace this line with the necessary code
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * The constructor and assignment operators follow the standard
 * paradigm described in the textbook.
 */

PriorityQueue::PriorityQueue(const PriorityQueue & src) {
   deepCopy(src);
}

PriorityQueue & PriorityQueue::operator=(const PriorityQueue & src) {
   if (this != &src) {
      if (array != NULL) delete[] array;
      deepCopy(src);
   }
   return *this;
}
