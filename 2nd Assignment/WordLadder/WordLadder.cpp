/*
 * File: WordLadder.cpp
 * --------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the word ladder problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "console.h"
#include "lexicon.h"
#include "queue.h"
#include "simpio.h"
#include "vector.h"
using namespace std;

int main() {
    Lexicon EnglishWords;
    Lexicon used_words;
    Vector<Vector<string> > wordladder;
    Vector<string> temp;
    Vector<string> DFS_ladder;
    Queue<string> next;
    string start,end,check;
    string changed;
    char l;
    int index=-1; //(-1 or 0 i'm not sure) holds index where is the partial ladder at hand

    cout<<" Give startd word :"<<endl;
    cin>>start;
    cout<<" Give end word (same size): "<<endl;
    cin>>end;

    used_words.add(start);
    next.add(start);
    temp.add(start);
    wordladder.add(temp);
    EnglishWords.addWordsFromFile("EnglishWords.dat");

    while( (! next.isEmpty() ) && (! (used_words.contains(end)) ) ){//could have used also DFS_ladder[DFS_ladder.size()-1]
        check=next.dequeue();
        index++;
        for(int i=0;i<26;i++){//i could start for i=97 to 123 and put l=i
             l=97+i;//all letters
            for(unsigned int j=0;j<check.length();j++){
                changed=check;
                changed.replace(j,1,1,l);// i could do changed[j]=l
                if( EnglishWords.contains(changed) && (! used_words.contains( changed ) ) ){
                    temp=wordladder[index];
                    temp.add(changed);
                    wordladder.add(temp);
                    used_words.add(changed);
                    next.enqueue(changed);
                    if(changed==end){
                        DFS_ladder=temp;
                        break;
                    }
                }
            }
			//Added by Dimitris Mang - this code replaces the for loop between lines : 47 - 61
			for (unsigned int j=0; j<check.length(); j++) {
               changed = check;
               changed[j] = l;
               if (!EnglishWords.contains(changed) || used_words.contains(changed)) {
                  continue;
               }
               temp = wordladder[index];
               temp.add(changed);
               wordladder.add(temp);
               used_words.add(changed);
               next.enqueue(changed);
               if (changed != end) {
                  continue;
               }   
               DFS_ladder = temp;
               break;
            }
        }
    }

    if(DFS_ladder.size()==0){
        cout<<"Ladder does not exist";
    }else{
        cout<<DFS_ladder<<endl;
    }

    return 0;
}
