#include <iostream>
#include <cmath>
#include <map>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


//Q1 Reversing a single linked list

/*struct node
{
    int data;
    struct node*next;
};
struct node*head=nullptr;
*/

/*void insertatend(int data)
{   node*newnode=new node();
    node*temp=head;
    newnode->data=data;
    newnode->next=nullptr;
    if(head==nullptr)
    {
            head=temp=newnode;
    }
    else{
       while(temp->next!=nullptr)
       {
        temp=temp->next;
       } 
       temp->next=newnode;
       newnode->next=nullptr;
    }
}

void display(node*headptr)
{
    cout<<"Displaying the list"<<endl;
    struct node*temp;
    temp=headptr;
    while(temp!=nullptr)
    {  
        cout<<temp->data<<"->";
         temp=temp->next;
    }
    cout<<endl;
}

void reversell()
{
    struct node*temp;
    struct node*prev;
    struct node*next;
    temp=head;
    next=nullptr;
    prev=nullptr;
    while(temp!=nullptr)
    {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;


    }
    head=prev;
}
*/
//Q1 (a)(Second approach)-Recursion
//Q1(b)Reverse a doubly linked list
/*struct node{
    int data;
    node*next=nullptr;
    node*prev=nullptr;
} ;
node*dllhead=nullptr;
node*tail=nullptr;
*/
/*
node* reversedll(node*&dllhead)
{
        node*temp=dllhead;
        node* nextnode;
        node*previous=nullptr; //Very important to initialise to nullptr
        
        if(dllhead==nullptr)
        {
            cout<<"List is empty "<<endl;
            return nullptr;
        }
        else if(dllhead->next==nullptr)
        {
            cout<<"Only one node";
            return dllhead;
        }
        else 
        {
            while(temp!=nullptr)
            {  
               
                nextnode = temp->next;
            temp->next = previous;
            temp->prev = nextnode;
            previous = temp;
            temp = nextnode;
            }
            dllhead=previous;
        } 
     return dllhead;
}
*/


/*

//Q2(1st approach) Find middle element 

void findMiddleElement()
{   struct node*temp;
temp=head;
int length=0;
    if(head==nullptr)
    {
        cout<<"The list is empty"<<endl;

        return;
    }
    else{
        
        while(temp!=nullptr)
        {
                temp=temp->next;
                length++;
        }
    }
    int middle=length/2;
    temp=head;
    while(middle!=0)
    {
        temp=temp->next;
        middle--;
    }
    cout<<"\nMiddle element is "<<temp->data;

}
//Q2(2nd approach) Find middle element
void Findmiddleelement2()
{
    struct node*temp;
    temp=head;
    struct node*slow;
    struct node*fast;
    slow=head;
    fast=head;
    while(fast!=nullptr && fast->next!=nullptr)//fast->next!=nullptr to make sure fast->next->next is a valid operation
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"\nMiddle element is "<<slow->data<<endl;
}
*/


/*
//Q3 Reverse a linked list in k groups (if k=2 ,reverse in 2 2 ke groups)
node* kreverse(node*headptr,int k)
{   //Base Condition
      struct node*temp;
    struct node*prev;
    struct node*next;
    temp=headptr;
    next=nullptr;
    prev=nullptr;
    int count=0;
    while(temp!=nullptr && count<k)
    {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
            count++;
    } 
    if(next!=nullptr) {
    headptr->next=kreverse(temp,k);}//can also use kreverse(next,2)since temp and next will be pointing at same(try logic)

    return prev;
}
*/

/*
//Q4 Check if a circular linked list or not

bool checkcircular()
{  { if(head==nullptr)
 cout<<"List is empty"<<endl;
    return false;}

    struct node*slow;
    struct node*fast;
    slow=head;
    fast=head;
    while(fast!=nullptr and fast->next !=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;

        if(fast==head || fast->next==head)//fast->next==head just in case there are odd number of elements and fast is one pointer away
        {
            return true;
        }
    }
    return false;
}
//Q4(2nd approach)
bool checkcircular2()
{
    if(head==nullptr)
    {
        return false;
    }
    struct node*temp;
    temp=head;
    while(temp!=nullptr)
    {
        temp=temp->next;
        if(temp==head)
        {
            return true;
        }
    }
    return false;
}

*/

