#include <iostream>
#include<stack>
using namespace std;
#include<string>
#include<vector>
//Stack implementation using array
class Stack{
    //Properties
    public:
    int size;
    int top;
    int *arr;


    //behaviour
    Stack(int size)
    {
        this->size=size;
        top=-1;
        arr= new int[size];
    }

    void push(int element)
    {
        if(top<size)
        {       top++;
            arr[top]=element;
        }
        else
        {
            cout<<"Stack is full"<<endl;//overflow
        }
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack  is empty"<<endl;//underflow
        }
        else{
            top--;
        }
    }
    int peek()
    {
        if(top>=0 && top<size)
        {
            return arr[top];
        }
        else
        {
             cout<<"Stack  is empty"<<endl;//underflow
             return -1;
        }
    }
    bool is_empty()
    {
        if(top>=0)
        {
            return false;
        }
        return true;
    }

};

//Stack implementation using linked list
class Stackll
{
//Properties
public:
int top=-1;
struct node
{
    int data;
    node*next;
};
node*head=nullptr;



void push(int element)
{      
        node*newnode=new node();
        newnode->data=element;
        newnode->next=head;
        head=newnode;
        top++;
       
}
void pop()
{
    if(top>=0)
    {   //deletefrombeginning
       node*temp=head;
       head=head->next;
       delete temp;
       top--;

    }
    else
    {
        cout<<"Stack is empty"<<endl;//underflow
    }
}

int peek()
{
    if(top<0)
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else
    {
            
            return head->data;
    }
}
bool is_empty()
{
    if(top==-1)
    {
        return true;
    }
    else{
        return false;
    }
}
};

//Implementation of two stacks in an array(stack 1 left to right and stack 2 right to left)
class TwoStack
{
//Properties
public:
int top1;
int top2;
int size;
int *arr;


//Constructor
TwoStack(int size)
{
    this->size=size;
    top1=-1;
    top2=size;
    arr=new int(size);

}

void push1(int element)
{
    if(top2-top1>1)//Atleast one empty space to push in
    {
        arr[top1]=element;
        top1++;
    }
    else
    {
        cout<<"Stack is full"<<endl;//Overflow
    }
}

void push2(int element)
{
     if(top2-top1>1)//Atleast one empty space to push in
    {
        arr[top2]=element;
        top2--;
    }
    else
    {
        cout<<"Stack is full"<<endl;//Overflow
    }
}

void pop1()
{
    if(top1>=0)
    {
        top1--;
    }
    else
    {
        cout<<"Stack is empty"<<endl;//Underflow
    }
}

void pop2()
{
    if(top2<size)
    {
        top2--;
    }
    else
    {
        cout<<"Stack is empty"<<endl;//underflow
    }
}
};

//Q3 Valid paranthesis 

bool isValidParanthesis(string expression) {
    stack<char> s;
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        // if opening bracket, push in stack
        // if closing bracket, check stack top and pop
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            if (!s.empty()) {
                char top = s.top();
                if ((ch == ']' && top == '[') || 
                    (ch == '}' && top == '{') || 
                    (ch == ')' && top == '(')) {
                    s.pop();
                } else {
                    return false; // Mismatch found
                }
            } else {
                return false; // Stack is empty but closing bracket found
            }
        }
    }
    return s.empty();
}



//Q4 Given an element,insert it at the bottom of the stack
void insert(stack<int> &inputstack,int x)
{
                if (inputstack.empty())
                {
                    inputstack.push(x);
                    return;
                }
                int num=inputstack.top();
                inputstack.pop();
                //Recursive call
                insert(inputstack,x);
                inputstack.push(num);
}

stack<int> insertatbottom(stack<int>&inputstack,int x)
{
   
   insert(inputstack,x);
   return inputstack;
}


//Q5 Reverse a stack using recursion
//step 1 put top element at side
//step 2 recursion baaki solve kr dega
//step 3 insert at bottom the first element in step 1
void insertatbottom2(stack<int>&inputstack,int x) 
{
     if (inputstack.empty())
                {
                    inputstack.push(x);
                    return;
                }
                int num=inputstack.top();
                inputstack.pop();
                //Recursive call
                insertatbottom2(inputstack,x);
                inputstack.push(num);
}

