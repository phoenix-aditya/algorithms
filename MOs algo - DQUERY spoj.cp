#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>


int arr[30001];

struct query{
  
    int l;
    int r;
    int index;
};

const int blk=555;

query qarray[200001];

bool comp(query a, query b)
{
    if(a.l/blk!=b.l/blk)
        return a.l/blk<b.l/blk;
    
    return a.r<b.r;
}

int count=0;

int freq[1000001];

void add(int pos)
{
    freq[arr[pos]]++;
    if(freq[arr[pos]]==1)
        ::count++;
}

void remove(int pos)
{
    freq[arr[pos]]--;
    if(freq[arr[pos]]==0)
        ::count--;
}

int ans[200001];

int main()
{
    speed;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int q;
    cin>>q;

    for(int i=0;i<q;i++)
    {
        cin>>qarray[i].l>>qarray[i].r;
        qarray[i].index=i;
        qarray[i].l--;
        qarray[i].r--;
    }
    
    sort(qarray,qarray+q,comp);
    
    int f=0, e=-1;
    
    for(int i=0;i<q;i++)
    {
        int L=qarray[i].l;
        int R=qarray[i].r;
        
        while(f<L)
        {remove(f);f++;}
        
        while(f>L)
        {f--;add(f);}
        
        while(e<R)
        {e++;add(e);}
        
        while(e>R)
        {remove(e);e--;}
        
        ans[qarray[i].index]=::count;
    }
    
    for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;
    
    return 0;
}