/*
//Q5(a) (1st approach)Loop detection(Cycle) (Floyds algorithm-space complexity O(1)and time complexity is O(n))

bool cyclepresent()
{
    node*fast=head;
    node*slow=head;

    while(fast!=nullptr && fast->next !=nullptr)
    {
            fast=fast->next->next;
            slow=slow->next;

            if(fast==slow)
            {
                return true;
            }


    }
    return false;
}
//Q5(a)(2nd approach)(space complexity O(n)and time complexity is O(n))
bool cyclepresent2()
{   struct node*temp;
temp=head;
if(head==nullptr)
{
    return false;
}
    map<node*,bool>visited; //#include <map>
    
    while(temp!=nullptr)
    {   if(visited[temp]==true)
    {
        return true;
    }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
//Q5(b) Find the length of loop

int findlength()
{
    struct node*fast;
    node*slow;
    slow=head;
    fast=head;
    struct node*temp=slow;
    int length=0;
    if(cyclepresent())
    {
        do{
            temp=temp->next;
            length++;
        }while(temp!=slow);

       
}
return length;
}


//Q5(c)Find beginning of loop

node* findbeginning()
{
    struct node*slow=head;
    struct node*fast=head;
    struct node*temp;
    if(cyclepresent())
    {   
            while(fast!=nullptr and fast->next!=nullptr)
            {
                fast=fast->next->next;
                slow=slow->next;

                if(fast==slow)
                {
                    break;
                }
            }
            slow=head;//reset one pointer to head move both at same pace until they meet again
            while(fast!=slow)
            {
                fast=fast->next;
                slow=slow->next;
            }
            cout<<"Beginning of loop is "<<slow->data;
    }
    return slow;
}

//Q5(d)Remove loop(1st approach)

void removeloop()
{   struct node*slow=head;
struct node*fast=head;
    if (cyclepresent())
    {while(fast->next!=nullptr and fast!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
        {
            break;
        }
    }
    }
    slow=head;
    while(fast!=slow)
    {
        slow=slow->next;
        fast=fast->next;
    }
    while(fast->next!=slow)
    {
        fast=fast->next;
    }
    fast->next=nullptr;
}
//Q5(d)(2nd approach)
void removeloop2()
{   struct node*temp;
    node*starting=findbeginning();
    while(temp->next!=starting)
    {
        temp=temp->next;
    }
    temp->next=nullptr; 
}
*/


/*

//Q6(a) Removing duplicates from sorted list

void removeduplicates()
{
        struct node*temp;
        temp=head;
        if(head==nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        struct node*duplicate;
        while(temp->next!=nullptr)
        {
            if(temp->next->data==temp->data)
            {
                duplicate=temp->next;
                temp->next=duplicate->next;
                delete duplicate;
                
            }
            else{
                temp=temp->next;
            }
        }
}

//Q6(b)Remove duplicates from unsorted list

void removeduplicatesunsorted() {
    struct node* temp1 = head;
    while (temp1 != nullptr && temp1->next != nullptr) {
        struct node* temp2 = temp1;
        while (temp2->next != nullptr) {
            if (temp2->next->data == temp1->data) {
                struct node* duplicate = temp2->next;
                temp2->next =duplicate->next;
                delete duplicate;
            } else {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
}
//Q6(b)(2nd approach) first sort the linked list and then same as sorted linked list function to remove duplicates
//How to sort a linked list(doubt)

*/

/*
//Q7 Split a circular list in two halves
void display2(node* headptr) {
    if (headptr == nullptr) return;
    
    node* temp = headptr;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != headptr);
    cout << headptr->data << " (back to head)" << endl; // Circular indication
}


void splitCircularList() {
    if (head == nullptr || head->next == head) {
        return; // Single node or empty list
    }
    struct node*head2;

    node* slow = head;
    node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // For even length, move fast to the end node
    if (fast->next->next == head) {
        fast = fast->next;
    }
    // Now slow is at the midpoint
    head2 = slow->next;
    slow->next = head; // First half circular

    fast->next = head2; // Second half circular

    // Display both halves
    cout << "First half: " << endl;
    display(head);
    cout << "Second half: " << endl;
    display(head2);
}
*/


