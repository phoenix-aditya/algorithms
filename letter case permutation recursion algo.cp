#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

void permutationwithcases(string input, string output)
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    }
    char c= input.front();
    char z;
    int zeta=c;
    input.erase(0,1);
    if(zeta>=97 && zeta<=123)
    {z= toupper(c);}
    else if(zeta>=65 && zeta<=(65+26))
    {z=tolower(c);}
    else
    {
        permutationwithcases(input, output+c);
        return;
    }
    permutationwithcases(input, output+c);
    permutationwithcases(input, output+z);
}

int main()
{
    string s;
    cin>>s;
    permutationwithcases(s, "");
    
    return 0;
}
