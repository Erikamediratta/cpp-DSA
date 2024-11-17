#include <iostream>
#include<algorithm>
using namespace std;

int binarysearch(int arr[],int size,int key)
{   int start=0;
int end=size-1;

    int mid=(start+end)/2;//what if aisi value aa jaaye jo int ke bahar nikl jaaye so start+(end-start)/2
    while(start<=end)
    {
       
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            //check left
          end=mid-1;
        }
        else 
        {
            //check right
           start=mid+1;
        }
       mid=(start+end)/2; //start+(end-start)/2
    }
    return -1;
}



//linear search
/*
just traverse and see if equal,return the index,else return -1
*/
//Binary search
/*
always applied on sorted arrays
1.Find middle element
2. check if equal,return else see which part to check,left or right
better than linear seach,less number of comparisons,o(log n) time complexity
*/


//Q1  Find first and last positions of an element in a sorted array
//(https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/)


int firstocc(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    int middle=start+(end-start)/2;
    int ans=-1;
    while(start<=end)
    {
        if(arr[middle]==key)
        {
           ans=middle;
            end=middle-1;//want to find the first and left most occurance

        }
        else if(arr[middle]>key)
        {
            end=middle-1;

        }
        else
        {
            start=middle+1;

        }
        middle=start+(end-start)/2;
    }
    return ans;
}
int lastocc(int arr[],int size,int key)
{           
    int start=0;
    int end=size-1;
    int middle=start+(end-start)/2;
    int ans=-1;
    while(start<=end)
    {
        if(arr[middle]==key)
        {
           ans=middle;
           start=middle+1;//want to find the last and right most occurance

        }
        else if(arr[middle]>key)
        {
            end=middle-1;

        }
        else
        {
            start=middle+1;

        }
        middle=start+(end-start)/2;
    }
    return ans;

}
//Q2 Peak index in a mountain array
//Q3 Find pivot element 
int getpivot(int arr[],int size)
{
    int s=0;
    int e=size-1;
    int mid=(s+e)/2;
    while(s<=e)
    {
        if(arr[mid]>=arr[0])
        {
            s=mid+1;
        }
        else
        {
            e=mid;
        }
        mid=(s+e)/2;
    }
    return s;
}

//Q4 Find the pair with a given difference
bool difference(int arr[],int size,int target)
{
    sort(arr,arr+size);
    //Two pointer technique
    int left=0;
    int right=1;
    while(right<size)
    {
        int diff=arr[right]-arr[left];
        if(diff==target)
        {
            return true;

        }
        else if(diff<target)
        {
            right++;

        }
        else
        {
            left++;
                        // Avoid left overtaking right
            if (left == right) {
                right++;
            }

        }
    }
    return false;
}      

//Q5 Count triplets with sum smaller than a given value
//(https://www.geeksforgeeks.org/count-triplets-with-sum-smaller-than-a-given-value/)

int tripletswithsumless(int arr[],int size,int target)
{   
    sort(arr,arr+size);
        int count=0;
    for(int i=0;i<size-2;i++)
    {
        int left=i+1;
        int right=size-1;
        int count=0;
        while(left<right)
        {
            if(arr[i]+arr[left]+arr[right]<target)
            {
                count=count+(right-left); //count all valid triplets at once
                left++;
            }
            else 
            {
                right--;
            }
            
        }
    }
    return count;
}

//Q5 Check if a Quadruple with given Sum Exists in an Array

