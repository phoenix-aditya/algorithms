#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

void parathesismaker( string output, int opout, int cbout, int n)
{
    if(output.length()>=2*n)
    {
        cout<<output<<endl;
        return;
    }
    char o='(';
    char c=')';
    
    if(opout<=cbout && opout<n)
    {
        parathesismaker(output+o, opout+1, cbout, n);
        return;
    }
    else
    {
        if(cbout<n)
        parathesismaker(output+c, opout, cbout+1, n);
        
        if(opout<n)
        parathesismaker(output+o, opout+1, cbout, n);
    }
}

int main()
{
    int n;
    cin>>n;
    
    parathesismaker("", 0, 0, n);
    
    
    return 0;
}
