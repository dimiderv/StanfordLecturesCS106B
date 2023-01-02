/*
 * File: PQTest.cpp
 * ----------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This is the starter file for the test program for Assignment #5.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include "pqueue.h"
#include "simpio.h"
#include "strlib.h"
#include "tokenscanner.h"
using namespace std;

/* Function prototypes */

void helpCommand();

/* Main program */

int main() {
   PriorityQueue pq;
   string value;
     string priority_num;
     double priority;
     while (true) {

        string cmd = getLine("> ");
        string enqueue_inputs;
        string cmd_enqueue= cmd.substr(0,7);

        if (cmd == "help") {

            helpCommand();

        }else if (cmd_enqueue == "enqueue") {
            enqueue_inputs = cmd.substr(8,cmd.size()-1);

            int i=0;
            while(enqueue_inputs[i] != ' '){//could use token scanner
              i++;
            }
              value = enqueue_inputs.substr(0,i);

              priority_num = enqueue_inputs.substr( i+1, enqueue_inputs.size()-1);

              priority = stringToDouble( priority_num );

              pq.enqueue(value,priority);



        }else if(cmd == "dequeue") {

            cout<<pq.dequeue()<<endl;

        }else if(cmd == "peek") {

            cout<< pq.peek() <<endl;

        }else if(cmd == "peekPriority") {

            cout<<pq.peekPriority()<<endl;

        }else if(cmd == "clear") {

            pq.clear();

        }else if(cmd == "size") {

            cout<<pq.size()<<endl;

        }else if(cmd == "isEmpty") {

            if(pq.isEmpty()){
                cout<<"true"<<endl;
            }else {
                cout<<"false"<<endl;
            }

        }else if(cmd == "list"){


              Entry * next_Entry=pq.list;
              while(next_Entry !=NULL ){
                  cout<<next_Entry->value<<" ";
                  next_Entry = next_Entry ->next;

              }
              cout <<endl;


        }else {
           cout << "Undefined command: " << cmd << endl;
        }
     }
     return 0;
  }

/*
 * Function: helpCommand
 * ---------------------
 * Displays a list of the required commands.  If you extend this program,
 * you should add new entries to this function.
 */

void helpCommand() {
   cout << "enqueue value priority -- Enqueues value at priority" << endl;
   cout << "dequeue -- Dequeues the most urgent item" << endl;
   cout << "peek -- Peeks at the first item without removing it" << endl;
   cout << "peekPriority -- Reports the priority of the first item" << endl;
   cout << "clear -- Clears the queue" << endl;
   cout << "size -- Reports the size of the queue" << endl;
   cout << "isEmpty -- Reports whether the queue is empty" << endl;
   cout << "list -- Lists the elements of the queue" << endl;
   cout << "help -- Prints this message" << endl;
}
