/*Examples:

Input : X = "ABCD",  Y = "BACDBDCD"
Output : 3
"ACD" is longest subsequence of X which
is substring of Y.

Input : X = "A",  Y = "A"
Output : 1
Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.
Method 1 (Brute Force):
Use brute force to find all the subsequence of X and for each subsequence check whether it is substring of Y or not.
If it is substring of Y, maintain a maximum length variable and compare length with it.

Method 2: (Dynamic Programming):
Let n be length of X and m be length of Y. Create a 2D array ‘dp[][]’ of m + 1 rows and n + 1 columns.
Value dp[i][j] is maximum length of subsequence of X[0….j] which is substring of Y[0….i]. Now for each cell of dp[][] fill value as :




for (i = 1 to m)
  for (j = 1 to n)
    if (x[i-1] == y[j - 1])
      dp[i][j] = dp[i-1][j-1] + 1;
    else
      dp[i][j] = dp[i][j-1];
And finally, the length of the longest subsequence of x which is substring of y is max(dp[i][n]) where 1 <= i <= m.

Below is implementation this approach:

*/
// C++ program to find maximum length of 
// subsequence of a string X such it is 
// substring in another string Y. 
#include <bits/stdc++.h> 
#define MAX 1000 
using namespace std; 
  
// Return the maximum size of substring of 
// X which is substring in Y. 
int maxSubsequenceSubstring(char x[], char y[], 
                            int n, int m) 
{ 
    int dp[MAX][MAX]; 
  
    // Initialize the dp[][] to 0. 
    for (int i = 0; i <= m; i++) 
        for (int j = 0; j <= n; j++) 
            dp[i][j] = 0; 
  
    // Calculating value for each element. 
    for (int i = 1; i <= m; i++) { 
        for (int j = 1; j <= n; j++) { 
  
            // If alphabet of string X and Y are 
            // equal make dp[i][j] = 1 + dp[i-1][j-1] 
            if (x[j - 1] == y[i - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1]; 
  
            // Else copy the previous value in the 
            // row i.e dp[i-1][j-1] 
            else
                dp[i][j] = dp[i][j - 1]; 
        } 
    } 
  
    // Finding the maximum length. 
    int ans = 0; 
    for (int i = 1; i <= m; i++) 
        ans = max(ans, dp[i][n]); 
  
    return ans; 
} 
  
// Driver Program 
int main() 
{ 
    char x[] = "ABCD"; 
    char y[] = "BACDBDCD"; 
    int n = strlen(x), m = strlen(y); 
    cout << maxSubsequenceSubstring(x, y, n, m); 
    return 0; 
}
