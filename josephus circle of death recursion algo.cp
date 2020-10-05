#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void josephuscircleofdeath(vector<int> v, int k, int killocation)
{
    if(v.size()==1)
    {
        cout<<v[0]<<endl;
        return;
    }
    v.erase(v.begin()+killocation);
    int nextkill=(killocation+k)%v.size();
    josephuscircleofdeath(v, k, nextkill);
}

int main()
{
    int t;
    cin>>t;
    
    while(t--){
    int n;
    cin>>n;
    
    int k;
    cin>>k;
    
    k=k-1;
    
    vector<int> people;
    for(int i=1;i<=n;i++)
        people.push_back(i);
    
    josephuscircleofdeath(people, k, k%people.size());
    }
    return 0;
}
