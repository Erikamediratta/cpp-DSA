#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int arr[5];
int top=-1;

void push()
{
    int x;
    cout<<"Enter element"<<endl;
    cin>>x;
    if(top==4)
    {
        cout<<"Overflow"<<endl;
    }
    else{
        top++;
        arr[top]=x;
    }
}
void pop()
{
        int item;
        if(top==-1)
        {
            cout<<"Underflow"<<endl;
        }
        else{
            item=arr[top];
            top--;
            cout<<"Popped element is "<<item<<endl;
        }
}
void peek()
{
    if(top==-1)
    {
        cout<<"Underflow"<<endl;
    }
    else{
        cout<<"The topmost element in the stack is "<<arr[top]<<endl;
    }
}
void display()
{
    for(int i=top;i>=0;i--)
    {   cout<<"Displaying the elements of the stack"<<endl;
        cout<<arr[i]<<endl;
    }
}
 void postfixeval(string exp)//evaluating and not modifying the string expression so call by value
{
   stack<int> s;
   for(int i=0;i<exp.length();i++) {//till length will iterate and then will check if exp[i] is a digit or not(left to right scanning)
        if (isdigit(exp[i])) {
            s.push(exp[i] - '0');
        }
        else{
            int val1=s.top();// value stored
            s.pop();//element popped from stack
            int val2=s.top();// value stored
            s.pop();//element popped from stack
            switch(exp[i])
            {
                case '+':
                {s.push(val2+val1);
                break;}
                
                    case '-':
                    {

                    s.push(val2-val1);
                    break;
                }
                case '*':
                {
                s.push(val2*val1);
                    break;
                }
                case '^':
                {
                    s.push(pow(val2,val1));
                    break;
                }
                case '/':
                {
                    s.push(val2/val1);
                    break;
                }
            }
           
        }
    }
    cout << "Result of postfix evaluation: " << s.top() << endl;
}

void prefixeval(string exp)
{
   stack<int> s;
    for(int i=exp.length()-1;i>=0;i--) {// start from indexing 4 if the length is 5,till i is greater or equal to 0(right to left scanning)
        if (isdigit(exp[i])) {
            s.push(exp[i]- '0');
        }
        else{
            int val1=s.top();// value stored
            s.pop();//element popped from stack
            int val2=s.top();// value stored
            s.pop();//element popped from stack
            switch(exp[i])
            {
                case '+':
                {s.push(val1+val2);
                break;}
                
                    case '-':
                    {

                    s.push(val1-val2);
                    break;
                }
                case '*':
                {
                s.push(val1*val2);
                    break;
                }
                case '^':
                {
                    s.push(pow(val1,val2));
                    break;
                }
                case '/':
                {
                    s.push(val1/val2);
                    break;
                }
            }
           
        }
    }
    cout << "Result of prefix evaluation: " << s.top() << endl;
}
 


int main() {
    
    push();
    push();
    display();
    pop();
    peek();
    postfixeval("231*+9-");
    prefixeval("-+23*19");
    return 0;
}//switch case can be added in main for different function choices
