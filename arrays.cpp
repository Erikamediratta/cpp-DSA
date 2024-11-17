#include <iostream>
#include<vector>
#include<algorithm> //for unique() and sort()  functions
#include<unordered_set>

using namespace std;

void printarray(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<< " ";
    }
}

int minimum(int arr[],int size)
{       
   int min=INT_MAX;
    for(int i=0;i<size;i++)
    {       //Pre defined function min=min(min,arr[i]);
        if(arr[i]<min)
        {
               min=arr[i];
        }
    }
    return min;
}
int maximum(int arr[], int size)
{
    int max=INT_MIN;
    for(int i=0;i<size;i++)
    {            //Pre defined function max=max(max,arr[i]);
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}
void reverse(int arr[],int size)
{
    int revarr[size];
    for(int i=0;i<size;i++)
    {                                                                       //can also be done using swap(no extra space will be used) 
                                                                                /*start =0;end=n-1;
                                                                                while(start<=end)
                                                                                {
                                                                                    swap(arr[start],arr[end]);
                                                                                    start++;
                                                                                    end--;
                                                                                }
                                                                                */
        revarr[i]=arr[size-1-i];
    }
  for(int i=0;i<size;i++)
  {
    cout<<revarr[i]<<" ";
  }
}
void sort(int arr[], int size)
{
    int zerocount=0;
    int onecount=0;
    int twocount=0;
    int count=0;

    for(int i=0;i<size;i++)
    {
        if(arr[i]==0)
        {
            zerocount++;
        }
        else if(arr[i]==1)
        {
            onecount++;
        }
        else if(arr[i]==2)
        {
            twocount++;
        }
    }
    while(zerocount>0)
    {
        for(int i=0;i<size && zerocount>0 ;i++)
        {
            arr[i]=0;
             zerocount--;
             count++;

        }
       
    }
     while(onecount>0)
    {
        for(int i=count;i<size && onecount>0 ;i++)
        {
            arr[i]=1;
             onecount--;
             count++;

        }
       
    }
     while(twocount>0)
    {
        for(int i=count;i<size && twocount>0 ;i++)
        {
            arr[i]=2;
             twocount--;

        }
       
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void assign(int arr[],int size)
{       
    int last=arr[size-1];
    for(int i=size-1;i>=0;i--)//using values before they get changed,else will overwrite element if done left to right traversing
    {  
        arr[i]=arr[i-1];
       
    }
    arr[0]=last;
    
 


    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void unionarray(int arr[],int size1,int arr2[],int size2)
{               int size3=size1+size2;
           vector<int> unionarr;
           //Vector doesn't support fixed size arrays so no unionarr[size3]
           //instead
           unionarr.reserve(size3);//Reserves space
           for(int i=0;i<size1;i++)
           {
            unionarr.push_back(arr[i]);
           }
           for(int i=size1;i<size2;i++){
            unionarr.push_back(arr2[i]);
           }
           //Remove duplicates

           sort(unionarr.begin(),unionarr.end());//to ensure all the duplicates are next to each other and so that unique can work properly
            auto last=unique(unionarr.begin(),unionarr.end());//it returns an iterator to last unique element in the vector 
            //auto type can be understood as "let the compiler predict the type of the variable"
            unionarr.erase(last,unionarr.end());
            //erases since last will point to the last unique element's iterator so after that will be duplicates if  any

//Printing array
for(int i=0;i<unionarr.size();i++)
{
    cout<<unionarr[i]<<" ";
}
}

void intersection(int arr[],int size1,int arr2[],int size2)
{     int size3=size1+size2;  
    vector<int>ans;
    ans.reserve(size3);

   for(int i=0;i<size1;i++)
   {
    for(int j=0;j<size2;j++)
    {
        if(arr[i]==arr2[j])
        {
            ans.push_back(arr[i]);
            break;
        }
    }
   } 

   for(int i =0;i<ans.size();i++)
   {
    cout<<ans[i]<<" ";
   }
}
//more optimised solution,below is the two pointer approach

void intersection2(int arr1[],int size1,int arr2[], int size2)
{       vector<int>ans;
    int i=0;
    int j=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]==arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;

        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else{
            j++;
        }
    }
}

void pairssum(int arr[],int size,int x)
{           
    unordered_map<int,bool>visited;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]+arr[j]==x && visited[arr[i]]!=true && visited[arr[j]]!=true)
            {
                cout<<"["<<arr[i]<<","<<arr[j]<<"]"<<endl;
                 visited[arr[j]]=true;
                 visited[arr[i]]=true;
            }
           
        }
        
    }
}

