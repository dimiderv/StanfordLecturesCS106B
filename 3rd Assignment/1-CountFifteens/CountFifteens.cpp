/*
 * File: CountFifteens.cpp
 * -----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter code for the CountFifteens problem from
 * Assignment #3.
 * [TODO: extend the documentation]
 */

#include <exception>
#include <iostream>
#include <string>
#include "card.h"
#include "console.h"
#include "error.h"
#include "simpio.h"
#include "tokenscanner.h"
#include "vector.h"

/* Function prototypes */

int countFifteens(Vector<Card> & cards);
int all_combinations(int array[],int n,int pairs,int combinations[],int index,int i ,int count);
/*
 * Main program
 * ------------
 * This test program does no error-checking on the input.  One of the
 * extensions you might consider is adding code to this program (and
 * possibly to the Card class) to allow the program to report errors.
 */

int main() {
   while (true) {
     std:: string line = getLine("Enter a hand of cards: ");
      if (line == "") break;
      TokenScanner scanner(line);
      scanner.ignoreWhitespace();
      Vector<Card> hand;
      while (scanner.hasMoreTokens()) {
         hand.add(Card(scanner.nextToken()));
      }
      int nWays = countFifteens(hand);
     std:: string plural = (nWays == 1) ? "" : "s";
     std:: cout << nWays<< " way" << plural << std:: endl;
   }
   return 0;
}

/*
 * Counts the number of ways of making a total of 15 from the vector of
 * cards.
 */

int countFifteens(Vector<Card> & cards) {
    int n=cards.size();
    int array[n];
    int combinations[n];
    for(int j=0;j<n;j++){
        if(cards[j].getRank()>10){
            array[j]=10;
            continue;
        }
        array[j]=cards[j].getRank();
    }
    int pairs=n; //how many pairs for example we start from 5 and go 4,3,2
    int countFifteen=0;

    for(int j=0;j<n-1;j++){
        countFifteen = all_combinations(array,n,pairs-j,combinations,0,0,countFifteen);
    }
    return countFifteen;
}

//this function looks only at pairs that we haven't used before and are single,for example the pair(10,5) is the same as(5,10)
int all_combinations(int array[],int n,int pairs,int combinations[],int index,int i ,int count){
    if (index == pairs )
    {

        int sum=0;
        for (int j=0; j<pairs; j++) {

            sum=sum+combinations[j];
             }



        if(sum==15){
            count=count +1;
            return count;
        }


        return count;
    }
    if(i>=n)
        return count;

   combinations[index]=array[i];
   count=all_combinations(  array,  n,  pairs,  combinations,   index+1,    i+1,    count);
   count=all_combinations(  array,  n,  pairs,  combinations,   index, i+1,count);
    return count;
}

/*
//Added by D. Mangiras
void generateCombinations(std::string soFar, std::string left) {
    if (left == "") {
        if (soFar != "") {
           std::cout << soFar << std::endl;    
        }
    } else {
        std::string new_left = left.substr(1);
        generateCombinations(soFar + left[0], new_left);
        generateCombinations(soFar, new_left);
    }
}

int main() {
  generateCombinations("", "abc");
}
*/

