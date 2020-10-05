#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;
#include<string.h>
int maxval(ll arr[], int s, int e)
{
    int max=0;
    for(int i=s;i<(1<<e);i++)
    {
        int sum=0;
        for(int j=s;j<e;j++)
        {
            if(i&(1<<j))
                sum+=arr[j];
        }
        if(sum>max)
            max=sum;
    }
    return max;
}

int calcsum(ll arr[],int n)
{
    int mid=n/2;
    
    
    return maxval(arr, 0, mid)+maxval(arr, mid, n);
    
    
    
}





int main()
{
    ll a[] = {2,4,9};
       int n=sizeof(a)/sizeof(a[0]);
    
    cout<<calcsum(a, n);
    
    return 0;
}
