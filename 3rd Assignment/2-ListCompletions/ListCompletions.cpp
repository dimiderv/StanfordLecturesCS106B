/*
 * File: ListCompletions.cpp
 * -------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the cell phone mind-reading problem
 * from Assignment #3
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "lexicon.h"

using namespace  std;
/* Function prototypes */

void listCompletions(std:: string all_digits, Lexicon & lexicon);
void numbers_to_words(std:: string numbers, std:: string words, Lexicon & lexicon);
void ListOfWords(std:: string list_of_words,Lexicon & lexicon);
/* Main program */

int main() {
   Lexicon english("EnglishWords.dat");
  std:: cout << "Cell phone mind-reading problem" << std::endl;
   while (true) {
      std:: cout << "Enter a set of all_digits: ";
      std:: string all_digits = getLine();
      if (all_digits == "" || all_digits == "quit") break;
      std:: cout << "The words beginning with those all_digits are:" << std:: endl;
      listCompletions(all_digits, english);
   }
   return 0;
}

/*
 * Function: listCompletions
 * Usage: listCompletions(all_digits, lexicon);
 * ----------------------------------------
 * Lists all the words in the lexicon that begin with the letters
 * corresponding to the specified all_digits on a telephone keypad.
 */

void listCompletions(std:: string all_digits, Lexicon & lexicon) {
   numbers_to_words(all_digits,"", lexicon );
}

void numbers_to_words(std:: string numbers, std:: string words, Lexicon & lexicon){
    if(numbers.length()>0){
            char current_number=numbers[0];
            char next_letter;
            string next_word,next_number;

            switch (current_number) {

            case '2':

                for(int i=0;i<=2;i++){
                    next_word=words;
                    next_letter = 97 +i;
                    next_word += next_letter;
                    if(lexicon.containsPrefix(next_word)){
                        next_number=numbers.substr(1);
                        numbers_to_words(next_number,next_word,lexicon);
                    }

                }
                break;
            case '3':
                for(int i=0;i<=2;i++){
                    next_letter = 100 +i;
                    next_word=words;
                    next_word+= next_letter;
                    if(lexicon.containsPrefix(next_word)){
                        next_number=numbers.substr(1);
                        numbers_to_words(next_number,next_word,lexicon);
                    }

                }
                break;

            case '4':
                for(int i=0;i<=2;i++){
                    next_letter = 103 +i;
                    next_word=words;
                    next_word+= next_letter;
                    if(lexicon.containsPrefix(next_word)){
                        next_number=numbers.substr(1);
                        numbers_to_words(next_number,next_word,lexicon);
                    }

                }
                break;
            case '5':

                for(int i=0;i<=2;i++){
                    next_letter = 106 +i;
                    next_word=words;
                    next_word+= next_letter;
                    if(lexicon.containsPrefix(next_word)){
                        next_number=numbers.substr(1);
                        numbers_to_words(next_number,next_word,lexicon);
                    }

                }
                break;

            case '6':
                for(int i=0;i<=2;i++){
                    next_letter = 109 +i;
                    next_word=words;
                    next_word+= next_letter;
                    if(lexicon.containsPrefix(next_word)){
                        next_number=numbers.substr(1);
                        numbers_to_words(next_number,next_word,lexicon);
                    }

                }
                break;

            case '7':
                for(int i=0;i<=3;i++){
                    next_letter = 112 +i;
                    next_word=words;
                    next_word+= next_letter;
                    if(lexicon.containsPrefix(next_word)){
                        next_number=numbers.substr(1);
                        numbers_to_words(next_number,next_word,lexicon);
                    }

                }
                break;

            case '8':
                for(int i=0;i<=2;i++){
                    next_letter = 116 +i;
                    next_word=words;
                    next_word+= next_letter;
                    if(lexicon.containsPrefix(next_word)){
                        next_number=numbers.substr(1);
                        numbers_to_words(next_number,next_word,lexicon);
                    }

                }
                break;

            case '9':
                for(int i=0;i<=3;i++){
                    next_letter = 119 +i;
                    next_word=words;
                    next_word+= next_letter;
                    if(lexicon.containsPrefix(next_word)){
                        next_number=numbers.substr(1);
                        numbers_to_words(next_number,next_word,lexicon);
                    }

                }

            break;
            }
        }else{

            ListOfWords(words,lexicon);
        }
}

void ListOfWords(std:: string list_of_words,Lexicon & lexicon){
    if(lexicon.contains(list_of_words)){

        std::cout <<list_of_words<< std::endl;
    }
    std::string next_list;
    char next_letter;
    for(int i=0;i<26;i++){
        next_list = list_of_words;
        next_letter = 97+i;
        next_list += next_letter;
        if(lexicon.containsPrefix(next_list)){
            ListOfWords(next_list,lexicon);
        }
    }
}
