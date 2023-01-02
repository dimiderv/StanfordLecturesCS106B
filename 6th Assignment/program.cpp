/*
 * File: program.cpp
 * -----------------
 * This file is a stub implementation of the program.h interface
 * in which none of the methods do anything beyond returning a
 * value of the correct type.  Your job is to fill in the bodies
 * of each of these methods with an implementation that satisfies
 * the performance guarantees specified in the assignment.
 */

#include <string>
#include "program.h"
#include "statement.h"
using namespace std;

Program::Program() {
  list = new Entry[initial_size];
  end=0;
}

Program::~Program() {
  delete [] list;

}

void Program::clear() {
    delete [] list;
    list = new Entry[initial_size];
    end=0;
	
}

void Program::addSourceLine(int lineNumber, string line/*=""*/) {
   //might need to check the inital capacity
   //previous assignment expandcap();
	


        int insert_index = end -1;
        bool exists=0;// i change here
        for (int i = 0; i<=insert_index;i++){//might not need
            // we have to check if the line has to be replaced
            if(list[i].code_number == lineNumber){
                list[i].code_line = line;
                list[i].statement = NULL; //not sure
                exists=1;
                break;

            }
        }
        //if the line already exists this is not needed
        if(!exists){
            while(list[insert_index].code_number > lineNumber){
                list[insert_index+1] = list [insert_index];
                insert_index--;
                if(insert_index<0) break;

            }

        }
		list[insert_index+1].code_number = lineNumber;
        list[insert_index+1].code_line = line;
        list[insert_index+1].statement = NULL; // not sure
            //could initialize it as NULL
            
		end++;
    

}

void Program::removeSourceLine(int lineNumber) {

	int insert_index = end -1;
    bool exists=0;
    for (int i = 0; i<=insert_index;i++){ // changed =
        // we have to check if the line has to be replaced
        if(list[i].code_number == lineNumber){
           // might not be needed cause of remove source line
                 exists=1;
                for(int j=i;j<=insert_index - 1;j++){//change =
                        list[j] =list[j+1];
                 //not entirely correct i have to delete the Entry
                 //else if i delete a line
                 // that Entry still exists in my memory
                 // could try copying entire list of entries
                 //(overload = or deep copy)
                }
                end--;

        }
    }
    if(!exists){
        cout<< " The line does not exist "<<endl;
    }
}

string Program::getSourceLine(int lineNumber) {
    string source_line="";
    for(int i=0; i <= end-1;i++){
        if(list[i].code_number==lineNumber){
            source_line = list[i].code_line;
            break;
        }
    }
   return source_line;

}

void Program::setParsedStatement(int lineNumber, Statement *stmt) {

   bool exists=0;
    for(int i =0 ; i<=end-1;i++){
       if(list[i].code_number==lineNumber){
           list[i].statement =stmt;
           exists=1;
           break;
       }
   }
    if(!exists){
        cout<< "line "<< lineNumber <<" does not exist"<<endl;
    }
}

Statement *Program::getParsedStatement(int lineNumber) {
    Statement *temp=NULL;
    bool exists=0;
    for(int i =0 ; i<=end-1;i++){
       if(list[i].code_number!=lineNumber){
           continue;
       }
       temp=list[i].statement;
       exists=1;
       break;
   }
    if(!exists){
        cout<< "line "<< lineNumber <<" does not exist"<<endl;
    }
    return temp;


}

int Program::getFirstLineNumber() {
   int first_line=-1;
   if(end!=0){
       first_line=list[0].code_number;
   }
   return first_line;
}

int Program::getNextLineNumber(int lineNumber) {
    int next_line=-1;
    for(int i =0 ; i<=end-2;i++){
       if(list[i].code_number!=lineNumber){
           continue;
       }
       next_line=list[i+1].code_number;
       break;
   }

    return next_line;
}
