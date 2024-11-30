//For every node,left subtree's data should be less that the root node and right subtree mein everything should
//be greater than the root node
#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d)
    {
        this->data=d;
        this->left=nullptr;
        this->right=nullptr;
    }


};

node*insertintoBST(node* root,int data)
{
    //Base case
    if(root==nullptr)
    {
        root=new node(data);
        return root;
    }

    if(data<root->data)
    {
        //left part
        root->left=insertintoBST(root->left,data);
    }
    else
    {
        //right part 
        root->right=insertintoBST(root->right,data);
    }
    return root;
}
void takeinput(node* &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        insertintoBST(root,data);
        cin>>data;
    }
}
//to print BST,copy the levelordertraversal code from binarytree.cpp and call it in main

//Search in binary search tree
bool searchBST(node*root,int val)
{
    if(root==nullptr)
    {
        return false;
    }
    if(root->data==val)
    {
        return true;
    }

    if(root->data>val)
    {
        bool searchBST(root->left);
    }
    else
    {
        bool searchBST(root->right);
    }

}

//Inorder traversal in BST always give sorted elements (LNR)

//Maximum element in BST

node*maxi(node*root)
{
    node*temp=root;
    while(temp->right!=nullptr)
    {
        temp=temp->right;
    }
    return temp;
}
//Minimum element in BST

node*mini(node*root)
{
    node*temp=root;
    while(temp->left!=nullptr)
    {
        temp=temp->left;
    }
    return temp;
}

//Deletion in BST

node*deletebst(node*root,int vali)
{
    //Base case
    if(root==nullptr)
    {
        return root ;
    }
    if(root->data==vali)
    {
        //0 child
        if(root->left==nullptr && root->right==nullptr)
        {
            delete root;
            return nullptr;
        }

        //1 child
        if(root->left==nullptr && root->right !=nullptr)
        {
            node*temp=root->right;
            delete root;
            return temp;
        }
         if(root->left!=nullptr && root->right ==nullptr)
        {
            node*temp=root->left;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=nullptr && root->right !=nullptr)
        {
                int minval=mini(root->right)->data;
                root->data=minval;
                root->right=deletebst(root->right,minval);
                return root;


        }

    }
    if(root->data>vali)
    {
        root->left=deletebst(root->left,vali);
       
        return root;
    }
    if(root->data<vali)
    {
      root->right=deletebst(root->right,vali);
        return root;
    }
}

//Inorder predecessor and inorder successor left


/*
//Merge 2 BST
//1.convert BST into sorted doubly linked list
//2. Merge two sorted linked list
//3. Converst linked list into BST


void convertbst(node*root,node* &head)
{
    //Base case
    if(root==nullptr)
    {
        return nullptr;

    }
    convertbst(root->right,head);

    root->right=head;
    if(head!=nullptr)
    {
        head->left=root;
    }
    convertbst(root->left,head);
}
//Merge two sorted linked list

//3. Converst linked list into bst
int countnodes(node*head)
{   int count=0;
    node*temp=head;
    while(temp!=nullptr)
    {       count++;
        temp=temp->next;
    }
    return count;
}
node*convertll(node*head,int cnt)
{
    //Base case
    if(cnt<=0||head==nullptr)
    {
        return nullptr;
    }
    node*left=convertll(head,cnt/2);
    
    node*root=head;
    root->left=left;
    head=head->next;
    root->right=convertll(head,cnt-cnt/2-1);

    return root;

}

node* mergebst(node*root1,node*root2)
{
    //step 1 convert bst into sorted dll
    node*head1==nullptr;
    convertbst(root1,head1);
    head1->left=nullptr;
    node*head2==nullptr;
    convertbst(root2,head2);
    head2->left=nullptr;

    //merge two sorted linked list

    //convert linked list into bst
    //function call


    //Time complexities depends and space complexities -O(h1+h2)
  

}

*/

//bst 2 parts done 1st and 4th
int main()
{   node*root=nullptr;
    cout<<"Enter data to be inserted in BST"<<endl;
    takeinput(root);
}