void tripletssum(int arr[], int size,int x)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            for(int k=j+1;k<size;k++)
            {
                if(arr[i]+arr[j]+arr[k]==x)
                {
                    cout<<"["<<arr[i]<<","<<arr[j]<<","<<arr[k]<<"]"<<endl;
                }
            }
        }
    }
}
//More optimised solution for counting triplets
void findTriplets(int arr[], int size, int sum) {
    std::sort(arr, arr + size); // Sort the array

    for (int i = 0; i < size - 2; i++) {
        int left = i + 1;
        int right = size - 1;

        while (left < right) {
            int currentSum = arr[i] + arr[left] + arr[right];

            if (currentSum == sum) {
                std::cout << "[" << arr[i] << ", " << arr[left] << ", " << arr[right] << "]\n";
                left++;
                right--;
            } else if (currentSum < sum) {
                left++;
            } else {
                right--;
            }
        }
    }
}//This has  O(n^2) complexity as compared to O(n^3) in our solution

void findduplicates(int arr[],int size)
{
    //in O(n) TC and O(n) SC
    unordered_map<int,bool>visited;
    for(int i=0;i<size;i++)
    {
        if(visited[arr[i]]==true)
        {
            cout<<arr[i];
          }
        else{
        visited[arr[i]]=true;
        }
    }
}

void common2(int arr1[],int size1,int arr2[],int size2,int arr3[], int size3)
{
    unordered_set<int>set1(arr1,arr1+size1);
    unordered_set<int>set2(arr2,arr2+size2);

    for(int i=0;i<size3;i++)
    {
        if(set1.find(arr3[i])!=set1.end() && set2.find(arr3[i])!= set2.end())
        {
            cout<<arr3[i];
        }
    }

}
//Sets are used for fast lookups, here we made two sets of arr1 and arr2, and iterated through arr3
//set1.find(arr3[i]) returns an iterator to where the element arr3[i] is found in arr1 
//if not found,it returns an iterator to the end so thats why condition is set1.find(arr3[i])!=set1.end()
//similarly for set2 

void unique(int arr[],int size)
{
    vector<int>res;
    for(int i=0;i<size;i++)
    {
        res.push_back(arr[i]);
    }
    sort(res.begin(),res.end());
    auto last=unique(res.begin(),res.end());
    res.erase(last,res.end());

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
}
void unique2(int arr[],int size)//this approach/sets doesn't maintain order of elements
{
    unordered_set<int>set1(arr,arr+size); // automatically removes the duplicates
    for(auto i=set1.begin();i!=set1.end();i++)
    {
        cout<<*i<<" "; //since i is an iterator/pointer  so need to dereference it
    }
}

void unique3(int arr[],int size)
{
    unordered_map<int,bool>visited;

    for(int i=0;i<size;i++)
    {
        if(visited[arr[i]]!=true)
        {
            cout<<arr[i]<<" ";
            visited[arr[i]]=true; //only mark the element as visited if it hasn't been visited before, right after you print it.
          
        }
      
    }
}

void nbyk(int arr[],int size,int k)
{
        unordered_map<int,int>visited;
        for(int i=0;i<size;i++)
        {
            visited[arr[i]]++;
        }
        int threshhold=size/k;
        for(auto i=visited.begin();i!=visited.end();i++)//just like sets,normal for loop won't work for maps as well
        {
            if(i->second>threshhold)
            {
               cout<<i->first<<" ";
            }
        }
}
//First and second refers to key value pairs in maps,first is the element and second is the count of that element
//Note-just like set1.find(something)!=set1.end(), it is same for maps,iteration is also same for maps and sets
//just sets use dereferencing and in maps,map->first and map->second

void kmax(int arr[],int size,int k)
{
    vector<int>res;
    for(int i=0;i<size;i++)
    {
        res.push_back(arr[i]);
    }
    sort(res.begin(),res.end());
    int kmax=res.size()-k;

    cout<<res[kmax]<<endl;
}

