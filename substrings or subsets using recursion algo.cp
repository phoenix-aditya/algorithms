  #include<bits/stdc++.h>
  #define pi 3.14159265359
  #define ll long long
  #define wh(t) int t;cin>>t; while(t--)
  #define speed  ios::sync_with_stdio(0); cin.tie(0);
  #define endl "\n"
  #define f(i,a,b) for(int i=a;i<b;i++)
  using namespace std;
  #include<string.h>

void solve(string ip, string op)
{
    if(ip.length()==0)
    {
        cout<<op<<endl;
        return;
    }
    
    char c=ip.front();
    ip.erase(0,1);
    solve(ip, op+c);
    solve(ip, op);
}

  int main()
  {
      cout<<"enter string: \n";
      string ip;
      cin>>ip;
      
      string op="";
      
      solve(ip, op);
      
      return 0;
  }
