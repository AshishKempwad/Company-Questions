/*

Given an array of items, an ith index element denotes the item id’s, 
and given a number m, the task is to remove m elements such 
that there should be minimum distinct id’s left. Print the number of distinct id’s.

Examples:

Input: arr[] = { 2, 2, 1, 3, 3, 3} m = 3
Output: 1
Explanation:
Remove 1 and both 2’s.
So, only 3 will be left, hence distinct number of element is 1.

Input: arr[] = { 2, 4, 1, 5, 3, 5, 1, 3} m = 2
Output: 3
Explanation:
Remove 2 and 4 completely. 
So, remaining 1, 3 and 5 i.e. 3 elements.

*/

#include <bits/stdc++.h>
using namespace std;

int distinctNumbers(int arr[], int m,int n)
{
	unordered_map<int, int> mp;

	for (int i = 0; i < n; i++)
  {
		  mp[arr[i]]++;
  }

	vector<int>freq(n + 1, 0);
	for (auto it : mp)
  {
		freq[it.second]++;
	}

	
	int ans = mp.size();

	for (int i = 1; i <= n; i++)
  {
		int temp = freq[i];
		if(temp!=0)
    {
          int t = min(temp, m / i);
          ans -= t;
          m -= i * t;
     }
}

	
	return ans;
}

// Driver Code
int main()
{
	// Initialize array
	int arr[] = { 2, 4, 1, 5, 3, 5, 1, 3 };

	// Size of array
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = 2;

	// Function call
	cout << distinctNumbers(arr, m, n);
	return 0;
}