void kmin(int arr[],int size,int k)
{
    vector<int>res;
    for(int i=0;i<size;i++)
    {
        res.push_back(arr[i]);
    }
    sort(res.begin(),res.end());
    cout<<res[k-1]<<endl;
}


void swapalternate(int arr[],int size)
{
    for(int i=0;i<size;i=i+2)
    {   if(i+1<size)
    {
        swap(arr[i],arr[i+1]);
    }
        }

        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
}

//xor-property a xor a=0 so unique element xan be find out as traversing and then ans=ans^arr[i] (xor= ^)(ans xor arr[i])

//Finding duplicates in a sorted array
void duplicatesorted(int arr[],int size)
{
    for(int i=0;i<size-1;i++)//size-1 because accessing arr[i+1] so to avoid being out of bounds
    {
        if(arr[i]!=arr[i+1])
        {
                continue;
        }
        else
        {
            cout<<arr[i]<< " ";
        }
    }
}
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

void swapposneg(int arr[], int size) {
    int first = 0; // Pointer to place positive numbers at even indices
    int second = 1; // Pointer to place negative numbers at odd indices

    while (first < size && second < size) {
        // Find a positive number at an even index
        while (first < size && arr[first] > 0) {
            first += 2;
        }
        // Find a negative number at an odd index
        while (second < size && arr[second] < 0) {
            second += 2;
        }
        
        // Swap the elements to maintain alternating positive and negative numbers
       {
            std::swap(arr[first], arr[second]);
        }
    }
}

//Two pointer approach is ki check if sahi jagah pr h to thik aage krte jaao,elsee swapppp
//Just check if alternate keeping,then initialise pointers that way, if segregating like something on left and something on right
//then start one from start and two from end 
void sortone(int arr[],int size)
{
    //two pointer approach ek start mein ek end mein
    int first=0;
    int second=size-1;
    while(first<second)
    {
        if(arr[first]==0)
        {
        first++;
        }
        else if(arr[second]==1)
        {
            second--;
        }
        //Now two things can happen,arr[first]=1 and arr[second]== in that case,swap
        else{
            swap(arr[first],arr[second]);
            first++;
            second--;
        }
    }
}

void medianequal(int arr1[],int size1,int arr2[],int size2)
{
    //Since O(n) space is allowed
    vector<int>ans;
    //Step 1 merge two sorted arrays
    int i=0;
    int j=0;
    while(i<size1 && j<size2)
    {
            if(arr1[i]<arr2[j])
            {
                ans.push_back(arr1[i]);
                i++;
            }
            else{
                ans.push_back(arr2[j]);
                j++;
            }
    }
     //since they are of equal size, no more merging required

    cout<<"Printing merged array"<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    //Step 2 Finding the median
  //Since arrays are of equal size,the merged array will have an even size
   int size3=size1+size2;
   int half=size3/2;
  double median=(ans[half]+ans[half-1])/2.0;
  cout<<"Median is "<<median<<endl;
}


void mediandiff(int arr1[],int size1,int arr2[],int size2)
{
    vector<int>ans;
    int i=0;
    int j=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    //After this while loop ,two situations possible,either i ran out of size or j ran out of size
    while(i<size1)
    {
        ans.push_back(arr1[i]);
        i++;
    }
    while(j<size2)
    {
        ans.push_back(arr2[j]);
        j++;
    }

    cout<<"Printing the merged array"<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    //Finding median 
    int size3=size1+size2;
    //size3 can be either even or odd
    int half=size3/2;
    if(size3%2==0)
    {
        double median=(ans[half]+ans[half-1])/2.0;
    cout<<"Median is "<<median<<endl;
    }
   else{
     double median=ans[half];
    cout<<"Median is "<<median<<endl;
   }

}

//Q12 with two pointer approach and constant space
void moveneg(int arr[],int size)
{       //Moving negative elements before positive elements
    int first=0;
    int second=size-1;
    while(first<second)
    {
        while(first <second && arr[first]<0)
        {
            first++;

        }
        while(first<second && arr[second]>0)
        {
            second--;
        }
        if(first<second){
            
        swap(arr[first],arr[second]);
        }
        
    }
}

