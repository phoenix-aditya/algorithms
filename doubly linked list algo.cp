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
    node* front;
    node* back;
};
node* head=nullptr;

//q1.a. doubly linked list
void insertfront(int data)
{
    node* temp=new node;
    temp->data=data;
    
    temp->front=head;
    temp->back=nullptr;
    
    if(head!=nullptr)
        head->back=temp;
    head=temp;
}
void insertback(int data)
{
    node* temp=new node;
    temp->data=data;
    
    node* last=head;
    temp->front=nullptr;
    
    if(head==nullptr)
    {
        temp->back=nullptr;
        head=temp;
        return;
    }
    while(last->front!=nullptr)
        last=last->front;
    
    last->front=temp;
    temp->back=last;
}

void insertafter(int data, int location)
{
    node* temp=head;
    for(int i=1;i<=location;i++)
    {
        if(temp->front==nullptr)
            break;
        temp=temp->front;
    }
    node* newnode= new node;
    newnode->data=data;
    newnode->front=temp->front;
    newnode->back=temp;
    temp->front=newnode;
}

//q1.c.
void search(int searchwhat)
{
    node* temp=head;
    int counter=1;
    while(temp->front!=nullptr)
    {
        if(temp->data==searchwhat)
        {
            cout<<"found at node "<<counter<<endl;
            return;
        }
        temp=temp->front;
        counter++;
    }
    cout<<"node not found!!!\n";
}
//q3.a.
int sizeofdoublylinkedlist()
{
    int counter=1;
    node* temp=head;
    while(temp->front!=nullptr)
    {
        counter++;
        temp=temp->front;
    }
    cout<<"size of list is : "<<counter<<endl;
    return counter;
}
//q4.
void paindromeornot()
{
    node* tempstart=head;
    node* tempend=head;
    while(tempend->front!=nullptr)
    {
        tempend=tempend->front;
    }
    
    bool checker=true;
    int listsize=sizeofdoublylinkedlist();
    
    for(int i=1;i<=listsize/2;i++)
    {
        if(tempstart==nullptr || tempend==nullptr)
        {
            return;
        }
        if(tempstart->data!=tempend->data)
        {
            checker=false;
        }
        tempstart=tempstart->front;
        tempend=tempend->back;
    }
    if(checker)
    {
        cout<<"palindrome it is\n";
    }
    else
        cout<<"not palindrome\n";
}
//q1. b.
void deletenode(int location)
{
    if(head==nullptr)
        return;

    if(location==1)
    {
        node* temp=head;
        head=temp->front;
        return;
    }
    
    if(location==sizeofdoublylinkedlist())
    {
        node* temp=head;
        for(int i=1;i<sizeofdoublylinkedlist();i++)
        {
            temp=temp->front;
        }
        temp->front=nullptr;
        return;
    }
    node* temp=head;
    for(int i=1;i<location;i++)
    {
        temp=temp->front;
    }
    node* tempback=temp->back;
    node* tempfront=temp->front;
    
    tempback->front=tempfront;
    tempfront->back=tempback;
    return;
}
void display()
{
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->front;
    }
    cout<<endl;
}

int main()
{
    cout<<"doubly linked list functions:\n";
    cout<<"1.insert front\n";
    cout<<"2.insert back\n";
    cout<<"3.insert at location:\n";
    cout<<"4.search data:\n";
    cout<<"5.palindrome or not\n";
    cout<<"6. size of list \n";
    cout<<"7. delete node \n";
    cout<<"8.exit\n";
    cout<<endl;
    int choice, data, location;
    do{
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"enter data: ";
                cin>>data;
                insertfront(data);
                display();
                break;
            case 2:
                cout<<"enter data: ";
                cin>>data;
                insertback(data);
                display();
                break;
            case 3:
                cout<<"enter data: ";
                cin>>data;
                cout<<"enter location: ";
                cin>>location;
                location-=1;
                insertafter(data,location);
                display();
                break;
            case 4:
                cout<<"enter data to search: ";
                cin>>data;
                search(data);
                break;
            case 5:
                paindromeornot();
                display();
                break;
            case 6:
                sizeofdoublylinkedlist();
                display();
                break;
            case 7:
                cout<<"enter location: ";
                cin>>location;
                deletenode(location);
                display();
                break;
            default:
                break;
        }
        
    }while(choice!=8);
    
    return 0;
}
