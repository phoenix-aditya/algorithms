#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>


struct node{
    int data;
    node* link;
};

node* top=nullptr;
void push(int data)
{
    node* temp=new node;
    temp->data=data;
    temp->link=top;
    top=temp;
}
void pop()
{
    node* temp=top;
    top=temp->link;
    delete temp;
}

void inserting(int data)
{
    if(top==nullptr || top->data>=data)
    {
        push(data);
        return;
    }
    int val = top->data;
    pop();
    inserting(data);
    push(val);
}
void sorter()
{
    if(top->link==nullptr)
        return;
    
    int val = top->data;
    pop();
    sorter();
    inserting(val);
}
void display()
{
    node* temp = top;
    
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
}
int main()
{
    int n;
    cin>>n;
    int c;
    while(n--)
    {
        cin>>c;
        push(c);
    }
    sorter();
    
    display();
    return 0;
}
