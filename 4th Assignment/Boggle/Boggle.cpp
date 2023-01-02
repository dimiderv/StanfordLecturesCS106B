/*
 * File: Boggle.cpp
 * ----------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the main starter file for Assignment #4, Boggle.
 * [TODO: extend the documentation]
 */
 
#include <iostream>
#include "gboggle.h"
#include "grid.h"
#include "gwindow.h"
#include "lexicon.h"
#include "random.h"
#include "simpio.h"



/* Constants */

const int BOGGLE_WINDOW_WIDTH = 650;
const int BOGGLE_WINDOW_HEIGHT = 350;

const std:: string STANDARD_CUBES[16]  = {
   "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
   "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
   "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
   "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};
 
const std:: string BIG_BOGGLE_CUBES[25]  = {
   "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
   "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
   "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
   "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
   "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

/* Function prototypes */
void shuffle( Grid<char> &Boggle_grid,const std:: string *STANDARD_CUBES,Vector<std:: string> &shuffled_cubes);
void shuffle( Grid<char> &Boggle_grid, std:: string user_boggle );
std:: string Get_user_boggle();
void Show_boggle(Grid<char> &Boggle_grid );
bool IsInHumansList(Vector <std:: string> & ListOfWords, std:: string enter_word);
void Human_turn(Lexicon &lex,Vector <std:: string> &ListOfWords,Grid<bool> &board,Grid <char> & Boggle_grid,Vector<int> &RowsColumns);
bool IsWordInCube(Grid<bool> &board,Grid <char> & Boggle_grid,Vector<int> &RowsColumns,std:: string word,int row,int column);
void LookWordinCube(Grid<bool> &board,Grid <char> & Boggle_grid,Vector<int> &RowsColumns,std:: string word);
void Highlight(Vector<int> & RowsColumns);
void Computers_turn(Lexicon &lex,Vector <std:: string> & ListOfWords,std:: string word,int row,int column,Grid<bool> &board,Grid <char> & Boggle_grid,Vector<std::string> &Computer_list);
void Call_computer(Lexicon &lex,Vector <std:: string> & ListOfWords,std:: string word,Grid<bool> &board,Grid <char> & Boggle_grid,Vector<std::string> &Computer_list);

/********************* Main program ******************************/



int main() {
   GWindow gw(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
   Grid<char> Boggle_grid(4,4);
   Lexicon english;
   english.addWordsFromFile("EnglishWords.dat");
   Vector <std:: string> ListOfWords;
   Vector <int> RowsColumns;
   Grid<bool> board(4,4,0);
   Vector<std::string> Computer_list;

  while(true){

   if(getYesOrNo(" If you want to give your boggle cubes press yes or else no ")){

      std:: string user_boggle =Get_user_boggle();
      user_boggle=toUpperCase(user_boggle);
      shuffle(Boggle_grid,user_boggle);

   }else{

       Vector<std:: string> shuffled_cubes;
       shuffle( Boggle_grid, STANDARD_CUBES, shuffled_cubes);

   }

    initGBoggle(gw);
    Show_boggle( Boggle_grid );
    Human_turn(english,ListOfWords,board,Boggle_grid,RowsColumns);
    Call_computer(english,ListOfWords,"",board,Boggle_grid,Computer_list);

}

   return 0;
}

/*********************END OF MAIN*********************************/




/****** Shuffles the cubes and Puts them on random sides on the Boggle Grid */

void shuffle( Grid<char> &Boggle_grid, const std:: string *STANDARD_CUBES,Vector<std:: string> &shuffled_cubes){

   std:: string temp;
   int num_of_cubes = Boggle_grid.nCols * Boggle_grid.nRows;
   int random_index;
   char cube_letter;
    // we copy the cubes at a vector
   for(int i=0; i< num_of_cubes ; i++ ){
        shuffled_cubes.add(*(STANDARD_CUBES+i));
    }

   //we shuffle the cubes
   for(int i = 0 ; i< num_of_cubes ; i++){
       random_index = randomInteger(i,num_of_cubes-1);
       temp = shuffled_cubes[i];
       shuffled_cubes[i] = shuffled_cubes[random_index];
       shuffled_cubes[random_index] = temp;
   }

   //here we put random sides on the Boggle grid
   for (int i =0 ; i<num_of_cubes; i+=4){
       for (int j =0 ; j < Boggle_grid.nRows ; j++){
           temp = shuffled_cubes[i+j];
           cube_letter = temp [randomInteger( 0 , temp.length() -1)];
           Boggle_grid.set(i/4,j,cube_letter);

       }

   }

}


/* *****OverLoad Function for user to put his own boggle***********/

void shuffle( Grid<char> &Boggle_grid, std:: string user_boggle ){

    std:: string temp;
    int num_of_cubes = Boggle_grid.nCols * Boggle_grid.nRows;
    char cube_letter;

    //here we put random sides on the Boggle grid
    for (int i =0 ; i<num_of_cubes; i+=4){
        for (int j =0 ; j < Boggle_grid.nRows ; j++){

            cube_letter = user_boggle[i+j];
            Boggle_grid.set(i/4,j,cube_letter);

        }

    }


}
/**************************************************************
 * this function gets the boggle cubes of the user
 *
 * *****************************************************************/
std:: string Get_user_boggle(){
    std:: string user_boggle;
    user_boggle = getLine("Please give your custom boggle ( 16 letters)");
    while( user_boggle.length() < 16 ){

        user_boggle=getLine("Please give your custom boggle ( 16 letters)");
    }

    return user_boggle;
}

/************Function that creates Boggle Board**************
 *  Takes as input the given grid and prints it
 *
 */

void Show_boggle(Grid<char> &Boggle_grid ){

    drawBoard(Boggle_grid.nRows,Boggle_grid.nCols);
    for (int i =0 ; i<Boggle_grid.nRows; i++){
        for (int j =0 ; j < Boggle_grid.nCols ; j++){
                labelCube(i,j,Boggle_grid[i][j]);

        }

    }
}
/************Human_turn*******************
 * this function lets the player enter the words he has found on the boggle
*************************************************************************************
*************************************************************************************/

void Human_turn(Lexicon &lex,Vector <std:: string> &ListOfWords,Grid<bool> &board,Grid <char> & Boggle_grid,Vector<int> &RowsColumns){

 std:: string   enter_word = getLine(" Enter word that you see in boggle ");
    while(enter_word!=""){

        enter_word=toUpperCase(enter_word);
        LookWordinCube(board,Boggle_grid,RowsColumns,enter_word);

        if(lex.contains(enter_word) && enter_word.length()>3 && (! IsInHumansList(ListOfWords,enter_word)) && RowsColumns.size()){
            Highlight(RowsColumns);
            ListOfWords.add(enter_word);
            recordWordForPlayer(enter_word,HUMAN);

         }
        RowsColumns.clear();
        enter_word = getLine(" Enter word that you see in boggle ");
}
}
/*
 *
 * IsInHumansList checks if the word is alreaady used******************/

bool IsInHumansList(Vector <std:: string> & ListOfWords, std:: string enter_word){
    for(std:: string s : ListOfWords ){
        if( s == enter_word){
            return 1;
        }
    }
    return 0;
}
/*checks if word is in the cube */
bool IsWordInCube(Grid<bool> &board,Grid <char> & Boggle_grid,Vector<int> &RowsColumns,std:: string word,int row,int column){
   if(word == ""){
       return true;
   }
   Grid<bool> board_x=board;

   for(int i=row -1 ; i<=row+1 ;i++ ){

       for(int j=column-1; j<=column+1 ; j++){

           if(i>=0 && j>=0 && i<4 && j<4   ){
              if(! board_x[i][j]){
                if(word[0] == Boggle_grid[i][j] ){
                    board_x[i][j] = 1;
                    RowsColumns.add(i);
                    RowsColumns.add(j);
                    if(IsWordInCube(board_x,Boggle_grid,RowsColumns,word.substr(1),i,j)) return true;

                    board_x[i][j] = 0;
                    RowsColumns.remove(RowsColumns.size()-1);
                    RowsColumns.remove(RowsColumns.size()-1);
            }
        }
        }
   }


} return false;
}

/*Wrapper function to call to look for all combinations of cube
            calls IsWordInCube
*/
void LookWordinCube(Grid<bool> &board,Grid <char> & Boggle_grid,Vector<int> &RowsColumns,std:: string word){
    bool flag=0;

    for(int i=0 ;i < 3; i++){
        for(int j=0 ; j<3; j++){

            if(IsWordInCube(board,Boggle_grid,RowsColumns,word,i,j) &&   flag==0){
                flag=1;
                break;
            }

        }


    }
}
// THIS FUNCTION HIGHLIGHTS THE WORDS THAT THE USER FINDS ON THE CUBE
void Highlight(Vector<int> & RowsColumns){
    int s=RowsColumns.size();
    for(int i = 0 ; i< s; i+= 2){
        highlightCube(RowsColumns[i],RowsColumns[i+1],1);
    }
    pause(1000);
    for(int i=0 ;i < s; i+=2){
        highlightCube(RowsColumns[i],RowsColumns[i+1],0);
    }
}
//This function is where the computer finds the remaining words and beats you
void Computers_turn(Lexicon &lex,Vector <std:: string> & ListOfWords,std:: string word,int row,int column,Grid<bool> &board,Grid <char> & Boggle_grid,Vector<std::string> &Computer_list){

    if(word.length()>3 && lex.contains(word) && (! IsInHumansList(ListOfWords,word)) && (!IsInHumansList(Computer_list,word))){

        recordWordForPlayer(word,COMPUTER);

        Computer_list.add(word);

    }

    Grid<bool> board_x=board;
    std :: string next_word=word;

    for(int i=row -1 ; i<=row+1 ;i++ ){

        for(int j=column-1; j<=column+1 ; j++){

         if(i>=0 && j>=0 && i<4 && j<4   ){
             if(! board_x[i][j]){

                 board_x[i][j]=1;
                 next_word=next_word + Boggle_grid[i][j];
                 if(lex.containsPrefix(next_word))
                 Computers_turn(lex,ListOfWords,next_word,i,j,board_x,Boggle_grid,Computer_list);

                 board_x[i][j] = 0;
                 next_word=word;

             }
         }
         }
    }




 }

void Call_computer(Lexicon &lex,Vector <std:: string> & ListOfWords,std:: string word,Grid<bool> &board,Grid <char> & Boggle_grid,Vector<std::string> &Computer_list){
    for(int i=0;i<3;i++){
          for(int j=0;j<3;j++){
              Computers_turn(lex,ListOfWords,word,i,j,board,Boggle_grid,Computer_list);
          }
      }
}

