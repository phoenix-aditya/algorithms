#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

void pairit(set<int> pair[], int n, int p, int q)
{
    int flag=0;
        for(int j=0;j<n;j++)
        {
            if((pair[j].count(p) || pair[j].count(q)) && pair[j].size()!=0)
            {
                pair[j].insert(p);
                pair[j].insert(q);
                cout<<"is ";
                flag=1;
                return;
            }
        }
    if(flag==0)
    {
        for(int i=0;i<n;i++)
        {
            if(pair[i].size()==0)
            {
                pair[i].insert(p);
                pair[i].insert(q);
                cout<<"new ";
                return;
                
            }
            
            
        }
        
        
    }
    
}

bool isconnected(set<int> pair[], int n, int p, int q)
{
    for(int i=0;i<n;i++)
    {
        if(pair[i].count(p)==1 && pair[i].count(q)==1)
            return true;
    }
    return false;
}


int main()
{
    int n;
    cin>>n;
    int p,q;
    set<int> pair[n];
    
    cin>>p>>q;
    
    pair[0].insert(p);
    pair[0].insert(q);
    
    for(int i=0;i<n-1;i++)
    {
        cin>>p>>q;
        pairit(pair, n, p, q);
        cout<<"done\n";
    }
    char query;
    while(1)
    {
        cout<<"press q for query 0 to exit: ";
        cin>>query;
        
        if(query=='q')
        {
            cout<<"enter query: ";
            cin>>p>>q;
            
            if(isconnected(pair, n, p, q))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else if(query=='0')
            exit(0);
        
        else
            cout<<"wrong query\n";
    }
    
    
    
    
    return 0;
}
