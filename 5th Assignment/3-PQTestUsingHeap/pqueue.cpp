/*
 * File: pqueue.cpp (heap version)
 * -------------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file implements the pqueue.h interface using a heap as the
 * underlying representation.  Only the copy constructor and assignment
 * operator are included.  Your job is to include definitions for the
 * other exported methods and to make a change to the definition of the
 * assignment operator so that it deletes any old storage.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include "error.h"
#include "pqueue.h"
using namespace std;

// TODO: Add your method definitions here

PriorityQueue::PriorityQueue(){
    list = new Entry[INITIAL_CAPACITY];
    last_node = 0;
    Capacity = 10;
}

PriorityQueue::~PriorityQueue(){
    delete [] list;
}

bool PriorityQueue::isEmpty(){
    bool flag=0;
    if(last_node==0){
        flag=1;
    }
    return flag ;
}

int PriorityQueue::size(){
    return last_node; //might have to start node from -1
}

void PriorityQueue::clear(){
    delete[] list;
    list = new Entry[INITIAL_CAPACITY];
    last_node = 0;
}

double PriorityQueue:: peekPriority(){
    double peeked_priority = -1; // not sure if it works
    if(last_node!=0){
        peeked_priority = list[0].priority;
    }
    return peeked_priority;
}


string PriorityQueue::peek(){
    string peeked_value="Queue is empty \n";
    if(last_node!=0){
        peeked_value = list[0].value;//i tried to use -> was automatically converted
    }
    return peeked_value;
}

void PriorityQueue::enqueue(std::string value, double priority){
    if(Capacity==last_node){
        expandCapacity(); // i might have to change it
    }

    Entry newOne,temp_Entry;
    int inserted_node_index = last_node;
    int parent = (last_node-1)/2;
    newOne.value = value;
    newOne.priority = priority;
    list[last_node] = newOne;

    if(last_node !=0){
        while(list[parent].priority > priority){

            temp_Entry = list [parent];
            list[parent] = list[inserted_node_index];
            list[inserted_node_index] = temp_Entry;

            inserted_node_index = parent ; //the new node takes parents place
            parent = (inserted_node_index-1)/2 ; //the parent as we see from Chapter 16.5 CS106BX

        }

    }


    last_node ++;

}

string PriorityQueue::dequeue(){
    string out="The queue is empty";
        Entry temp;
        int min_node;
        int parent=0,leftChild=1,right_child=2;
        if(last_node!=0){
            out = list[0].value;
            last_node--;

            list[0] = list[last_node];

                while ((last_node > 1) && (list[parent].priority > list[leftChild].priority || list[parent].priority > list[right_child].priority)) {

                        if(list[leftChild].priority <= list[right_child].priority){
                            min_node = leftChild;
                        }else {
                            min_node = right_child;
                        }
                        temp = list[parent];
                        list[parent] = list[min_node];
                        list[min_node] = temp;

                        parent = min_node;
                        leftChild = (2 * parent) + 1;
                        right_child = leftChild + 1;


                    if(right_child> last_node) break;


            }
        }


        return out;
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * The constructor and assignment operators follow a standard paradigm,
 * as described in the textbook.
 */

PriorityQueue::PriorityQueue(const PriorityQueue & src) {
   deepCopy(src);
}

PriorityQueue & PriorityQueue::operator=(const PriorityQueue & src) {
   if (this != &src) {
      // TODO: Include code to delete any data from the old queue
      deepCopy(src);
   }
   return *this;
}