/*
//Q8 Sort 0s,1s,2s in linked list(1st approach)

void sortlist()
{
    int zerocount=0;
    int onecount=0;
    int twocount=0;
    struct node*temp;
    temp=head;
    while(temp!=nullptr)
    {
        if(temp->data=0)
        {
            zerocount++;
        }
        else if(temp->data=1)
        {
            onecount++;
        }
        else if(temp->data=2)
        {
            twocount++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr)
    {
            if(zerocount!=0)
            {
                temp->data=0;
                zerocount--;
            }
            else if(onecount!=0)
            {
                temp->data=1;
                onecount--;
            }
            else if(twocount!=0)
            {
                temp->data=2;
                twocount--;
            }
            temp=temp->next;
    }

}
//Q8(2nd approach) Can't change links

void insertatend2(node* &headptr, int value) {
    node* newnodeptr = new node();
    newnodeptr->next = nullptr;
    newnodeptr->data = value;
    if (headptr == nullptr) {
        headptr = newnodeptr;
    } else {
        node* temp = headptr;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnodeptr;
    }
}


void sortlink() {
    node* zerohead = nullptr;
    node* zerotail = nullptr;
    node* onehead = nullptr;
    node* onetail = nullptr;
    node* twohead = nullptr;
    node* twotail = nullptr;

    node* temp = head;
    while (temp != nullptr) {
        if (temp->data == 0) {
            insertatend(zerohead, temp->data);
            if (zerotail == nullptr) {
                zerotail = zerohead;
            } else {
                zerotail = zerotail->next;
            }
        } else if (temp->data == 1) {
            insertatend(onehead, temp->data);
            if (onetail == nullptr) {
                onetail = onehead;
            } else {
                onetail = onetail->next;
            }
        } else if (temp->data == 2) {
            insertatend(twohead, temp->data);
            if (twotail == nullptr) {
                twotail = twohead;
            } else {
                twotail = twotail->next;
            }
        }
        temp = temp->next;
    }

    // Merge three sublists
    if (zerohead != nullptr) {
        head = zerohead;
        zerotail->next = onehead;
    } else {
        head = onehead;
    }

    if (onehead != nullptr) {
        zerotail->next = onehead;
        onetail->next = twohead;
    } else {
        zerotail->next = twohead;
    }

    if (twohead != nullptr) {
        twotail->next = nullptr;
    }
}


*/
/*
//Q9 Merge sorted lists
void insertatend2(node* &headptr,int value)//took reference because headptr needs to  be modified
{       struct node*newnodeptr=new node();
                newnodeptr->next=nullptr;
               newnodeptr->data=value;
            if(headptr==nullptr)
            {
               headptr=newnodeptr;
               
            }
            else{
                struct node*temp;
                temp=headptr;
                while(temp->next!=nullptr)
                {
                    temp=temp->next;
                }
                temp->next=newnodeptr;
                
            }
}
struct node*head3=nullptr;
node* mergesortedlists(node*head,node*head2)
{
    node*first=head;
    node*second=head2;
    while(first!=nullptr && second!=nullptr)
    {
        if(first->data<=second->data)
        {
            insertatend2(head3,first->data);
            first=first->next;
        }
        else if(second->data<=first->data)
        {
            insertatend2(head3,second->data);
            second=second->next;
        }

    }
    while(first!=nullptr)
    {
        insertatend2(head3,first->data);
         first=first->next;
    }
    while(second!=nullptr)
    {
        insertatend2(head3,second->data);
        second=second->next;
    }
    return head3;
}
*/

