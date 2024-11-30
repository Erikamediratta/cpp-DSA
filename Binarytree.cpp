//Non linear data structure
//Basic terms-Node
//root -starting element
//parents-upar wala node
//siblings-same parents
//leaf-no child
//ancestors-go upar and upar ,they are ancestors
//children-neeche wala node

//Creating
#include <iostream>
#include<queue>

using namespace std;

class node
{
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
node* buildtree() { 
    int data;
 cout << "Enter data: ";
  cin >> data;
   if (data == -1)
    { return nullptr; }
     node* root = new node(data);
      cout << "Enter data for left of " << data << ": "; 
      root->left = buildtree();
       cout << "Enter data for right of " << data << ": ";
        root->right = buildtree(); 
return root;
}
node*leveloftraversal(node*root)
{
    queue<node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        node*temp=q.front();
         q.pop();
        if(temp==nullptr)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
           
            cout<<temp->data;
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
//inorder(LNR) preorder(NLR) postorder(LRN)
void inorder(node*root)
{
    if(root==nullptr)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void preorder(node*root)
{
    if(root==nullptr)
    {
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
void postorder(node*root)
{
    if(root==nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}
//Build from level order

void buildonlevelorder(node* &root)
{
    queue<node*>q;
    cout<<"Enter data for the root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty())
    {
        node*temp=q.front();
        q.pop();

        cout<<"Enter left node"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1)
        {
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter right node"<< temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1)
        {
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
        
    }
}
//Find number of leaf nodes
void  inorder(node*root,int &count )
{
    if(root==nullptr)
    {
        return;
    }

    inorder(root->left);

    if(root->left==nullptr && root->right==nullptr)
    {
        count++;
    }
    inorder(root->right);
}
int leafnode(node*root,int count)
{
    count=0;
    inorder(root,count);
    return count;
}
//Height of the tree (children +root)
int height(node*root)
{
    if(root==nullptr)
    {
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);

    int ans=max(left,right)+1;
    return ans;
}

//Check if identical trees
bool isidentical(node*root1,node*root2)
{
    if(root1==nullptr && root2==nullptr)
    {
        return true;
    }
    else if(root1!=nullptr &&root2==nullptr)
    {
        return false;
    }
    else if(root1==nullptr && root2!=nullptr)
    {
        return false;
    }
    bool left=isidentical(root1->left,root2->left);
    bool right=isidentical(root1->right,root2->right);
    bool curr=root1->data==root2->data;
    if(left && right && curr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Balanced tree and sum tree left (Part1 completed)


int main()
{
    node*root=nullptr;
  root = buildtree();

    leveloftraversal(root);
    
}