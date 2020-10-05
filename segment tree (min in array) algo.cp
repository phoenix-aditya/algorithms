#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

const int z=2e5;
int segmenttree[z]={0};


void segmentree(int arr[],int stpos, int si, int ei)
{
    if(si==ei)
    {segmenttree[stpos]=arr[si];return;}
    
    int mid=(si+ei)/2;
    
    segmentree(arr, 2*stpos, si, mid);
    segmentree(arr, 2*stpos+1, mid+1, ei);
    
    segmenttree[stpos]=min(segmenttree[2*stpos],segmenttree[2*stpos+1]);
}


int main()
{
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(int);
    
    segmentree(arr, 1, 0, size-1);
    
    for(int i=0;i<(size*2+1);i++)
        cout<<segmenttree[i]<<" ";
    cout<<endl;
    
    
    
    return 0;
}