/*
//Q10(1st approach) Check if a linked list is palindrome or not(kisi bhi side se pdho,same number )(TC AND SC O(n))
bool palindrome(vector<int>arr)
{
    int n=0;
    int s=arr.size();
    int e=s-1;
    while(n<=e)
    {
        if (arr[n]==arr[e])
        {return true;}
        n++;
        e--;

    }
    return false;
}

bool checkpalindrome(node* headptr)
{           //converting into array first,then checking palindrome on array
            vector<int> arr;
            node*temp=headptr;
            while(temp!=nullptr)
            {
                arr.push_back(temp->data);
                temp=temp->next;
            }

            return palindrome(arr);
}

//Q10(2nd approach)
//Find Middle and second step- reverse middle ke aage wali list - and then compare first part and reversed part and then repeat the second step
node* getMid(node* head)
{
    node*fast;
    node*slow;
    fast=head;
    slow=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node*reverse(node*head)
{
        node*curr=head;
        node*next=nullptr;
        node*prev=nullptr;
        while(curr!=nullptr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
}
bool palindrome2(node*head)//(TC O(n) and SC O(1))
{       if(head==nullptr && head->next==nullptr)
        {
            return true;
        }
        node* middle=getMid(head);
        node*temp=middle->next;
        //Reverse starting from temp
        middle->next=reverse(temp);
        //Compare both halves
        node*head1=head;
        node*headnext=middle->next;
        while(headnext!=nullptr)
        {if(head1->data!=headnext->data)
        {
                return false;
        }
        else{
            head1=head1->next;
            headnext=headnext->next;
        }
        }
        //Repeat step 2 (Jaisi list thi vaisi)
        temp=middle->next;
        middle->next=reverse(temp);
        return true;
}
*/
/*
//Q11 Add linked list for ex two lists given ,1->2,2->3, output 3->5

node* reverse(node* head1)
{
    node*next=nullptr;
    node*prev=nullptr;
    node*curr=head;
    while(next!=nullptr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=prev;

    }
    return prev;
}

void insertatend(node*head,node*tail,int val)
{       node*temp=new node();
temp->data=val;
    if(head==nullptr)
    {
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}
node*add(node*first,node*second)
{
    //carry 0
    //sum find
    //find digit(sum%10)
    //create node for digit
    //carry nikalo(sum/10)
    //delete node for digit
    node*anshead=nullptr;
    node*anstail=nullptr;
    int carry=0;
    while(first!=nullptr and second !=nullptr)
    {
        int sum=carry+ first->data +second->data;
        int digit= sum%10;
        
        //Create node and add in answer linked list
        insertatend(anshead,anstail,digit);
        carry=sum/10;
        first=first->next;
        second=second->next;

    }
    while(first!=nullptr)
    {
         int sum=carry+ first->data ;
        int digit= sum%10;
        insertatend(anshead,anstail,digit);
        carry=sum/10;
        first=first->next;
    }
     while(second!=nullptr)
    {
         int sum=carry+ second->data ;
        int digit= sum%10;
        insertatend(anshead,anstail,digit);
        carry=sum/10;
        second=second->next;
    }
     while(carry!=0)
    {
         int sum=carry ;
        int digit= sum%10;
        insertatend(anshead,anstail,digit);
        carry=sum/10;
    }
        return anshead;
}

node* AddLinkedLists(node*first,node*second)
{
    //Step 1 Reverse both linked list
    //Step 2 Add numbers on linked list and add to a new linked list
    //step 3 Reverse the new linked list(answer linked list)


        first=reverse(first);
        second=reverse(second);
        node*ans=add(first,second);
        ans=reverse(ans);
    
return ans;
    
}

*/

