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

node* head=nullptr;

void push(int data)
{
    node* temp=new node;
    temp->data=data;
    temp->link=head;
    head=temp;
}

void pop()
{
    node* temp=head;
    head=temp->link;
    cout<<temp->data;
    delete temp;
}
void pop2()
{
    node* temp=head;
    head=temp->link;
    delete temp;
}

int calcsize()
{
    int counter=1;
    node* temp=head;
    while(temp->link!=nullptr)
    {
        counter++;
        temp=temp->link;
    }
    return counter;
}

void middleinstack(int k)
{
    if(k==0)
    {
        node* temp=head;
        cout<<"middle of stack is: "<<temp->data<<endl;
        return;
    }
    node* temp=head;
    int data=temp->data;
    pop2();
    middleinstack(k-1);
    push(data);
}
void mid()
{
    int size=calcsize();
    if(size%2==0)
    {
        int k=size/2;
        middleinstack(k);
    }
    else
    {
        int k=size/2;
        middleinstack(k);
    }
}

void display()
{
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    
    display();
    
    mid();
    display();
    return 0;
}
