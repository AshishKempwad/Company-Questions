/*
In a N x N grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through;
1 means the cell contains a cherry, that you can pick up and pass through;
-1 means the cell contains a thorn that blocks your way.
 
Your task is to collect maximum number of cherries possible by following the rules below:

Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.
 
Example 1:

Input: grid =
[[0, 1, -1],
 [1, 0, -1],
 [1, 1,  1]]
Output: 5
Explanation: 
The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.

*/

//TC = O(N^3)
//SC = N(N^2)


class Solution {
public:
    
    //no.of steps = r1+c1 or r2+c2
    // Hence, r1+c1 = r2+c2 , Hence r2 = r1+c1-c2
    
    int helper(int r1,int c1,int c2,int n,vector<vector<vector<int>>>&dp,vector<vector<int>>&grid)
    {
        int r2 = r1+c1-c2;
        
        if(r1==n-1 && c1==n-1)
        {
            return grid[r1][c1];
        }
        if(r1 >= n || c1 >= n || r2 >=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1 )
        {
            return INT_MIN;
        }
        if(dp[r1][c1][c2]!=-1)
        {
            return dp[r1][c1][c2];
        }
        int curr_state = 0;
        
        if(r1==r2 && c1==c2)
        {
            curr_state = grid[r1][c1];   // if both arrive at same place, we choose only once as only one can pick the cherry
        }
        else 
        {
            curr_state = grid[r1][c1]+grid[r2][c2];
        }
        
        int ans=0;
        int ans1 = helper(r1+1,c1,c2,n,dp,grid);
        int ans2 = helper(r1+1,c1,c2+1,n,dp,grid);
        int ans3 = helper(r1,c1+1,c2,n,dp,grid);
        int ans4 = helper(r1,c1+1,c2+1,n,dp,grid);
        
        ans = ans1;
        ans = max(ans,ans2);
        ans=max(ans,ans3);
        ans=max(ans,ans4);
        
        dp[r1][c1][c2]=ans+curr_state;
        
        return dp[r1][c1][c2];
    }
    
    
    
    int cherryPickup(vector<vector<int>>& grid)
    {
       //Rather than going from bottom to up in second iteration, we can go from top to down twice.
        
        int n = grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans = max(0,helper(0,0,0,n,dp,grid));
        return ans;
        
    }
};