void reverse(stack<int>&inputstack )
{   //Base case
if(inputstack.empty())
    {       
        return;

    }
    int num=inputstack.top();
    inputstack.pop();

        reverse(inputstack );
    insertatbottom2(inputstack,num);
    
}




//Q6 Sort a stack with no kind of loops included

void sort(stack<int>&inputstack,int num) //same as insertatbottom but sorted insert
{      //Base case
     if(inputstack.empty() || inputstack.empty() && num>inputstack.top())
{
    inputstack.push(num);
    return;
}  
        int x=inputstack.top();
        inputstack.pop();
        sort(inputstack,num);
        inputstack.push(x);
}

void sortstack(stack<int>&inputstack)
{       
    if(inputstack.empty())
   {
    return;
   }
   int num=inputstack.top();
   inputstack.pop();
   sortstack(inputstack);
   sort(inputstack,num);

}


//Q7 Check if there are rendundant brackets or not  ((a+b)), true (a+b)false

bool checkuseless(string expression)
{
    stack<char>st;

    for(int i=0;i<expression.length();i++)
    {
        char ch=expression[i];
        if(ch==')'|| ch=='+'||ch=='/'||ch=='*'||ch=='-')
        {
            st.push(ch); 
        }  
        else
        {
            bool isRedundant=true;
        if(ch==')')
        {
           while(st.top()!='(')
           {
            char top=st.top();
            if ( top=='+'||top=='/'||top=='*'||top=='-')
            {
                isRedundant=false;
            }
            st.pop();
           }
           if(isRedundant==true)
           {
            return true;
           }
           st.pop();
        }

        }
    }
    return false;
        
} 



//Q8 Valid paranthesis

//Condition no of open braces=no of closed braces
//Every close brace should have open brace before it
//invalid {{{{{,}}}}},}}}{{{
//Doubt

//Q9 Next smaller element(https://www.geeksforgeeks.org/next-smaller-element/)

//Approach right to left scan
vector<int>nextsmallerelement(vector<int>&arr,int n)
{
    stack<int>s;
    s.push(-1);//coz right to left scan,there's no next first small element for last element in the array
   vector<int>ans(n);
   for(int i=n-1;i>=0;i--)//right to left traversal
   {    int curr=arr[i];
   while(s.top()>=curr)
   {
    s.pop();
   }
   ans[i]=s.top();
   s.push(curr);
   }
   return ans;
}

//Q10 Largest rectangle area histogram

