//Data structure
//Hash function
//hash code-conversion to int (suppose strings,chars,objs to int )(like storing a string to indexes in array) and
//uniform distribution
//collision -hash code for "babbar" sum of ascii codes 23 and for also "babbra"=23 so collision
//compressed fucntion-make the int got from hash code come in range of indexes

//to avoid collision
//Open hashing
//same place pr daaldo
//suppose babbara and babbar 23 7th index so at 7th index we have a head of linked list and in that linked list
//first node for babbra and second node for babbar and so on if there more words for 7th index(same sum of ascii)
//Also known as seperate chaining
//Second is open addressing
//linear probing
//hia=ha+fia where fi=i
//quadratic probing
//hia =ha +fia where fi =i^2
//closed addressing thi yeh sb
//whats actually happening is 7th index pr daalna tha to if already occupied,find next freespot

//Complexity Analysis
//hash code's TC is O(1)assuming n is far far greater than k where n is number of words and k is length
//of element so ideally the tc should be O(k)but is O(1) due to above given reason
//Properties of a good hashing function
/*
Deterministic: The same input will always produce the same hash.

Efficiently Computable: The hash value is quick to calculate.

Uniform Distribution: Hash values are distributed uniformly to avoid clustering
*/

//division function
//The division method is a common hashing technique. In this method,
// the hash value is computed as the remainder of the division of the key by a prime number. The formula is:

//Hash Value=Key%Prime Number
//Here, the prime number should ideally be close to the number of elements expected to be in the hash table.
//insertion
/*
m[key]=value;
pair<int,int>makepair(key,value);
*/
//Searching
/* m[key];
m.at(key);
*/

/*to check presence
m.count(key);
*/

#include <iostream>
#include <vector>

using namespace std;
int hashfunction(int key,int size)
{
    return key%size;
}
void insert(int key,vector<int> &hashtable)
{
    int index=hashfunction(key,hashtable.size());

    while(hashtable[index]!=-1)
    {
        index=(index+1)% hashtable.size();
    }
hashtable[index]=key;
}
void displayhashtable(vector<int>hashtable)
{
    for(int i=0;i<hashtable.size();i++)
    {
        cout<<hashtable[i];
    }
}
int main() {
    int tableSize = 10; // Size of the hash table
    vector<int> hashtable(tableSize, -1); // Initialize hash table with -1 (indicating empty slots)

    // Specific keys to be inserted
    vector<int> keys = {15, 25, 35, 45, 55};

    for (int key : keys) {
        insert(key, hashtable);
    }

    // Display the hash table
    cout << "Hash Table:" << endl;
    displayhashtable(hashtable);

    return 0;
}