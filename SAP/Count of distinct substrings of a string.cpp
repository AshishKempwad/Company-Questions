/*
Given a string of length n of lowercase alphabet characters, we need to count total number of distinct substrings of this string.
Examples:

Input  : str = “ababa”
Output : 10
Total number of distinct substring are 10, which are,
"", "a", "b", "ab", "ba", "aba", "bab", "abab", "baba"
and "ababa"
*/

#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
     string s = "ababa";
     unordered_set<string>st;
     st.insert("");
     int n=s.size();
     for(int i=0;i<n-1;i++)
     {
         for(int j=i;j<n;j++)
         {
             string temp = s.substr(i,j-i+1);
             st.insert(temp);
         }
     }
     cout<<st.size();
     return 0;
}
