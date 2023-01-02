/*
 * File: BinaryEncoding.cpp
 * ------------------------
 * Starter file for the binary encoding problem on Assignment #3.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include<math.h>


/* Function prototypes */

void generateBinaryCode(int nBits);

/* Main program */

int A[100];
int N;
int main() {
   int nBits = getInteger("Number of bits: ");
   N=nBits;
   generateBinaryCode(nBits);
   
   std::cout << std::endl << std::endl;
   generateBinary("", nBits);
   
   return 0;
}

/*
 * Function: generateBinaryCode
 * Usage: generateBinaryCode(nBits);
 * ---------------------------------
 * Lists all the binary values containing the specified number of bits.
 */

void generateBinaryCode(int nBits) {
   // Fill this in
if(nBits<=0){
    int k;
    for(int i=N-1;i>-1;i--){
        k=A[i];
        std::cout<<k;

    }std::cout<<std::endl;
}else{
    A[nBits-1]=0;
    generateBinaryCode(nBits-1);
    A[nBits-1]=1;
    generateBinaryCode(nBits-1);
}

// Added by D. Mangiras
void generateBinary(std::string soFar, int nBits) {
    if (nBits == 0) {
       std::cout << soFar << std::endl;    
    } else {
       generateBinary(soFar + "0", nBits-1);    
       generateBinary(soFar + "1", nBits-1);
    }
}

}
