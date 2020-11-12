/*Your are given n and an input array with n numbers.
You have to tell the minimum number of operations needed to pick each element from the input array make a sorted arrangement.
Every insertion and removal is 1 operation.
A sorted arrangement is basically an array that is sorted.
lets understand with example..
let n be 4
and input array be 2 4 1 3
so first we take 2 and insert in the empty sorted arrangement. so 1 operation
then the sorted arrangement is- 2
then we pick 4 and put it in the sorted arrangement.. so we would put after 2 so 1 operation
then the sorted arrangement is- 2 ,4
then we pick 1 and put it in the left so 1 operation..
then the sorted arrangement is- 1,2,4
(now this is important)
now we pick 3 and put we can either remove 1 and 2 put 3 and then again put 2 and 1 back or we can remove 4 , put 3 and again put 4.
obviously the latter takes 3 operations and former takes 5 operations. so we would perform the latter one.
answer is 1+1+1+3=6 operations.

constraints
N<10^5
*/

//Using Fenwick tree // Best Method

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>store;  // count,duplicate

void update(int index)
{
    int n = store.size();
    store[index].second += 1; // duplicates
    while(index<n)
    {
        store[index].first += 1;
        index += (index & -index);
    }
}


int query(int index)
{
    int count = 0;
    count += store[index].second; // add duplicates if already inserted
    while(index>0)
    {
        count += store[index].first;
        index -= (index & -index);
    }
    return count;
}



int main()
{
    
    int n;
    cin>>n;
    vector<int> nums(n);
    store.resize(n+5);   // arbitary
    int ans= 0;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    for(int i=0;i<n;i++)
    {
        int smallerAndEqual = query(nums[i]+1);
        int larger = i + -smallerAndEqual;
        // cout<<"smallerAndEqual:"<<smallerAndEqual<<endl;
        // cout<<"larger:"<<larger<<endl;
        ans+= 2*min(smallerAndEqual,larger) + 1;
        update(nums[i]+1);   
    }
    cout<<ans<<endl;
}

// Brute Force
//O(n^2)

#include<bits/stdc++.h>
using namespace std;



int main()
{
    
    int n;
    cin>>n;
    vector<int>arr(n);
    int ans= 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
     int count = 0;
    int left = 0;
    int right = 0;
    vector<int>targetArray;
    
   for(int i=0; i<arr.size(); i++)
   {
       left = 0;
       right = 0;
       for (int j=0;j<targetArray.size(); j++)
       {
           if(arr[i] != arr[j])
           {
            if(i != j)
            {
                if(arr[i] < arr[j]) 
                {
                    left++;
                } 
                else 
                {
                    right++;
                }
            }
       }
       }
       targetArray.push_back(arr[i]);
       count += (min(left, right) * 2) + 1;
    
   }
    cout<<count;
  
}


