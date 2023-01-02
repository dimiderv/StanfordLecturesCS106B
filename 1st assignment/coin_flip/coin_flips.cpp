#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{   int toss;
    int count=0;
    int flips=1;
    while(count<3){
        toss=rand()%2;
        if(toss==1){
           count++;
            cout<<"heads"<<endl;
        }else{
           count=0;
            cout<<"tails"<<endl;
        }
        flips++;
    }
    cout<<"it took "<< flips << "flips for 3 consecutive heads"<<endl;
    return 0;
}
