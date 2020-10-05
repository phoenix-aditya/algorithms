#include<iostream>
using namespace std;

void binarynumber10prefix(int n, string output, int no1, int no0)
{
    if(output.length()==n)
    {
        cout<<output<<endl;
        return;
    }
    char one='1';
    char zero='0';
    if(no1<=no0)
    {
        binarynumber10prefix(n, output+one, no1+1, no0);
    }
    else
    {
        binarynumber10prefix(n, output+zero, no1, no0+1);
        binarynumber10prefix(n, output+one, no1+1, no0);
    }
}

int main()
{
    int n;
    cin>>n;
    
    string s="";
    
    binarynumber10prefix(n, s, 0, 0);
    
    return 0;
}
