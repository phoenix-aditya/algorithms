using namespace std;
#include<bits/stdc++.h>
#define ll long long

//to print distinct primefactors of a number
void primefactors(int n)
{
    
    if(n%2==0)
    {
        cout<<"2 ";
        while(n%2==0)
            n=n/2;
    }
    for(int i=3;i<=sqrt(n);i+=2)
    {
        
        if(n%i==0)
        {
            cout<<i<<" ";
            while(n%i==0)
                n=n/i;
            
        }
    }
    if(n>2)
        cout<<n<<" ";
    
    cout<<endl;
}

int main()
{
    primefactors(315);
    
    
    return 0;
}