bool quadruple(int arr[],int size,int target)
{       
    sort(arr,arr+size);
    for(int i=0;i<size-3;i++)
    {
        for(int j=i+1;j<size-2;j++)
        {
            int left=j+1;
            int right=size-1;
            while(left<right)
            {
                if(arr[i]+arr[j]+arr[left]+arr[right]==target)
                {
                    return true;

                }
                else if(arr[i]+arr[j]+arr[left]+arr[right]>target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }
    return false;
}

 //Q6 Missing and Repeating in an Array

 void missing(int arr[],int size)
 {
    sort(arr,arr+size);
    for(int i=0;i<size-1;i++)
    {
        if(arr[i+1]!=arr[i]+1)
        {
            cout<<"Missing element is "<<arr[i]+1;
            break;
        }
       
    }
    
 }  
//The following can also be done by above method
 void repeating(int arr[],int size)
 {
    sort(arr,arr+size);
    int left=0;
    int right=1;
    while(right<size)
    {
    if(arr[left]==arr[right])
    {
        cout<<"Repeating element is "<<arr[left]<<endl;
        left++;
        break;
    }
    else 
    {   left++;
        right++;
    }
    }
 }   

//Q7 Maximum and minimum of an array using minimum number of comparisons

int setmini(int A[], int N)
{
    int mini = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (A[i] < mini) {
            mini = A[i];
        }
    }
    return mini;
}
int setmaxi(int A[], int N)
{
    int maxi = INT_MIN;

    for (int i = 0; i < N; i++) {
        if (A[i] > maxi) {
            maxi = A[i];
        }
    }
    return maxi;
}

//Q8 Search in a rotated sorted array({8,9,1,2,3})

void rotatedsearch(int arr[],int size,int k)
{
    int pivot=getpivot(arr,size);
    //if(k>=arr[pivot] && k<=arr[n-1])
    //Apply binary search in second part 
    //binarysearch(arr,pivot,end,k);
    /*else
    {
        binarysearch(arr,0,pivot,k);
    }
    */
}//Time complexity O(logn)
//Q9 Finding square root using binary search

//Answer lies in search space if n=5 then its square root will lie between 0-5
//Find mid and check mid's square if it greater equal or less than n(Binary search)

long long int squareroot(int n)
{
    int start=0;
    int end=n;
    int mid=(start+end)/2;
   long long  int ans=-1;
    while(start<=end)
    {   int square=mid*mid;
        if(square==n)
        {
            return mid;
        }
        else if(square<n)
        {
            int ans=mid;
            start=mid+1;

        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return ans;
}
//Finding floating part
double square(int n,int p,int tempsol)//p is decimal points
{
    double factor=1;
    double ans=tempsol;
    for(int i=0;i<p;i++)
    {
        factor=factor/10;//0.1 0.01 0.001

    }
    for(double j=ans;j*j< n;j=j+factor)
    {
            ans=j;
    }
    return ans;
}

//Q10  Book Allocation problem
//(https://www.geeksforgeeks.org/allocate-minimum-number-pages/)

//Given an array,{10,20,30,40},the number of pages are given
//You have to allocate the books to m students,such that the maximum number of pages given to each student should be minimum
//m=2,n=4
//max=sum of all elements(values in array)
//search space 0-sum
//Find mid(suppose 50),m=2
//Ispossiblesolution 50 ? 1st student ko 10 yes 10+20 =30 yes 10+20+30=60 no 20 ke aage  bar
//2nd student 30<50 yes 30+40=70<50 no 30 ke aage bar
//So 50 not the solution coz 40 not occupied
//start=mid+1 search space=51-100 mid=75
//1st student 10,10+20,10+30 yes 30 ke aage bar
//2nd student 40 yes 40<75 so 75 is a possible solution then bda number will also be solution
//end=mid-1(to find minimum)(when possible solution found)
//51-74 search space mid=62
//1st student 10,10+20,30,40 no 30 ke aage bar
//2nd student 40 yes 
//end=mid-1,51-61,mid=56 so not a possible solution
//start=mid+1,mid=59 1st student 10,20,   30 no 20 ke aage bar,2nd student 30 yes 30+40 no ,59 not solution
//start=mid+1,mid=60,1st student 10,20,30 yes 40 no so 2nd student 40 yes,possible solution


bool ispossiblesolution(int arr[],int size,int m,int mid)
{   int student=1;
int pagesum=0;
    for(int i=0;i<size;i++)
    {
      if(pagesum+arr[i]<=mid)
      { pagesum=pagesum+arr[i];
       
      }
      else
      {
        student=student+1;
        if(student>m ||arr[i]>mid)
        {
                return false;
        }
        pagesum=arr[i]; //if  condition se agar bahar aa gye
      }

    
    }
    return true;
}

int bookallocation(int arr[],int size,int m)
{
    int start=0;
    int sum=0;
    int ans=-1;
    for(int i=0;i<size;i++)
    {
        sum=sum+arr[i];
    }
    int end=sum;
    int mid=start+(end-start)/2;

    while(start<=end)
{
        if(ispossiblesolution(arr,size,m,mid))
        {   ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
        mid=start+(end-start)/2;
}
return ans;
}


//Q11 Painters Partition Problem
//Given an array and k number of painters
//1 unit board painting takes 1 unit of time
//Minimum  time required
//similar to book allocation problem
//search space 0-sum arr={5,5,5,5} mid=10 (k=2)
//1st painter 5 yes 10 yes 5,5 ,5 no  
//2nd painter 5,5 yes possible soution exists
//end=mid-1 0-9 mid=4
//1st painter no 5>4 no possible solution exists
//start=mid+1 5-9 mid=7
//1st painter 5 yes 5,5 no
//2nd painter 5,5 no solution exists
//start=mid+1 8-9 mid =8
//1st painter 5 yes
//2nd painter 5 no 3rd 5 se cant give no possible solution
//start=mid+1 mid=9
//no possible solution exists
//start 10 end 9 no

bool ispossiblesolution2(int arr[],int size,int k,int mid)
{
    int painter=1;
    int element=0;
    for(int i=0;i<size;i++)
    {
        if(element+arr[i]<=mid)
        {
            element=element+arr[i];

        }
        else
        {
            painter=painter+1;
            if(painter>k ||arr[i]>mid)
            {
                return false;
            }
            element=arr[i];
        }
    }
    return true;
}

int painterspartition(int arr[],int size,int k)
{
    int start=0;
    int sum=0;
    int ans=-1;
    for(int i=0;i<size;i++)
    {
        sum=sum+arr[i];
    }
    int end=sum;
    int mid=start+(end-start)/2;
    while(start<=end)
    {
    if(ispossiblesolution2(arr,size,k,mid))
    {       ans=mid;
        end=mid-1;
    }
    else
    {
        start=mid+1;
    }
        mid=start+(end-start)/2;
    }
 return ans;   
}

/* The essence of both the painter's partition and book allocation problems lies 
in minimizing the maximum workload (or pages) assigned to any painter (or student) 
Principle- Distribute the total workload such that the maximum workload assigned to
any single entity is minimized.*/

//Question of arrays(file)
//Chocolate distribution problem
//(https://www.geeksforgeeks.org/chocolate-distribution-problem/)read question


bool possiblesolution(int arr[], int size, int m, int mid) {
     {for(int i=0;i+m-1<size;i++)
        if (arr[i + m - 1] - arr[i] <= mid) {
            return true;
        }
    }
    return false;
}
int chocolatedistribution(int arr[], int size, int m) {
    if (size < m) {
        return -1; // Not enough packets for each student
    }

    sort(arr, arr + size); // Sort the array

    int start = 0;
    int end = arr[size - 1] - arr[0]; // Maximum possible difference
    int ans = INT_MAX;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (possiblesolution(arr, size, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

//Q11 Aggressive cows
//return the largest minimum distance
//suppose arr given={4,2,1,3,6}cows=2

bool possiblesol(int arr[],int size,int k,int mid)
{
    int cowcount=1;
    int lastpos=arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]-lastpos>=mid)
        {
            cowcount++;
            lastpos=lastpos+arr[i];
        }
        if(cowcount==k)
        {
            return true;
        }
        lastpos=arr[i];

    }
    return false;
    }

int aggressivecows(int arr[],int size,int k)
{
sort(arr,arr+size);
int start=0;
int end=arr[size-1]-arr[0];
int mid=start+(end-start)/2;
int ans=INT_MAX;
while(start<=end)
{
    if(possiblesol(arr,size,k,mid))
    {   ans=mid;
        start=mid+1;//because largest instead of minimising
    }
    else
    {
        end=mid-1;
    }
    mid=start+(end-start)/2;
}
return ans;
}

//Q12 Kth element of two sorted arrays
//(https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/)
void mergetwosorted(int arr1[],int size1,int arr2[],int size2)
{
    //Assuming that arr1 has enough space for arr2's elements, like its size is size1+size2 but has elements till size1
    //Step 1 
    int index=size1+size2-1;
    int first=size1-1;
    int second=size2-1;
    //step 2-backward traversing
    while(first>=0 && second>=0)
    {
        if(arr1[first]>=arr2[second])
        {
           arr1[index]=arr1[first];
            index--;
            first--;
        }
        else
        {
            arr1[index]=arr2[second];
            index--;
            second--;

        }
       
    }
    //Now two things can happen,one is first could have been equal to zero or less than it or second could be the same
    //if second is equal to zero then its elements are already in place,check by doing
    //but if first is out of place the,
    while(second>=0)
    {
         arr1[index]=arr2[second];
            index--;
            second--;
    }
}


int search(int arr[],int size,int k)
{
    return arr[k-1];
}
//Q13 Find the missing number in Arithmetic Progression
//(https://www.geeksforgeeks.org/find-missing-number-arithmetic-progression/)
//Sum of the n elements = (n/2)(a+l)
//n is the number of elements, a is the first element and l is the last element

int apmissing(int arr[],int n)
{    int a,l,s;
    a=arr[0]; 
    l=arr[n-1]; 
      if((a+l)%2==0) /* ensuring this as n/2(a+l) and (a+l)/2 
                      would give different values programmatically */
    { 
        s = (a+l)/2; 
        s = s*(n+1); 
    } 
    else
    { 
        s = (n+1)/2; 
        s = (a+l)*s; 
  
    } 
      int sum=0;
      for(int i=0;i<n;i++)
      {
        sum=sum+arr[i];
      }
      return s-sum;

}
//Sorting techniques

//Bubble sort
//Comparing adjacent elements and swapping

void bubblesort(int arr[],int size)
{for(int i=0;i<size;i++)//outer loop 
{   //bool isswap=false;
    for(int j=0;j<size-i-1;j++)
{
        if(arr[j]>arr[j+1])
        {
           swap(arr[j],arr[j+1]);
           //bool isswap=true;
        }

       
}
/*if (isswap==false)
{
    //return;
}
*/
}


//Selection sort
//Assume the smallest element is first element
//two parts sorted and unsorted

        
for(int i=0;i<size;i++)
{
        cout<<arr[i]<<endl;
}
}
void selectionsort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int smallestindex=i;//smallest maan liya i
        for(int j=i+1;j<size;j++)//finds the smallest element
        {
                if(arr[j]>arr[smallestindex])
                {
                    smallestindex=j;//smallestindex=j
                }
        }
        swap(arr[smallestindex],arr[i]); //swapping 
    }
}

//Insertion sort
//{4,1,5,2,3}Assuming first element is sorted(4 is sorted part else is unsorted part)
//pick first element from unsorted part,take variable curr=1
//take variable prev and compare it with prev+1,now sorted part consists of 2 elements
//curr=5 compare 4 with 5 now sorted part consists of 3 elements and unsorted 2 elements
//curr 2 check 5 with 2,and so on

void insertionsort(int arr[],int size)
{
    for(int i=1;i<size;i++)//started loop with 1 coz starting unsorted part from there
    {
       int curr=arr[i];
       int prev=i-1;
       while(prev>=0 && arr[prev]>curr)
       {
            arr[prev+1]=arr[prev];
            prev--;
       }
       arr[prev+1]=curr; //placing current in its correct position
    }
}
//Changing <> we can do descending order

// Q14 Product of array except self
//(https://www.geeksforgeeks.org/product-array-puzzle-set-2-o1-space/)

//Bruteforce
void prodarray(int arr[],int size)
{       
        vector<int>ans(size,1); //ans vector
    for(int i=0;i<size;i++)//0 se start j 0 se start hoga and ith index of ans pr product(except i) store kr dega
    {
        int prod=1;
        for(int j=0;j<size;j++)
        {
            if(i!=j)
            {
                prod=prod*arr[j];
            }
        }
        ans[i]=prod;
    }
}
//Time complexity O(n^2)
//Optimised approach
//left ka product* left product
void productarray(int arr[],int n)
{       
    vector<int>prefix(n,1);
    prefix[0]=1;
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]*arr[i-1];
    }
    vector<int>suffix(n,1); //right to left traversing
    suffix[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        suffix[i]=suffix[i+1]*arr[i+1];
    }
    vector<int>ans(n,1);
    for(int i=0;i<n;i++)
    {
        ans[i]=prefix[i]*suffix[i];
    }

}
//TC and SC O(n)
void optimalproductarray(int arr[],int n)
{       
    vector<int>ans(n,1);
   
    for(int i=1;i<n;i++)
    {
        ans[i]=ans[i-1]*arr[i-1]; //directly into ans without prefix vector
    }
   int suffix=1;
    for(int i=n-2;i>=0;i--)
    {       suffix=suffix*arr[i+1];
        ans[i]=suffix*arr[i];
    }
}//TC O(n) SC O(1)
//Explanation
/*{1,2,3,4}
ans arr={1,1,2,6} suffix =1 for 6 now 1*6 =6
for 2nd last element suffix=1*4=4 and ans element 2 4*2 =8
for 3rd last element suffix=4*3=12 and ans element 1 12*1 =12
for 4th last element suffix=4*3*2=24 and ans element 1 24*1=24
*/

//Q15 Container with most water

//Brute force Approach
/*pick two lines 
//all possible containers nikalo
right boundary is starting with i+1
now find water in these conatiners- width=j-1 height = whichever is small in i and j,area=height*width
now compare them ans=max(area,ans);
*/
int mostwater(int arr[],int size)
{
     int ans=0;
for(int i=0;i<size;i++)
{  
    for(int j=i+1;j<size;j++)
    {
        int height=min(arr[i],arr[j]);
        int width=j-i;
        int currwater=height*width;
        ans=max(ans,currwater);
    }
}
return ans;
}//TC O(n^2)

//Optimised approach
//Explanation
/*
right(bdi height)se left jaayenge to water decrease hii hoga (bdi to chhoti height)
same goes for bdi to equal height(right to left)
bdi to chhoti krne ka no point
go from chhoti height to bdi height left to right
*/
int container(int arr[],int size)
{   //  Two pointer approach
    int lb=0;
    int rb=size-1;
    int ans=0;
    while(lb<rb)
    {
        int width=rb-lb;
        int height= min(arr[lb],arr[rb]);
        int currwater=width*height;
        ans=max(ans,currwater);
        arr[lb]<arr[rb]?lb++ : rb--;//vo change kro jo change laa rha h that is min height
    }
    return ans;
}//O(n)TC


//Q16 Merge overlapping intervals
//(https://www.geeksforgeeks.org/merging-intervals/)
//Explanation
/*
sort the intervals if merged list ke last mein jo interval h iska second element is bda or equal to current
interval's first,then there's overlapping and we'll merge them,else we'll add the current interval into
the merged list
Input: arr[] = [[1, 3], [2, 4], [6, 8], [9, 10]]
Output: [[1, 4], [6, 8], [9, 10]]

*/
void mergeintervals(vector<pair<int,int>>&interval)
{   //Sorting
    sort(interval.begin(),interval.end());
    vector<pair<int,int>>mergelist;
    mergelist.push_back(interval[0]);
    for(int i=1;i<interval.size();i++)
    {
        if(mergelist.back().second>=interval[i].first)//back() gives last pair in mergelist
        {
            //Overlapping is there
            mergelist.back().second=max(mergelist.back().second,interval[i].second);
        }
        else{
            mergelist.push_back(interval[i]);//interval[i]contains a pair
        }
    }
}

//Q16 Find the kth smallest number again
//(https://www.geeksforgeeks.org/find-k-th-smallest-element-in-given-n-ranges/)
void kthsmallest(vector<pair<int,int>>interval,int size,int queries[],int size2)
{
    //Sorting
    sort(interval.begin(),interval.end());
    vector<pair<int,int>>mergelist;
    mergelist.push_back(interval[0]);
    for(int i=1;i<interval.size();i++)
    {
        if(mergelist.back().second>=interval[i].first)//back() gives last pair in mergelist
        {
            //Overlapping is there
            mergelist.back().second=max(mergelist.back().second,interval[i].second);
        }
        else{
            mergelist.push_back(interval[i]);//interval[i]contains a pair
        }
    }
        //flatten the merge intervals
        vector<int>flattened;
        for(auto interval:mergelist)
        {
            for(int i=interval.first;i<=interval.second;i++)
            {
                    flattened.push_back(i);
            }
        }
        //now print the queries by running a for loop and flattened[k] return where k=queries[i]
}

//Q17 Single element in a sorted array
//arr={1,1,2,2,3,3,4,4,5} return 5 since every element occur twice and 5 occur once
//Brute force
int singlelement(int arr[],int size)
{
   unordered_map<int,int> visited;
   for(int i=0;i<size;i++)
   {
    visited[arr[i]]++;
   }
   for(int i=0;i<size;i++)
   {
        if(visited[arr[i]]==1)
            {
                return arr[i];
            }
   }
   
return -1; 
}
//Optmised approach

int single(int arr[],int size)
{
    //Binary search
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    if(size==1)
    {
        return arr[0];
    }
    while(start<=end)
    {   //handlin exceptions 
    if(mid==0 && arr[mid]!=arr[mid+1])
    {
        return arr[mid];
    }
    if(mid==size-1 && arr[mid]!=arr[mid-1])
    {
        return arr[mid];
    }
        if(arr[mid-1]!=arr[mid] && arr[mid]!=arr[mid+1])
        {
            return arr[mid];
        }
        //even number of elements on both left and right
        //if mid-1 and mid are equal then left part has odd number of elements ans is there
        //if mid is equal to mid +1 then right part has odd number of elements ans is there
        // odd number of elements on both left and right
        //if mid-1 equal to mid then even numbers on left so ans is on right part
        //if mid is equal to even then even element on both sides and vice versa
        else if(arr[mid-1]==arr[mid]&& mid%2==0)
        {
            end=mid-1;
        }
        else if(arr[mid+1]==arr[mid]&& mid%2==0)
        {
            start=mid+1;
        }
        else if(arr[mid-1]==arr[mid]&& mid%2 !=0)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
//Next permutation
//A={1,2,3}lexographic order,every number is greater than previous number(permutation)
//in place changes,no additional space should be used
//Bruteforce
//Find all the permutations(will be found by recursion),find lexographically next permutation

//Optimised approach
//starting part is same,there is one special character that changes in next lexographically order
//12543 4>3 5>4 2<5 so 2 is that special character
//123654   next-124356
//1st step-find the pivot element
//2nd step-find the rightmost element greater than pivot element
//3rd step-swap that element with 4 124653
//4th step- continue later
//majority element left
//Minimum number of swaps to sort an array,make it a palindrome


int main()
{
    int arr[5]={1,2,3,4,5};
    int odd=binarysearch(arr,5,3);
    cout<<odd<<endl;
    int evenarr[6]={1,2,3,4,5,6};
     int even=binarysearch(evenarr,6,3);
    cout<<even<<endl;
    //Q1
    int ques1[6]={1,2,3,3,4,5};
    int left=firstocc(ques1,6,3);
    cout<<"First occurance "<< left<<endl;
    int right=lastocc(ques1,6,3);
    cout<<"last occurance "<< right<<endl;
        //total number of occurance =(right occ-left occ)+1
        //Q6
       int missingarr[] = {3, 1, 3};
       missing(missingarr,3);
       repeating(missingarr,3);
       //Q9
       int ans=squareroot(25);
       cout<<ans;
int chocolatearr[7] = {7, 3, 2, 4, 9, 12, 56};
int chocolateans=chocolatedistribution(chocolatearr,7,5);
cout<<chocolateans;
int aparr[6]  = {2, 4, 8, 10, 12, 14};
int apmissing1=apmissing(aparr,6);
cout<<apmissing1;
int singlelementarr[13]={1,1,2,2,3,3,4,4,5,5,6,7,7};
int single1=single(singlelementarr,13);
cout<<single1;



    
}