bool subarrayzero(int arr[],int size)
{
    int i=0;
    bool found =false;
    while(i<size-2)//Ensuring atleast three elements
    {
        if(arr[i]+arr[i+1]+arr[i+2]==0)
        {
              found=true;
           
        }
       i++; //wont include in else part,coz always need to increment and check
    }
    if(found==true)
    {
        return true;
    }
    return false;
}

void subarraysum(int arr[],int size,int x)
{       //Window sliding technique
    int min_length=INT_MAX;
    int start=0;
    int currentsum=0;
    for(int i=0;i<size;i++)
    {
        currentsum=currentsum+arr[i]; // current sum update
    
    while(currentsum>x)
    {
        min_length=min(min_length,i-start+1); //minimum length find out
        currentsum=currentsum-arr[start];//try shrinking window
        start++;
    }
    }
    if(min_length==INT_MAX)
    {
        cout<<"No subarray with sum strictly greater than "<<x<< " is not found"<<endl;
    }
    else{
        cout<<"Subarray with sum strictly greater than "<<x<< " is with length "<< min_length<<endl;
    }

}

 int maximumsubarrsum(int arr[],int size)
{
    //Kadane's algorithm
    //Need to find the subarray with maximum sum
 int max_sum=INT_MIN;
 int current_sum=0;
 for(int i=0;i<size;i++)
 {
    current_sum=current_sum+arr[i];
    max_sum=max(max_sum,current_sum);
    if(current_sum<0)
    {
        current_sum=0;
    }
 }
return max_sum;


}


bool subsetarr(int arr1[],int size1,int arr2[], int size2)
{
    //Both the arrays are not sorted
    //Step 1 sort them
    sort(arr1,arr1+size1);
    sort(arr2,arr2+size2);
    int first=0;
    int second=0;
    int count=0;
    while(first<size1 && second<size2)
    {
        if(arr1[first]==arr2[second])
        {
            first++;
            second++;
            count++;
        }
        else if(arr2[second]>arr1[first])
        {
            first++;
        }
    }
    if (count==size2)
    
    {
        return true;
    }
    return false;
    }
//Using hashmaps
bool subsetmap(int arr1[],int size1,int arr2[],int size2)
{
    unordered_map<int,int>visited;
   
    for(int i=0;i<size1;i++)
    {
      visited[arr1[i]]++;
    }
    //Now check for arr2 if all its elements are in arr1
    for(int i=0;i<size2;i++)
    {
        if(visited[arr2[i]]==0)
        {
          return false; //immidiately return false,even if one element not found
        }
    }
   return true;

}

