//Enque-insertion deque-deletion first come first serve or last in last out
// suppose if 2 3 in queue, front is pointing to 2 and 3 is pointing to rear
//insertion from rear end and deletion from front end
//FIFO
//Operations-insertion(),deletion(),front()/peak,isfull(),isempty()
//if queue is empty front=rear=-1
//if enque/insertion function,increment rear,dont touch or update front
//if deque function,increment or update front
//if rear >size-1 ,overflow condition
//front() function,if front>rear ,queue is empty
//time complexity-O(1),no loops required for these functions


#include<iostream>
using namespace std;

int n=5;
int queue[5];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    //insertion from rear
    if(rear==n-1)
    {
        cout<<"Overflow condition"<<endl;
    }
    if(rear==-1 && front==-1)
    {
        front++;
        rear++;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1&& rear==-1)
    {
        cout<<"Underflow condition"<<endl;
    }
    else if (front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {   cout<<queue[front];//dequed element
        front++;

    }
    
}

void display()
{
    for(int i=front;i<rear+1;i++)
    {
        cout<<queue[i];
    }
}
void peak()
{
    if(front==-1&& rear==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<queue[front];
    }
}
//Implementation of queues using linked list
//the problem with array implementation was static memory allocation,we need to define the size of n

struct node
{
    int data;
    node* next;
};
struct node*front1=nullptr;
struct node*rear1=nullptr;
void enqueue2(int x)
{
    //insertion from rear
    node*newnode=new node();
    newnode->data=x;
    newnode->next=nullptr;
    if(front1== nullptr && rear1==nullptr)
    {
        front1=rear1=newnode;
    }
    else{
        rear1->next=newnode;
        rear1=newnode;
    }
}
void dequeue2()
{
    if(front1==nullptr && rear1==nullptr)
    {
        cout<<"Underflow condition"<<endl;
    }
    else
    {   node*temp=front1;
        front1=front1->next;
        delete temp;
    }

}
void display2()
{
    if(front1==nullptr && rear1==nullptr)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        node*temp=front1;
        while(temp !=nullptr)
        {
            cout<<temp->data;
            temp=temp->next;
        }
    }
}
void peek2()
{
    if(front1 ==nullptr && rear1==nullptr)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<front1->data;
    }
}

//Circular Queue
//Drawback of normal queues-not proper memory utilisation
void enqueue3(int x)
{
    if(front==-1 && rear==-1)
    {
            front=rear=0;
            queue[rear]=x;
    }
    else if((rear+1)%n==front)
    {
        cout<<"Queue is full";
    }
    else
    {
        rear=(rear+1)%n;
        queue[rear]=x;
    }
}
void dequeue3()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(front ==rear)//One element
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%n;

    }
}
void display3()
{   int i=front;
    while(i!=rear)
    {
        cout<<queue[i]<<endl;
        i=(i+1)%n;
    }
    cout<<queue[rear];

}
//Peak function same as linear queue

//Implementation of circular queue using linked list

void enqueue4(int x)
{
    node*newnode=new node();
    newnode->next=nullptr;
    newnode->data=x;
    if(front1== nullptr && rear1==nullptr)
    {
        front1=rear1=newnode;
        rear1->next=front1;

    }
    else
    {
        rear1->next=newnode;
        rear1=newnode;
        rear1->next=front1;
    }
    
}
void dequeue4()
{
    if(front1==nullptr && rear1==nullptr)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {   struct node*temp=front1;
        front1=front1->next;
        rear1->next=front1;
        delete front1;

    }
}
void display4()
{
    struct node*temp;
    temp=front1;
    while(temp->next!=front1)
    {
        cout<<temp->data;
    }
    cout<<temp->data;
}
//peak operation same

//Implementing queue using stacks
//Using two stacks enqueue in stack1 and dequeue from stack2 
int s1[5];
int s2[5];
int top1=-1;
int top2=-1;
int count=0;
void push1(int data)
{
    if(top1==n-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        top1++;
        s1[top1]=data;
    }
}
int pop1()
{
    return s1[top1];
    top1--;
}
void push2(int data)
{
    if(top2==n-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        top2++;
        s2[top2]=data;
    }
}
int pop2()
{
    return s2[top2];
    top2--;
}
void enqueue5(int x)
{
    //Push in first stack
    if(top1==n-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        push1(x);
        count++;
    }
}
void dequeue5()
{
    if(top1==-1 && top2==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {   for(int i=0;i<count;i++)
        {int a=pop1();
        push2(a);}
        int b=pop2();
        //dequeued element is pop2
        count--;
        for(int i=0;i<count ;i++)
        {
           int a=pop2();
            push1(a);
        }
    }
}
//display function is for loop i<top1 coz stack1 contains all the elements,we have pushed elements into stack1


//Deque -double ended queue,allows insertion and deletion from both front and rear sides-because this type of queue 
//follows both lifo and fifo property
//two types-input restricted-insertion allowed from one side but deletion from both sides
//output restricted-deletion from one side but insertion from both sides
//Applications -supports multiprocessor systems,proces threads that are ready to be executed
//Both stacks and queues can be implemented

//Implementing deque using circular array

void enqueuefront(int x)
{
    if(front==n-1 && rear==n-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[front]=x;
    }
    else if(front1==0)
    {
        front=n-1;
        queue[front]=x;
    }
    else
    {
        front--;
        queue[front]=x;
    }
}

void enqueuerear(int x)
{
    if(front==n-1 && rear==n-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if(rear==0)
    {
        rear=n-1;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}
//display function is same as circular array implementation of linear queue

void dequeuefront()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(front== rear)//single element
    {
        front=rear=-1;
    }
    else if(front==n-1)
    {
        front=0;
    }
    else{
        front++;
    }
}
void dequeuerear()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(front==rear)//single element
    {
        front=rear=-1;
    }
    else if(rear==0)
    {
        rear=n-1;
    }
    else{
        rear--;
    }
}

int main()
{
    cout<<"Hello world"<<endl;
    return 0;
}

//Priority queues left