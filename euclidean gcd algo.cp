using namespace std;
#include<bits/stdc++.h>
#define ll long long

ll gcd(int a, int b)
{
    if(a==0)
        return b;
    
    else
        return gcd(b%a,a);
}

int main()
{
    cout<<gcd(10,15);
    
    
    return 0;
}