void duplicatetwopointer(int arr[],int size)
{   
    sort(arr,arr+size);
    vector<int>ans;
    int left=0;
    int right=1;
       while (right < size) {
        if (arr[left] == arr[right]) {
            ans.push_back(arr[left]);
            // Move both pointers to avoid duplicate counting
            while (right < size && arr[left] == arr[right]) {
                right++;
            }
            left = right-1;
        } else {
            left++;
            right++;
        }
    }

     auto last=unique(ans.begin(),ans.end());
    ans.erase(last,ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}

int longestconsecutivesubsequence(int arr[],int size)
{
    //sort
    sort(arr,arr+size);
    //Here,it is given that the elements are distinct,if not given then remove duplicates using vector
    
    int count=1;
    int max_count=INT_MIN;
    vector<int>ans;
    ans.push_back(arr[0]);
    for(int i=1;i<size;i++)
    {
        if(arr[i]==arr[i-1]+1)
        {
            ans.push_back(arr[i]);
            count++;
            max_count=max(count,max_count);
        }
         else{
            break;
        }
        
    }
    
       
    //Printing the longest consecutive subsequence
    cout<<"Printing the consecutive subsequence "<<endl;
   
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
   
    cout<<" Count is ";
   return max_count;

}

//Q26 pow(x^n)
//3^5 3*3*3*3*3  x^n
//time complexity O(n),wont be right
//Binary exponentiation
//if n is decimal(power),then its binary contain logn base 2+1
//time complexity will come out O(log n),loop will not run till 5(ex 3^5),binary form pr loop calculate
//1st find binary form,ans intialised at 1
double mypow(double x,int n)
{       if(n==0)
                return 1.0;
                if(x==0)
                return 0.0;
                if(x==1)
                return 1.0;
        long binform=n;
        if(n<0)//binary form is n but binary form pr loop chl rha h,this condition is for negative n
        {
            x=1/x;
            binform=-binform;
        }
        double ans=1;
        while(binform>0)
        {
            if(binform%2==1)
            {
                ans=ans*x;
            }
            x=x*x;
            binform=binform/2;
        }
        return ans;
}
//Q24 Buy and sell stock
//Buy a stock and choosing a different day to sell (always future day)the stock and maximise the profit
//{7,1,5,3,6,4} find min price to buy and maximum price to sell in future
//it cant be 1(min) and 7(max) because 7 comes before 1
//approach-imagine everyday as selling day
int buyandsell(int arr[],int size)
{
    int maxprofit=0;
    int bestbuy=arr[0];//to keep a track of the buy day,suppose at 3 we'll find minimum of before 3 values
    for(int i=1;i<size;i++)
    {
        //int i=1 cox 0th value cannot be selling day,we need to buy first
        if(arr[i]>bestbuy)//profit can happen
        {
            maxprofit=max(maxprofit,arr[i]-bestbuy);
        }
        bestbuy=min(bestbuy,arr[i]);

    }
    return maxprofit;
}



int main(){
    /*
        int third[15]={1,2,3,4,5};
        printarray(third,15);
        cout<<endl;
        //Finding size
        int thirdsize=sizeof(third)/sizeof(int);
        cout<<thirdsize;
        */

       //Q1 Finding minimum and maximum element in an array
       int arr[5]={1,2,7,4,5};
       int min=minimum(arr,5);
       cout<<min<<endl;
       int max=maximum(arr,5);
       cout<<max<<endl;

       //Q2 Reverse an array
       /*for(int i=4;i>=0;i--)
       {
            cout<<arr[i];
       }*/
       //using function 
       reverse(arr,5);
       cout<<endl;

       //Q3 Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
       /*int arr2[7]={0,1,2,0,0,1,0};
       sort(arr2,7);
       cout<<endl;
       int arr3[10]={1,1,2,2,0,0,1,1,0,0};
       sort(arr3,10);
       */
       //Q4 Program to cyclically rotate an array by one
       //Assign every element with its previous element  and first element with last element
       int rotate[6]={1,2,3,4,5,6};
       assign(rotate,6);
       cout<<endl;

       //Q5 Find union and intersection of two sorted arrays
       int unionarr1[7]={1,2,3,4,5,6,7};
       int unionarr2[6]={1,3,4,5,6,8};
       cout<<"Union of two arrays are"<<endl;
       unionarray(unionarr1,7,unionarr2,6);
       cout<<endl;
       intersection(unionarr1,7,unionarr2,6);
       cout<<endl;

//Q6 Count pairs with given sum(https://www.geeksforgeeks.org/count-pairs-with-given-sum/)
pairssum(unionarr1,7,9);
//Q7 Find duplicates in O(n) time and O(n) extra space(https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/)
int duplicatearr[12]={1,2,3,4,5,5,6,4,3,2,1};
findduplicates(duplicatearr,12);
cout<<endl;
//Q8Find common elements in three sorted arrays(https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/)
common2(unionarr1,7,duplicatearr,12,unionarr2,6);
cout<<endl;
//Q9Given Array of size n and a number k, find all elements that appear more than n/k times
int nbykarr[8]={3,1,2,3,2,2,3,1};
nbyk(nbykarr,8,4);
cout<<endl;
//Q10 Sum – Triplet Sum in Array(https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/)
tripletssum(unionarr1,7,10);
findTriplets(unionarr1,7,10);
//Q11 Find unique element in an array(3 approaches)
int uniquearr[12]={1,2,3,4,5,6,1,2,2,7,3,4};
unique(uniquearr,12);
cout<<endl;
unique2(uniquearr,12);
cout<<endl;
unique3(uniquearr,12);
cout<<endl;
//Q12 Move all the negative elements before positive elements with constant extra space
//(https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/)
//answer= just sort the array using any sorting technique
//Another method is two pointer approach( done after Q19 median of sorted arrays of diff sizes)
//Q13 Find kth max and min element in an array
int kmaxminarr[8]={1,2,4,5,6,7,8,3};
kmax(kmaxminarr,8,3);
kmin(kmaxminarr,8,3);
//Q14 swap alternates
swapalternate(kmaxminarr,8);
cout<<endl;
//Q16 Rearrange positive and negative numbers alternatively
//This question can be done by two pointer approach
int swapposnegarr[7]={1,2,3,4,-5,-6,-7};
swapposneg(swapposnegarr,7);
printarray(swapposnegarr,7);
cout<<endl;
//another question for two pointer approach-sort 0s1s
//One thing is like we sorted 0,1,2s but another approach is two pointer approach
//Two pointer approach-best time complexity
int sortzeroarr[7]={0,1,0,1,0,1,0};
sortone(sortzeroarr,7);
printarray(sortzeroarr,7);
cout<<endl;
//Q17 Merge two sorted arrays without using any extra space
//if extra space was allowed then simply while i and j not equal to 0, we would have cgecked which element is greater and push into the new vector
//and then jo khatm ho jaaye aur jo naa hue iske elements add
int mergearr1[10]={1,2,3,4,5};
int mergearr2[5]={1,2,3,4,5};
 int size1 = 5; // Initially filled elements in arr1
    int size2 = sizeof(mergearr2) / sizeof(mergearr2[0]);

    mergetwosorted(mergearr1, size1, mergearr2, size2);
    printarray(mergearr1, size1 + size2);
    cout<<endl;

//Q18 Median of two sorted arrays of same size
int medianarr1[5]={1,2,3,4,5};
int medianarr2[5]={1,2,3,4,5};
medianequal(medianarr1,5,medianarr2,5);
//Q19 Median of two Sorted Arrays of Different Sizes
int mediandiffarr1[5]={1,2,3,4,5};
int mediandiffarr2[2]={1,7};
mediandiff(mediandiffarr1,5,mediandiffarr2,2);
cout<<endl;
//Q20 Subarray with 0 sum
//(https://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/)
int subarrayarr[5]={4, 2, -3, 1, 6};
bool ans=subarrayzero(subarrayarr,5);
cout<<ans<<endl;
//Q21 Smallest subarray with sum greater than a given value
//(https://www.geeksforgeeks.org/minimum-length-subarray-sum-greater-given-value/)
//Window sliding technique is used when need to find subarrays or something related to subarrays
int subarrayarr1[6] = {1, 4, 45, 6, 0, 19};
subarraysum(subarrayarr1,6,51);
//If need to print the subarray
/*start index=0,end index=-1;
if (min_length > i - start + 1) {
    min_length = i - start + 1;
    start_index = start;
    end_index = i;
}
and then simply traverse krke print(from start index to end index)
*/
//If the array is sorted then,the question done before of finding pairs with a given sum can be done with two pointer approach
//left=0,right=size-1,while(left<right),if sum found print it and left++,right--,if sum less than target,too low,left++,else right--(too high)
//Q22 Find whether an array is subset of another array
//(https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/)
//One approach can be using nested loops

int subsetarr1[6]={1,2,3,4,5,6};
int subsetarr2[3]={1,2,7};
int issubset=subsetarr(subsetarr1,6,subsetarr2,3);
cout<<issubset<<endl;

//using hashmaps
//Q22 kadane's algorithm -Find the subarray with maximum sum and return its sum
int sum=maximumsubarrsum(subsetarr1,6);
cout<<sum<<endl;
//Q24 Stock Buy and Sell – Max one Transaction Allowed
//(https://www.geeksforgeeks.org/best-time-to-buy-and-sell-stock/)

//Find duplicates using two pointer approach-always require sorting
int twoptrduplarr[7]={1,2,2,3,4,5,5};
duplicatetwopointer(twoptrduplarr,7);
cout<<endl;
//Q25 Maximum product subarray(left)

//Q26 Pow(x^n)

//Q27 Longest Consecutive Subsequence
//(https://www.geeksforgeeks.org/longest-consecutive-subsequence/)
 int longestconsarr1[7] = {1, 9, 3, 10, 4, 20, 2};
 int longestcount1=longestconsecutivesubsequence(longestconsarr1,7);
 cout<<longestcount1<<endl;
 int longestconsarr2[11] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42};
  int longestcount2=longestconsecutivesubsequence(longestconsarr2,11);
  cout<<longestcount2<<endl;






}