/*
//Q12Clone a linked list with random pointers(1st approach)(TC o(n^2))
//1st step-clone normal linked list wthout random pointers
//2nd step-Two loops 
//(2nd approach)
//1st step-clone normal linked list without random pointers
//2nd step-mapping,[clone list->random]=mapping[originalnode->random]

//code(2nd approach)
struct node
{
    int data;
    struct node*next;
    struct node*random;
};
struct node*head=nullptr;
void insertatend3(node*&headptr,int val)
{   node*newnode=new node();    
    newnode->data=val;
    newnode->next=nullptr;
    if(headptr==nullptr)
    {
        headptr=newnode;
        return;
    }
    else{
    node*temp;
    temp=headptr;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    }
    

    
}
node* clonelist(node*head)
{
    node*clonehead=nullptr;
    node*temp;
    temp=head;
    while(temp!=nullptr)
    {
        insertatend3(clonehead,temp->data);
        temp=temp->next;
    }
    //step 2
    unordered_map<node*, node*>OldToNew;
    node*original=head;
    node*clone=clonehead;
    while(original!=nullptr && clone!=nullptr)
    {
        OldToNew[original]=clone;
        original=original->next;                                                   //saving mapping
        clone=clone->next;                                          

    }
    original=head;
    clone=clonehead;
    while(original!=nullptr)
    {
        clone->random=OldToNew[original->random];
        original=original->next;                                                   //copying
        clone=clone->next;   
    }
    return clonehead;
}
//(3rd approach) Don't use map
//Changing links
//step-1 Create a clone linked list without random pointers
//Step 2 Clone node add in between original nodes
//step 3 copy random pointers temp->next->random=temp->random->next;
//step 4 revert changes made in step 2 

//code approach 3 
node *clonelist2(node*head)
{       //step 1
        node*clonehead=head;
        node*temp;
    temp=head;
    while(temp!=nullptr)
    {
        insertatend3(clonehead,temp->data);
        temp=temp->next;
    }
    //step 2 
   node *originalNode=head;
   node *CloneNode=clonehead;
   while(originalNode!=nullptr && CloneNode!=nullptr)
   {
    node*Next=originalNode->next;
    originalNode->next=CloneNode;
        originalNode=originalNode->next;

        Next=CloneNode->next;
        CloneNode->next=originalNode;
        CloneNode=CloneNode->next;

   }
   //Step 3

   temp=head;
   while(temp!=nullptr)
   {
    if(temp->next!=nullptr)
    {
         temp->next->random=temp->random ? temp->random->next: temp->next;//tertiary operator
    }
    temp=temp->next->next; //two times because to reach next of original list(in step 2-made the list zic-zac)
   }
   //step 4 
   originalNode=head;
   CloneNode=clonehead;
   while(originalNode!=nullptr && CloneNode!=nullptr)
   { 
    originalNode->next=CloneNode->next;
    originalNode=originalNode->next;

    CloneNode->next=originalNode->next;
    CloneNode=CloneNode->next;

   }
   return clonehead;


}

*/

//Q13 Merge sort,Quicksort in Linked list(left)
//Q14 Flatten a linked list(left)
/*
//Q15 Intersection of two linked list
*/
struct node
{
    int data;
    node*next;
};
struct node*head=nullptr;

void insertatend3(node*&headptr,int val)
{   node*newnode=new node();    
    newnode->data=val;
    newnode->next=nullptr;
    if(headptr==nullptr)
    {
        headptr=newnode;
        return;
    }
    else{
    node*temp;
    temp=headptr;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    }
}
/*
node* intersection(node*head1,node*head2)
{
        struct node*temp;
        temp=head1;
        
        node*ans=nullptr;
        while(temp!=nullptr&& temp->next!=nullptr)
        {   node*temp2=head2;
            while(temp2!=nullptr)
            {
                if(temp->data==temp2->data)
                {
                    insertatend3(ans,temp2->data);
                    break; //once found,no need to look forward
                }
                else{
                    temp2=temp2->next;
                }
            }
            temp=temp->next;
        }
        return ans;
}


void display(node*headptr)
{
    node*temp=headptr;
    if(headptr==nullptr)
    {   cout<<"List is empty"<<endl;
        return;
    }
    else{
        while(temp!=nullptr)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
   
}
*/