class solution{
    private:
    vector<int>nextsmallerelement2(vector<int>arr,int len)
    {
        stack<int>s;
        vector<int>ans(len);
        s.push(-1);
        for(int i=len-1;i>=0;i--)
        {       int curr=arr[i];
            while(s.top() !=-1 && arr[s.top()]>=curr)//arr[s.top()]=element at the index stored at the top of the stack
            {
                s.pop();
            }
            //stack ka top is smaller element if out of loop
            ans[i]=s.top();
            s.push(i); //index pushed
            
        }
        return ans;
    }
    vector<int>previousSmallerElement(vector<int>arr,int len)
    {
        stack<int>s;
        s.push(-1);
        vector<int>ans(len);
        for(int i=0;i<len;i++)
        {       int curr=arr[i];
            while(s.top()!=-1 && arr[s.top()] >=curr)
            {
                s.pop();
            }
            //stack ka top is previous smaller element
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
public:
int LargestRectangleArea(vector<int> & heights){
    int len=heights.size();
    vector<int>next(len);
    next=nextsmallerelement2(heights,len);
    vector<int>prev(len);
    prev=previousSmallerElement(heights,len);
    int area=INT_MIN;
   for(int i=0;i<len;i++)
   {
    int l=heights[i];
    
    if(next[i]==-1)//[ 2 2 2 2 2 ]
    {
        next[i]=len;
    }
     int b=next[i]-prev[i]-1;
    int newarea=l*b;
    area=max(newarea,area);
   }
   return area;
}
};


//Q11 who's celebrity()
//condition-Celebrity knows no one
//everyone knows celebrity
//One approach is for loop then inside one for loop for rows and one for loop for columns to checks 0 1(Time complexity (O(n^2)))
//ignore diagonal elements coz everyone knows themselves
//all the row elements for the celebrity person is 0 and all columns elements for celebrity person is 1 except diagonal element
//2-D Vector is like a matrix only,like(vector<int>m,int n)here n is the size like 3x3 
//(2nd approach using stack)
class celebrity
{       private:
        bool knows(vector<vector<int>>&M,int a,int b,int n)
        {
                if(M[a][b]==1)//a and b are indices suppose M[1][2]
                {
                    return true;
                }
                else{
                    return false;
                }
        }
        public:
        int whoscelebrity(vector<vector<int>>&M,int n)
        {
            //Step 1 Push all the elements into the stack
            stack<int>s;
            for(int i=0;i<n;i++)
            {
                
                s.push(i); //index is pushed
            }
            //Step 2 Pop two element from the stack till the size of the stack is not one(single element present in the stack)
            while(s.size()>1)
            {
                int a=s.top(); //got an index
                s.pop();
                int b=s.top(); //got another index
                s.pop();
                if(knows(M,a,b,n))//a knows b means a can't be a celebrity
                {
                        s.push(b);
                }
                else //b knows a means b can't be celebrity
                {
                    s.push(a);
                }
            }
            //stack mein present element after the loop (single element) is a potential celebrity(still dicy)
            //Verify it
            int candidate=s.top();//Potential celebrity
            //For verifying check the row and the column
            //Rows
            bool rowcheck=false;
            int zerocount=0; //all the elements in the row should be zero
            for(int i=0;i<n;i++)
            {
                if(M[candidate][i]==0)
                {
                    zerocount++;
                }
            }
            if(zerocount==n)//all the row elements are zero
            {
                rowcheck=true;

            }
            //Column check
            bool colcheck=false;
            int onecount=0; //all the elements in the column should be one except diagonal
            for(int i=0;i<n;i++)
            {
                if(M[i][candidate]==1)
                {
                    onecount++;
                }
            }
            if(onecount==n-1)//Diagonal won't count
            {
                    colcheck=true;
            }
            if(rowcheck==true && colcheck==true)
            {
                return candidate;
            }
            else
            {
                return -1;
            }



        }
};

//Q12 Maximum rectanglular area in a binary matrix with all 1's(https://www.geeksforgeeks.org/problems/max-rectangle/1)

class Binary{
private:
 vector<int>nextsmallerelement2(int*arr,int len)
    {
        stack<int>s;
        vector<int>ans(len);
        s.push(-1);
        for(int i=len-1;i>=0;i--)
        {       int curr=arr[i];
            while(s.top() !=-1 && arr[s.top()]>=curr)//arr[s.top()]=element at the index stored at the top of the stack
            {
                s.pop();
            }
            //stack ka top is smaller element if out of loop
            ans[i]=s.top();
            s.push(i); //index pushed
            
        }
        return ans;
    }
    vector<int>previousSmallerElement(int*arr,int len)
    {
        stack<int>s;
        s.push(-1);
        vector<int>ans(len);
        for(int i=0;i<len;i++)
        {       int curr=arr[i];
            while(s.top()!=-1 && arr[s.top()] >=curr)
            {
                s.pop();
            }
            //stack ka top is previous smaller element
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int LargestRectangleArea(int*heights,int len){
    vector<int>next(len);
    next=nextsmallerelement2(heights,len);
    vector<int>prev(len);
    prev=previousSmallerElement(heights,len);
    int area=INT_MIN;
   for(int i=0;i<len;i++)
   {
    int l=heights[i];
    
    if(next[i]==-1)//[ 2 2 2 2 2 ]
    {
        next[i]=len;
    }
     int b=next[i]-prev[i]-1;
    int newarea=l*b;
    area=max(newarea,area);
   }
   return area;
}
public:
int MaxArea(int M[][100],int n,int m)
{
    //Compute area for first row
    int area=LargestRectangleArea(M[0],m);
    //Row update by adding previous row's values
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {   if(M[i][j]!=0)
        {
                M[i][j]=M[i][j]+M[i-1][j];//adding previous row's values
        }
        else{
            M[i][j]=0;
        }
            
        }
        //Entire row is updated now
        area=max(area,LargestRectangleArea(M[i],m));
    }
    return area;
}

};
//Q13 Implement N stacks in an array
//(1st approach) sizeofarray/K (k is the number of stacks),But it is not space optimised
//(2nd approach) top[] It will represent index of top element
//next[] array, two things can happen 1. It can point to next element 2.It can point to next free space
//How to recognise 1 or 2? if arr[i] stores an element then next[] will represent 1, and if nothing's stored in arr, next[] will represent 2
//Example- no of stacks=3,size of array=6
//Make top array,size will be number of stacks
//Make next[] initialise with 1 2 3 4 5 -1
//Make freespot variable- will represent index ,free list ka index
//1st query- push(10,1)
//Step 1 Find index (int index=freespot)
//Step 2 update freespot(freespot=next[index])
//step 3 insert in array(arr[index]=10)
//step 4 update next (next[index]=top[m-1])
//step 5 update top(top[m-1]=index)
class Nstack{
private:
int *arr;
int*top;
int *next;
int n;
int s;
int freespot;
public:
//Constructor
Nstack(int N,int S)
{
    n=N;
    s=S;
    arr=new int[s];
    next= new int[s];
    top=new int[n];
    //Initialise top
    for(int i=0;i<n;i++)
    {
        top[i]=-1;
    }
    //Initialise next
    for(int i=0;i<s;i++)
    {
        next[i]=i+1;
    }
    //initialise last index value of next to -1
    next[s-1]= -1;
    //Initialise freespot
     freespot=0;
}
    //Pushes 'x' into the Mth stack, return true if pushed otherwise false
    bool push(int x,int M)
    {
        //check for stack overflow
        if(freespot==-1)
        {
            return false;
        }
        //find index
        int index=freespot;
        //update freespot
        freespot=next[index];
        //insert
        arr[index]=x;
        //update next
        next[index]=top[M-1];
        //update top
        top[M-1]=index;

        return true;
    }

    int pop(int M)//returns -1 if stack is empty and popped element if popped
    {       //reverse the push operation
        //check stack underflow
        if(top[M-1]==-1)
        {
            return -1;
        }
        int index=top[M-1];

        top[M-1]=next[index];

        next[index]=freespot;

        freespot=index;
        
        return arr[index];
    }


};

//Q14 Design a stack with getMin() function with O(1) time complexity and space complexity

class SpecialStack {
    // Define the data members.
	stack<int> s;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else
        {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else
            {
                s.push(data);
            }
        }
    }
    int pop() {
        if(s.empty()){
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }
    int top() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else
        {
            return curr;
        }
    }
    bool isEmpty() {
        return s.empty();
    }
    int getMin() {
        if(s.empty())
            return -1;
        
        return mini;
    }  
};




int main(){
/*
Stack st(5);
st.push(23);
st.push(45);
st.push(36);
 
 cout<<st.peek()<<endl;
 st.pop();
 cout<<st.peek()<<endl;
 st.pop();
 cout<<st.peek()<<endl;
 st.pop();
 cout<<st.peek()<<endl;
 if(st.is_empty())
 {
    cout<<"Stack is empty"<<endl;
 }
 else{
    cout<<"Stack is not empty"<<endl;
 }
*/
/*
Stackll stl;

stl.push(43);
stl.push(22);
stl.push(36);
 cout<<stl.peek()<<endl;
 stl.pop();
 cout<<stl.peek()<<endl;
 if(stl.is_empty())
 {
    cout<<"Stack is empty"<<endl;
 }
 else{
    cout<<"Stack is not empty"<<endl;
 }

*/
 
 
    /*
//Creation
stack <int>s;
//Push operaion
s.push(2);
s.push(3);

//pop operation

s.pop();

//Top element
cout<<"Top element is "<<s.top()<<endl;
//Empty
if(s.empty())
{
    cout<<"Stack is empty"<<endl;
}
else{
    cout<<"Stack is not empty"<<endl;
}
*/
/*

//Q1 Reverse a string using stacks
string str="Love";
stack <char> s;
string ans="";

for(int i=0;i<str.length();i++)
{
 char ch=str[i];
 s.push(ch);
}

while(!s.empty())
{
char ch=s.top();
ans.push_back(ch);

s.pop();
}
cout<<ans;

*/

/*
//Q2 Delete middle element
void solve (stack <int> &inputstack,int count,int size)
{
    //Base case
    if(count==size/2)
    {
        inputstack.pop();
        return;
    }
    int num=inputstack.top();
    inputstack.pop();

    solve (inputstack, count+1, size);
    inputstack.push(num);

}

void deletemiddle(stack <int> &inputstack,int n)
{
    int count=0;
    solve(inputstack,count,n);
}
*/

}
