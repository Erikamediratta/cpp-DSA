//Heaps are complete binary trees(CBT) and follows a heap property
//CBT is a binary tree jiske saare nodes full hote h except the last level like the last level can be unfilled also
//but another thing to keep in mind while recognising CBT is left to right filling honi chahiye if last level
//mein someone's right node is filled but left is not filled then its not a cbt though all its 
//levels are full except the last one
//heap property-max heap-parent is bda than children
//min heap-children are bde than parents
//Insertion in heap
//Insert the node at last point and check parent upar upar krke if its still chhota or else swap
//we use an array to implement heap where we keep nothing on 0th index and start filling from the first index
//parent is found at index/2 position
//left child found at 2*index
//right child is found at 2*index=1

class Heap{
public:
int arr[100];
int size;
//constructor
heap()
{
    arr[0]=-1;
    size=0;
}
void insert(int value)
{
    size=size+1;
    int index=size;
    arr[index]=value;
    //above we have inserted at last index 
    //now check 
    while(index>1)
    {
        int parent =index/2;
        if(arr[parent]<arr[index])
        {
            swap(arr[parent],arr[index] );
            index=parent;
        }
        else
        {
            return;
        }

    }
}
void deletefromheap()
{
    //to delete,we'll put the last index value at first and then place it at its correct position
    arr[1]=arr[size];
    size--;
    int i=1;
    while(i<size)
    {
        int leftindex=2*i;
        int rightindex=2*i+1;
        if(leftindex<size && arr[leftindex]>arr[i])
        {
            swap(arr[leftindex],arr[i]);
            i=leftindex;
        }
        if(rightindex<size && arr[rightindex]>arr[i])
        {
            swap(arr[rightindex],arr[i]);
            i=rightindex;
        }
        else
        {
            return;
        }
    }
    

}
//tc of insertion and deletion is O(logn)
};
void heapify(int arr[],int size,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<size && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<size && arr[right]>arr[largest])
    {
        largest=right;
    }
if(largest!=i)
{
    swap(arr[i],arr[largest]);
    heapify(arr,size,largest);
}
}
//tc O(logn)but converted to O(n)
//if wanted to made min heap just change the signs 
//and if indexing from 0 left =2*i+1 and right=2*i+2

//heap sort
void heapsort(int arr[],int size)
{
    int t=size;
  
    while(t>1)
    {
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
}//tc O(nlogn)
//Priority queues-include library queue priority_queue<int>pq;
//pq.push(2),pq.push(3) but if we do pq.front(),no matter in which order we inserted values,it will always give
//max value for max heap
//for min heap priority_queue<int,vector<int>,greater<int>pq ; pq.push(2); pq.push(1) pq.front will give 1
int main()
{
    int arr[5]={-1,2,3,4,5};
    int size=5;
    int i=1;
    for(int i=size;i>0;i++)
    {
        heapify(arr,size,i);
    }//right to left traversing

    //print heap
}