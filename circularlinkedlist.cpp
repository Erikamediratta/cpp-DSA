#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;

};
struct node*tail=nullptr;


//creation with head is same as single linked list,just adding temp->next=head;

//creation with only tail pointer 
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
    
    if(tail==0)
    {
       tail=newnode;
       tail->next=newnode;
    }
    else{
        
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
        
    }
     
    cout<<"do you want to continue adding ?Press 1 for yes and 0 for no"<<endl;
    cin>>choice;
     }

}
void display()
{  struct node*temp;
    temp=tail->next;
    if(temp==nullptr)
    {
        cout<<"The linked list is empty"<<endl;
    }
    else{
        temp=tail->next;
    
    while(temp->next!=tail->next)
    {   cout<<temp->data<< " ";
        temp=temp->next;
        
    cout<<endl;
    }
    cout<<temp->data;
    }
}
int getlength()
{   int count=0;
    struct node*temp;
    temp=tail->next;
    while(temp->next!=tail->next)
    {
        count++;
        temp=temp->next;

    }
    count++;
    return count;
}
void insertionatbeginning(int x)// x is just here to be used and not to be modified(x itself doesn't need to be modified),so call by value is fine
{
    struct node*newnode;
    newnode=new node();
    newnode->data=x;
    if(tail->next==nullptr)
    {
        tail->next=newnode;
    }
    else{
    newnode->next=tail->next;
    tail->next=newnode;
    }
}
void insertionatend(int y)
{
    struct node*newnode;
    newnode=new node();
    newnode->data=y;
    if(tail->next==nullptr)
    {
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;

    }
}
void insertionatpos(int pos,int z)//Just using the position and value to be added and not to modify these arguements so call by value
{   int i=1;
 struct node*temp;
 temp=tail->next;
    if(pos==1)
    {
        insertionatbeginning(z);
    }
    else{
    struct node*newnode;
    newnode=new node();
    newnode->data=z;
    if(tail->next==nullptr)
    {
        tail->next=newnode;
    }
    while(pos-1>i)
    {
       temp=temp->next;
       i++;
        
    }
    newnode->next=temp->next;
    temp->next=newnode;
    }
}
void deletefrombeginning()
{   struct node*temp;
temp=tail->next;
    if(tail->next==nullptr)
    {
        cout<<"The list is empty";

        return;
    }
    else 
    {
        tail->next=temp->next;
        delete temp;
    }
}
void deletefromend()
{
     struct node*temp;
     struct node*prev;
temp=tail->next;
    if(tail->next==nullptr)
    {
        cout<<"The list is empty";

        return;
    }
    else{
        while(temp->next!=tail->next)

        {
                prev=temp;
                temp=temp->next;
        }
        prev->next=tail->next;
        tail=prev;
        delete temp;
    }
}
void deletefrompos(int pos)
{
    struct node*temp;
    struct node*prev;
    int i=1;
    temp=tail->next;
    if(pos==1)
    {
        deletefrombeginning();
    }
    else{
        while(pos>i)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        delete temp;
    }
}
void search(int x) // x is the element to be searched and x is not here to be modified so call by value is fine
{
    int i = 1;
    struct node *temp;
    temp = tail->next;
    bool found = false;

    if (tail->next == nullptr)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        do
        {
            if (temp->data == x)
            {
                cout << "Element found at " << i << endl;
                found = true;
                break;
            }
            temp = temp->next;
            i++;
        } while (temp != tail->next);

        if (!found)
        {
            cout << "Not found" << endl;
        }
    }
}

int main()
{
    create();
    cout<<"Displaying the Double linked list"<<endl;
    display();
    int length=getlength();
    cout<<"\nThe length of the linked list is " <<length<<endl; 
    insertionatbeginning(10);
    insertionatend(5);
    insertionatpos(3,5);
    cout<<"Dispaying after insertions"<<endl;
    display();
    int length2=getlength();
     cout<<"\nThe length of the updated linked list is " <<length2<<endl; 
     deletefrombeginning();
     deletefromend();
     deletefrompos(3);
     cout<<"Displaying after deletions"<<endl;
     display();
     int length3=getlength();
     cout<<"\nThe length of the updated linked list is " <<length3<<endl;
    search(4);

}//reversing left
//void create can also be done with do while loop(executes the loop at least once and then check while condition)
