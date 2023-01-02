/*
 * File: statement.cpp
 * -------------------
 * This file implements the constructor and destructor for
 * the Statement class itself.  Your implementation must do
 * the same for the subclasses you define for each of the
 * BASIC statements.
 */

#include <string>
#include "statement.h"
#include "parser.h"
#include "simpio.h"
using namespace std;

/* Implementation of the Statement class */

Statement::Statement() {
   /* Empty */
}

Statement::~Statement() {
   /* Empty */
}

PrintStmt::PrintStmt(TokenScanner & scanner) {
    expression = readE(scanner, 0);
    if (scanner.hasMoreTokens()) {
    error("Extraneous token " + scanner.nextToken());
    }
}

PrintStmt::~PrintStmt() {
    delete expression;
}

void PrintStmt::execute(EvalState & context) {
    cout << expression->eval(context) << endl;
};

Letstmt::Letstmt(TokenScanner &scanner){
  variable_name= scanner.nextToken();
  scanner.nextToken();
  expression = readE(scanner,0);
  if(scanner.hasMoreTokens()) {
      error(("Extraneous token " + scanner.nextToken()));
  }

};

Letstmt::~Letstmt(){
  delete expression;
};

void Letstmt::execute(EvalState &context){
  context.setValue(variable_name,expression->eval(context));
//not sure if it will work
};


Inputstmt::Inputstmt(TokenScanner &scanner){
  variable_name = scanner.nextToken();
  if(scanner.hasMoreTokens()) {
      error(("Extraneous token " + scanner.nextToken()));
  }
};


void Inputstmt::execute(EvalState &context){
    int insert_value;
    cout<<" ?"<<endl;
    cin>>insert_value;
    context.setValue(variable_name,insert_value);

};

Remstmt:: Remstmt(TokenScanner &scanner){
       while(scanner.hasMoreTokens()){
           comment_line= comment_line +" "+ scanner.nextToken();
       }
};

void Remstmt::execute(EvalState &context){
};



Gotostmt::Gotostmt(TokenScanner &scanner){
    go_to_line = stringToInteger(scanner.nextToken());
    if(scanner.hasMoreTokens()) {
        error(("Extraneous token " + scanner.nextToken()));
    }
};

void Gotostmt::execute(EvalState &context){
    context.current_line = go_to_line;
    context.control_statement = true;
    context.end_of_code=false;
};
//changed here
Ifstmt::Ifstmt(TokenScanner &scanner){
    expression = readE(scanner,0);
	/*
    if(scanner.nextToken()=="THEN"){
        then_line = stringToInteger(scanner.nextToken());
    }
	*/
	scanner.nextToken();
	then_line= stringToInteger(scanner.nextToken());


    if(scanner.hasMoreTokens()) {
        error(("Extraneous token " + scanner.nextToken()));
    }
}

Ifstmt::~Ifstmt(){
    delete expression;
}
//might be wrong here 
void Ifstmt::execute(EvalState &context){
    bool activate_if=expression->eval(context);
	
    if(expression->eval(context) == true){
        
        context.current_line= then_line;
        context.control_statement = true;
    }	
   /*
   if(activate_if){
        context.current_line= then_line;
        context.control_statement = true;
    }
	*/
}

Endstmt::Endstmt(TokenScanner &scanner){
    last_line=true;

}


void Endstmt::execute(EvalState &context){

    context.control_statement = true;
    context.end_of_code = true;
	
}
