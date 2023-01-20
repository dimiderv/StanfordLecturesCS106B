# 6th Assignment


In this assignment I had to build a minimal BASIC interpreter. The programming language BASIC ( Beginner's All-purpose Symbolic Instruction Code) was one of the first languages designed to be easy to use and learn. In BASIC, a program consists of a sequence of numbered statements, as illustrated by the simple program below:
<br>

&emsp; 10 REM Program to add two numbers  
&emsp; 20 INPUT n1  
&emsp; 30 INPUT n2  
&emsp; 40 LET total = n1 + n2  
&emsp; 50 PRINT total  
&emsp; 60 END  
<br>

The line numbers at the beginning of the line establish the sequence of operations in a program and are executed in ascending numerical order starting at the lowest number. In this example program execution begins at line 10 which is a comment. Line 20 and 30 request two values from the user and LET statement is an example of an assignment in BASIC. There is no need for statements to be entered in order since the numbers indicate their relative position. Statements implemented in the minimal BASIC:
<br>

*  __REM__, This statement is used for comments.
*  __LET__, This statement is BASIC’s assignment statement.  
*  __PRINT__, The effect of this statement is to print the value of 
the expression on the console and then print a newline character so that the 
output from the next PRINT statement begins on a new line.  
*  __INPUT__, The effect of this statement is to 
print a prompt consisting of the string " ? " and then to read in a value to be 
stored in the variable.
*  __GOTO__, This statement forces an unconditional change in the control flow of the program.  
*  __IF__, This statement provides conditional control.
*  __END__, Marks the end of the program. Execution halts when this line is reached. This statement is usually optional in BASIC programs because execution also stops if the program continues past the last numbered line.
<br>
Commands to control the BASIC interpreter:<br>  
*  __RUN__, This command starts program execution beginning at the lowest-numbered line. Unless the flow is changed by GOTO and IF commands, statements are executed in line-number order. Execution ends when the program hits the END
statement or continues past the last statement in the program.
*  __LIST__, This command lists the steps in the program in numerical sequence.
*  __CLEAR__, This command deletes the program so the user can start entering a new one.
*  __HELP__, This command provides a simple help message describing your interpreter.
*  __QUIT__, Typing QUIT exits from the BASIC interpreter by calling exit(0).
<br>


