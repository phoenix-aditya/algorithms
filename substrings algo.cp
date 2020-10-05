#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

unordered_set<string> substrings;
void substringmaker(string input, string output)
{
    if(input.length()==0)
    {
        substrings.insert(output);
        return;
    }
    char c= input.front();
    string z="";
    z+=c;
    input.erase(0,1);
    if(output.size()!=0)
    {
        substrings.insert(output);
        substringmaker(input, z);
    }
    substringmaker(input, output+c);
}

int main()
{
    substrings.clear();
    string s;
    cin>>s;
    substringmaker(s, "");
    cout<<"unique subsets are:  \n";
    for(auto x: substrings)
        cout<<x<<endl;
    
    return 0;
}
