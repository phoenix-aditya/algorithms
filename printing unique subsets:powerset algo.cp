#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

unordered_set<string> uniquesubsets;
void printuniquesubsets(string input, string output)
{
    if(input.length()==0)
    {
        uniquesubsets.insert(output);
        return;
    }
    char c=input.front();
    input.erase(0,1);
    printuniquesubsets(input, output);
    printuniquesubsets(input, output+c);
}

int main()
{
    uniquesubsets.clear();
    string s;
    cin>>s;
    printuniquesubsets(s, "");
    cout<<"unique subsets are:  \n";
    for(auto x: uniquesubsets)
        cout<<x<<endl;
    
    return 0;
}