/*
//Q16 Move the last element in the front

void insertionatbeg(node* &head,int val)
{   node*newnode=new node();
newnode->data=val;
newnode->next=nullptr;
   
    if(head==nullptr)
    {
        head=newnode;
    }
    else{
        
        newnode->next=head;
        head=newnode;
    }
}
node*deletionfromend(node*head)
{
    if(head==nullptr)
    {   cout<<"List is empty"<<endl;
    return nullptr;
        
    }
    else{
        node*temp=head;
   
        while(temp->next->next!=nullptr)
        {   
      
            temp=temp->next;
        }
         delete temp->next;
        temp->next=nullptr;


    }
    return head;
}

node* move(node*head)
{
    node*temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    
    insertionatbeg(head,temp->data);
    head=deletionfromend(head);
   
 return head;   
}
*/

/*
//Q17 Segregate odd and even numbers in linked list

node* oddandeven(node*headptr)
{
    node*temp=headptr;
    node*evenhead=nullptr;
    node*oddhead=nullptr;
    while(temp!=nullptr)
    {
       if(temp->data%2==0)
       {
        insertatend3(evenhead,temp->data);
       }
       else if(temp->data%2!=0)
       {
        insertatend3(oddhead,temp->data);
       }
       temp=temp->next;
    }
    //Combine/Merge two lists
    node*combinehead=nullptr;
    node*temp2=evenhead;
    node*temp3=oddhead;
    while(temp2!=nullptr)
    {
        insertatend3(combinehead,temp2->data);
        temp2=temp2->next;
    }
    while(temp3!=nullptr)
    {
        insertatend3(combinehead,temp3->data);
        temp3=temp3->next;
    }



return combinehead;
}
*/

/*
//Q18(a) count and display the pairs with a given sum in doubly linked list


node* dllHead=nullptr;

int sumofpairs(node*headptr,int x)
{
   int count=0;
  
   unordered_map<int,bool>visited;
    node*temp=headptr;
    while(temp!=nullptr)
    {   node*temp2=temp->next;
        while(temp2!=nullptr)
        {
            if(temp->data+temp2->data==x && visited[temp->data]!=true && visited[temp2->data]!=true)
            {
                count++;
                cout<<"("<<temp->data<<","<<temp2->data<<")"<<endl;
               visited[temp2->data]=true;
               visited[temp->data]=true;
            }
            temp2=temp2->next;
        }
        
        temp=temp->next;

    }
    return count;
}

//Q18(b)Count triplets with a given sum x(Won't work with map and just simply iterating)
int counttriplets(node*headptr,int x)
{
  
    int count=0;
    node*temp=headptr;
    while(temp!=nullptr)
    {
        node*temp2=temp->next;
        while(temp2!=nullptr)
        {
            node*temp3=temp2->next;
            while(temp3!=nullptr)
            {
                if(temp->data+temp2->data+temp3->data==x ){
               
                
                    count++;
                    cout<<"("<<temp->data<<","<<temp2->data<<","<<temp3->data<<")"<<endl;
                
            }
             temp3=temp3->next;
             }
           
            temp2=temp2->next;
        }
             
        temp=temp->next;

    }
    return count;
}

*/

/*
//Q19 Reverse a doubly linked list in groups of k  1->2->3->4 output= 2->1->4->3
void insertatenddll(node*&dllhead,int val)
{       node*newnode=new node();
newnode->data=val;
newnode->next=nullptr;
newnode->prev=nullptr;
if(dllhead==nullptr)
{
    dllhead=newnode;
    return;
}
    node*temp=dllhead;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    

}

node* reversedllink(node*head,int k)
{
    node*temp=head;
  
    node*nextnode;
    node*previous=nullptr; //Very important to initialise to nullptr to avoid any kind of garbage values
    int count=0;
  while(temp!=nullptr && count <k)
    {
        
        nextnode=temp->next;
        temp->next=previous;
        temp->prev=nextnode;
        previous=temp;
        temp=nextnode;
         count++;
    }

   
    if(nextnode!=nullptr )
    {
        head->next=reversedllink(nextnode,k);
        if (head->next != nullptr) {
            head->next->prev = head;
        }
    }
     return previous;
    }
   */

