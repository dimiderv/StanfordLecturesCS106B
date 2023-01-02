#include<iostream>

using namespace std;

int c(int n,int k)
{
    if (n==k || k==0)
        return 1;

    return c(n-1,k-1) + c(n-1,k);
}


int main ()

{int n,k;
    cout<< " Give n ,k to compute pascal triangle"<<endl;
    cin>>n>>k;
    cout<<c(n,k)<<endl;
    return 0;
}
