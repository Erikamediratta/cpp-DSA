#include <iostream>

using namespace std;
struct node{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head;
struct node*temp;

void create()
{  int choice;
    cout<<"Do you want to create a node,Press 1 for yes and 0 for no"<<endl;
    cin>>choice;
    while(choice==1)
     {int data;
    struct node*newnode;
    newnode=new node();
    cout<<"Enter data for the node"<<endl;
    cin>>data;
    newnode->data=data;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    if(head==0)
    {
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
        
    }
     
    cout<<"do you want to continue adding ?Press 1 for yes and 0 for no"<<endl;
    cin>>choice;
     }

}

void display()
{
    temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<endl;
       
        temp=temp->next;
    }
}

void insertionatbeginning()
{   int data;
    temp=head;
    struct node*newnode;
    newnode=new node;
    cout<<"Enter data for the new node in the beginning"<<endl;
    cin>>data;
    newnode->data=data;
    if(head==nullptr)
    {
        head=newnode;
    }
    else
    {   newnode->next=temp;
        newnode->prev=nullptr;
        temp->prev=newnode;
        head=newnode;

    }
}
void insertionatend()
{
    int data;
    temp=head;
    struct node*newnode;
    newnode=new node;
    cout<<"Enter data for the new node in the beginning"<<endl;
    cin>>data;
    newnode->data=data;
    if(head==nullptr)
    {
        head=newnode;
    }

    else{
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next=nullptr;
        
    }
}
void insertionatpos()
{
    int pos;
    int i=1;
    cout<<"Enter position at which you want to insert a node"<<endl;
    cin>>pos;
    int data;
    temp=head;
    struct node*newnode;
    newnode=new node;
    cout<<"Enter data for the new node in the beginning"<<endl;
    cin>>data;
    newnode->data=data;
    if(head==nullptr)
    {
        head=newnode;
    }
    if(pos==1)
    {
        insertionatbeginning();
    }
    else{
        while(pos-1>i)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;

    }
}

void deletefrombeginning()
{
    temp=head;
    if(head==nullptr)
    {
        cout<<"The linked list is empty"<<endl;

    }
    else{
        head=head->next;
        delete temp;
    }
}
void deletefromend()
{
    temp=head;
    if(head==nullptr)
    {
        cout<<"The linked list is empty"<<endl;

    }
    else{
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->prev->next=nullptr;
        delete temp;
    }
}
void deletefrompos()
{
    temp=head;
    int pos;
    int i=1;
    cout<<"Enter position from which node is to be deleted"<<endl;
    cin>>pos;
    if(pos==1)
    {
        deletefrombeginning();

    }
   else if(head==nullptr)
   {
    cout<<"The linked list is empty"<<endl;
   }
   else{
    while(pos>i)
    {
        temp=temp->next;
        i++;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    delete temp;
   }
}

int main()
{   int idchoice,ichoice,dchoice;
    create();
    cout<<"Displaying the Double linked list"<<endl;
    display();
    cout<<"Do you want to insert a node or delete a node,Press 1 for insertion and 2 for deletion"<<endl;
    cin>>idchoice;
    if(idchoice!=1 && idchoice !=2)
    {
        cout<<"Wrong choice "<<endl;
    }
    if(idchoice==1)
    {
        cout<<"Press 1 for inserting in beginning,2 for in the end,3 for a specified position"<<endl;
        cin>>ichoice;
        if(ichoice==1)
        {
            insertionatbeginning();
            cout<<"Displaying the Linked list after inserting in the beginning"<<endl;
            display();
        }
        if(ichoice==2)
        {
            insertionatend();
            cout<<"Displaying the Linked list after inserting at end"<<endl;
            display();
        }
        if(ichoice==3)
        {
            insertionatpos();
            cout<<"Displaying the linked list after inserting at the specified position"<<endl;
            display();
        }
    }
    if(idchoice==2)
    {
        cout<<"Press 1 for deleting from beginning,2 for deleting from end,3 for deleting from a specified position"<<endl;
        cin>>dchoice;
        if(dchoice==1)
        {
            deletefrombeginning();
            cout<<"Displaying linked list after deleting first node"<<endl;
            display();
        }
        if(dchoice==2)
        {
            deletefromend();
            cout<<"Displaying linked list after deleting last node"<<endl;
            display();
        }
        if(dchoice==3)
        {
            deletefrompos();
            cout<<"Displaying linked list after deleting from the specified position"<<endl;
            display();
        }
    }
}//reversing left