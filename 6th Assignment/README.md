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

&emsp; * REM This statement is used for comments. Any text on the line after the keyword 
REM is ignored.  
&emsp; * LET This statement is BASIC’s assignment statement. The LET keyword is 
followed by a variable name, an equal sign, and an expression. As in C++, the 
effect of this statement is to assign the value of the expression to the variable, 
replacing any previous value. In BASIC, assignment is not an operator and 
may not be nested inside other expressions.  
&emsp; * PRINT In minimal BASIC, the PRINT statement has the form:  
PRINT exp where exp is an expression. The effect of this statement is to print the value of 
the expression on the console and then print a newline character so that the 
output from the next PRINT statement begins on a new line.  
&emsp; * INPUT In the minimal version of the BASIC interpreter, the INPUT statement has the 
form: INPUT var where var is a variable read in from the user. The effect of this statement is to 
print a prompt consisting of the string " ? " and then to read in a value to be 
stored in the variable.
&emsp; * GOTO This statement has the syntax
GOTO n and forces an unconditional change in the control flow of the program. When 
the program hits this statement, the program continues from line n instead of 
continuing with the next statement. Your program should report an error if 
line n does not exist.
&emsp; * IF This statement provides conditional control. The syntax for this statement is:
IF exp1 op exp2 THEN n where exp1 and exp2 are expressions and op is one of the conditional operators 
=, <, or >. If the condition holds, the program should continue from line n just 
as in the GOTO statement. If not, the program continues on to the next line.
&emsp; * END Marks the end of the program. Execution halts when this line is reached. This 
statement is usually optional in BASIC programs because execution also stops 
if the program continues past the last numbered line.


