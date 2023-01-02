/*
 * File: pqueue.cpp (linked-list version)
 * --------------------------------------
 * value: [TODO: enter value here]
 * Section: [TODO: enter section leader here]
 * This file implements the pqueue.h interface using a linked list as the
 * underlying representation.  Only the copy constructor and assignment
 * operator are included.  Your job is to include definitions for the
 * other exported methods.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include "error.h"
#include "pqueue.h"
using namespace std;

// TODO: Add your method definitions here

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * The constructor and assignment operators follow a standard paradigm,
 * as described in the textbook.
 */
PriorityQueue::PriorityQueue(){
    list = NULL;

}

PriorityQueue::~PriorityQueue(){
    delete list;
}

bool PriorityQueue::isEmpty(){
    bool flag=0;

    if(list == NULL){
        flag=1;
    }
        return flag;

}

void PriorityQueue::enqueue(std::string value, double priority){

    Entry *next_high,*previous_low_,*newOne;
    newOne = new Entry;
    newOne->value = value;
    newOne->priority = priority;
    if(list == NULL){

        newOne->next = list;
        list=newOne;
    }else {

        if(list->priority < priority){
            next_high=list;
            previous_low_=list;
            while (next_high->priority < priority) {
                previous_low_=next_high;
                next_high=next_high->next;
                if (next_high == NULL){
                    break;
                }
            }
            newOne->next=next_high;
            previous_low_->next=newOne;
        }else {
            newOne->next = list;
            list=newOne;

        }



    }
}

string PriorityQueue::dequeue(){
    string deq="Queue is empty ";
    if(list != NULL){
        Entry *temp;
        temp = list;
        deq = list->value;
        list = list->next;
        delete temp;

    }
    return deq;
}

// we need this function to deallocate memory because if we
// just delete list we will have orphaned memory
void Deallocate(Entry *list){
    if(list!=NULL){
        //Entry *next=list->next; // we could do this and keep delete before deallocate or do it recursively
        // delete list;
        // Deallocate (next);
        Deallocate(list->next); //here its done recursively first deletes the first we put in and then continues (first to last)
        delete list;


    }
}

void PriorityQueue::clear(){
    Deallocate(list);
    list=NULL;

}
//function that counts recursively
/*
does not work
*/int Count(Entry *list){
    if(list==NULL) return 0;
    return 1+Count(list->next);
}

int PriorityQueue::size(){

    return Count(list);


}

string PriorityQueue::peek(){ // might not work
    string peeked_value= "Queue is empty";
    if(!isEmpty()){
       peeked_value = list->value;
    }
    return peeked_value;
}

double PriorityQueue::peekPriority(){
    double peeked_priority= -1; //not sure of -1 use
    if(!isEmpty()){
       peeked_priority = list->priority;
    }
    return peeked_priority;
}



PriorityQueue::PriorityQueue(const PriorityQueue & src) {
   deepCopy(src);
}

PriorityQueue & PriorityQueue::operator=(const PriorityQueue & src) {
   if (this != &src) {
      clear();
      deepCopy(src);
   }
   return *this;
}
