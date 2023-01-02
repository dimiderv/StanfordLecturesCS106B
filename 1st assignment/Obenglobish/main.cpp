#include<iostream>
#include <string>
#include<cstring>
#include<array>
using namespace std;

bool is_vowel(string word){

    bool flag=0;
    if(word=="a" || word=="e" || word=="i" || word=="o" || word=="u")flag=1;
    return flag;
};

void obenglobish(string &word){
    string vowels="aeiou";
    string  ob_word="";
    string check;
    string next_check;
//e last and vowel after vowel
    for(unsigned int i=0;i<word.length();i++){
        check=word[i];
        next_check=word[i+1];
        if(is_vowel(check)){
            if(check == "e" && i==word.length()-1){
                ob_word+=check;
            }else{
                if(i!=0 && is_vowel(next_check)){ //we can remove "i!=0 &&" and still works
                    ob_word+=check;
                }else{
                    ob_word= ob_word + "ob"+ check;
                }
            }
        }else{
            ob_word +=check;
        }

}

word=ob_word;
};



int main(){
    string word;
   cout<<"give me an english word"<<endl;
   cin>>word;
   obenglobish(word);
   cout<<word<<endl;

    return 0;
}

