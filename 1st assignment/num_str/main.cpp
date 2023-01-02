#include <iostream>
#include<math.h>
#include<string>
#include<string.h>


using namespace std;

int str_tonum(string word);
int fornum(string word,int x );
string int_tostr(int x);
int main()
{   string k;
    int ans;
    //here string to number is called
    cout<<"give str"<<endl;
    cin>>k;
    cout<<str_tonum(k)<<endl;
    // here int to string is called
    cout<<"Give integer to convert to string"<<endl;
    cin>>ans;
    cout<<int_tostr(ans)<<endl;

    return 0;
}
int fornum(string word,int x){
  int temp;
    if(x==word.length()){
      return 0;
  }  else{
      temp=(word[x]-48)*pow(10,word.length()-x-1);

      return fornum(word,x+1)+temp;
  }
};

int str_tonum(string word){
    int i=0;
    if(word[0]=='-'){
        i=1;
        return -1*fornum(word,i);
   }
    else{
        return fornum(word,i);
    }


};
//integer to string
string int_tostr(int x){
        string word;
        char c;
        if(x<0){
        word=word+"-";
        x=x*(-1);
        }
        if(x/10 == 0){
            c=x%10 +48;
        return word+c;
        }else{
            c=x%10+48;
        return  word + int_tostr(x/10)+c;
        }


};

