#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

//aditya ranaut- phoenix_aditya

void insert(vector<int> &arr, int temp)
{
    if(arr.size()==0 || arr[arr.size()-1]<=temp)
    {
        arr.push_back(temp);
        return;
    }
    int val= arr[arr.size()-1];
    arr.pop_back();
    insert(arr, temp);
    arr.push_back(val);
}

void sorter(vector<int> &arr)
{
    if(arr.size()==1)
        return;
    
    int val= arr[arr.size()-1];
    arr.pop_back();
    sorter(arr);
    insert(arr, val);
}

void solve()
{
    int n;
    cin>>n;
    
    vector<int> arr;
    int temp;
    f(i,0,n)
    {cin>>temp;arr.push_back(temp);}
    
    sorter(arr);
    
    for(auto x: arr)
        cout<<x<<" ";
    cout<<endl;
}



int main()
{
    speed;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    wh(t)
     {solve();}
    
    return 0;
}