void displaydll(node*head)
{
    node*temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
/*
//Q20  Find the intersection point Given that intersection occurs in Y shaped linked lists

void intersectionPoint(node*head1,node*head2)
{
    node*temp=head1;
    bool Found=false;
    while(temp!=nullptr)
    {
        node*temp2=head2;
        while(temp2!=nullptr)
        {
            if(temp->data==temp2->data)
            {
                cout<<"Intersection point is "<<temp2->next->data;
                Found=true;
                break;
            }
           temp2=temp2->next; 
        }
        temp=temp->next;
         if(Found==true)
    {
        break;
    }
    }
   
}
*/

//Q21 Rotate a linked list by N nodes (https://www.geeksforgeeks.org/rotate-doubly-linked-list-n-nodes/)(left)
//Q22 Sort a nearly sorted doubly linked list k nodes(https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/)
//Q23 Multiply 2 linked list(https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1)





int main()
{
   /* insertatend(10);
    insertatend(11);
    insertatend(10);
     insertatend(13);
    insertatend(11);
    display(head);
    findMiddleElement();
    Findmiddleelement2();
    //head=kreverse(head,2);
    display(head);*/
    //head->next->next->next->next = head;(Uncommenting this line would give iscircular ? Yes)

    //bool isCircular = checkcircular2();
    //cout << "Is the linked list circular? " << (isCircular ? "Yes" : "No") << endl;

    //head->next->next->next->next = head; //for cycle detection 

        //bool isCyclePresent = cyclepresent();
    //cout << "Cycle detected (Floyd's Algorithm): " << (isCyclePresent ? "Yes" : "No") << endl;

   
    //bool isCyclePresent2 = cyclepresent2();
    //cout << "Cycle detected (Using Map): " << (isCyclePresent2 ? "Yes" : "No") << endl;

    //findbeginning();
    //removeloop();
    //bool isCyclePresent3 = cyclepresent2();
    //cout << "Cycle detected (Using Map): " << (isCyclePresent3  ? "Yes" : "No") << endl;
      //removeloop2();
    //bool isCyclePresent4 = cyclepresent2();
    //cout << "Cycle detected (Using Map): " << (isCyclePresent4 ? "Yes" : "No") << endl;
    //removeduplicates();
    //display(head);
    //removeduplicatesunsorted();
    //display(head);
    /*struct node*head2=nullptr;
    insertatend2(head,2);
    insertatend2(head,3);
    insertatend2(head,4);
    insertatend2(head2,1);
    insertatend2(head2,3);
    insertatend2(head2,4);
    node* headptr=mergesortedlists(head,head2);
    display(headptr);*/
    //Q15
    /* struct node*head2=nullptr;
    insertatend3(head,1);
    insertatend3(head,2);
    insertatend3(head,3);
    insertatend3(head,4);
    insertatend3(head,5);
    insertatend3(head,6);
    insertatend3(head2,7);
    insertatend3(head2,8);
    */
    
    //node*answer=intersection(head,head2);
    //display(answer);
    //node* answer=move(head);
    //display(answer);
    //node*answer2=oddandeven(head);
    //display(answer2);
   /* insertatend3(dllHead,3);
    insertatend3(dllHead,4);
    insertatend3(dllHead,5);
    insertatend3(dllHead,2);
    insertatend3(dllHead,1);
    insertatend3(dllHead,6);
    insertatend3(dllHead,8);


    //int ans=sumofpairs(dllHead,3);
    //cout<<"The count is "<<ans;
    int ans2=counttriplets(dllHead,12);
    cout<<"The count is "<<ans2;
    */

//insertatenddll(dllhead,3);
//insertatenddll(dllhead,4);
//insertatenddll(dllhead,5);
//insertatenddll(dllhead,6);
//node*answer=reversedllink(dllhead,2);
//displaydll(answer);
//node*ans=reversedll(dllhead);
//displaydll(ans);

//Q20
struct node*head2=nullptr;
    insertatend3(head,1);
    insertatend3(head,2);
    insertatend3(head,3);
    insertatend3(head,4);
    insertatend3(head,5);
    insertatend3(head2,3);
    insertatend3(head2,4);
    insertatend3(head2,5);
    intersectionPoint(head,head2);

   
    
        


    
   
}
