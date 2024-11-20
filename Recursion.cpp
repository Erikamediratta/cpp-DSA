#include<iostream>
 using namespace std;


int factorial(int n){
    //Base case and return statement in base case is mandatory
        if(n==0)
        {
            return 1;
        }

        return n*factorial(n-1);
    
}

//Fibonacci number 0 1 1 2 3 5 8 13 

int fibonacci(int n)
{
    //Base case 
    if(n==0)
    
            return 0;
    
    if(n==1)
    
        return 1;

    int ans=fibonacci(n-1)+fibonacci(n-2);
    return ans;

}
//Check if an array is sorted
bool issorted(int arr[],int size)
{
    //Base case
    if(size==0||size==1)
    {
        return true;
    }
    //solve one case
    if(arr[0]>arr[1])
    {
        return true;
    }
    bool ans=issorted(arr+1,size-1);
    return ans;
}
//get sum of an array using recursion
int sum(int arr[],int size)
{
    //Base case
    if(size==0)
    {
        return 0;
    }
    if(size==1)
    {
        return arr[1];
    }
    //solve one case
    int remainingpart=sum(arr+1,size-1);
    int sum=arr[0]+remainingpart;
    return sum;
}
//Linear search using recursion
bool linearsearch(int arr[],int size,int key)
{
    //Base case,jb ruk jaana chahiye
    if(size==0)
    {
        return false;
    }
    //solve one case
    if (arr[0]==key)
    {
        return true;
    }
    else
    {
        bool checkremaining=linearsearch(arr+1,size-1,key);
        return checkremaining;
    }
    
}
//Binary search using recursion

bool binarysearch(int arr[],int size,int start,int end,int key)
{
    //Base case
    if(start>end)
    {
        return false;
    }
    int mid=(start+end)/2;
    //solve one case
    if(arr[mid]==key)
    {
        return true;
    }
    else if(arr[mid]>key)
    {
        return binarysearch(arr,size,start,mid-1,key);
    }
    else
    {
        return binarysearch(arr,size,mid+1,end,key);
    }

    
}
//Bubble sort using recursion
void bubblesort(int arr[],int size)
{
    //Base case
    if(size==0|| size==1)
    {
        return;
    }
    //solve 1 case ,will keep the largest element at n-1 poaition
    for(int i=0;i<size-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    bubblesort(arr+1,size-1);
}
//Selection sort using recursion
//we remember that we used to find the smallest index and then swap it with arr[i]

void selectionsort(int arr[], int size) {
    // Base case
    if (size == 0 || size == 1) {
        return;
    }
    
    // Solve one case
    int smallestindex = 0; // Initialize smallestindex correctly
    for (int i = 1; i < size; i++) { // Start loop from 1
        if (arr[i] < arr[smallestindex]) { // Find the smallest element
            smallestindex = i;
        }
    }
    // Swap the found smallest element with the first element
    int temp = arr[0];
    arr[0] = arr[smallestindex];
    arr[smallestindex] = temp;
    
    // Recursively call selectionsort for the remaining array
    selectionsort(arr + 1, size - 1);
}
//Merge sort
/*
38 27 43 3 9 82 10 
divide by mid
38 27 43 3       9 82 10
divide by mid
38 27   43 3       9 82    10
*/
//Approach 
//divide by mid and then merge two sorted arrays
void merge(int arr[],int start,int end)
{
    int mid=(start+end)/2;
    //make new arrays and copy 
    int len1=mid-start+1;
    int len2=end-mid;
    //Initialise arrays
    int *arr1=new int[len1];
    int *arr2=new int[len2];
    //copy values
    int k=start;
    for(int i=0;i<len1;i++)
    {
        arr1[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        arr2[i]=arr[k++];
    }
    //made two arrays

    //merge two sorted arrays
    int index=len1+len2-1;
    int left=len1-1;
    int right=len2-1;
    while(left>=0 && right>=0)
    {
        if(arr1[left]>=arr2[right])
        {
            arr1[index]>=arr1[left];
            left--;
            index--;
        }
        else{
            arr1[index]=arr2[right];
            right--;
            index--;
        }
    }
    while(right>=0)
    {
        arr1[index]=arr2[right];
        index--;
        right--;
    }


}
void mergesort(int arr[],int size,int start,int end)
{
    //Base case
   if(start>=end)
   {
    return;
   }
   //solve one case
   int mid=(start+end)/2;

   //left part sort
   mergesort(arr,size,start,mid-1);
   //right part sort
   mergesort(arr,size,mid-1,end);


   //Merge them
   merge(arr,start,end);
}

//Quick sort
/*
3 5 1 8 2 4
pick one element and put it at its right place,left ke elements should be less than that element and right side
mein bde hote h
first do partition then recursive call
*/
int partition(int arr[],int start,int end)
{
    int pivot=arr[start];
    int count=0;
    for(int i=start+1;i<end;i++)
    {
        if(arr[i]<=pivot)
        {
           count++;
        }
       
    }
    int pivotindex=start+count;
    swap(arr[start],arr[pivotindex]);

    int i=start;
    int j=end;
    while(i<pivotindex && j>pivotindex)
    {
        while(arr[i]<pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<pivotindex && j>pivotindex)
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}
void quicksort(int arr[],int start,int end)
{
    //Base case
    if(start>=end)
    {
        return;
    }
    //partition
    int p=partition(arr,start,end);
    //left part sort
    quicksort(arr,start,p-1);
    //right part sort 
    quicksort(arr,p+1,end);
}
//Give power set of an array
//Rat in a maze problem
//Phone keypad problem

//Time and space complexity
/*TC
Linear search-O(n)
Recursive algorithms-Factorial-O(n)
Binary search-O(log n) recursive algorithms =the function like f(n-1)=T(n-1) base case=contant time say x
Mergesort-O(nlogn)
Fibonacci-O(2^n)
SC-Space reuired at ny instant of time
Binary search -Klogn so O(logn)
Mergesort-O(klogn)+O(n) so n>>>>klogn so O(n)
Fibonacci-O(n)










//Insertion sort using recursion
 int main()
 {
    int n=5;
    int ans=factorial(n);
    cout<< ans;
    return 0;
 }

 