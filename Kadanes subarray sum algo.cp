#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define f(i,a,b) for(int i=0;i<n;i++)
#define endl "\n"
using namespace std;
#include<string.h>

int main()
{
    int arr[]={1,-3,2,1,-1};
    
    int best=0;
    int sum=0;
    
    for(int i=0;i<5;i++)
    {
        sum=max(arr[i],sum+arr[i]);
        best=max(best,sum);
    }
    cout<<best<<endl;
    return 0;
}
