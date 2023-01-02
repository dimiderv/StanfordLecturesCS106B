/*
 * File: Basic.cpp
 * ---------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the BASIC interpreter from
 * Assignment #6.
 * [TODO: extend and correct the documentation]
 */

#include <cctype>
#include <iostream>
#include <string>
#include "console.h"
#include "exp.h"
#include "parser.h"
#include "program.h"
#include "tokenscanner.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

void processLine(string line, Program & program, EvalState & state);

/* Main program */

int main() {
   EvalState context;
   Program program;
   string line;
   cout << "Stub implementation of BASIC" << endl;
   while (true) {
      try {
         line=getLine();
         processLine(toUpperCase(line), program, context);
      } catch (ErrorException & ex) {
         cerr << "Error: " << ex.getMessage() << endl;
      }
   }
   return 0;
}

/*
 * Function: processLine
 * Usage: processLine(line, program, state);
 * -----------------------------------------
 * Processes a single line entered by the user.  In this version,
 * the implementation does exactly what the interpreter program
 * does in Chapter 19: read a line, parse it as an expression,
 * and then print the result.  In your implementation, you will
 * need to replace this method with one that can respond correctly
 * when the user enters a program line (which begins with a number)
 * or one of the BASIC commands, such as LIST or RUN.
 */

void processLine(string line, Program & program, EvalState & context) {
   TokenScanner scanner;
   scanner.ignoreWhitespace();
   scanner.scanNumbers();
   scanner.setInput(line);
  // Expression *exp = parseExp(scanner);
   string token ;
   string next_token;
   Statement *stmt=NULL;
   token = scanner.nextToken();


   if(scanner.getTokenType(token)==WORD){

       if(token=="LIST" || token =="list"){
            int list_line = program.getFirstLineNumber();
            while(list_line != -1){
                //it works
                cout<< program.getSourceLine(list_line);
                list_line = program.getNextLineNumber(list_line);

            }

       }else if(token=="LET" || token == "let"){

           next_token=scanner.nextToken();
           scanner.nextToken();
           Expression *expression = readE(scanner,0); // not sure
           context.setValue(next_token,expression->eval(context));
           //scanner.nextToken() might be wrong
           delete expression;

       } else if(token=="PRINT" || token =="print"){

           Expression *expression =readE(scanner,0);
           cout<<expression->eval(context);//shows value
           delete expression;

       } else if(token =="clear" || token =="CLEAR"){

           program.clear();
		   context.end_of_code = false;

       } else if(token=="INPUT" || token =="input" ){
           next_token=scanner.nextToken();
           int input_value;
           cout<<" ?";
           cin >> input_value;
           cout<<endl;
           context.setValue(next_token,input_value);
       } else if(token=="QUIT" || token =="quit"){

           exit(0);

       } else if(token== "run" || token == "RUN"){
          // might need Statement variable


            context.current_line = program.getFirstLineNumber();


            while(context.end_of_code!= true && context.current_line!=-1){
                stmt = program.getParsedStatement(context.current_line);
                stmt->execute(context);
                if(context.control_statement){
                    context.control_statement=false;
                    stmt = program.getParsedStatement(context.current_line);
                    stmt->execute(context);

                }

                context.current_line=program.getNextLineNumber(context.current_line);

            }
            context.end_of_code = false;




       } else{
           error("Undifiened command" + token);
       }


   }else if(scanner.getTokenType(token)==NUMBER){
       next_token=scanner.nextToken();
       int code_num=stringToInteger(token);

       if(next_token != ""){

           program.addSourceLine(code_num,line);
           scanner.saveToken(next_token);

           stmt = ParseStatement(scanner);
           program.setParsedStatement(code_num,stmt);
       }else{
           program.removeSourceLine(code_num);
       }

   }else{
        //error("Undifiened command" + token);
   }

}
