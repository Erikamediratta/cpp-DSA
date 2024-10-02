#include <iostream>


using namespace std;

struct node
{
    int data;
    struct node* next;

};
struct node*head=nullptr;



void create()
{   int choice;
cout<<"Do you want to add a node?,Press 1 for yes and 0 for no\n";
   cin>>choice;
while(choice==1)
{

    int data;
   struct node*temp;
   temp=head;
   struct node*newnode;
   newnode=new node();
   
   cout<<"Enter data for the node\n";
   cin>>data;
   newnode->data=data;
   newnode->next=nullptr;
   if(head==nullptr)
   {
    temp=head=newnode;
   }
   else{
   temp = head;
    while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }

        cout << "Do you want to add another node? Press 1 for yes and 0 for no\n";
        cin >> choice; 
}
}



void display()
{  
    if(head==nullptr)
    {
        cout<<"The linked list is empty"<<endl;
    }
    struct node*temp;
    temp=head;
    while(temp!=nullptr)
    {   cout<<temp->data<< " ";
        temp=temp->next;
        
    cout<<endl;
    }
}
int getlength()
{   int count=0;
    struct node*temp;
    temp=head;
    while(temp!=0)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

    
void insertionatbeginning()
{
    struct node*temp;
    temp=head;
    if(head==0)
    {
        cout<<"The list is empty"<<endl;

    }
    else
    {   int data;
        struct node*newnode;
        newnode=new node();
        cout<<"Enter data for the first node"<<endl;
        cin>>data;
        newnode->data=data;
        head=newnode;
        newnode->next=temp;  
    }
}

void insertionatend()  
{
    struct node*temp;
    temp=head;
    if(head==nullptr)
    {
        cout<<"The list is empty"<<endl;

    }
    else
    {
        int data;
        struct node*newnode;
        newnode=new node();
        cout<<"Enter Data for the last node"<<endl;
        cin>>data;
        newnode->data=data;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=nullptr;
    }
    
}
void insertionatpos()
{   int i=1;
int pos;
cout<<"Enter the position at which you want to add a node"<<endl;
cin>>pos;
    struct node*temp;
    temp=head;
    if(head==nullptr)
    {
        cout<<"The list is empty"<<endl;
    }
    else if(pos==1)
    {
        insertionatbeginning();
    }
    else{
        int data;
        struct node*newnode;
        newnode=new node();
        cout<<"Enter Data for the last node"<<endl;
        cin>>data;
        newnode->data=data;
    while(pos>i)
    {
        temp=temp->next;
        i++;
    }
    
    newnode->next=temp->next;
    temp->next=newnode;

    }
}
void deletefrombeginning()
{
    struct node*temp;
    temp=head;
    if(head==nullptr)
    {
        cout<<"The list is empty"<<endl;
    }
    else
    {
        head=head->next;
        delete temp;
    }
    
}

void deletefromend()
{
    struct node*temp;
    struct node*prevnode;
    temp=head;
    if(head==nullptr)
    {
       
        cout<<"The list is empty"<<endl;
    }
    else
    {
        while(temp->next!=nullptr)
        {   prevnode=temp;
            temp=temp->next;
        }
        if(temp==head)
        {
            head==nullptr;
            delete head;
        }
        else{
            prevnode->next=0;
            delete temp;
        }
    }
}
void deletefrompos()
{   struct node*temp; 
    struct node*nextnode;
    temp=head;
    int  pos;
    int i=1;
    cout<<"Enter the position of the node to be deleted"<<endl;
    cin>>pos;
    if(pos==1)
    {
        deletefrombeginning();
    }
    while(pos-1>i)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    delete nextnode;
}
int main()
{   int ichoice,idchoice,dchoice;
    create();
   cout<<"Displaying the Linked list\n";
   display();
   int length=getlength();
   cout<<"The length of the list is "<<length<<endl;
   cout<<"Do you want to insert or delete a node,Press 1 for inserting and 2 for deleting,else Press any key "<<endl;
   cin>>idchoice;
    
   if(idchoice!=1 && idchoice!=2)
   {
    cout<<"Wrong choice entered"<<endl;
   }
    if (idchoice==1)
   {cout<<"Press 1 for adding in the beginning,Press 2 for adding in the end,Press 3 for adding a node at a specific position"<<endl;
    cin>>ichoice;
   if (ichoice==1)
   {
    insertionatbeginning();
    cout<<"Displaying the Linked list after inserting a node in the beginning"<<endl;
    display();
   }
   else if(ichoice==2)
   {
    insertionatend();
    cout<<"Displaying the Linked list after inserting a node in the end"<<endl;
    display();
    
   }
   else if(ichoice==3)
   {
    insertionatpos();
     cout<<"Displaying the Linked list after inserting a node at the specified position"<<endl;
     display();
     

   }
   }
if(idchoice==2)
{
    cout<<"Press 1 for deleting a node from the beginning, Press 2 if from the end,Press 3 for deleting a node from a specific position"<<endl;
    cin>>dchoice;
    if(dchoice==1)
    {
        deletefrombeginning();
        if (head!=nullptr)
        {
        cout<<"Displaying after deleting node from the beginning"<<endl;
        display();
        }
    }
    if(dchoice==2)
    {
        deletefromend();
        if (head!=nullptr)
        {
        cout<<"Displaying after deleting node from the beginning"<<endl;
        display();
        }

    }
    if(dchoice==3)
    {
        deletefrompos();
        if (head!=nullptr)
        {
        cout<<"Displaying after deleting node from the position"<<endl;
        display();
        }

    }
    
}


}
//Reversing left