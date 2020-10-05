#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

//q1.
struct node{
    char data;
    node* link;
};

node* head=nullptr;

void push(char data)
{
    node* temp=new node;
    temp->data=data;
    temp->link=head;
    head=temp;
}
void pop()
{
    node* temp=head;
    char c=temp->data;
    head=temp->link;
    delete temp;
}

bool isempty()
{
    if(head==nullptr)
    {
//        cout<<"empty\n";
        return true;}
//    cout<<"Not empty\n";
    return false;
}

void isfull(){
    cout<<"its a linked list stack no limit\n";
}
void display()
{
    node* temp=head;
    while(temp->link!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<temp->data;
    cout<<endl;
}
char peek()
{
    if(head==nullptr)
    {
//        cout<<"empty stack \n";
        return 0;
    }
    node* temp=head;
//    cout<<temp->data<<endl;
    return temp->data;
}

//q2.
void secondq(string s)
{
    head=nullptr;
    for(char c:s)
    {
        push(c);
    }
    display();
}

//q3.
void balancedparanthesis(string s)
{
    head=nullptr;
    for(auto c:s)
    {
        if(c=='(')
            push(c);
        else if(c==')' && peek()=='(')
            pop();
        else
            push(')');
    }
    if(isempty())
    {
        cout<<"balanced\n";
        return;
    }
    cout<<"not balanced\n";
}

//q4.

int p(char x)
{
    if(x=='^')
        return 3;
    if(x=='*' || x=='/')
       return 2;
    if(x=='+' || x=='-')
        return 1;
    else
        return -1;
}
void infixtopostfix(string s)
{
    head=nullptr;
    for(char c:s)
    {
        if((c>= 'a' && c<= 'z')||(c >= 'A' && c<= 'Z'))
        {
            cout<<c;
            continue;
        }
        else if(c=='(')
            push(c);
        
        else if(c==')')
        {
            while(!isempty() && peek()!='(')
            {
                char x=peek();
                pop();
                cout<<x;
            }
            if(peek()=='(')
            {
                char x=peek();
                pop();
            }
        }
        else
        {
            while(head!=nullptr && p(c)<=p(head->data))
            {
                char x=peek();
                pop();
                cout<<x;
            }
            push(c);
        }
    }
    while(head!=nullptr)
    {
        char x=peek();
        pop();
        cout<<x;
    }
}

//q5.
void evalpostfix(string s)
{
    head=nullptr;
    for(char c:s)
    {
        if(isdigit(c))
        {
            push(c);
        }
        else
        {
            int val1= peek()-'0';
            pop();
            int val2= peek()-'0';
            pop();
            
            switch(c)
            {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2/val1); break;
            }
        }
    }
    cout<<peek()-'0'<<endl;
    pop();
}
int main()
{
     cout<<"stack functions:\n";
     cout<<"1.push\n";
     cout<<"2.pop\n";
     cout<<"3.peek\n";
     cout<<"4.isempty?\n";
     cout<<"5.display\n";
     cout<<"6.reverse string\n";
     cout<<"7.infix to postfix \n";
     cout<<"8.evaluate postfix \n";
    cout<<"9. exit\n";
     cout<<endl;
     int choice;
    string s;
    char data;
     do{
         cin>>choice;
         switch (choice) {
             case 1:
                 cout<<"enter data: ";
                 cin>>data;
                 push(data);
                 display();
                 break;
             case 2:
                 pop();
                 display();
                 break;
             case 3:
                 cout<<peek()<<endl;
                 display();
                 break;
             case 4:
                 if(isempty())
                     cout<<"is empty\n";
                 else
                     cout<<"not empty\n";
                 break;
             case 5:
                 display();
                 break;
             case 6:
                 cout<<"enter string\n";
                 cin>>s;
                 secondq(s);
                 break;
             case 7:
                 cout<<"input expression: \n";
                 cin>>s;
                 infixtopostfix(s);
                 break;
             case 8:
                 cout<<"enter expression: \n";
                 cin>>s;
                 evalpostfix(s);
                 break;
             default:
                 break;
         }
         
     }while(choice!=9);
     
     return 0;
}
