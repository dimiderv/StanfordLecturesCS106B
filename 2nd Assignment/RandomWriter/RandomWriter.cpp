/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the random writer problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "map.h"
#include "random.h"

#include "vector.h"
#include "filelib.h"




int main()
{
    Map< std:: string,Map < char , int > > Markov;
    Map<  char, int >  Map_of_next_letters;
    std:: ifstream in;
    std:: string key;
    char next_letter;
    std:: string filename;
    std:: string line;
    int seed;                         //order of   Markov chain


    std :: cout << " Give file name (Hamlet.txt,Middlemarch or TomSawyer) "<< std :: endl;

    std :: cin >> filename;



//************checks if file name is valid******************


    while( !fileExists( filename ) ){
        std :: cout<<" Wrong file name,please give file name "<<  std :: endl;
        std :: cin >> filename;
    }

    in.open( filename );

    std :: cout<< " now please give order of Markov(seed value) from 1 to 10 "<< std :: endl;
    std :: cin>> seed;

//*************************************CREATES MARKOV CHAIN************************************************************************//

     //has an error for seed 1 it doesn't detect " " and makes another copy of the same letter could be a problem
     //probably detects next line or EOF
getline( in,line );
key.replace( key.begin() , key.end(), line.begin(), line.begin()+seed );
int boundary;
int i = seed;
while( !in.eof() ){


     boundary = line.length() ;


     while( i < boundary ){


         next_letter = line[ i ];     // i think it gets out of bounds

         if ( Markov.containsKey(key) ){

            Map_of_next_letters = Markov[ key ];
            if ( Map_of_next_letters.containsKey( next_letter ) ){

                Map_of_next_letters[ next_letter ]+=1;

            }else{

                Map_of_next_letters[ next_letter ]=1;

            }

            Markov.add( key, Map_of_next_letters );


         }else{

             Map_of_next_letters.clear();      //deletes all entries
             Map_of_next_letters[ next_letter ] = 1; //creates new string and puts value
             Markov.add( key , Map_of_next_letters ); //adds new map that key creates
         }
         key = key.substr(1,seed - 1); //replace doesn't work correctly
         key = key + next_letter ;
         i++;
         /*key.replace( key.begin() , key.end(), line.begin() +i-2, line.begin()+i  );
         i++;*/
     }

     getline(in,line);
     i=0; // starts from the start of the next line


}
in.close();

//  \000 is the string for nextline or EOF
/************************************END OF MARKOV CHAIN***************************************/

/************************************START PRINTING RESULTS************************************/
//****** first we find the starting word*******//
//****** we need a counter to see how many times a word appears here its sum and when we find a maximum we insert it to max_counter

 Map <std:: string,Map< char, int > >:: iterator itr_Markov_keys;   //iterates though keys of Markov Map
 Map < char ,int> :: iterator itr_map;                            //iterrates through keys of Internal Map of markov

std:: string starting_word;
int max_counter = 0 ;                                                      //sees how many times we see a word so that we can start with it
int sum ;
for ( itr_Markov_keys = Markov.begin(); itr_Markov_keys != Markov.end(); ++itr_Markov_keys ){
    sum = 0;
    Map_of_next_letters = Markov[ *itr_Markov_keys ];
    for(itr_map = Map_of_next_letters.begin(); itr_map != Map_of_next_letters.end(); ++itr_map ){
        sum += Map_of_next_letters[*itr_map];
    }

    if( max_counter > sum ){
        continue;
    }
    max_counter = sum;
    starting_word = *itr_Markov_keys; //holds of current starting word
}

/****** WE HAVE FOUND THE STARTING WORD NOW WE SHOULD START PRINTING AFTER COMPUTING THE PROBABILITIES FROM THE
*******FREQUENCY THAT THE LETTERS APPEAR AFTER THE SELECTED SEED***********************************************/

std::string RandomWriter = starting_word;

std::string next_word = starting_word;

int random_int;


for( int i = 0; i < 2000; i++ ){
    Map_of_next_letters = Markov[ next_word ];
    sum = 0;

    for( itr_map=Map_of_next_letters.begin();  itr_map != Map_of_next_letters.end(); ++itr_map ){ //we use this for to compute the frequency that we see the word in
                                                                 // so that we compute the probabilities
        sum += Map_of_next_letters[ *itr_map ];

    }
    random_int = randomInteger( 1 , sum );                         //gets a random value for range (1,sum)

    sum = 0;

    for( itr_map = Map_of_next_letters.begin(); itr_map != Map_of_next_letters.end(); ++itr_map ){ //we use this for to compute the frequency that we see the word in
                                                                    // so that we compute the probabilities
        sum += Map_of_next_letters[ *itr_map ]; // not sure if it works correctly the higher the frequency of the letter the higher the chance to get it this way
                                                // a better way is to use a distribution from the probabilities of each letter
        if( sum >= random_int  ){

            next_letter= *itr_map;

            next_word = next_word.substr(1 , seed-1);

            next_word = next_word + next_letter;

            RandomWriter = RandomWriter + next_letter;

            break;

        }

    }
}
std:: cout << RandomWriter;

return 0;
}
