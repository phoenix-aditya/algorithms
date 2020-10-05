#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

unordered_set<string> permutwidspaces;
void permutwidspacesmaker(string input, string output)
{
    if(input.length()==0)
    {
        permutwidspaces.insert(output);
        return;
    }
    char c= input.front();
    input.erase(0,1);
    
    permutwidspacesmaker(input, output+" "+c);
    permutwidspacesmaker(input, output+c);
}

int main()
{
    permutwidspaces.clear();
    string s;
    cin>>s;
    char x= s.front();
    string z="";
    z+=x;
    s.erase(0,1);
    permutwidspacesmaker(s, z);
    cout<<"unique permutations of spaces are:  \n";
    for(auto x: permutwidspaces)
        cout<<x<<endl;
    
    return 0;
}
